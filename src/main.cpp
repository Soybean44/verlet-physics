#include "raylib.h"
#include <raylib-cpp.hpp>

class Ball {
  private:
	raylib::Vector2 current_pos;
	raylib::Vector2 prev_pos;
	Color color;
	float time;
	float velocity;

  public:
	Ball(float x, float y, Color c = RAYWHITE) {
		current_pos = raylib::Vector2(x, y);
		prev_pos = current_pos;
		color = c;
		time = 0.0;
		velocity = 0.0;
	}
	Vector2 getVector() {
		return current_pos;
	}
	void Update(float dt, float a) {
		prev_pos = current_pos;
		time += dt;
		raylib::Vector2 temp_pos = current_pos;
		current_pos.y = current_pos.y + velocity * dt + 0.5 * a * dt * dt;
		velocity += a * dt;
		prev_pos = temp_pos;
	}
	void Draw() {
		DrawCircle(current_pos.x, current_pos.y, 10, color);
	}
};

int main() {

	// Initialization
	int screenWidth = 1600;
	int screenHeight = 900;

	raylib::Color ballColor(0x74c7ecff);
	raylib::Color bgColor(0x1e1e2eff);
	raylib::Window w(screenWidth, screenHeight, "Verlet Integration");

	SetTargetFPS(60);
	Ball ball = Ball(((float)screenWidth)/2, 10, ballColor);

	// Main game loop
	while (!w.ShouldClose()) { // Detect window close button or ESC key
		// Update
		ball.Update(1, 1);
		// Draw
		BeginDrawing();
		ClearBackground(bgColor);
		ball.Draw();
		EndDrawing();
	}

	return 0;
}
