#include <opencv2/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace xfeatures2d;

Mat src;
int main() {
	src = imread("demo1.jpg",1);

	if (!src.data){
		printf("读取图片错误，请确定目录下是否有imread函数指定名称的图片存在~！ \n"); return false;
	}

	imshow("原始图",src);


	namedWindow("[surf特征点]",WINDOW_AUTOSIZE);
	int minHessian = 100;

	vector<KeyPoint> keypoints_1;

	Ptr<SURF> detector = SURF::create(minHessian);

	detector->detect(src, keypoints_1);

	Mat img_keypoints_1;
	drawKeypoints(src, keypoints_1, img_keypoints_1, Scalar::all(-1),
			DrawMatchesFlags::DEFAULT);

	imshow("[surf特征点]",img_keypoints_1);

	while (1) {
		int c = waitKey(1);
		if ((char) c == 'q' || c == 27) {
			break;
		}
	}

	return 0;
}
