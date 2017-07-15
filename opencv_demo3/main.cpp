#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
void salt(Mat& image, int n) {
	for (int k = 0; k < n; k++) {
		int i = rand() % image.cols;
		int j = rand() % image.rows;

		if (image.channels() == 1) {
			image.at<uchar>(j, i) = 255;
		} else {
			image.at<Vec3b>(j, i)[0] = 255;
			image.at<Vec3b>(j, i)[1] = 255;
			image.at<Vec3b>(j, i)[2] = 255;
		}
	}
}
int main() {
	Mat img = imread("2015-12-29 173343.jpg");
	salt(img, 10000);
	namedWindow("image");
	imshow("image", img);
	//测试用滤波的手段消除椒盐噪声
	Mat result;
	Mat kernel;
	int ddepth;
	int kernel_size;
	ddepth = -1;
	int ind = 0;
	while (true) {
		//每0.5秒刷新一次图像
		int c = waitKey(500);
		//按esc键退出程序
		if ((char) c == 27) {
			break;
		}

		kernel_size = 3 + 2 * (ind % 5);
		kernel = Mat::ones(kernel_size, kernel_size, CV_32F)
				/ (float) (kernel_size * kernel_size);

		cout<<kernel<<'\n';


		filter2D(img, result, ddepth, kernel);
		imshow("滤波结果", result);
		ind++;
	}
	waitKey(0);
}

