
#include <iostream>
#include <opencv2/opencv.hpp>
#include "color.hpp"
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
   //data
   String name = "imyunjin";
   int age = 20;
   Point pt1(100, 200);
   vector<int> scores = {80, 90, 100};
   Mat mat1 = (Mat_ <float> (2, 2) << 1.0f,1.5f,2.0f,3.2f);
   

   String filename = folderPath + "mydata.yml";
   FileStorage fs(filename, FileStorage::WRITE);
   fs << "name" << name;
   fs << "age" << age;
   fs << "pt1" << pt1;
   fs << "scores" << scores;
   fs << "mat1" << mat1;
   fs.release();
   
}