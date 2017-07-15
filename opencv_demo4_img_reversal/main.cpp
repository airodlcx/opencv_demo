#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main() {
	//声明一个变量来承载图片,大小为0*0
	    Mat image ;
	    cout<<"size:"<<image.size().height<<","<<image.size().width<<std::endl;
	    //读取一幅图像
	    image= imread("2015-12-29 173343.jpg");
	    if (!image.data)
	    {
	        std::cout<<"read image fail!"<<std::endl;
	    }
	    //创建名为“My Image”的图像窗口
	    namedWindow("My Image");
	    //显示一幅图像
	    imshow("My Image",image);
	    //等待按键：返回值为按键的asc码值或者-1（当等待时间到了时，如果没有按键按下）
	    waitKey(0);
	    Mat result;
	    result.create(image.rows,image.cols,image.type());
	    int rows = image.rows;
	    int cols = image.cols;
	    //对图像做水平翻转
	    for(int i = 0;i < rows;i++)
	    {
	        for(int j = 0;j < cols;j++)
	        {
	            result.at<Vec3b>(i,j)[0] = image.at<Vec3b>(i,cols-j-1)[0];
	            result.at<Vec3b>(i,j)[1] = image.at<Vec3b>(i,cols-j-1)[1];
	            result.at<Vec3b>(i,j)[2] = image.at<Vec3b>(i,cols-j-1)[2];
	        }
	    }
	    //flip(image,result,1);//正值水平变换
	                            //0垂直变换
	                            //负值二者都有

	    namedWindow("output image");
	    imshow("output image",result);
	    waitKey(0);

	    return 0;
}

