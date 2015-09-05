#include "opencv3Sample.h"
#include <iostream>
#include "ImageProcessor.h"

int main(int argc, char** argv) {
	// コマンドライン引数チェック
	if (argc < 2) {
		printUsage();
		return -1;
	}

	// 画像操作オブジェクト生成、画像読み込み
	ImageProcessor image(argv[1]);
	if (!image.readImage()) {
		std::cout << "readImage error" << std::endl;
		return -1;
	}

	// ここに画像処理呼び出しを記述する
	image.rotateImage(30.0);


	//画像表示
	image.showImage();

	int key;
	std::cout << "press any key" << std::endl;
	std::cin >> key;

	image.closeImage();

	return 0;
}

void printUsage() {
	std::cout << "opencv3Sample.exe <filename>" << std::endl;
}
