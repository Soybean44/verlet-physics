#include "orbit.hpp"
#include "raylib.h"
#include <iostream>
#include <sys/types.h>

Orbit::Orbit(int w, int h) :
	ball_1(raylib::Vector2(((float)w)/2-100, 450), 10, raylib::Vector2(0,6), raylib::Color(0xfab387ff)),
	ball_2(raylib::Vector2(((float)w)/2-300, 450), 25, raylib::Vector2(0,6), raylib::Color(0x74c7ecff)),
	ball_3(raylib::Vector2(((float)w)/2, 450), 50, raylib::Vector2(0,0), raylib::Color(0xa6e3a1ff)) {
	screenWidth = w;
	screenHeight = h;
}

void Orbit::Rotate(Ball *b, raylib::Vector2 point, float v_initial, float dist) {
	Vector2 accel = {0};
	raylib::Vector2 n = point-b->position;
	n = n/n.Length();
	float a = ((v_initial*v_initial)/dist);
	accel.x = n.x*a;
	accel.y = n.y*a;

	b->Update(0.7, accel, screenWidth, screenHeight);
	raylib::Vector2 correction = -n*dist;
	n = point-b->position;
	n = n/n.Length();
}

void Orbit::Update(Color bgColor) {
	ClearBackground(bgColor);
	// Update
	Rotate(&ball_1, ball_3.position, 6, 100);
	Rotate(&ball_2, ball_3.position, 6, 300);
	// Drawing
	ball_1.Draw();
	ball_2.Draw();
	ball_3.Draw();
}
