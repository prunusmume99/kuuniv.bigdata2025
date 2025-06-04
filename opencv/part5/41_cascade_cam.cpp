#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp> // red 정의 포함되어 있으면 사용
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
    // 1. 분류기 로드
    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");
    if (classifier.empty())
    {
        cerr << "❌ 캐스케이드 파일을 불러올 수 없습니다!" << endl;
        return -1;
    }

    // 2. 카메라 열기
    VideoCapture cap(0);  // 0번 웹캠 (내장 카메라)
    if (!cap.isOpened())
    {
        cerr << "❌ 카메라를 열 수 없습니다!" << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        if (frame.empty()) break;

        // 3. 얼굴 검출
        vector<Rect> faces;
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        equalizeHist(gray, gray);  // 밝기 보정

        classifier.detectMultiScale(gray, faces, 1.1, 5);

        // 4. 얼굴 위치에 사각형 그리기
        for (auto &rect : faces)
        {
            rectangle(frame, rect, red, 2); // red 정의된 경우
            // rectangle(frame, rect, Scalar(0,0,255), 2); // 혹시 red 정의 안 됐을 때
        }

        // 5. 결과 화면 출력
        imshow("Webcam - Face Detection", frame);

        // ESC 키 누르면 종료
        if (waitKey(10) == 27)
            break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
