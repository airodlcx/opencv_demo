#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	Mat srcImg = imread("2015-12-29 173343.jpg");
	Mat logoImg = imread("logo.jpg",0);
	vector<Mat> channels;
	Mat src(srcImg.cols,srcImg.rows,srcImg.type());
//	src.create(srcImg.cols,srcImg.rows,srcImg.type());
	split(srcImg,channels);

	Mat ROI = channels.at(0)(Rect(srcImg.cols-logoImg.cols,srcImg.rows-logoImg.rows,logoImg.cols,logoImg.rows));

//	addWeighted(ROI,1.0,logoImg,1.0,0.0,ROI);

	logoImg.copyTo(ROI);

	merge(channels,src);

	namedWindow("img",WINDOW_NORMAL);

	imshow("img",src);

	waitKey(0);

	return 0;
}

