#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";


int main()
{
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img.clone());
    Mat noise(img.size(), CV_32FC1);
    randn(noise, 0, 15);
    add(img, noise, img, Mat(), CV_8U);
    images.push_back(img);
    images.emplace_back(Mat()); // 벡터 내부에 바로 생성
    images.emplace_back(Mat());
    GaussianBlur(img, images[2], Size(), 5);
    bilateralFilter(img, images[3], -1, 10, 5);

    int i = 1;
    for(auto img : images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    destroyAllWindows();

    return 0;
}