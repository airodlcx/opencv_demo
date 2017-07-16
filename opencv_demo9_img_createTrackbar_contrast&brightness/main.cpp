#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int contrast = 100;
int brightness = 100;
Mat src_img,dst_img;

static void on_trackbar(int, void*) {

	for (int i = 0; i < src_img.rows; i++) {
		for (int j = 0; j < src_img.cols; j++) {
			for (int c = 0; c < 3; c++) {
				dst_img.at<Vec3b>(i,j)[c] = saturate_cast<uchar>(
						src_img.at<Vec3b>(i,j)[c] * (contrast * 0.01) + brightness);
			}
		}
	}

	//显示窗口
	imshow("【原始图窗口】", src_img);
	imshow("【效果图窗口】", dst_img);
}

int main() {
	src_img = imread("2015-12-29 173343.jpg");
	if (!src_img.data) {
		printf("OH,NO!读取img图片文件错误~！ \n");
		return -1;
	}
	dst_img = Mat::zeros(src_img.size(), src_img.type());

	//创建窗口
	namedWindow("【原始图窗口】", 0);
	namedWindow("【效果图窗口】", 0);
	//创建轨迹条
	createTrackbar("contrast", "【原始图窗口】", &contrast, 200,
			on_trackbar);
	//创建轨迹条
	createTrackbar("brightness", "【原始图窗口】", &brightness, 300,
			on_trackbar);

	on_trackbar(contrast, 0); //轨迹条回调函数

	//输出一些帮助信息
	cout << endl << "\t嗯。好了，请调整滚动条观察图像效果~\n\n" << "\t按下“q”键时，程序退出~!\n"
			<< "\n\n\t\t\t\tby:lcx";

	//按下“q”键时，程序退出
	while (char(waitKey(1)) != 'q') {
	}
	return 0;
}

