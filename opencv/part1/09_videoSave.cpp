#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/yj/kuuniv.bigdata2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    if(!cap.isOpened()){
        cerr << "동영상 파일이 없습니다" << endl;
        // cerr << "장치가 없습니다!" << endl;
    }
    // 영상 정보 가져오기
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) ;
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    // 프레임 속도 가져오기
    double fps = cap.get(CAP_PROP_FPS);
    // 영상 저장 설정
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');
    VideoWriter outputVideo(folderPath + "vtest_out.avi", fourcc, fps, Size(w, h));

    // 영상 저장 설정 확인
    if(!outputVideo.isOpened()){
        cerr << "영상 저장 실패" << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        //  영상 처리 
        frame = ~frame;
        if(frame.empty())
            break;      // 마지막 프레임 처리
        // 영상 저장
        outputVideo << frame;   
        imshow("frame", frame);
        if (waitKey(1000/fps) == 27) // fps 조절 숫자. 1s -> 1000, 
            break;
    }

    cap.release();
    outputVideo.release();
    destroyAllWindows();

    return 0;
}