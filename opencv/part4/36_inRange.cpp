#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";
typedef struct
{
    int lower_hue;
    int upper_hue;
    vector<Mat> images;
} Mydata;
void on_hue_changed(int pos, void *data);

int main()
{
    Mat img = imread(folderPath + "candies.png");
    Mydata mydata;
    mydata.images.push_back(img.clone());
    cvtColor(img, img, COLOR_BGR2HSV);
    mydata.images.push_back(img);
    mydata.images.push_back(Mat::zeros(img.size(), CV_8UC1));
    namedWindow("img2");
    createTrackbar("lower Hue", "img2", &mydata.lower_hue, 179, on_hue_changed, (void *)&mydata);
    createTrackbar("upper Hue", "img2", &mydata.upper_hue, 179, on_hue_changed, (void *)&mydata);
    on_hue_changed(0, &mydata);
    // vector img show 코드
    int i = 1;
    for (auto img : mydata.images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    waitKey();
    destroyAllWindows();
    return 0;
}

void on_hue_changed(int pos, void *data)
{
    Mydata *mydata = (Mydata *)data;
    Scalar lowerb(mydata->lower_hue, 0, 0);
    Scalar upperb(mydata->upper_hue, 255, 255);
    inRange(mydata->images[1], lowerb, upperb, mydata->images[2]);
    imshow("img3", mydata->images[2]);
}