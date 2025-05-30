// 카메라를 켜서 frame 확보
// 색 공간 -> hsv로 변경, clone() 해서 따로 처리
// 양방향 필터 처리
// inRange -> 색종이 인식
// morph 함수 사용 -> 이진화 Mat 처리
// labeling
// 화면에 rectangle로 표시
// putText, ft2로 색종이 or color paper 표시
// 사각형과 폰트는 색종이를 따라다녀야 함. 

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

bool isRectInside(const Rect& rect, const Size& size) {
    return rect.x >= 0 && rect.y >= 0 &&
           rect.x + rect.width <= size.width &&
           rect.y + rect.height <= size.height;
}

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "❌ 카메라를 열 수 없습니다." << endl;
        return -1;
    }

    while (true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty()) break;

        Mat hsv_full, filtered_full, mask_full, morphed;
        cvtColor(frame, hsv_full, COLOR_BGR2HSV);
        bilateralFilter(hsv_full, filtered_full, 9, 75, 75);

        // HSV 범위 완화
        Scalar lower_pink(140, 30, 100);
        Scalar upper_pink(180, 150, 255);
        inRange(filtered_full, lower_pink, upper_pink, mask_full);

        // Morphology
        Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(mask_full, morphed, MORPH_OPEN, kernel);
        morphologyEx(morphed, morphed, MORPH_CLOSE, kernel);

        // 윤곽선 탐색
        vector<vector<Point>> contours;
        findContours(morphed, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        for (const auto& contour : contours) {
            double area = contourArea(contour);
            if (area < 700 || area > 40000) continue;

            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(contour, true) * 0.03, true);
            if (approx.size() >= 4 && isContourConvex(approx)) {
                Rect box = boundingRect(approx);
                float aspect = (float)box.width / box.height;
                if (aspect < 0.4 || aspect > 2.5) continue; // 너무 가늘거나 길면 제외 (손가락)

                if (!isRectInside(box, frame.size())) continue; // 유효한 범위인지 검사

                // crop 영역 안전하게 잘라내고 HSV 처리
                Mat cropped = frame(box).clone(); // clone 사용
                Mat cropped_hsv;
                cvtColor(cropped, cropped_hsv, COLOR_BGR2HSV);

                // 평균 채도 계산
                Scalar mean_hsv = mean(cropped_hsv);
                double mean_saturation = mean_hsv[1];
                if (mean_saturation < 50) continue; // 채도가 너무 낮으면 제외 (손가락, 종이 아님)

                // 색종이 확정
                rectangle(frame, box, Scalar(0, 255, 0), 2);
                putText(frame, "Color Paper", Point(box.x, box.y - 10),
                        FONT_HERSHEY_SIMPLEX, 0.8, Scalar(0, 0, 255), 2);
            }
        }

        imshow("Color Paper Tracker", frame);
        imshow("Mask View", mask_full);
        if (waitKey(10) == 27) break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
