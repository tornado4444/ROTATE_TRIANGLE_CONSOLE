/*
 ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄ 
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌
▐░█▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌           ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀▀▀▀▀▀█░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌░▌     ▐░▌
▐░▌       ▐░▌▐░▌          ▐░▌       ▐░▌▐░▌               ▐░▌               ▐░▌▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌▐░▌    ▐░▌
▐░█▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌               ▐░▌      ▄▄▄▄▄▄▄▄▄█░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌ ▐░▌   ▐░▌
▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌               ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌  ▐░▌  ▐░▌
▐░█▀▀▀▀█░█▀▀ ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌▐░▌               ▐░▌     ▐░█▀▀▀▀▀▀▀▀▀ ▐░█▀▀▀▀▀▀▀█░▌     ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌   ▐░▌ ▐░▌
▐░▌     ▐░▌  ▐░▌          ▐░▌       ▐░▌▐░▌               ▐░▌     ▐░▌          ▐░▌       ▐░▌     ▐░▌          ▐░▌     ▐░▌       ▐░▌▐░▌    ▐░▌▐░▌
▐░▌      ▐░▌ ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░▌       ▐░▌     ▐░▌      ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄█░▌▐░▌     ▐░▐░▌
▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌       ▐░▌     ▐░▌     ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌
 ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀         ▀       ▀       ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀ 
                                                                                                                                               
*/

#include "Triangle.hpp"

// CALCULATE X: It's the first realisation for rotationX
float Solution::calculateX(float i, float j, float k) {
	float centerX = TRIANGLE_WIDTH / 2; // center divide by 2 so that the triangle rotates in the center, and not like a circle
	i -= centerX;   //  increment i, that to realization, to rotate counterclockwise                                                                                                                    
	j -= centerX;   //  increment j, that to realization, to rotate counterclockwise
	k -= centerX;   //  increment k, that to realization, to rotate counterclockwise

    // The formula for 3D rotation(more details on github)
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

// CALCULATE Y: It's the first realisation for rotationY
float Solution::calculateY(float i, float j, float k) {
    float centerY = TRIANGLE_WIDTH / 2;
    i -= centerY;
    j -= centerY;
    k -= centerY;
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
        j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
        i * cos(B) * sin(C);
}

// CALCULATE Z: It's the first realisation for rotationX
float Solution::calculateZ(float i, float j, float k) {
    float centerZ = TRIANGLE_WIDTH / 2;
    i -= centerZ;
    j -= centerZ;
    k -= centerZ;
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

void Solution::calculateForSurface(float triangleX, float triangleY, float triangleZ, char ch) {
    // Get the coordinates of the point after all rotations
    x = calculateX(triangleX, triangleY, triangleZ);
    y = calculateY(triangleX, triangleY, triangleZ);
    z = calculateZ(triangleX, triangleY, triangleZ) + distanceFromCam;

    // Calculate the inverse of Z to create a perspective effect
    // The further away the point (higher Z), the smaller the ooz
    ooz = 1 / z;

    // Project 3D coordinates onto 2D screen
    xp = (int)(WIDTH / 2 + K1 * ooz * x * 2); // to compensate for the proportions of the character in the console
    yp = (int)(HEIGHT /  2 + K1 * ooz * y); // Center on the screen

    // Calculate index in one-dimensional buffer from 2D coordinates
    idx_buffer = xp + yp * WIDTH;

    // Check if the point is within the screen
    if (idx_buffer >= 0 && idx_buffer < WIDTH * HEIGHT) {
        // If the current point is closer to the camera than the one already drawn
        if (ooz > zBuffer[idx_buffer]) {
            // Update the depth buffer and the character at that point
            zBuffer[idx_buffer] = ooz;
            buffer[idx_buffer] = ch;
        }
    }
}
