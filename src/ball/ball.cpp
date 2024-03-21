#include "ball.hpp"
#include <raylib-cpp.hpp>

Ball::Ball(raylib::Vector2 pos, int s, raylib::Vector2 vel, Color c) {
	position = pos;
	size = s;
	color = c;
	time = 0.0; // time will be displayed on the screen in the future
	velocity = vel;
}

raylib::Vector2 Ball::getVector() {
	return position;
}
void Ball::Update(float dt, raylib::Vector2 a, int screenWidth, int screenHeight) {
	// ---- MAIN VERLET STUFF ---- //
	time += dt;
	// update verlet position
	position.y = position.y + velocity.y * dt + 0.5 * a.y * dt * dt;
	position.x = position.x + velocity.x * dt + 0.5 * a.x * dt * dt;
	velocity.y += a.y * dt;
	velocity.x += a.x * dt;
}

void Ball::Bounce(int screenWidth, int screenHeight) {
// bounce on the bottom of the screen
	if (position.y+size > screenHeight) {
		position.y = screenHeight-size;

		// only dampen velocity to a certain point otherwise set it to 0
		if (velocity.y*velocity.y >= 2) { // square the velocity to account for sign
			velocity.y = -(velocity.y*0.5); // 0.5 is the damping factor, which may be tweaked
		} else {
			velocity.y = 0;
		}
	}
	// bounce on the sides of the screen
	if (position.x+size > screenWidth) {
		position.x = screenWidth-size;

		// only dampen velocity to a certain point otherwise set it to 0
		if (velocity.x*velocity.x >= 2) { // square the velocity to account for sign
			velocity.x = -(velocity.x*0.5); // 0.5 is the damping factor, which may be tweaked
		} else {
			velocity.x = 0;
		}
	} else if (position.x-size < 0) {
		position.x = size;

		// only dampen velocity to a certain point otherwise set it to 0
		if (velocity.x*velocity.x >= 2) { // square the velocity to account for sign
			velocity.x = -(velocity.x*0.5); // 0.5 is the damping factor, which may be tweaked
		} else {
			velocity.x = 0;
		}
	}

}

void Ball::Collide(Ball *b) {
	const raylib::Vector2 collision_axis = position - b->position;
	float dist = collision_axis.Length();
	if (dist < size+b->size) { // check if balls are colliding
		raylib::Vector2 n = collision_axis/dist;
		raylib::Vector2 delta = (size+b->size) - dist;
		float dx = 0.5f * delta.x * n.x;
		float dy = 0.5f * delta.y * n.y;
		raylib::Vector2 tmpPos = position;
		raylib::Vector2 tmpPosB = b->position;
		position.x += dx;
		position.y += dy;
		b->position.x -= dx;
		b->position.y -= dy;
		velocity = position-tmpPos;
		b->velocity = b->position-tmpPosB;
	}
}

void Ball::Draw() {
	DrawCircle(position.x, position.y, size, color);
}
