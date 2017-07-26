#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src,mid,dst;
int main() {
	src = imread("0027010801006586_b.jpg");
//	GaussianBlur(src,src,Size(3,3),0,0,BORDER_DEFAULT);

	Canny(src,mid,50,200,3);

	cvtColor(mid,dst,CV_GRAY2BGR);

//	vector<Vec2f> lines;

	vector<Vec4i> lines;

//	HoughLines(mid,lines,1,CV_PI/180,250,0,0);

	HoughLinesP(mid,lines,CV_PI/180,1,95,50,10);

	for(int i = 0;i<lines.size();i++){//此处解释见同目录截图

		Vec4i l = lines[i];

		line(src,Point(l[0],l[1]),Point(l[2],l[3]),Scalar(0,0,0),1,CV_AA);


//		float rho = lines[i][0];
//		float theta = lines[i][1];
//
//
//		Point p1,p2;
//		double a = sin(theta),b = cos(theta);
//
//		double x = b*rho,y = a*rho;
//
//		p1.x = cvRound(x - a*1000);
//		p1.y = cvRound(y + b*1000);
//
//		p2.x = cvRound(x + a*1000);
//		p2.y = cvRound(y - b*1000);
//
//		line(src,p1,p2,Scalar(55,100,195),1,CV_AA);
	}

	namedWindow("【效果图】",WINDOW_AUTOSIZE);

	imshow("【效果图】",src);

	while (1) {
		int c = waitKey(1);

		if ((char) c == 'q' || c == 27) {
			break;
		}

	}

	return 0;
}

