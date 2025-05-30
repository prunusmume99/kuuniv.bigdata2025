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
    Mat img = imread(folderPath + "sudoku.jpg", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img);
    images.emplace_back(Mat());
    images.emplace_back(Mat());
    threshold(img, images[1], 128, 255, THRESH_OTSU);
    adaptiveThreshold(img, images[2], 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 35, 5);

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