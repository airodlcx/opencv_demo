#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;


Mat src;
Mat dst;
int structElementSize = 1;
int typeNum = 0;

static void process(int,void*){
	Mat ksize = getStructuringElement(MORPH_RECT,Size(structElementSize*2+1,structElementSize*2+1),Point(-1,-1));


	if(typeNum == 0){
		erode(src,dst,ksize);
	}else{
		dilate(src,dst,ksize);
	}

	imshow("【效果图】",dst);

}

static void on_trackType(int,void*){
	process(structElementSize,0);
}


int main() {
	src = imread("2015-12-29 173343.jpg");

	namedWindow("【原图】",0);

	imshow("【原图】",src);

	namedWindow("【效果图】",0);

	createTrackbar("【0-腐蚀、1-膨胀】效果图","【原图】",&typeNum,1,on_trackType);

	createTrackbar("【ksize】","【原图】",&structElementSize,10,process);

	process(structElementSize,0);

	while(true){
		if(char(waitKey(2)=='q')){
			break;
		}
	}

	return 0;

}
