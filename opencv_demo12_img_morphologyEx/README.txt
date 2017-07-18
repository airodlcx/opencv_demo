形态学图像处理：开闭运算、形态学梯度、顶帽、黑帽
morphologyEx函数详解
上面我们已经讲到，morphologyEx函数利用基本的膨胀和腐蚀技术，来执行更加高级形态学变换，如开闭运算，形态学梯度，“顶帽”、“黑帽”等等。这一节我们来了解它的参数意义和使用方法。
C++: void morphologyEx(  
InputArray src,  
OutputArray dst,  
int op,  
InputArraykernel,  
Pointanchor=Point(-1,-1),  
intiterations=1,  
intborderType=BORDER_CONSTANT,  
constScalar& borderValue=morphologyDefaultBorderValue() );  
第一个参数，InputArray类型的src，输入图像，即源图像，填Mat类的对象即可。图像位深应该为以下五种之一：CV_8U, CV_16U,CV_16S, CV_32F 或CV_64F。
第二个参数，OutputArray类型的dst，即目标图像，函数的输出参数，需要和源图片有一样的尺寸和类型。
第三个参数，int类型的op，表示形态学运算的类型，可以是如下之一的标识符：
    MORPH_OPEN – 开运算（Opening operation）
    MORPH_CLOSE – 闭运算（Closing operation）
    MORPH_GRADIENT -形态学梯度（Morphological gradient）
    MORPH_TOPHAT - “顶帽”（“Top hat”）
    MORPH_BLACKHAT - “黑帽”（“Black hat“）
        另有CV版本的标识符也可选择，如CV_MOP_CLOSE，CV_MOP_GRADIENT，CV_MOP_TOPHAT，CV_MOP_BLACKHAT，这应该是OpenCV1.0系列版本遗留下来的标识符，和上面的“MORPH_OPEN”一样的效果。
第四个参数，InputArray类型的kernel，形态学运算的内核。若为NULL时，表示的是使用参考点位于中心3x3的核。我们一般使用函数 getStructuringElement配合这个参数的使用。getStructuringElement函数会返回指定形状和尺寸的结构元素（内核矩阵）。关于getStructuringElement我们上篇文章中讲过了，这里为了大家参阅方便，再写一遍：
    其中，getStructuringElement函数的第一个参数表示内核的形状，我们可以选择如下三种形状之一:
        矩形: MORPH_RECT
        交叉形: MORPH_CROSS
        椭圆形: MORPH_ELLIPSE
    而getStructuringElement函数的第二和第三个参数分别是内核的尺寸以及锚点的位置。
    我们一般在调用erode以及dilate函数之前，先定义一个Mat类型的变量来获得getStructuringElement函数的返回值。对于锚点的位置，有默认值Point(-1,-1)，表示锚点位于中心。且需要注意，十字形的element形状唯一依赖于锚点的位置。而在其他情况下，锚点只是影响了形态学运算结果的偏移。

getStructuringElement函数相关的调用示例代码如下：
    int g_nStructElementSize = 3; //结构元素(内核矩阵)的尺寸  
    //获取自定义核  
    Mat element =getStructuringElement(MORPH_RECT,  
           Size(2*g_nStructElementSize+1,2*g_nStructElementSize+1),  
           Point(g_nStructElementSize, g_nStructElementSize ));  
调用这样之后，我们便可以在接下来调用erode、dilate或morphologyEx函数时，kernel参数填保存getStructuringElement返回值的Mat类型变量。对应于我们上面的示例，就是填element变量。
第五个参数，Point类型的anchor，锚的位置，其有默认值（-1，-1），表示锚位于中心。
第六个参数，int类型的iterations，迭代使用函数的次数，默认值为1。
第七个参数，int类型的borderType，用于推断图像外部像素的某种边界模式。注意它有默认值BORDER_ CONSTANT。
第八个参数，const Scalar&类型的borderValue，当边界为常数时的边界值，有默认值morphologyDefaultBorderValue()，一般我们不用去管他。需要用到它时，可以看官方文档中的createMorphologyFilter()函数得到更详细的解释。