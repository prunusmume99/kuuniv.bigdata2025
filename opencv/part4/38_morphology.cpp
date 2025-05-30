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
    Mat img = imread(folderPath + "milkdrop.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img);
    for (int i = 0; i < 5; ++i)
        images.emplace_back(Mat());
    threshold(img, images[1], 0, 255, THRESH_BINARY | THRESH_OTSU);
    erode(images[1], images[2], Mat());
    dilate(images[1], images[3], Mat());
    morphologyEx(images[1], images[4], MORPH_OPEN, Mat(), Point(-1, -1), 4);
    morphologyEx(images[4], images[5], MORPH_CLOSE, Mat(), Point(-1, -1), 3);

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