#include "orbit.hpp"
#include "raylib.h"

Orbit::Orbit(int w, int h) :
	ball_1(raylib::Vector2(((float)w)/2-200, 450), 25, raylib::Vector2(3,0), raylib::Color(0x74c7ecff)),
	ball_2(raylib::Vector2(((float)w)/2, 450), 25, raylib::Vector2(-3,0), raylib::Color(0xa6e3a1ff)) {
	screenWidth = w;
	screenHeight = h;
}

void Orbit::Update(Color bgColor) {
	ClearBackground(bgColor);
	ball_1.Draw();
	ball_2.Draw();
}
