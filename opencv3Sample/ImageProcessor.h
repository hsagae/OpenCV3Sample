#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class ImageProcessor
{
public:
	ImageProcessor(char* filename);
	~ImageProcessor();

	bool readImage();
	void showImage();
	void closeImage();

	void rotateImage(float angle);

private:
	ImageProcessor();

	std::string _filename;
	Mat _src;				//< 変換前画像
	Mat _dst;				//< 変換後画像
};

