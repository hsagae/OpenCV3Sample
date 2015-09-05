#include "opencv3Sample.h"
#include <iostream>
#include "ImageProcessor.h"

int main(int argc, char** argv) {
	// �R�}���h���C�������`�F�b�N
	if (argc < 2) {
		printUsage();
		return -1;
	}

	// �摜����I�u�W�F�N�g�����A�摜�ǂݍ���
	ImageProcessor image(argv[1]);
	if (!image.readImage()) {
		std::cout << "readImage error" << std::endl;
		return -1;
	}

	// �����ɉ摜�����Ăяo�����L�q����
	image.rotateImage(30.0);


	//�摜�\��
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
