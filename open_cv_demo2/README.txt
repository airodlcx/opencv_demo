cv::getTickCount()可以用来测量一段代码的运行时间，这个函数返回从上次开机算起的时钟周期数。

由于我们需要的是某个代码段运行的毫秒数，因此还需要另一个函数cv::getTickFrequency()。此函数返回每秒内时钟的周期数。

用于统计函数（或一段代码）耗费时间的方法如下：

double duration;

duration  = static_cast<double>(cv::getTickCount());

colorReduce(image);      // 被测试的函数

duration static_cast<double>(cv::getTickCount()) - duration;

duration /= cv::getTickFrequency(); // 运行时间，ms为单位