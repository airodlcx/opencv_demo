#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Mat dst;
Mat map_x, map_y;

int main() {
	src = imread("2015-12-29 173343.jpg");
	if (!src.data) {
		printf("数据读取出错");
	}

	/*remap*/
	dst.create(src.size(), src.type());
	map_x.create(src.size(), CV_32FC1);
	map_y.create(src.size(), CV_32FC1);

	for (int i = 0; i < src.cols; i++) {
		for (int j = 0; j < src.rows; j++) {
			map_x.at<float>(j,i) = static_cast<float>(src.cols - i);
			map_y.at<float>(j,i) = static_cast<float>(j);
		}
	}

	remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_DEFAULT,
			Scalar(0, 0, 0));

	imshow("[result]", dst);


	/*surf*/
	int minHessian = 400;


	while (1) {
		int c = waitKey(1);

		if ((char) c == 'q' || c == 27) {
			break;
		}

	}

	return 0;

}
