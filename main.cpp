#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main()
{
	// Read image from file
	Mat img = imread("tank.jpg", 0);
	Mat img1, F, New_img;
	img.convertTo(img1, CV_32F);
	dft(img1, F, DFT_COMPLEX_OUTPUT); // Applying DFT
	int L = 25;
	for (int K1 = L; K1 <= 255 - L + 1; K1++) {
		for (int K2 = L; K2 <= 255 - L + 1; K2++) {
			F.at<float>(K1, K2) = 0;
		}
	}

	// Reconstructing original image from the DFT coefficients
	idft(F, New_img, DFT_SCALE | DFT_REAL_OUTPUT); // Applying IDFT
	New_img.convertTo(New_img, CV_8U);
	imwrite("L_min_DFT.jpg", New_img);
	imshow("Output_DFT", New_img);
	imshow("Original Image", img);
	Mat img2, D, New_img2;
	img.convertTo(img2, CV_32F);
	dct(img2, D, 0); // Applying DCT
	L = 100;
	for (int K1 = 0; K1 <= 255; K1++) {
		for (int K2 = 0; K2 <= 255; K2++) {
			if (K1 < L && K2 < L) {
				continue;
			}
			D.at<float>(K1, K2) = 0;
		}
	}

	//Draw the resulting DCT
	imshow("DCT", D);
	// Reconstructing original image from the DFT coefficients
	idct(D, New_img2, 0); // Applying IDCT
	New_img2.convertTo(New_img2, CV_8U);
	imwrite("L_min_DCT.jpg", New_img);
	imshow("Output_DCT", New_img2);
	//show the image
	imshow("Original Image", img);
	// Wait until user press some key
	waitKey(0);
	return 0;
}
