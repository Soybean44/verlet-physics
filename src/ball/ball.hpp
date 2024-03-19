#pragma once
#include <raylib-cpp.hpp>

class Ball {
  private:
	int size;
	Color color;
	float time;

  public:
	
  raylib::Vector2 position;
	raylib::Vector2 velocity;

	Ball(raylib::Vector2 pos, int s, raylib::Vector2 vel = raylib::Vector2(0,0), Color c = RAYWHITE);
	raylib::Vector2 getVector();
	void Update(float dt, raylib::Vector2 a, int screenWidth, int screenHeight);
	void Collide(Ball *b);
	void Draw();
};
