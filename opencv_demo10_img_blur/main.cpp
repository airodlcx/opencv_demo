#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Mat boxFilter_img; //方框滤波
Mat blur_img; //均值滤波
Mat GaussianBlur_img; //高斯滤波
int boxFilterSize = 3;
int blurSize = 3;
int GaussianBlurSize = 3;

static void boxFilter_trackbar(int, void*);
static void blur_trackbar(int, void*);
static void GaussianBlur_trackbar(int, void*);
int main() {
	src = imread("2015-12-29 173343.jpg");

	namedWindow("【原图】", 0);
	imshow("【原图】", src);

	namedWindow("【方框滤波】", 0);
	createTrackbar("【方框滤波Track】", "【方框滤波】", &boxFilterSize, 40,
			boxFilter_trackbar);
	boxFilter_trackbar(boxFilterSize, 0);

	namedWindow("【均值滤波】", 0);
	createTrackbar("【均值滤波Track】", "【均值滤波】", &blurSize, 40,
			blur_trackbar);
	blur_trackbar(boxFilterSize, 0);

	namedWindow("【高斯滤波】", 0);
	createTrackbar("【高斯滤波Track】", "【高斯滤波】", &GaussianBlurSize, 30,
			GaussianBlur_trackbar);
	GaussianBlur_trackbar(GaussianBlurSize, 0);

	while (true) {
		if (char(waitKey(1)) == 'q') {
			break;
		}
	}

	return 0;
}

static void boxFilter_trackbar(int, void*) {
	boxFilter(src, boxFilter_img, -1, Size(boxFilterSize, boxFilterSize));
	imshow("【方框滤波】", boxFilter_img);
}

static void blur_trackbar(int, void*){

	blur(src,blur_img,Size(blurSize,blurSize));
	imshow("【均值滤波】",blur_img);
}

static void GaussianBlur_trackbar(int,void*){

	GaussianBlur(src,GaussianBlur_img,Size(GaussianBlurSize,GaussianBlurSize),0,0);
	imshow("【高斯滤波】",GaussianBlur_img);
}
