/*
 ▄▄       ▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄▄        ▄
▐░░▌     ▐░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░▌      ▐░▌
▐░▌░▌   ▐░▐░▌▐░█▀▀▀▀▀▀▀█░▌ ▀▀▀▀█░█▀▀▀▀ ▐░▌░▌     ▐░▌
▐░▌▐░▌ ▐░▌▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌▐░▌    ▐░▌
▐░▌ ▐░▐░▌ ▐░▌▐░█▄▄▄▄▄▄▄█░▌     ▐░▌     ▐░▌ ▐░▌   ▐░▌
▐░▌  ▐░▌  ▐░▌▐░░░░░░░░░░░▌     ▐░▌     ▐░▌  ▐░▌  ▐░▌
▐░▌   ▀   ▐░▌▐░█▀▀▀▀▀▀▀█░▌     ▐░▌     ▐░▌   ▐░▌ ▐░▌
▐░▌       ▐░▌▐░▌       ▐░▌     ▐░▌     ▐░▌    ▐░▌▐░▌
▐░▌       ▐░▌▐░▌       ▐░▌ ▄▄▄▄█░█▄▄▄▄ ▐░▌     ▐░▐░▌
▐░▌       ▐░▌▐░▌       ▐░▌▐░░░░░░░░░░░▌▐░▌      ▐░░▌
 ▀         ▀  ▀         ▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀        ▀▀

*/

#include "Triangle.hpp"

using namespace std::chrono; // for without announcement std

int main() {
	Solution soul; // for the realization the class
    // ON WINDOWS
    /*system("cls");*/
    // ON UBUNTU AND WINDOWS
    std::cout << "\x1b[2J"; // for the clear the system

    // ON C: WHILE(1), BUT I'M ON C++ LOL, (0: false), (1: true)
    while (true) {
        // Clear buffers for new cadrs
        std::fill(soul.buffer.begin(), soul.buffer.end(), soul.backGroundASCIICode);
        std::fill(soul.zBuffer.begin(), soul.zBuffer.end(), 0.0f);

        // Draw the triangle
        for (float i = 0; i <= TRIANGLE_WIDTH; i += soul.incrementSpeed) {
            for (float j = 0; j <= TRIANGLE_WIDTH - i; j += soul.incrementSpeed) {
                // Base (lower triangle)
                soul.calculateForSurface(i, j, 0, '#');
                // Side faces
                if (i + j <= TRIANGLE_WIDTH) {
                    float height = TRIANGLE_WIDTH - (i + j); // HEIGHT for the current point
                    soul.calculateForSurface(i, j, height, '@'); // Front edge
                    soul.calculateForSurface(i, 0, j, '%'); // Right edge
                    soul.calculateForSurface(0, i, j, '*'); // Left edge
                }
            }
        }

        // Move the cursor to the beginning of the screen
        std::cout << "\x1b[H";

        // Output the current frame
        for (int k = 0; k < WIDTH * HEIGHT; k++) {
            std::cout << (k % WIDTH ? soul.buffer[k] : '\n');
        }

        // Update the angles for rotation
        soul.A += 0.005; // Rotate around the X axis
        soul.B += 0.005; // Rotate around the Y axis
        // Pause between frames
        std::this_thread::sleep_for(microseconds(soul.commone));
    }
	return 0;
}
