#include "gravity.hpp"
#include "raylib.h"

Gravity::Gravity(int w, int h) {
	screenWidth = w;
	screenHeight = h;
	raylib::Color ball_2_Color(0xa6e3a1ff);
	ball_1_Color = Color {0x74, 0xc7, 0xec,0xff};
	balls.push_back(Ball(raylib::Vector2(((float)screenWidth)/2-100, 450), 25, raylib::Vector2(3,0), ball_1_Color));
	balls.push_back(Ball(raylib::Vector2(((float)screenWidth)/2+100, 450), 25, raylib::Vector2(-3,0), ball_2_Color));
}

void Gravity::Update(Color bgColor) {
	ClearBackground(bgColor);

	// spawn new balls
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		balls.push_back(Ball(raylib::Vector2((float)GetMouseX(), (float)GetMouseY()), 25, raylib::Vector2(0,0), ball_1_Color));
	}

	for(int i=0; i<balls.size(); i++) {
		balls[i].Update(0.7, raylib::Vector2(0,1), screenWidth, screenHeight);
		for(int j=0; j<balls.size(); j++) {
			if (i != j)
				balls[i].Collide(&balls[j]);
		}
		balls[i].Draw();
	}
}
