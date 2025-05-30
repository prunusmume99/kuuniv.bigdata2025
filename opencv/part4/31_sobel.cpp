#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;

    Mat dx, dy;
    Sobel(img, dx, CV_32FC1, 1, 0);
    Sobel(img, dy, CV_32FC1, 0, 1);
    // Scharr 필터.
    Mat magni, phase_mat;
    magnitude(dx, dx, magni);
    phase(dx, dy, phase_mat, true);

    dx.convertTo(dx, CV_8UC1);
    images.push_back(dx);
    dy.convertTo(dy, CV_8UC1);
    images.push_back(dy);
    magni.convertTo(magni, CV_8UC1);
    images.push_back(magni);
    phase_mat.convertTo(phase_mat, CV_8UC1);
    images.push_back(phase_mat);
    Mat edge = magni > 150;
    images.push_back(edge);

    // vector img show 코드
    int i = 1;
    for (auto img : images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    waitKey();
    destroyAllWindows();
    return 0;
}




// #include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
// #include <chrono>
// #include <iostream>
// #include <opencv2/opencv.hpp>
// #include <thread>
// #include <vector>

// using namespace std;
// using namespace cv;

// String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

// int main()
// {
//     // 그레이스케일로 이미지 로드
//     Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
//     if(img.empty()) {
//         cerr << "이미지를 불러올 수 없습니다!" << endl;
//         return -1;
//     }

//     // Sobel 연산을 위한 변수들 선언
//     // dx: x방향 미분 결과
//     // dy: y방향 미분 결과
//     // magnitude: 그래디언트의 크기
//     // angle: 그래디언트의 방향
//     Mat dx, dy, magnitude, angle;
    
//     // Sobel 연산 수행
//     // CV_32F: 32비트 실수형으로 결과 저장
//     // 1, 0: x방향 미분 (수평 엣지 검출)
//     // 0, 1: y방향 미분 (수직 엣지 검출)
//     Sobel(img, dx, CV_32F, 1, 0);
//     Sobel(img, dy, CV_32F, 0, 1);

//     // 그래디언트의 크기와 방향 계산을 위한 행렬 초기화
//     magnitude = Mat::zeros(dx.size(), CV_32F);
//     angle = Mat::zeros(dx.size(), CV_32F);
    
//     // 각 픽셀에 대해 그래디언트 크기와 방향 계산
//     for(int y = 0; y < dx.rows; y++) {
//         for(int x = 0; x < dx.cols; x++) {
//             float gx = dx.at<float>(y, x);  // x방향 그래디언트
//             float gy = dy.at<float>(y, x);  // y방향 그래디언트
//             // 그래디언트 크기 = sqrt(gx^2 + gy^2)
//             magnitude.at<float>(y, x) = sqrt(gx*gx + gy*gy);
//             // 그래디언트 방향 = atan2(gy, gx) * 180/π (도 단위)
//             angle.at<float>(y, x) = atan2(gy, gx) * 180 / CV_PI;
//         }
//     }

//     // 결과 이미지들을 8비트로 변환 (시각화를 위해)
//     Mat dx_8u, dy_8u, magnitude_8u, angle_8u;
//     dx.convertTo(dx_8u, CV_8U);        // x방향 미분 결과
//     dy.convertTo(dy_8u, CV_8U);        // y방향 미분 결과
//     magnitude.convertTo(magnitude_8u, CV_8U);  // 그래디언트 크기
//     angle.convertTo(angle_8u, CV_8U);          // 그래디언트 방향

//     // 엣지 검출 (임계값 150 적용)
//     // magnitude가 150보다 큰 픽셀은 255(흰색), 작은 픽셀은 0(검은색)으로 설정
//     Mat edge;
//     threshold(magnitude_8u, edge, 150, 255, THRESH_BINARY);

//     // 결과 이미지들 표시
//     imshow("Original", img);           // 원본 이미지
//     imshow("Sobel X", dx_8u);         // x방향 미분 결과
//     imshow("Sobel Y", dy_8u);         // y방향 미분 결과
//     imshow("Magnitude", magnitude_8u); // 그래디언트 크기
//     imshow("Angle", angle_8u);        // 그래디언트 방향
//     imshow("Edge", edge);             // 임계값 적용된 엣지

//     waitKey(0);  // 키 입력 대기
//     destroyAllWindows();  // 모든 창 닫기
//     return 0;
// }