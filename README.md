# ROTATE_TRIANGLE_CONSOLE

Perhaps you have already seen a console implementation of a cube implemented in C, which was written by YouTuber Servet Gulnaroglu... after watching his video, I decided to do almost the same thing, but to make not a cube, but a triangle, in C++. I will say in advance, all those formulas that I used (namely the 3D rotation formulas in Wikipedia) are exactly the same, since I am not doing 2D, but 3D. However, there will still be a small difference, and I will try to explain and show with an example.

# THE EXPLANATION

Let me explain specifically how I understood this topic. Well, let's start with the fact that the 3D rotation that I use is typical linear algebra, if you don't know it well, it's not a problem (there are many formulas on the Internet), one thing you need to understand is that a rotation matrix is a transformation matrix that is used to perform a rotation in Euclidean space. For example, using the convention below, the matrix.

![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/formula_1%202025-01-20%20191646.png)

A basic 3D rotation (also called an elementary rotation) is a rotation around one of the axes of the coordinate system. So this means that you have three coordinates (x, y, z)... in principle, it sounds logical, since we are talking about 3D.
![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/formula_2.png)

You can find out more about other 3D rotation formulas in Wikipedia, here is the link:
https://en.wikipedia.org/wiki/Rotation_matrix

As you already understood, with the help of this formula Servet Gulnaroglu implemented his 3D cube, and it really rotated, here I also decided to tell in detail about the implementation of that guy in the C programming language.

+ ## __CALCULATE X__
```c
float calculateX(int i, int j, int k) {
   return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}
```
So, let's analyze what he did, he specified three integers in the function, namely i, j, k (needed for calculation) and takes the formula, and substitutes these three values ​... specifically:
```c
return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
```
it turns out that the specified edge will rotate only along the X axis that we specified(A, B, C SPECIFIED PARTIES).

+ ## __CALCULATE Y__
```c
float calculateY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
        j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
        i * cos(B) * sin(C);
}
```
Next, following the same logic, we describe calculate Y and describe its parameters, however, since this is Y, the logic changes a little, before

_1) j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + j * cos(A) * sin(C)_

however, now we simply change the signs to the opposite

_2) j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) + j * cos(A) * sin(C)_

Also, we're change the signs to the oposite:

_3) k * cos(A) * sin(B) * sin(C) - i * cos(B) * sin(C)_

+ ## __CALCULATE Z__
```c
float calculateZ(int i, int j, int k) {
    return j * sin(A) * cos(B) - k * cos(A) * cos(B) - i * sin(B);
}
```
Calculate the Z coordinate after all rotations(with the help formula).

# THE RESULT(Servet Gulnaroglu)

![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/commone.gif)

# ABOUT MY INITIALIZATION.
So, here we come to my implementation, let me explain to you in detail what is happening in my code, namely the formulas.

+ ## __CALCULATE X__
```c++
float Solution::calculateX(float i, float j, float k) {
	float centerX = TRIANGLE_WIDTH / 2; // center divide by 2 so that the triangle rotates in the center, and not like a circle
	i -= centerX;   //  increment i, that to realization, to rotate counterclockwise                                                                                                                    
	j -= centerX;   //  increment j, that to realization, to rotate counterclockwise
	k -= centerX;   //  increment k, that to realization, to rotate counterclockwise

    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}
```
Here is the same logic for formula 3D rotation...but we have but there are some differences:

_1) i -= centerX;_ 

Here we specifically center the coordinates relative to the middle of the triangle (the first side __i__ and we rotate it counterclockwise, since we have a minus).

_2) j -= centerY;_ 

Here we specifically center the coordinates relative to the middle of the triangle (the first side __j__ and we rotate it counterclockwise, since we have a minus).

_3) k -= centerX;_

Here we specifically center the coordinates relative to the middle of the triangle (the first side __k__ and we rotate it counterclockwise, since we have a minus).

+ ## __CALCULATE Y__
```c++
float Solution::calculateY(float i, float j, float k) {
    float centerY = TRIANGLE_WIDTH / 2;
    i -= centerY;
    j -= centerY;
    k -= centerY;
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
        j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
        i * cos(B) * sin(C);
}
```

The same logic for formula 3D rotation...but we have but there are some differences:
# FULL RESULT.

![image](https://github.com/tornado4444/ROTATE_TRIANGLE_CONSOLE/blob/main/CONSOLE_TRIANGLE/x64/Debug/CONSOLE_TRIANGLE.tlog/pedro.gif)
