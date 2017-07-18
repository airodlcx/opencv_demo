#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat src;
Mat opencloseMat, topblackMat, erodedilateMat;

int shape = MORPH_RECT;

int sepNum = 10; //分割数量
int opencloseKsize = 0;
int topblackMatKsize = 0;
int erodedilateKsize = 0;

static void on_trackOpenClose(int, void*);
static void on_trackTopBlack(int, void*);
static void on_trackErodeDilate(int, void*);

static void ShowHelpText();

int main() {

	ShowHelpText();
	src = imread("2015-12-29 173343.jpg");

	namedWindow("【原图】", 0);
	namedWindow("【open&close】", 0);
	namedWindow("【top&black】", 0);
	namedWindow("【erode&bilate】", 0);

	createTrackbar("【open&close】", "【原图】", &opencloseKsize, sepNum * 2 + 1,
			on_trackOpenClose);
	createTrackbar("【top&black】", "【原图】", &topblackMatKsize, sepNum * 2 + 1,
			on_trackTopBlack);
	createTrackbar("【erode&bilate】", "【原图】", &erodedilateKsize, sepNum * 2 + 1,
			on_trackErodeDilate);

	imshow("【原图】", src);

	while (1) {
		on_trackOpenClose(opencloseKsize, 0);
		on_trackTopBlack(topblackMatKsize, 0);
		on_trackErodeDilate(erodedilateKsize, 0);
		int c = waitKey(0);

		//按下键盘按键Q或者ESC，程序退出
		if ((char) c == 'q' || (char) c == 27)
			break;
		//按下键盘按键1，使用椭圆(Elliptic)结构元素结构元素MORPH_ELLIPSE
		if ((char) c == 49) //键盘按键1的ASII码为49
			shape = MORPH_ELLIPSE;
		//按下键盘按键2，使用矩形(Rectangle)结构元素MORPH_RECT
		else if ((char) c == 50) //键盘按键2的ASII码为50
			shape = MORPH_RECT;
		//按下键盘按键3，使用十字形(Cross-shaped)结构元素MORPH_CROSS
		else if ((char) c == 51) //键盘按键3的ASII码为51
			shape = MORPH_CROSS;
		//按下键盘按键space，在矩形、椭圆、十字形结构元素中循环
		else if ((char) c == ' ')
			shape = (shape + 1) % 3;

	}

	return 0;

}

static void on_trackOpenClose(int, void*) {
	int offset = opencloseKsize - sepNum;
	int absOffset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(shape,
			Size(absOffset * 2 + 1, absOffset * 2 + 1));
	if (offset < 0) {
		morphologyEx(src, opencloseMat, MORPH_OPEN, element);
	} else {
		morphologyEx(src, opencloseMat, MORPH_CLOSE, element);
	}

	imshow("【open&close】", opencloseMat);

}
static void on_trackTopBlack(int, void*) {
	int offset = topblackMatKsize - sepNum;
	int absOffset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(shape,
			Size(absOffset * 2 + 1, absOffset * 2 + 1));
	if (offset < 0) {
		morphologyEx(src, topblackMat, MORPH_TOPHAT, element);
	} else {
		morphologyEx(src, topblackMat, MORPH_BLACKHAT, element);
	}

	imshow("【top&black】", topblackMat);
}
static void on_trackErodeDilate(int, void*) {
	int offset = erodedilateKsize - sepNum;
	int absOffset = offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(shape,
			Size(absOffset * 2 + 1, absOffset * 2 + 1));
	if (offset < 0) {
		morphologyEx(src, erodedilateMat, MORPH_ERODE, element);
	} else {
		morphologyEx(src, erodedilateMat, MORPH_DILATE, element);
	}

	imshow("【erode&bilate】", erodedilateMat);
}

static void ShowHelpText()
{
//输出一些帮助信息
    printf("\n\n\n\t请调整滚动条观察图像效果~\n\n");
    printf( "\n\n\t按键操作说明: \n\n"
        "\t\t键盘按键【ESC】或者【Q】- 退出程序\n"
        "\t\t键盘按键【1】- 使用椭圆(Elliptic)结构元素\n"
        "\t\t键盘按键【2】- 使用矩形(Rectangle )结构元素\n"
        "\t\t键盘按键【3】- 使用十字型(Cross-shaped)结构元素\n"
        "\t\t键盘按键【空格SPACE】- 在矩形、椭圆、十字形结构元素中循环\n"
        "\n\n\t\t\t\t\t\t\t\t by浅墨"
        );
}
