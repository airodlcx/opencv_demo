#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	Mat logo = imread("logo.jpg");
	Mat srcImg = imread("2015-12-29 173343.jpg");
	Mat roi = srcImg(Rect(srcImg.cols-logo.cols,srcImg.rows-logo.rows,logo.cols,logo.rows));
	Mat mask = imread("logo.jpg",0);
//	logo.copyTo(roi,mask);

	addWeighted(roi,1.0,logo,1.0,0.0,roi);
	namedWindow("img",WINDOW_NORMAL);
	imshow("img",srcImg);

	waitKey(0);
	return 0;
}

