#pragma once
#include <Defines.h>
#include <math.h>

struct Vector3 {
	f32 x, y, z;

	Vector3(f32 x = 0.0f, f32 y = 0.0f, f32 z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	f32 length_sqr() {
		return this->x * this->x + this->y * this->y + this->z * this->z;
	}

	f32 length() {
		return sqrtf(this->length_sqr());
	}

	Vector3 normalized() {
		f32 l = this->length();

		if (l == 0.0f) {
			return *this;
		}

		return Vector3(this->x / l, this->y / l, this->z / l);
	}

	static f32 dot(Vector3 v1, Vector3 v2) {
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	static Vector3 cross(Vector3 v1, Vector3 v2) {
		return Vector3(
			v1.y * v2.z - v1.z * v2.y,
			v1.z * v2.x - v1.x * v2.z,
			v1.x * v2.y - v1.y * v2.x
		);
	}

	Vector3 projected(Vector3 project_on) {
		Vector3 a = *this;
		Vector3 b = project_on.normalized();

		f32 dot = Vector3::dot(a, b);
		return b * dot;
	}

	Vector3 operator+(Vector3 other) {
		return Vector3(this->x + other.x, this->y + other.y, this->z + other.y);
	}

	void operator+=(Vector3 other) {
		*this = *this + other;
	}

	Vector3 operator-(Vector3 other) {
		return Vector3(this->x - other.x, this->y - other.y, this->z - other.y);
	}

	void operator-=(Vector3 other) {
		*this = *this - other;
	}

	Vector3 operator*(float scalar) {
		return Vector3(this->x * scalar, this->y * scalar, this->z * scalar);
	}

	void operator*=(float scalar) {
		*this = *this * scalar;
	}
};



