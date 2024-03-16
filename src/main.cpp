#include "gravity.hpp"
#include "raylib.h"
#include <raylib-cpp.hpp>

int main() {

	// Initialization
	int screenWidth = 1600;
	int screenHeight = 900;

	raylib::Color ball_1_Color(0x74c7ecff);
	raylib::Color ball_2_Color(0xa6e3a1ff);
	raylib::Color bgColor(0x1e1e2eff);
	raylib::Window w(screenWidth, screenHeight, "Verlet Integration");

	SetTargetFPS(60);

	Gravity g = Gravity(screenWidth, screenHeight);

	// Main game loop
	while (!w.ShouldClose()) { // Detect window close button or ESC key
		BeginDrawing();
		g.Update(bgColor);
		EndDrawing();
	}

	return 0;
}
