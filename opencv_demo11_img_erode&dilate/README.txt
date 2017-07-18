形态学图像处理：膨胀与腐蚀 
形态学腐蚀——erode函数
erode函数，使用像素邻域内的局部极小运算符来腐蚀一张图片，从src输入，由dst输出。支持就地（in-place）操作。
看一下函数原型：
C++: void erode(  
    InputArray src,  
    OutputArray dst,  
    InputArray kernel,  
    Point anchor=Point(-1,-1),  
    int iterations=1,  
    int borderType=BORDER_CONSTANT,  
    const Scalar& borderValue=morphologyDefaultBorderValue()  
 );  
第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像通道的数量可以是任意的，但图像深度应为CV_8U，CV_16U，CV_16S，CV_32F或 CV_64F其中之一。
第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
第三个参数，InputArray类型的kernel，腐蚀操作的内核。若为NULL时，表示的是使用参考点位于中心3x3的核。我们一般使用函数 getStructuringElement配合这个参数的使用。getStructuringElement函数会返回指定形状和尺寸的结构元素（内核矩阵）。（具体看上文中浅出部分dilate函数的第三个参数讲解部分）
第四个参数，Point类型的anchor，锚的位置，其有默认值（-1，-1），表示锚位于单位（element）的中心，我们一般不用管它。
第五个参数，int类型的iterations，迭代使用erode（）函数的次数，默认值为1。
第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。
第七个参数，const Scalar&类型的borderValue，当边界为常数时的边界值，有默认值morphologyDefaultBorderValue()，一般我们不用去管他。需要用到它时，可以看官方文档中的createMorphologyFilter()函数得到更详细的解释。

形态学膨胀——dilate函数
erode函数，使用像素邻域内的局部极大运算符来膨胀一张图片，从src输入，由dst输出。支持就地（in-place）操作。
函数原型：
C++: void dilate(  
    InputArray src,  
    OutputArray dst,  
    InputArray kernel,  
    Point anchor=Point(-1,-1),  
    int iterations=1,  
    int borderType=BORDER_CONSTANT,  
    const Scalar& borderValue=morphologyDefaultBorderValue()   
    );  
第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像通道的数量可以是任意的，但图像深度应为CV_8U，CV_16U，CV_16S，CV_32F或 CV_64F其中之一。
第二个参数，OutputArray类型的dst，即目标图像，需要和源图片有一样的尺寸和类型。
第三个参数，InputArray类型的kernel，膨胀操作的核。若为NULL时，表示的是使用参考点位于中心3x3的核。

我们一般使用函数 getStructuringElement配合这个参数的使用。getStructuringElement函数会返回指定形状和尺寸的结构元素（内核矩阵）。

其中，getStructuringElement函数的第一个参数表示内核的形状，我们可以选择如下三种形状之一:
矩形: MORPH_RECT
交叉形: MORPH_CROSS
椭圆形: MORPH_ELLIPSE
而getStructuringElement函数的第二和第三个参数分别是内核的尺寸以及锚点的位置。
我们一般在调用erode以及dilate函数之前，先定义一个Mat类型的变量来获得getStructuringElement函数的返回值。对于锚点的位置，有默认值Point(-1,-1)，表示锚点位于中心。且需要注意，十字形的element形状唯一依赖于锚点的位置。而在其他情况下，锚点只是影响了形态学运算结果的偏移。
getStructuringElement函数相关的调用示例代码如下：
     int g_nStructElementSize = 3; //结构元素(内核矩阵)的尺寸  
    //获取自定义核  
    Mat element = getStructuringElement(MORPH_RECT,  
        Size(2*g_nStructElementSize+1,2*g_nStructElementSize+1),  
        Point( g_nStructElementSize, g_nStructElementSize ));  
调用这样之后，我们便可以在接下来调用erode或dilate函数时，第三个参数填保存了getStructuringElement返回值的Mat类型变量。对应于我们上面的示例，就是填element变量。
第四个参数，Point类型的anchor，锚的位置，其有默认值（-1，-1），表示锚位于中心。
第五个参数，int类型的iterations，迭代使用erode（）函数的次数，默认值为1。
第六个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_DEFAULT。
第七个参数，const Scalar&类型的borderValue，当边界为常数时的边界值，有默认值morphologyDefaultBorderValue()，一般我们不用去管他。需要用到它时，可以看官方文档中的createMorphologyFilter()函数得到更详细的解释。
使用erode函数，一般我们只需要填前面的三个参数，后面的四个参数都有默认值。而且往往结合getStructuringElement一起使用。