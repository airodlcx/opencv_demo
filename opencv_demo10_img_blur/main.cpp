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
Mat MedianBlur_img; //中值滤波
Mat BilateralFilter_img; //双边滤波
int MedianBlurSize = 10;  //中值滤波参数值
int BilateralFilterSize = 10;  //双边滤波参数值
int boxFilterSize = 3;
int blurSize = 3;
int GaussianBlurSize = 3;

static void boxFilter_trackbar(int, void*);
static void blur_trackbar(int, void*);
static void GaussianBlur_trackbar(int, void*);
static void MedianBlur_trackbar(int, void*);
static void BilateralFilter_trackbar(int, void*);

int main() {
	src = imread("2015-12-29 173343.jpg");

	namedWindow("【原图】", 0);
	imshow("【原图】", src);

	namedWindow("【方框滤波】", 0);
	createTrackbar("【方框滤波Track】", "【方框滤波】", &boxFilterSize, 40,
			boxFilter_trackbar);
	boxFilter_trackbar(boxFilterSize, 0);

	namedWindow("【均值滤波】", 0);
	createTrackbar("【均值滤波Track】", "【均值滤波】", &blurSize, 40, blur_trackbar);
	blur_trackbar(boxFilterSize, 0);

	namedWindow("【高斯滤波】", 0);
	createTrackbar("【高斯滤波Track】", "【高斯滤波】", &GaussianBlurSize, 30,
			GaussianBlur_trackbar);
	GaussianBlur_trackbar(GaussianBlurSize, 0);

	namedWindow("【中值滤波】", 0);
	createTrackbar("【中值滤波Track】", "【中值滤波】", &MedianBlurSize, 40,
			MedianBlur_trackbar);
	MedianBlur_trackbar(GaussianBlurSize, 0);

	namedWindow("【双边滤波】", 0);
	createTrackbar("【双边滤波Track】", "【双边滤波】", &BilateralFilterSize, 40,
			BilateralFilter_trackbar);
	BilateralFilter_trackbar(GaussianBlurSize, 0);

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

static void blur_trackbar(int, void*) {

	blur(src, blur_img, Size(blurSize, blurSize));
	imshow("【均值滤波】", blur_img);
}

static void GaussianBlur_trackbar(int, void*) {

	GaussianBlur(src, GaussianBlur_img,
			Size(GaussianBlurSize*2+1, GaussianBlurSize*2+1), 0, 0);
	imshow("【高斯滤波】", GaussianBlur_img);
}

static void MedianBlur_trackbar(int, void*) {
	medianBlur(src,MedianBlur_img,MedianBlurSize*2+1);
	imshow("【中值滤波】", MedianBlur_img);
}

static void BilateralFilter_trackbar(int, void*) {
	bilateralFilter(src,BilateralFilter_img,BilateralFilterSize,BilateralFilterSize*2,BilateralFilterSize/2);
	imshow("【双边滤波】", BilateralFilter_img);
}
