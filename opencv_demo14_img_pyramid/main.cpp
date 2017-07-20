#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

int main() {
	src = imread("2015-12-29 173343.jpg");

	if (!src.data) {
		printf("图片加载错误！");
	}

	namedWindow("【原图】", WINDOW_AUTOSIZE);

	namedWindow("【变换后的图像】", WINDOW_AUTOSIZE);

	imshow("【原图】", src);

	imshow("【变换后的图像】", src);

	while (1) {
		int c = waitKey(1);

		if ((char) c == 'q' || c == 27) {
			break;
		}

		if ((char) c == 'w' || c == 49) {
			printf("resize+");
			resize(src, src, Size(), 2, 2);
			imshow("【变换后的图像】", src);
		}

		if ((char) c == 's' || c == 50) {
			printf("resize-");
			resize(src, src, Size(), 0.5, 0.5);
			imshow("【变换后的图像】", src);
		}

		if ((char) c == 'a' || c == 51) {
			printf("pyrup+");
			pyrUp(src,src);
			imshow("【变换后的图像】", src);
		}

		if ((char) c == 'd' || c == 52) {
			printf("pyrdown-");
			pyrDown(src,src);
			imshow("【变换后的图像】", src);
		}

	}

	return 0;
}

