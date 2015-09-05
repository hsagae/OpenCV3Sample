#include "ImageProcessor.h"


ImageProcessor::ImageProcessor() {
}


ImageProcessor::~ImageProcessor() {
}

ImageProcessor::ImageProcessor(char* filename) {
	// 引数チェック
	if (filename) {
		_filename = std::string(filename);
	} else {
		_filename = "";
	}
}

bool ImageProcessor::readImage() {
	if (_filename.empty()) {
		return false;
	}

	_src = imread(_filename, IMREAD_COLOR);
	if (!_src.data) {
		return false;
	}

	_src.copyTo(_dst);

	return true;
}

void ImageProcessor::showImage() {
	if (!_src.data) {
		return;
	}

	namedWindow("showImage", WINDOW_AUTOSIZE);
	imshow("showImage", _dst);

	waitKey(100);
}

void ImageProcessor::closeImage() {
	destroyWindow("showImage");
}

void ImageProcessor::rotateImage(float angle) {
	if (!_src.data) {
		return;
	}

	// 回転角度、回転中心、スケーリングを指定してアフィン変換によって回転を実現する
	Point2f center(_src.cols * 0.5, _src.rows * 0.5);
	float scale = 1.0f;

	const Mat affineMat = getRotationMatrix2D(center, angle, scale);
	warpAffine(_src, _dst, affineMat, _src.size());

	return;
}