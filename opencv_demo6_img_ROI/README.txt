图片水印
cvAddWeighted( const CvArr* src1, double alpha,  const CvArr* src2, double beta,  double gamma, CvArr* dst );
       src1  //第一个原数组.      
alpha  //第一个数组元素的权值  
src2  //第二个原数组  
beta  //第二个数组元素的权值  
dst  //输出数组  
gamma  //添加的常数项。  
函数 cvAddWeighted 计算两数组的加权值的和：  
dst(I)=src1(I)*alpha+src2(I)*beta+gamma

说以说0.7和0.9分别代表两个图像在dst图像中占得比例，是由你自己给定的，后面的0只是起一个微调作用。


