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

    int cnt = connectedComponents(images[5], images[5], 4);

    cout << "Labelling: " << cnt << endl;

    Mat stats, centroids;
    int cnt = connectedComponentsWithStats(images[5], images[5], stats, centroids, 4);

    // vector img show 코드
    int i = 1;
    for (int i = 1; i <= cnt; i++){
        int *p = stats.ptr<int>(i);
        if(p[4] > 1000){
            rectangle(images[4], Point(p[0], p[1]), Point(p[0] + p[2], p[1] + p[3]), red, 2, LINE_AA);
    }

    waitKey();
    destroyAllWindows();
    return 0;
}