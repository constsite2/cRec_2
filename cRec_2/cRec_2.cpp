#include<opencv2/opencv.hpp>
#include "opencv2/core/utility.hpp"
#include "opencv2/imgcodecs.hpp"
#include<iostream>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv/cv.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
using namespace std;
using namespace cv;


int main() {
	cv::VideoCapture capVideo;

	cv::Mat imgFrame;

	capVideo.open("test.avi");

	if (!capVideo.isOpened()) {                                                 // if unable to open video file
		std::cout << "error reading video file" << std::endl << std::endl;      // show error message
		return(0);                                                              // and exit program
	}

	char chCheckForEscKey = 0;

	double dblFPS = capVideo.get(CV_CAP_PROP_FPS);

	std::cout << "1st time - dblFPS = " << dblFPS << "\n";         // this prints "10" to std out as expected

	bool blnSetReturnValue = capVideo.set(CV_CAP_PROP_FPS, 5);

	std::cout << "2nd time - dblFPS = " << dblFPS << "\n";         // this also prints "10", why not "5" as expected ??!!

	std::cout << "blnSetReturnValue = " << blnSetReturnValue << std::endl;     // this prints "0" (i.e. false)

	long ShowStartTime;

	// try 1

	while (chCheckForEscKey != 27) {
		capVideo.read(imgFrame);

		ShowStartTime = GetTickCount();

		if (imgFrame.empty()) break;

		cv::imshow("imgFrame", imgFrame);

		do { cvWaitKey(1); } while (ShowStartTime - GetTickCount() < 19);

		chCheckForEscKey = cv::waitKey(1);
	}

	return(0);
}