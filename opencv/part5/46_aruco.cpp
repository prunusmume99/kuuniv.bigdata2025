#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp> // red 정의 포함되어 있으면 사용
#include <iostream>
#include <opencv2/aruco.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
    Ptr<aruco::Dictionary> dictionary = aruco::getPredefinedDictionary(aruco::DICT_6X6_250);
    Ptr<aruco::DetectorParameters> parameters = aruco::DetectorParameters::create();
    VideoCapture cap(0);

    vector<vector<Point>> corners;
    vector<int> ids;
    Mat cameraMatrix = (Mat_<double>(3, 3) << 1000, 0, 320, 0, 1000, 240, 0, 0, 1);
    Mat distCoeffs = (Mat_<double>(5, 1) << 0, 0, 0, 0, 0);
    
    vector<Vec3d> rvecs, tvecs;
    Mat img;
    while (true)
    {
        cap >> img;
        if (img.empty())
            break;
        aruco::detectMarkers(img, dictionary, corners, ids, parameters, cameraMatrix, distCoeffs);

        if (ids.size() > 0)
        {
            aruco::drawDetectedMarkers(img, corners, ids);
        }

        imshow("img", img);
        if (waitKey(33) == 27)
            break;
    }
    destroyAllWindows();
    return 0;
}