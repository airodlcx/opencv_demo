OpenCV边缘检测：Canny算子,Sobel算子,Laplace算子,Scharr滤波器
Canny函数利用Canny算法来进行图像的边缘检测。
    C++: void Canny(InputArray image,OutputArray edges, double threshold1, double threshold2, int apertureSize=3,bool L2gradient=false )  
    第一个参数，InputArray类型的image，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位图像。
    第二个参数，OutputArray类型的edges，输出的边缘图，需要和源图片有一样的尺寸和类型。
    第三个参数，double类型的threshold1，第一个滞后性阈值。
    第四个参数，double类型的threshold2，第二个滞后性阈值。
    第五个参数，int类型的apertureSize，表示应用Sobel算子的孔径大小，其有默认值3。
    第六个参数，bool类型的L2gradient，一个计算图像梯度幅值的标识，有默认值false。
需要注意的是，这个函数阈值1和阈值2两者的小者用于边缘连接，而大者用来控制强边缘的初始段，推荐的高低阈值比在2:1到3:1之间。
调用示例：
   //载入原始图   
   Mat src = imread("1.jpg");  //工程目录下应该有一张名为1.jpg的素材图  
   Canny(src, src, 3, 9,3 );  
   imshow("【效果图】Canny边缘检测", src);  
Sobel函数使用扩展的 Sobel 算子，来计算一阶、二阶、三阶或混合图像差分。
    C++: void Sobel (  
    InputArray src,//输入图  
     OutputArray dst,//输出图  
     int ddepth,//输出图像的深度  
     int dx,  
     int dy,  
     int ksize=3,  
     double scale=1,  
     double delta=0,  
     int borderType=BORDER_DEFAULT );  
    第一个参数，InputArray 类型的src，为输入图像，填Mat类型即可。
    第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
    第三个参数，int类型的ddepth，输出图像的深度，支持如下src.depth()和ddepth的组合：

        若src.depth() = CV_8U, 取ddepth =-1/CV_16S/CV_32F/CV_64F
        若src.depth() = CV_16U/CV_16S, 取ddepth =-1/CV_32F/CV_64F
        若src.depth() = CV_32F, 取ddepth =-1/CV_32F/CV_64F
        若src.depth() = CV_64F, 取ddepth = -1/CV_64F

    第四个参数，int类型dx，x 方向上的差分阶数。
    第五个参数，int类型dy，y方向上的差分阶数。
    第六个参数，int类型ksize，有默认值3，表示Sobel核的大小;必须取1，3，5或7。
    第七个参数，double类型的scale，计算导数值时可选的缩放因子，默认值是1，表示默认情况下是没有应用缩放的。我们可以在文档中查阅getDerivKernels的相关介绍，来得到这个参数的更多信息。
    第八个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
    第九个参数， int类型的borderType，我们的老朋友了（万年是最后一个参数），边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate处得到更详细的信息。
    一般情况下，都是用ksize x ksize内核来计算导数的。然而，有一种特殊情况——当ksize为1时，往往会使用3 x 1或者1 x 3的内核。且这种情况下，并没有进行高斯平滑操作。
Laplacian函数可以计算出图像经过拉普拉斯变换后的结果。
    C++: void Laplacian(InputArray src,OutputArray dst, int ddepth, int ksize=1, double scale=1, double delta=0, intborderType=BORDER_DEFAULT );  
    第一个参数，InputArray类型的image，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位图像。
    第二个参数，OutputArray类型的edges，输出的边缘图，需要和源图片有一样的尺寸和通道数。
    第三个参数，int类型的ddept，目标图像的深度。
    第四个参数，int类型的ksize，用于计算二阶导数的滤波器的孔径尺寸，大小必须为正奇数，且有默认值1。
    第五个参数，double类型的scale，计算拉普拉斯值的时候可选的比例因子，有默认值1。
    第六个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
    第七个参数， int类型的borderType，边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate()处得到更详细的信息。
Laplacian( )函数其实主要是利用sobel算子的运算。它通过加上sobel算子运算出的图像x方向和y方向上的导数，来得到我们载入图像的拉普拉斯变换结果。

使用Scharr滤波器运算符计算x或y方向的图像差分。其实它的参数变量和Sobel基本上是一样的，除了没有ksize核的大小。
    C++: void Scharr(  
    InputArray src, //源图  
     OutputArray dst, //目标图  
     int ddepth,//图像深度  
     int dx,// x方向上的差分阶数  
     int dy,//y方向上的差分阶数  
     double scale=1,//缩放因子  
     double delta=0,// delta值  
     intborderType=BORDER_DEFAULT )// 边界模式  
    第一个参数，InputArray 类型的src，为输入图像，填Mat类型即可。
    第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
    第三个参数，int类型的ddepth，输出图像的深度，支持如下src.depth()和ddepth的组合：
        若src.depth() = CV_8U, 取ddepth =-1/CV_16S/CV_32F/CV_64F
        若src.depth() = CV_16U/CV_16S, 取ddepth =-1/CV_32F/CV_64F
        若src.depth() = CV_32F, 取ddepth =-1/CV_32F/CV_64F
        若src.depth() = CV_64F, 取ddepth = -1/CV_64F
    第四个参数，int类型dx，x方向上的差分阶数。
    第五个参数，int类型dy，y方向上的差分阶数。
    第六个参数，double类型的scale，计算导数值时可选的缩放因子，默认值是1，表示默认情况下是没有应用缩放的。我们可以在文档中查阅getDerivKernels的相关介绍，来得到这个参数的更多信息。
    第七个参数，double类型的delta，表示在结果存入目标图（第二个参数dst）之前可选的delta值，有默认值0。
    第八个参数， int类型的borderType，我们的老朋友了（万年是最后一个参数），边界模式，默认值为BORDER_DEFAULT。这个参数可以在官方文档中borderInterpolate处得到更详细的信息。
不难理解，如下两者是等价的：
    Scharr(src, dst, ddepth, dx, dy, scale,delta, borderType);  
与
    Sobel(src, dst, ddepth, dx, dy, CV_SCHARR,scale, delta, borderType);  