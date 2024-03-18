#pragma once
#include "ball.hpp"
#include "raylib.h"

class Orbit {
  private:
	Ball ball_1;
	Ball ball_2;
	int screenWidth, screenHeight;

  public:
	Orbit(int w, int h);
	void Update(Color);
};
