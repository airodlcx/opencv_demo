OpenCV图像金字塔：高斯金字塔、拉普拉斯金字塔与图片尺寸缩放
resize( )为OpenCV中专职调整图像大小的函数。
此函数将源图像精确地转换为指定尺寸的目标图像。如果源图像中设置了ROI（Region Of Interest ，感兴趣区域），那么resize( )函数会对源图像的ROI区域进行调整图像尺寸的操作，来输出到目标图像中。若目标图像中已经设置ROI区域，不难理解resize( )将会对源图像进行尺寸调整并填充到目标图像的ROI中。
很多时候，我们并不用考虑第二个参数dst的初始图像尺寸和类型（即直接定义一个Mat类型，不用对其初始化），因为其尺寸和类型可以由src,dsize,fx和fy这其他的几个参数来确定。
看一下它的函数原型：
    C++: void resize(InputArray src,OutputArray dst, Size dsize, double fx=0, double fy=0, int interpolation=INTER_LINEAR )  
    第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
    第二个参数，OutputArray类型的dst，输出图像，当其非零时，有着dsize（第三个参数）的尺寸，或者由src.size()计算出来。
    第三个参数，Size类型的dsize，输出图像的大小;如果它等于零，由下式进行计算：


		其中，dsize，fx，fy都不能为0。

    第四个参数，double类型的fx，沿水平轴的缩放系数，有默认值0，且当其等于0时，由下式进行计算：
    第五个参数，double类型的fy，沿垂直轴的缩放系数，有默认值0，且当其等于0时，由下式进行计算：
    第六个参数，int类型的interpolation，用于指定插值方式，默认为INTER_LINEAR（线性插值）。
	可选的插值方式如下：
        INTER_NEAREST - 最近邻插值
        INTER_LINEAR - 线性插值（默认值）
        INTER_AREA - 区域插值（利用像素区域关系的重采样插值）
        INTER_CUBIC –三次样条插值（超过4×4像素邻域内的双三次插值）
        INTER_LANCZOS4 -Lanczos插值（超过8×8像素邻域的Lanczos插值）
若要缩小图像，一般情况下最好用CV_INTER_AREA来插值，
而若要放大图像，一般情况下最好用CV_INTER_CUBIC（效率不高，慢，不推荐使用）或CV_INTER_LINEAR（效率较高，速度较快，推荐使用）。

pyrUp( )函数的作用是向上采样并模糊一张图像，说白了就是放大一张图片。
    C++: void pyrUp(InputArray src, OutputArraydst, const Size& dstsize=Size(), int borderType=BORDER_DEFAULT )  
    第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
    第二个参数，OutputArray类型的dst，输出图像，和源图片有一样的尺寸和类型。
    第三个参数，const Size&类型的dstsize，输出图像的大小;有默认值Size()，即默认情况下，由Size（src.cols*2，src.rows*2）来进行计算，且一直需要满足下列条件：


    第四个参数，int类型的borderType，又来了，边界模式，一般我们不用去管它。

pyrUp函数执行高斯金字塔的采样操作，其实它也可以用于拉普拉斯金字塔的。
首先，它通过插入可为零的行与列，对源图像进行向上取样操作，然后将结果与pyrDown（）乘以4的内核做卷积，就是这样。

pyrDown( )函数的作用是向下采样并模糊一张图片，说白了就是缩小一张图片。
    C++: void pyrDown(InputArray src,OutputArray dst, const Size& dstsize=Size(), int borderType=BORDER_DEFAULT)  
    第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。
    第二个参数，OutputArray类型的dst，输出图像，和源图片有一样的尺寸和类型。
    第三个参数，const Size&类型的dstsize，输出图像的大小;有默认值Size()，即默认情况下，由Size Size((src.cols+1)/2, (src.rows+1)/2)