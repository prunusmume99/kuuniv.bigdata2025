#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>  // red 정의 포함되어 있으면 유지
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
    // 원본 이미지 읽기
    Mat img = imread(folderPath + "kids.png");
    if (img.empty())
    {
        cerr << "이미지를 불러올 수 없습니다!" << endl;
        return -1;
    }       

    vector<Mat> images;
    images.push_back(img.clone());  // 원본 저장
    images.emplace_back(Mat());     // 빈 이미지 공간 추가

    // 캐스케이드 분류기 로드
    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");
    if (classifier.empty())
    {
        cerr << "캐스케이드 파일을 불러올 수 없습니다!" << endl;
        return -1;
    }

    // 얼굴 검출
    vector<Rect> faces;
    classifier.detectMultiScale(img, faces);

    // 얼굴 위치에 사각형 그리기
    for (auto &rect : faces)
    {
        rectangle(img, rect, Scalar(0, 0, 255), 2); // red 안 될 경우 직접 지정
    }

    images[1] = img.clone(); // 얼굴 검출 후 이미지 저장

    // 이미지 벡터 출력
    for (size_t i = 0; i < images.size(); i++)
    {
        String winName = "Image " + to_string(i);
        imshow(winName, images[i]);
    }

    waitKey(0);
    destroyAllWindows();
    return 0;
}
