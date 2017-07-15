#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;
void colorReduce(Mat& inputImage, Mat& outputImage, int div);
int main() {
	Mat image = imread("2015-12-29 173343.jpg");
	imshow("源图像", image);
	Mat result; //用来保存结果
	result.create(image.rows, image.cols, image.type()); //它的大小、类型与原图片相匹配
	double duration;
	duration = static_cast<double>(cv::getTickCount());

	colorReduce(image, result, 64);

	duration = static_cast<double>(cv::getTickCount()) - duration;
	duration /= cv::getTickFrequency(); // the elapsed time in m
	cout << "time is" << duration << endl;

	imshow("显示结果", result);
	waitKey(0);
}

/*void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
	outputImage = inputImage.clone();
	int rows = outputImage.rows;
	int cols = outputImage.cols;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0]
					/ div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[1]
					/ div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[2]
					/ div * div + div / 2;
		}
	}
}*/
void colorReduce(Mat& inputImage, Mat& outputImage, int div)
{
    outputImage = inputImage.clone();
    //模板必须指明数据类型

    Mat_<Vec3b>::iterator it = inputImage.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = inputImage.end<Vec3b>();
    //也可以通过指明cimage类型的方法不写begin和end的类型
    Mat_<Vec3b> cimage= outputImage;
    Mat_<Vec3b>::iterator itout = cimage.begin();
    Mat_<Vec3b>::iterator itoutend = cimage.end();
    for(;it != itend;it++,itout++)
    {
        (*itout)[0] = (*it)[0]/div*div + div/2;
        (*itout)[1] = (*it)[1]/div*div + div/2;
        (*itout)[2] = (*it)[2]/div*div + div/2;
    }
}
