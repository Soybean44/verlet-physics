#pragma once
#include "ball.hpp"
#include "raylib.h"

class Orbit {
  private:
	Ball ball_1;
	Ball ball_2;
	Ball ball_3;
	int screenWidth, screenHeight;

  public:
	Orbit(int w, int h);
	void Update(Color);
	void Rotate(Ball *b, raylib::Vector2 point, float v_initial, float dist);
};
