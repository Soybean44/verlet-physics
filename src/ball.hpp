#pragma once
#include "raylib.h"
#include <raylib-cpp.hpp>

class Ball {
  private:
	raylib::Vector2 current_pos;
	raylib::Vector2 prev_pos;
	int size;
	Color color;
	float time;
	raylib::Vector2 velocity;

  public:
	Ball(float x, float y, int s, Color c = RAYWHITE);
	Vector2 getVector();
	void Update(float dt, float a, int screenWidth, int screenHeight);
	void Draw();
};
