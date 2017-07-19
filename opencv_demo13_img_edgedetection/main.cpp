#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Mat dst;
Mat gray;
Mat edge;
Mat sobel_x, sobel_y, sobel_xy;

int main() {

	namedWindow("【原图】", 0);

	namedWindow("【canny边缘检测】", 0);

	namedWindow("【sobel边缘检测】x", 0);

	namedWindow("【sobel边缘检测】y", 0);

	namedWindow("【sobel边缘检测】xy", 0);

	namedWindow("【Laplacian边缘检测】",0);

	namedWindow("【Scharr边缘检测】x",0);

	namedWindow("【Scharr边缘检测】y",0);

	namedWindow("【Scharr边缘检测】xy",0);

	src = imread("2015-12-29 173343.jpg");

	cvtColor(src, gray, CV_BGR2GRAY);

	blur(gray, edge, Size(3, 3));

	imshow("【原图】", src);

	Canny(edge, edge, 3, 9, 3);

	dst.create(src.size(), src.type());

	dst = Scalar::all(0);

	src.copyTo(dst, 255 - edge);

	imshow("【canny边缘检测】", dst);

	Sobel(src, sobel_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs( sobel_x, sobel_x );

	imshow("【sobel边缘检测】x", sobel_x);

	Sobel(src, sobel_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs( sobel_y, sobel_y );


	imshow("【sobel边缘检测】y", sobel_y);

	addWeighted(sobel_x,0.5,sobel_y,0.5,0.0,sobel_xy);

	imshow("【sobel边缘检测】xy", sobel_xy);

	GaussianBlur( src, src, Size(3,3), 0, 0, BORDER_DEFAULT );

	Mat src_gray;
	Mat abs_dst;
	cvtColor( src, src_gray, CV_RGB2GRAY );
	Laplacian( src_gray, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT );
	convertScaleAbs( dst, dst );

	imshow("【Laplacian边缘检测】", dst);

	Mat scharr_x, scharr_y, scharr_xy;
	Scharr(src,scharr_x,CV_16S,1,0,1,0,BORDER_DEFAULT);
	convertScaleAbs(scharr_x,scharr_x);
	imshow("【Scharr边缘检测】x", sobel_y);


	Scharr(src,scharr_y,CV_16S,0,1,1,0,BORDER_DEFAULT);
	convertScaleAbs(scharr_y,scharr_y);
	imshow("【Scharr边缘检测】y", sobel_y);

	addWeighted(scharr_x,0.5,scharr_y,0.5,0.0,scharr_xy);
	imshow("【Scharr边缘检测】xy", sobel_y);


	while (1) {
		int c = waitKey(1);

		if ((char) c == 'q' || c == 27) {
			break;
		}
	}

	return 0;
}

