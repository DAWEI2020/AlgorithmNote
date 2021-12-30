#include <iostream>
#include "linklist.h"
#include <vector>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	Mat src = imread("E:/model/1.jpg");
	imshow("show", src);
	int width = src.cols;
	int height = src.rows;
	int channels = src.channels();

	cout << "width: " << width << endl;
	cout << "height: " << height << endl;
	cout << "channels: " << channels << endl;
	cout << "dims: " << src.dims << endl;
	cout << "size: " << src.size << endl;  // h * w

	int count = 0;
	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			for (int ch = 0; ch < channels; ch++) {
				int gray = src.at<Vec3b>(r,c)[ch];
				int value = src.data[width * channels * r + channels * c + ch];  // ch->c->r
				if (gray == value) { count++; }
			}
		}
	}
	cout << "w*h*c: " << width * height * channels << endl;
	cout << "count: " << count << endl;
	
	cout << "Hello world!" << endl;
	waitKey(0);
	return 0;
}

/*
0 git pull origin master
1 git add file
2 git commit -m "first commit!"
3 git push origin master
*/