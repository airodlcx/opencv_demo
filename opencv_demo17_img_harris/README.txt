OpenCV角点检测之Harris角点检测
C++: void cornerHarris(InputArray src,OutputArray dst, int blockSize, int ksize, double k, intborderType=BORDER_DEFAULT )  
第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可，且需为单通道8位或者浮点型图像。
第二个参数，OutputArray类型的dst，函数调用后的运算结果存在这里，即这个参数用于存放Harris角点检测的输出结果，和源图片有一样的尺寸和类型。
第三个参数，int类型的blockSize，表示邻域的大小，更多的详细信息在cornerEigenValsAndVecs（）中有讲到。
第四个参数，int类型的ksize，表示Sobel()算子的孔径大小。
第五个参数，double类型的k，Harris参数。
第六个参数，int类型的borderType，图像像素的边界模式，注意它有默认值BORDER_DEFAULT。更详细的解释，参考borderInterpolate( )函数。