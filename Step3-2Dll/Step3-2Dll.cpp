// Step3-2Dll.cpp : DLL �A�v���P�[�V�����p�ɃG�N�X�|�[�g�����֐����`���܂��B
//

#include "stdafx.h"
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv/highgui.h>

void UseOpenCV(const char *imagePath) {
	
	// �摜�ǂݍ���
	const cv::Mat input = cv::imread(imagePath, 1);

	// SIFT�ɂ��������o
	cv::SiftFeatureDetector detector;
	std::vector<cv::KeyPoint> keypoints;
	detector.detect(input, keypoints);

	// �����_�̏�������
	cv::Mat output;
	cv::drawKeypoints(input, keypoints, output);

	// �����_���������񂾉摜�̕\��
	cv::imshow("�摜�̓����_���o", output);

	cv::waitKey(0);
}