#pragma once
#include "ball.hpp"
#include "raylib.h"

class Gravity {
  private:
	std::vector<Ball> balls;
	int screenWidth, screenHeight;
	Color ball_1_Color;

  public:
	Gravity(int w, int h);
	void Update(Color);
};
