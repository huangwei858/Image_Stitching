
/*
 * FileName : image_mosaicking.cpp
 * Author   : huangwei858@163.com
 * Version  : v1.0
 * Date     : Sun 01 Jun 2016 00:20:00 PM CST
 * Brief    : 
 * 
 * Copyright (C) MICL,USTB
 */
 
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/stitcher.hpp"

using namespace std;
using namespace cv;

bool try_use_gpu = false;
vector<Mat> imgs;
string result_name = "result.jpg";

int main(int argc, char* argv[])
{
	Mat img=imread("01.jpg");
	imgs.push_back(img);
	img=imread("02.jpg");
	imgs.push_back(img);
	img=imread("03.jpg");
	imgs.push_back(img);

	Mat pano;
	Stitcher stitcher = Stitcher::createDefault(try_use_gpu);
	Stitcher::Status status = stitcher.stitch(imgs, pano);   //传入stitcher类，直接利用此类进行处理

	if (status != Stitcher::OK)
	{
		cout << "Can't stitch images, error code = " << int(status) << endl;
		return -1;
	}

	imwrite(result_name, pano);
	return 0;
}
