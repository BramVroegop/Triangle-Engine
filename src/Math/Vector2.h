#pragma once
#include <Defines.h>
#include <math.h>

struct Vector2 {
	f32 x, y;

	Vector2(f32 x = 0.0f, f32 y = 0.0f) {
		this->x = x;
		this->y = y;
	}

	f32 length_sqr() {
		return this->x * this->x + this->y * this->y;
	}

	f32 length() {
		return sqrtf(this->length_sqr());
	}

	Vector2 normalized() {
		f32 l = this->length();

		if (l == 0.0f) {
			return *this;
		}

		return Vector2(this->x / l, this->y / l);
	}

	static f32 dot(Vector2 v1, Vector2 v2) {
		return v1.x * v2.x + v1.y * v2.y;
	}

	Vector2 projected(Vector2 project_on) {
		Vector2 a = *this;
		Vector2 b = project_on.normalized();

		f32 dot = Vector2::dot(a, b);
		return b * dot;
	}

	Vector2 operator+(Vector2 other) {
		return Vector2(this->x + other.x, this->y + other.y);
	}

	void operator+=(Vector2 other) {
		*this = *this + other;
	}

	Vector2 operator-(Vector2 other) {
		return Vector2(this->x - other.x, this->y - other.y);
	}

	void operator-=(Vector2 other) {
		*this = *this - other;
	}

	Vector2 operator*(float scalar) {
		return Vector2(this->x * scalar, this->y * scalar);
	}

	void operator*=(float scalar) {
		*this = *this * scalar;
	}
};


