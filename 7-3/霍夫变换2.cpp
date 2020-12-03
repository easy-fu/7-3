#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = cv::imread("C:/Users/DELL/Desktop/18.jpg", 1);
	if (srcMat.empty())
	{
		cout << "failed to read image!" << endl;
		return -1;
	}
	Mat gryMat;
	Mat cannyMat;
	Mat linesp_Mat;
	cvtColor(srcMat, gryMat, COLOR_BGR2GRAY);
	Canny(gryMat, cannyMat, 60, 180, 3);
	HoughLinesP(cannyMat, linesp_Mat, 1, CV_PI / 180, 22, 10, 10);
	int heightsp = linesp_Mat.rows;
	int widthsp = linesp_Mat.cols;

	for (int i = 0; i < heightsp; i++)
	{
		for (int j = 0; j < widthsp; j++)
		{

			Point p1, p2;
			p1.x = linesp_Mat.at<Vec4i>(i, j)[0];
			p1.y = linesp_Mat.at<Vec4i>(i, j)[1];
			p2.x = linesp_Mat.at<Vec4i>(i, j)[2];
			p2.y = linesp_Mat.at<Vec4i>(i, j)[3];

			cv::line(srcMat, p1, p2, cv::Scalar(255, 255, 0), 1, 8, 0);
		}
	}

	imshow("srcMat", srcMat);
	waitKey(0);
}



