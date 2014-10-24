#pragma once
#include <opencv2/opencv.hpp>
#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/background_segm.hpp"
#include <mutex>
#include <chrono>
#include "Frame.h"
#include <vector>

using namespace cv;
using namespace std;
using namespace chrono;

class Capture
{
	const int MINRECTPERIMETR = 50;
	const int MAXCONTS = 500;
	const int MAX_POINTS = 500;

	VideoCapture capture;
	milliseconds currentTime, lastTime;
	const int timeRange = 5000; // in milliseconds


	vector <Point2f> getFeaturePoints(vector<Point>);
	//	void display(Mat frame, vector<vector<Point>>);
	void displayTime(Mat);
	vector<Rect> uniteRect(vector<vector<Point>>);
	vector<vector<Point>> uniteContours(vector<vector<Point>>);
	vector<Point2f> convertTo2F(vector<Point>);
	vector<Point> convertBack(vector<Point2f>);
	vector <Point2f> getPoints(Rect);

public:
	Capture(int);
	Capture(string);
	~Capture();
	bool isOpened();
	Mat getFrame();
	void find(map<milliseconds, Frame>&, mutex&, vector<map<milliseconds, Rect>>&, mutex&);
	void cut(map<milliseconds, Frame>&, mutex&, vector<map<milliseconds, Rect>>&, mutex&);
	void display(map<milliseconds, Frame>&, mutex&, vector<map<milliseconds, Rect>>&, mutex&);

};
