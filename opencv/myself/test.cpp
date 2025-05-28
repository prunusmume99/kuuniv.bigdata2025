#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
    cout << "hello, world" << endl;

    // 이미지 불러오기
    Mat img = imread(folderPath + "tekapo.bmp");
    if (img.empty())
    {
        cerr << "이미지 불러오기 실패!!" << endl;
        return -1;
    }

    // 원하는 창 크기 지정 (예: 1280x720)
    int winWidth = 1280;
    int winHeight = 720;

    // 이미지 리사이즈해서 창 크기에 맞춤
    Mat resizedImg;
    resize(img, resizedImg, Size(winWidth, winHeight));

    // 창 생성 및 크기 설정
    namedWindow("dog", WINDOW_NORMAL);
    resizeWindow("dog", winWidth, winHeight);

    // 이미지 출력
    imshow("dog", resizedImg);
    waitKey();

    // 저장 (옵션)
    vector<int> jpg_params = {IMWRITE_JPEG_QUALITY, 20};
    imwrite(folderPath + "dog_save_20.jpg", resizedImg, jpg_params);

    destroyAllWindows();
    return 0;
}

// #include <iostream>
// #include <opencv2/opencv.hpp>

// using namespace std;
// using namespace cv;

// String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

// int main()
// {
//     cout << "hello, world" << endl;

//     // 이미지 불러오기
//     Mat img = imread(folderPath + "dog.bmp");
//     if (img.empty())
//     {
//         cerr << "이미지 불러오기 실패!!" << endl;
//         return -1;
//     }

//     // 원하는 창 크기 지정 (예: 1280x720)
//     int winWidth = 1280;
//     int winHeight = 720;

//     // 이미지 리사이즈해서 창 크기에 맞춤
//     Mat resizedImg;
//     resize(img, resizedImg, Size(winWidth, winHeight));

//     // 창 생성 및 크기 설정
//     namedWindow("dog", WINDOW_NORMAL);
//     resizeWindow("dog", winWidth, winHeight);

//     // 이미지 출력
//     imshow("dog", resizedImg);
//     waitKey();

//     // 저장 (옵션)
//     vector<int> jpg_params = {IMWRITE_JPEG_QUALITY, 20};
//     imwrite(folderPath + "dog_save_20.jpg", resizedImg, jpg_params);

//     destroyAllWindows();
//     return 0;
// }
