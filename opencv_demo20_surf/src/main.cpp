#include <opencv2/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace xfeatures2d;

Mat src_1;

Mat src_2;
Mat dst;
Mat dst_warp_rotate;
int main() {

	src_1 = imread("2015-12-29 173343.jpg");
	src_2 = imread("demo1.jpg");

	vector<KeyPoint> keypoint_1,keypoint_2;

	int minHessian = 700;//SURF算法中的hessian阈值

	Ptr<SurfFeatureDetector> ptr_sfd = SurfFeatureDetector::create(minHessian);

	ptr_sfd->detect(src_1,keypoint_1);
	ptr_sfd->detect(src_2,keypoint_2);

	Ptr<SurfDescriptorExtractor> ptr_sde;
	Mat descriptor1,descriptor2;
	ptr_sde->compute(src_1,keypoint_1,descriptor1);
	ptr_sde->compute(src_2,keypoint_2,descriptor2);

	Ptr<BFMatcher> ptr_bfm;
	vector<DMatch> matches;

	ptr_bfm->match(descriptor1,descriptor2,matches);

	Mat imgMatches;

	drawMatches( src_1, keypoint_1, src_2, keypoint_2, matches, imgMatches );//进行绘制

	imshow("匹配图", imgMatches );

	while (1) {
		int c = waitKey(1);
		if ((char) c == 'q' || c == 27) {
			break;
		}
	}

	return 0;
}
