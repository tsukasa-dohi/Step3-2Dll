// Step3-2Dll.cpp : DLL アプリケーション用にエクスポートされる関数を定義します。
//

#include "stdafx.h"
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv/highgui.h>

void UseOpenCV(const char *imagePath) {
	
	// 画像読み込み
	const cv::Mat input = cv::imread(imagePath, 1);

	// SIFTによる特徴検出
	cv::SiftFeatureDetector detector;
	std::vector<cv::KeyPoint> keypoints;
	detector.detect(input, keypoints);

	// 特徴点の書き込み
	cv::Mat output;
	cv::drawKeypoints(input, keypoints, output);

	// 特徴点を書き込んだ画像の表示
	cv::imshow("画像の特徴点検出", output);

	cv::waitKey(0);
}