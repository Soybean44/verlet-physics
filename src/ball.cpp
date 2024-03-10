#include "ball.hpp"
Ball::Ball(float x, float y, int s, Color c) {
	current_pos = raylib::Vector2(x, y);
	prev_pos = current_pos;
	size = s;
	color = c;
	time = 0.0; // time will be displayed on the screen in the future
	velocity = 0.0;
}
Vector2 Ball::getVector() {
	return current_pos;
}
void Ball::Update(float dt, float a, int screenWidth, int screenHeight) {
	// ---- MAIN VERLET STUFF ---- //
	prev_pos = current_pos;
	time += dt;
	raylib::Vector2 temp_pos = current_pos;
	current_pos.y = current_pos.y + velocity * dt + 0.5 * a * dt * dt; // update verlet position
	velocity += a * dt;
	prev_pos = temp_pos;

	// bounce on the bottom of the screen
	if (current_pos.y+size > screenHeight) {
		current_pos.y = screenHeight-size;

		// only dampen velocity to a certain point otherwise set it to 0
		if (velocity*velocity >= 2) { // square the velocity to account for sign
			velocity = -(velocity*0.5); // 0.5 is the damping factor, which may be tweaked
		} else {
			velocity = 0;
		}
	}
}
void Ball::Draw() {
	DrawCircle(current_pos.x, current_pos.y, size, color);
}
