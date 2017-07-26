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
Mat dst;
Mat dst_warp_rotate;
int main() {

	Mat warpMat(2, 3, CV_32FC3);

	Mat rotMat(2, 3, CV_32FC1);

	src = imread("2015-12-29 173343.jpg",1);

	dst = Mat::zeros(src.rows, src.cols, src.type());

	Point2f srcTriangle[3];
	Point2f dstTriangle[3];

	srcTriangle[0] = Point2f(0,0);
	srcTriangle[1] = Point2f(0,(src.rows-1));
	srcTriangle[2] = Point2f((src.cols-1),0);

	dstTriangle[0] = Point2f(static_cast<float>(src.cols*0.0),static_cast<float>(src.rows*0.05));
	dstTriangle[1] = Point2f(static_cast<float>(src.cols*0.2),static_cast<float>(src.rows*0.6));
	dstTriangle[2] = Point2f(static_cast<float>(src.cols*0.65),static_cast<float>(src.rows*0.0));

	warpMat = getAffineTransform(srcTriangle,dstTriangle);

	warpAffine(src,dst,warpMat,dst.size());

	Point center = Point(dst.rows/2,dst.cols/2);

	double angle = -30;

	double scale = 0.8;

	rotMat = getRotationMatrix2D(center,angle,scale);

	warpAffine(dst,dst_warp_rotate,rotMat,dst.size());

	imshow( "[1]", src );
	imshow( "[2]", dst );
	imshow( "[3]", dst_warp_rotate );

	imwrite("demo1.jpg",dst);

	while (1) {
		int c = waitKey(1);
		if ((char) c == 'q' || c == 27) {
			break;
		}
	}

	return 0;
}
