// 키 입력 처리 테스트
// 이미지 효과 토글 실험
// 프레임 속도(FPS) 측정
// 같은 상황에서 유용한 디버깅 및 실험용 툴 코드

#include <iostream>
#include <opencv2/opencv.hpp>
#include "color.hpp"
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;


String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";


int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        keycode = waitKeyEx(0);
        cout << "keycode: " << keycode << endl;
        cout << "i: " << i << endl;
        cout << "fps: " << getTickFrequency() / (getTickCount() - i) << endl;

        if (keycode == 'v' || keycode == 'V')
        {
            img = ~img;
        }
        if (keycode == 'a' || keycode == 'A')
        {
            img = img + 1;
        }
        if (keycode == 'd' || keycode == 'D')
        {
            img = img - 1;
        }
        if (keycode == 65364)
        {
            cout << "key up arrow!" << endl;
        }
        if (keycode == 65362)
        {
            cout << "key down arrow!" << endl;
        }
        imshow("img", img);
        if (keycode == 1048603)
            break;
        i = getTickCount();
    }
    destroyAllWindows();
    return 0;
}