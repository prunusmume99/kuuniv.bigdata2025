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
   String name;
   int age;
   Point pt1();
   vector<int> scores;
   Mat mat1;

   String filename = folderPath + "mydata.yml";
   FileStorage fs(filename, FileStorage::READ);
   fs ["name"] >> name;
   fs ["age"] >> age;   
   fs ["pt1"] >> pt1;
   fs ["scores"] >> scores;
   fs ["mat1"] >> mat1;

   cout << "name: " << name << endl;
   cout << "age: " << age << endl;
   cout << "point: " << pt1 << endl;
   cout << "scores: " <<Mat(scores).t() << endl;
   cout << "mat1: " << mat1 << endl;

   fs.release();
   
}