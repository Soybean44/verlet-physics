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
		// momentum X
		float e = 5;
		float dv = velocity.x - b->velocity.x;
		float dt = 1;
		if (dv != 0) {
			float pa = size*velocity.x;
			float pb = size*velocity.x;
			float F = (e*dv);
			pb = pb + F*dt;
			pa = pa - F*dt;
			b->velocity.x = pb/b->size;
			velocity.x = pa/size;
			b->position.x = b->position.x + pb*dt/b->size;
			position.x = position.x + pb*dt/b->size;
		}

		// momentum Y
		dv = b->velocity.y - velocity.y;
		if (dv != 0) {
			raylib::Vector2 r = collision_axis/(dv);
			float pa = size*velocity.y;
			float pb = size*velocity.y;
			float F = (e*dv);
			pb = pb + F*dt;
			pa = pa - F*dt;
			b->velocity.y = pb/b->size;
			velocity.y = pa/size;
			b->position.y = b->position.y + pb*dt/b->size;
			position.y = position.y + pb*dt/b->size;
		}

	}
}

void Ball::Draw() {
	DrawCircle(position.x, position.y, size, color);
}
