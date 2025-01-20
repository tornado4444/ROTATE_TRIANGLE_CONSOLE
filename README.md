# ROTATE_TRIANGLE_CONSOLE

Perhaps you have already seen a console implementation of a cube implemented in C, which was written by YouTuber Servet Gulnaroglu... after watching his video, I decided to do almost the same thing, but to make not a cube, but a triangle, in C++. I will say in advance, all those formulas that I used (namely the 3D rotation formulas in Wikipedia) are exactly the same, since I am not doing 2D, but 3D. However, there will still be a small difference, and I will try to explain and show with an example.

# THE EXPLANATION

Let me explain specifically how I understood this topic. Well, let's start with the fact that the 3D rotation that I use is typical linear algebra, if you don't know it well, it's not a problem (there are many formulas on the Internet), one thing you need to understand is that a rotation matrix is a transformation matrix that is used to perform a rotation in Euclidean space. For example, using the convention below, the matrix.

![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/formula_1%202025-01-20%20191646.png)

A basic 3D rotation (also called an elementary rotation) is a rotation around one of the axes of the coordinate system. So this means that you have three coordinates (x, y, z)... in principle, it sounds logical, since we are talking about 3D.
![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/formula_2.png)

You can find out more about other 3D rotation formulas in Wikipedia, here is the link:
https://en.wikipedia.org/wiki/Rotation_matrix

