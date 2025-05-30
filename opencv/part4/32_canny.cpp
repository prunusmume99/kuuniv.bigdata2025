#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    VideoCapture cap(0); // 또는 "test_video.mp4" 등
    if (!cap.isOpened()) {
        cerr << "카메라 또는 영상 파일을 열 수 없습니다!" << endl;
        return -1;
    }

    Mat img, edge;
    int low_v = 50, high_v = 150; // 초기값 필수!

    namedWindow("img1");
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);

    while (true)
    {
        cap >> img;
        if (img.empty()) break;

        cvtColor(img, img, COLOR_BGR2GRAY); // Canny는 그레이스케일 입력 필요
        Canny(img, edge, low_v, high_v);
        imshow("img1", edge);

        if (waitKey(30) == 27) // ESC키 종료
            break;
    }

    cap.release();
    destroyAllWindows();
    return 0;
}



// #include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
// #include <iostream>
// #include <opencv2/opencv.hpp>
// #include <vector>

// using namespace std;
// using namespace cv;

// String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

// int lowedge = 100;  // 트랙바를 위한 전역 변수

// int main()
// {
//     // 이미지 로드
//     Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
//     if(img.empty()) {
//         cerr << "이미지를 불러올 수 없습니다!" << endl;
//         return -1;
//     }

//     // 노이즈 제거를 위한 가우시안 블러
//     Mat blurred;
//     GaussianBlur(img, blurred, Size(5, 5), 0);

//     // 결과를 저장할 벡터
//     vector<Mat> images;
//     images.push_back(img.clone());  // 원본 이미지 저장

//     // 윈도우 생성 및 트랙바 추가
//     namedWindow("Original");
//     createTrackbar("lowedge", "Original", &lowedge, 255);

//     while(true)
//     {
//         // Canny 엣지 검출
//         Mat edges;
//         Canny(img, edges, lowedge, lowedge * 2);
        
//         // 결과 표시
//         imshow("Original", img);    // 원본 이미지
//         imshow("Edges", edges);     // 엣지 검출 결과

//         // ESC 키를 누르면 종료
//         if(waitKey(33) == 27)
//             break;
//     }

//     destroyAllWindows();
//     return 0;
// }