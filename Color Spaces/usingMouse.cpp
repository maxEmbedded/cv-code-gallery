// Code taken from OpenCV Quick Guide at http://bsd-noobz.com/opencv-guide/45-3-using-mouse

#include <cv.h>
#include <highgui.h>
#include <stdio.h>

using namespace cv;

Mat img;

void onMouse(int event, int x, int y, int flags, void* param)
{
    char text[20];
    Mat img2, img3;

    img2 = img.clone();

    if (event == CV_EVENT_LBUTTONDOWN)
    {
        Vec3b p = img2.at<Vec3b>(y,x);
        sprintf(text, "R=%d, G=%d, B=%d", p[2], p[1], p[0]);
    }
    else if (event == CV_EVENT_RBUTTONDOWN)
    {
        cvtColor(img, img3, CV_BGR2HSV);
        Vec3b p = img3.at<Vec3b>(y,x);
        sprintf(text, "H=%d, S=%d, V=%d", p[0], p[1], p[2]);
    }
    else
        sprintf(text, "x=%d, y=%d", x, y);

    putText(img2, text, Point(5,15), FONT_HERSHEY_PLAIN, 1.0, CV_RGB(0,255,0));
    imshow("image", img2);
}

int main(int argc, char** argv)
{
    img = imread(argc == 2 ? argv[1] : "hello.png");
    if (img.empty())
        return -1;

    namedWindow("image");
    setMouseCallback("image", onMouse, 0);
    imshow("image", img);
    waitKey(0);

    return 0;
}