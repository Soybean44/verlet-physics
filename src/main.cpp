#include "raylib.h"
#include <raylib-cpp.hpp>
#include "ball.hpp"

int main() {

	// Initialization
	int screenWidth = 1600;
	int screenHeight = 900;

	raylib::Color ballColor(0x74c7ecff);
	raylib::Color bgColor(0x1e1e2eff);
	raylib::Window w(screenWidth, screenHeight, "Verlet Integration");

	SetTargetFPS(60);
	Ball ball = Ball(((float)screenWidth)/2, 25, 25, ballColor);

	// Main game loop
	while (!w.ShouldClose()) { // Detect window close button or ESC key
		// Update
		ball.Update(0.7, 1, screenWidth, screenHeight);
		// Draw
		BeginDrawing();
		ClearBackground(bgColor);
		ball.Draw();
		EndDrawing();
	}

	return 0;
}
