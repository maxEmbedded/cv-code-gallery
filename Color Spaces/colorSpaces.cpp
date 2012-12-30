// colorSpaces.cpp : Defines the entry point for the console application.
// Description : Takes an RGB image, converts into HSV, prints their header info and displays all channels separately
// Author : Mayank
// Last Updated : 29th December, 2012
// 

#include "stdafx.h"

#include <cv.h>
#include <highgui.h>

// function to access the IplImage header and print the details in the console
void printImageInfo(IplImage* src) {
	printf("\n\nImage Header Details:\n\n");
	printf("Size		: %d\n", src->nSize);
	printf("Channels	: %d\n", src->nChannels);
	printf("Depth		: %d\n", src->depth);
	printf("Color Model	: %s\n", src->colorModel);
	printf("Channel Seq	: %s\n", src->channelSeq);
	printf("Data Order	: %d\n", src->dataOrder);
	printf("Origin		: %d\n", src->origin);
	printf("Align		: %d\n", src->align);
	printf("Width		: %d\n", src->width);
	printf("Height		: %d\n", src->height);
	printf("Image Size	: %d\n", src->imageSize);
	printf("Width Step	: %d\n", src->widthStep);
}

int main(int argc, char* argv[])
{
	// TODO: load the image from the given file
	IplImage* src = cvLoadImage(argc == 2 ? argv[1] : "hello.png");				// RGB Image
	IplImage* dst = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);	// HSV Image
	
	// TODO: create variables to store separate channels of images
	// b, g, r for RGB Image (src)
	IplImage* b = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* g = cvCreateImage(cvGetSize(src), src->depth, 1);
	IplImage* r = cvCreateImage(cvGetSize(src), src->depth, 1);
	// h, s, v for HSV Image (dst)
	IplImage* h = cvCreateImage(cvGetSize(dst), dst->depth, 1);
	IplImage* s = cvCreateImage(cvGetSize(dst), dst->depth, 1);
	IplImage* v = cvCreateImage(cvGetSize(dst), dst->depth, 1);

	// TODO: convert BGR to HSV
	cvCvtColor(src, dst, CV_BGR2HSV);

	// TODO: split the channels of both the images
	cvSplit(src, b, g, r, NULL);		// Because OpenCV loads RGB as BGR sequence
	cvSplit(dst, h, s, v, NULL);
	
	// TODO: create named windows
	cvNamedWindow("BGR Image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("HSV Image", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("BLUE Only", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("GREEN Only", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("RED Only", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("HUE Only", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("SATURATION Only", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("VALUE Only", CV_WINDOW_AUTOSIZE);
	
	// TODO: save images to disk
	cvSaveImage("0 bgr.jpg", src);
	cvSaveImage("0 hsv.jpg", dst);
	cvSaveImage("1 red.jpg", r);
	cvSaveImage("2 green.jpg", g);
	cvSaveImage("3 blue.jpg", b);
	cvSaveImage("4 hue.jpg", h);
	cvSaveImage("5 saturation.jpg", s);
	cvSaveImage("6 value.jpg", v);

	// TODO: show images in windows
	cvShowImage("BGR Image", src);
	cvShowImage("HSV Image", dst);
	cvShowImage("RED Only", r);
	cvShowImage("GREEN Only", g);
	cvShowImage("BLUE Only", b);
	cvShowImage("HUE Only", h);
	cvShowImage("SATURATION Only", s);
	cvShowImage("VALUE Only", v);
	
	// TODO: access the IplImage header for details
	// print them in the console
	printf("\nRGB");		printImageInfo(src);
	printf("\nHSV");		printImageInfo(dst);
	printf("\nRED");		printImageInfo(r);
	printf("\nGREEN");		printImageInfo(g);
	printf("\nBLUE");		printImageInfo(b);
	printf("\nHUE");		printImageInfo(h);
	printf("\nSATURATION"); printImageInfo(s);
	printf("\nVALUE");		printImageInfo(v);
	
	// TODO: wait for key press
	cvWaitKey(0);
	
	// TODO: clean up and don't be piggies!
	cvReleaseImage(&src);
	cvReleaseImage(&dst);
	cvReleaseImage(&r);
	cvReleaseImage(&g);
	cvReleaseImage(&b);
	cvReleaseImage(&h);
	cvReleaseImage(&s);
	cvReleaseImage(&v);

	cvDestroyAllWindows();
	
	return 0;
}