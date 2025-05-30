#include </home/yj/kuuniv.bigdata2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>

using namespace std;
using namespace cv;

// 사용자 데이터를 저장할 구조체 정의
typedef struct
{
    Point2f srcPts[4];    // 원본 이미지의 4개 점 좌표
    Point2f dstPts[4];    // 변환될 이미지의 4개 점 좌표
    Mat frame;            // 현재 프레임
    Mat dst;              // 변환된 결과 이미지
} Mydata;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

// 마우스 이벤트 처리 함수 선언
void on_mouse(int event, int x, int y, int flags, void *userdata);

int main()
{ 
    // 웹캠 열기
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다!" << endl;
    }
    // 웹캠 정보 출력
    cout << "Frame width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    auto fps = cap.get(CAP_PROP_FPS);
    cout << "fps : " << cvRound(fps) << endl;

    // 윈도우 생성 및 마우스 콜백 함수 설정
    namedWindow("frame");
    Mydata userdata;
    setMouseCallback("frame", on_mouse, (void *)&userdata);

    Mat frame;
    while (true)
    {
        // 프레임 읽기
        cap >> userdata.frame;
        if (userdata.frame.empty())
            break; // 마지막 프레임 처리

        // 선택된 4개의 점을 빨간색 원으로 표시
        for (int i = 0; i < 4; ++i)
        {
            circle(userdata.frame, Point(userdata.srcPts[i].x, userdata.srcPts[i].y), 5, red, -1);
        }
        imshow("frame", userdata.frame);
        if (waitKey(1000 / fps) == 27) // ESC 키를 누르면 종료
            break;
    }

    // 자원 해제
    cap.release();
    destroyAllWindows();
    return 0;
}

// 마우스 이벤트 처리 함수
void on_mouse(int event, int x, int y, int flags, void *userdata)
{
    Mydata *mydata = (Mydata *)userdata;
    static int cnt = 0;  // 클릭한 점의 개수를 추적

    if (event == EVENT_LBUTTONDOWN)  // 마우스 왼쪽 버튼 클릭 시
    {
        if (cnt < 4)  // 4개의 점을 모두 선택하지 않았다면
        {
            mydata->srcPts[cnt++] = Point2f(x, y);  // 클릭한 위치 저장
        }
        if (cnt == 4)  // 4개의 점을 모두 선택했다면
        {
            // 변환될 이미지의 크기 설정
            int w = 200, h = 300;
            // 변환될 이미지의 4개 모서리 좌표 설정
            mydata->dstPts[0] = Point2f(0, 0);
            mydata->dstPts[1] = Point2f(w - 1, 0);
            mydata->dstPts[2] = Point2f(w - 1, h - 1);
            mydata->dstPts[3] = Point2f(0, h - 1);

            // 원근 변환 행렬 계산
            Mat M = getPerspectiveTransform(mydata->srcPts, mydata->dstPts);
            // 원근 변환 적용
            warpPerspective(mydata->frame, mydata->dst, M, Size(w, h));
            // 변환된 이미지 표시
            imshow("dst", mydata->dst);
            cnt = 0;  // 점 개수 초기화
        }
    }
}