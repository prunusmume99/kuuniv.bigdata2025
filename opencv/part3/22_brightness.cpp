#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

Mat clacGrayHist(const Mat& img)
{
    CV_Assert(img.type() == CV_8UC1); 

    Mat hist;
    int channel[] = {0}; 
    int dims = 1;
    const int histSize[] = {256}; 
    float gyaylevel[] = {0, 256}; 
    const float* ranges[] = {gyaylevel};

    calcHist(&img, 1, channel, noArray(), hist, dims, histSize, ranges);
    return hist;
}

Mat getGreyHistogram(const Mat& hist)
{
    CV_Assert(hist.type() == CV_32FC1);     // Grey histogram should be of type CV_32FC1 (grey 스케일 확인 에러 발생)
    CV_Assert(hist.size() == Size(1, 256)); // Histogram should have 256 bins (histogram 인지 확인)

    double histMax;
    minMaxLoc(hist, 0, &histMax);           // Get the maximum value in the histogram

    Mat imgHist(100, 256, CV_8UC1, Scalar(255)); 
    for (int i = 0; i < 256; ++i) {
        line(imgHist, Point(i, 100), Point(i, 100 - (cvRound(hist.at<float>(i,0))) / histMax * 100), black);
    }
    return imgHist;
}

int main()
{
    Mat img = imread(folderPath + "hawkes.bmp", IMREAD_GRAYSCALE);
    namedWindow("img");
    Mat img2 = img + 100; // bright
    Mat img3 = 2.f * img; // contrast 대조
    Mat img4 = img + (img - 128) * 1.f;

    double min, max;
    minMaxLoc(img, &min, &max); 

    Mat img5 = (img - min) / (max - min) * 255; // stretching

    Mat img6;
    equalizeHist(img, img6); // 히스토그램 평활화

    // histgram 만들기
    imshow("hist-img", getGreyHistogram(clacGrayHist(img)));

    imshow("img", img);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    imshow("img5", img5);
    imshow("img6", img6);

    waitKey();
    destroyAllWindows();
    return 0;
}