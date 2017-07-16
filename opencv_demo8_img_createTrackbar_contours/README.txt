创建Trackbar & OpenCV官方的sample示例程序  图像轮廓
1. findContours函数，这个函数的原型为：

void findContours(InputOutputArray image, OutputArrayOfArrays contours, OutputArray hierar-
chy, int mode, int method, Point offset=Point())

参数说明:
输入图像image必须为一个2值单通道图像
contours参数为检测的轮廓数组，每一个轮廓用一个point类型的vector表示
hiararchy参数和轮廓个数相同，每个轮廓contours[ i ]对应4个hierarchy元素hierarchy[ i ][ 0 ] ~hierarchy[ i ][ 3 ]，分别表示后一个轮廓、前一个轮廓、父轮廓、内嵌轮廓的索引编号，如果没有对应项，该值设置为负数。
mode表示轮廓的检索模式:
	CV_RETR_EXTERNAL表示只检测外轮廓

    CV_RETR_LIST检测的轮廓不建立等级关系

    CV_RETR_CCOMP建立两个等级的轮廓，上面的一层为外边界，里面的一层为内孔的边界信息。如果内孔内还有一个连通物体，这个物体的边界也在顶层。

    CV_RETR_TREE建立一个等级树结构的轮廓。具体参考contours.c这个demo

method为轮廓的近似办法

    CV_CHAIN_APPROX_NONE存储所有的轮廓点，相邻的两个点的像素位置差不超过1，即max（abs（x1-x2），abs（y2-y1））==1

    CV_CHAIN_APPROX_SIMPLE压缩水平方向，垂直方向，对角线方向的元素，只保留该方向的终点坐标，例如一个矩形轮廓只需4个点来保存轮廓信息

    CV_CHAIN_APPROX_TC89_L1，CV_CHAIN_APPROX_TC89_KCOS使用teh-Chinl chain 近似算法

offset表示代表轮廓点的偏移量，可以设置为任意值。对ROI图像中找出的轮廓，并要在整个图像中进行分析时，这个参数还是很有用的。

findContours后会对输入的2值图像改变，所以如果不想改变该2值图像，需创建新mat来存放，findContours后的轮廓信息contours可能过于复杂不平滑，可以用approxPolyDP函数对该多边形曲线做适当近似

contourArea函数可以得到当前轮廓包含区域的大小，方便轮廓的筛选
2.void drawContours(InputOutputArray image, InputArrayOfArrays contours, int contourIdx, const Scalar& color, int thickness=1, int lineType=8, InputArray hierarchy=noArray(), int maxLevel=INT_MAX, Point offset=Point() )

函数参数详解：

其中第一个参数image表示目标图像，

第二个参数contours表示输入的轮廓组，每一组轮廓由点vector构成，

第三个参数contourIdx指明画第几个轮廓，如果该参数为负值，则画全部轮廓，

第四个参数color为轮廓的颜色，

第五个参数thickness为轮廓的线宽，如果为负值或CV_FILLED表示填充轮廓内部，

第六个参数lineType为线型，

第七个参数为轮廓结构信息，

第八个参数为maxLevel

