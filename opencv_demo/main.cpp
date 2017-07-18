#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
using namespace std;
using namespace cv;

Mat frame;
Mat edges;
int structElementSize = 1;
int typeNum = 0;
static void process(int, void*) {
	Mat ksize = getStructuringElement(MORPH_RECT,
			Size(structElementSize * 2 + 1, structElementSize * 2 + 1),
			Point(-1, -1));

	if (typeNum == 0) {
		erode(frame, edges, ksize);
	} else {
		dilate(frame, edges, ksize);
	}
}

static void on_trackType(int, void*) {
	process(structElementSize, 0);
}

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

	namedWindow("当前视频",WINDOW_AUTOSIZE);

//	createTrackbar("【0-腐蚀、1-膨胀】效果图", "当前视频", &typeNum, 1, process);
//
//	createTrackbar("【ksize】", "当前视频", &structElementSize, 10, process);

	while (true) { //waitkey 时间ms，while循环。每xms刷新摄像头图像。产生实时画面。
		capture >> frame;

//		process(structElementSize,0);

		cvtColor(frame, edges, CV_BGR2GRAY);
//		GaussianBlur(edges, edges, Size(7, 7), 1.5, 1.5);
//		Canny(edges, edges, 0, 30, 3);
		imshow("当前视频", frame);

		imshow("效果视频", edges);
		char c = waitKey(1);
		if (c == 'q') {
			break;
		}
	}

	return 0;
}
