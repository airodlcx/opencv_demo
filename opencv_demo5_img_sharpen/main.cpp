#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	Mat image;
	image = imread("2015-12-29 173343.jpg", 1); //读取的是图像的灰度值，所以在sharpen函数中没有考虑通道数 filter2D 彩色
	Mat result;
	result.create(image.rows, image.cols, image.type());
//	//使用3*3滤波器，所以遍历的像素中不能包括图像最外围的一圈
//	for (int i = 1; i < image.rows - 1; i++) {
//		//前一行、当前行、后一行的指针
//		uchar* previous = image.ptr<uchar>(i - 1);
//		uchar* current = image.ptr<uchar>(i);
//		uchar* next = image.ptr<uchar>(i + 1);
//		//输出结果图像的行指针
//		uchar* output = result.ptr<uchar>(i);
//		for (int j = 1; j < image.cols - 1; j++) {
//			//图像锐化操作
//			*output++ = cv::saturate_cast<uchar>(
//					5 * current[j] - current[j - 1] - current[j + 1]
//							- previous[j] - next[j]); //saturate_cast<uchar>会将小于0的置零，大于255的改为255
//		}
//	}
//	result.row(0).setTo(cv::Scalar(0));
//	result.row(result.rows - 1).setTo(cv::Scalar(0));
//	result.col(0).setTo(cv::Scalar(0));
//	result.col(result.cols - 1).setTo(cv::Scalar(0));

	 //调用滤波函数来完成图像的锐化
	 //滤波器的核
	 Mat kernel(3,3,CV_32F,Scalar(0));
	 // 分配像素置
	 kernel.at<float>(1,1) = 5.0;
	 kernel.at<float>(0,1) = -1.0;
	 kernel.at<float>(2,1) = -1.0;
	 kernel.at<float>(1,0) = -1.0;
	 kernel.at<float>(1,2) = -1.0;

	 //调用滤波函数
	 filter2D(image,result,image.depth(),kernel);

	imshow("源图像", image);
	imshow("锐化结果", result);
	waitKey(0);
	return 0;
}

