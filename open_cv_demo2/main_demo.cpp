#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	VideoCapture capture;

	capture.open(0);

	if (!capture.isOpened()) {
		return -1;
	}

	double w = 320, h = 240;
	capture.set(CV_CAP_PROP_FRAME_WIDTH, w);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, h);
	capture.set(CV_CAP_PROP_FRAME_WIDTH, w);
	capture.set(CV_CAP_PROP_FRAME_HEIGHT, h);


	Mat frame;
	Mat edges;

	while (true) {

		capture>>frame;
		cvtColor(frame, edges, CV_BGR2GRAY);
		GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
		Canny(edges, edges, 0, 30, 3);
		imshow("当前视频",edges);

		//展示当前帧的图片
//		imshow("myWindow", frame);
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	}
}
