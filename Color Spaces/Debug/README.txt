This contains two executables to be run in Windows. Its tested in Windows 7 32-bit, however it should work in all Windows versions.

There are two ways to execute them:

1. Double click on colorSpaces.exe (or usingMouse.exe) - This will take the hello.png image by default and perform all operations on it.

2. Go to command prompt and enter this directory. Shortcut to do this is to hold Shift key and right click, and then click on "Open Command Window Here". Then execute the file by typing any of the following:

colorSpaces.exe lena.jpg
colorSpaces.exe colorBand.png

(or)
usingMouse.exe lena.jpg

In general, you can run them as:
colorSpaces.exe <image location with extension>
usingMouse.exe <image location with extension>

e.g. colorSpaces.exe C:\Users\Mayank\myPic.tiff
e.g. usingMouse.exe C:\Users\Mayank\myPic.tiff


OUTPUT OF colorSpaces.exe
-------------------------
The program should print details of all the images in the console window. It will show the following images in different windows and save a copy of the generated images in the same folder as well:
RGB, HSV, R, G, B, H, S, V


OUTPUT OF usingMouse.exe
------------------------
This program shows the (x,y) coordinates of the mouse pointer over the image. Upon left click on the image, it shows [R G B] values of that pixel. Upon right click on the image, it shows [H S V] values of that pixel.


------

The source code of the program can be found in the level-up directory. They should be named as colorSpaces.cpp and usingMouse.cpp

The source code is written using OpenCV and was compiled using Visual C++ 2010. Refer to README.txt file in the corresponding folder for more details.
------

This is a part of the Computer Vision Code Gallery at maxEmbedded.

In case of any queries, please visit maxEmbedded.com and/or send an email to: maxEmbedded@gmail.com

------
Presented by Mayank Prasad, Admin at maxEmbedded