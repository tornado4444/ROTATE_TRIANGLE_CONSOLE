/*
 ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄       ▄▄  ▄▄       ▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄  ▄▄▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌     ▐░░▌▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌▐░░░░░░░░░░░▌
▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌   ▐░▐░▌▐░▌░▌   ▐░▐░▌▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌▐░█▀▀▀▀▀▀▀▀▀
▐░▌          ▐░▌       ▐░▌▐░▌▐░▌ ▐░▌▐░▌▐░▌▐░▌ ▐░▌▐░▌▐░▌       ▐░▌▐░▌▐░▌    ▐░▌▐░▌
▐░▌          ▐░▌       ▐░▌▐░▌ ▐░▐░▌ ▐░▌▐░▌ ▐░▐░▌ ▐░▌▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌▐░█▄▄▄▄▄▄▄▄▄
▐░▌          ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░▌  ▐░▌  ▐░▌▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌
▐░▌          ▐░▌       ▐░▌▐░▌   ▀   ▐░▌▐░▌   ▀   ▐░▌▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌▐░█▀▀▀▀▀▀▀▀▀
▐░▌          ▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░▌    ▐░▌▐░▌▐░▌
▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌▐░█▄▄▄▄▄▄▄▄▄
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌▐░░░░░░░░░░░▌
 ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀  ▀▀▀▀▀▀▀▀▀▀▀

*/

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <cmath>
#include <thread>
#include <vector>

#define TRIANGLE_WIDTH 14 // FOR THE WITH THE SYMBOLS
#define WIDTH 160
#define HEIGHT 44

class Solution {
public:
    // constructor: initialize all rotation angles to zero and create buffers
    Solution() : A(0), B(0), C(0) {
        zBuffer.resize(WIDTH * HEIGHT);
        buffer.resize(WIDTH * HEIGHT);
    }

    const long long commone = 1000; // Delay between frames in microseconds

    // Векторы для хранения данных о глубине и символах
    std::vector<float> zBuffer; // Stores depth values ​​for each point on the screen.
    std::vector<char> buffer;   // Stores symbols for drawing

    // Constants for drawing
    static constexpr char backGroundASCIICode = ' '; // SYMBOL THE BACKGROUND
    static constexpr float distanceFromCam = 60; // Distance from camera to object
    float incrementSpeed = 0.6; // Increment step when constructing triangle points
    float A, B, C; // Angles of rotation around the axes

    // Methods for calculating coordinates
    float calculateX(float, float, float); // Calculates the X coordinate after rotation
    float calculateY(float, float, float); // Calculates the Y coordinate after rotation
    float calculateZ(float, float, float); // Calculates the Z coordinate after rotation

    // Method for calculating and rendering the surface
    void calculateForSurface(float, float, float, char);

private:
    /*float zBuffer[160 * 44];
    char buffer[160 * 44];
    int backGroundASCIICode = ' ';
    int distanceFromCam = 60;*/
    float K1 = 40;
    float x, y, z;
    float ooz;
    int xp, yp;
    int idx_buffer;
};