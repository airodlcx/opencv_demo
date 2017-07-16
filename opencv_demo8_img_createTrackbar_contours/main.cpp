#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int currentNumber = 160;
Mat img;

static void on_trackbar(int, void*) {
	Mat bw =
			currentNumber > 128 ? (img > currentNumber) : (img < currentNumber);

	vector<vector<Point>> contours;

	vector<Vec4i> hierarchy;

	findContours(bw, contours, hierarchy, CV_RETR_CCOMP,
			CV_CHAIN_APPROX_SIMPLE);

	Mat dst = Mat::zeros(img.size(), CV_8UC3);

	if (!contours.empty() && !hierarchy.empty()) {
		int idx = 0;
		for (; idx >= 0; idx = hierarchy[idx][0]) {
			Scalar color(rand() & 255, rand() & 255, rand() & 255);
			drawContours(dst, contours, idx, color, CV_FILLED, 8, hierarchy);
		}
	}

	//显示窗口
	imshow("Connected Components", dst);
}

int main() {
	img = imread("2015-12-29 173343.jpg", 0);
	if (!img.data) {
		printf("OH,NO!读取img图片文件错误~！ \n");
		return -1;
	}

	//显示原图
	namedWindow("Image", 1);
	imshow("Image", img);

	//创建处理窗口
	namedWindow("Connected Components", WINDOW_AUTOSIZE);
	//创建轨迹条
	createTrackbar("Threshold", "Connected Components", &currentNumber, 255,
			on_trackbar);

	on_trackbar(currentNumber, 0); //轨迹条回调函数

	waitKey(0);
	return 0;
}

