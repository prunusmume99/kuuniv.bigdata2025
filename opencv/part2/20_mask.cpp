#include </home/aa/kuBig2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/aa/kuBig2025/opencv/data/";

int main()
{
    Mat img1 = imread(folderPath + "lenna.bmp");
    Mat img2 = imread(folderPath + "mask_smile.bmp", IMREAD_GRAYSCALE);

    img1.setTo(yellow, img2);
    imshow("img", img1);

    Mat airplan = imread(folderPath + "airplane.bmp");
    Mat maskAirplan = imread(folderPath + "mask_plane.bmp", IMREAD_GRAYSCALE);
    Mat sky = imread(folderPath + "field.bmp");

    airplan.copyTo(sky, maskAirplan);

    imshow("sky", sky);

    waitKey();
    destroyAllWindows();

    return 0;
}