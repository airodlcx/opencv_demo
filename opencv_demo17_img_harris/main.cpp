#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Mat dst;
Mat dstImage; //目标图
Mat normImage; //归一化后的图
Mat scaledImage; //线性变换后的八位无符号整型的图

int main() {
	src = imread("0027010801006586_b.jpg", 0);

	imshow("【原图】", src);

	Mat cornerStrength;

	cornerHarris(src, cornerStrength, 2, 3, 0.02, BORDER_DEFAULT);

	normalize(cornerStrength, normImage, 0, 255, NORM_MINMAX, CV_32FC1, Mat());
	convertScaleAbs(normImage, scaledImage);

	for (int j = 0; j < normImage.rows; j++) {
		for (int i = 0; i < normImage.cols; i++) {
			if ((int) normImage.at<float>(j, i) > 0 + 80) {
				circle(src, Point(i, j), 5, Scalar(10, 10, 255), 2, 8,
						0);
				circle(scaledImage, Point(i, j), 5, Scalar(0, 10, 255), 2, 8,
						0);
			}
		}
	}

	imshow("[corner]", cornerStrength);

	Mat harrisCorner;
	threshold(cornerStrength, harrisCorner, 0.00001, 255, THRESH_BINARY);
	imshow("角点检测后的二值效果图", src);

	while (1) {
		int c = waitKey(1);

		if ((char) c == 'q' || c == 27) {
			break;
		}

	}

	return 0;

}
