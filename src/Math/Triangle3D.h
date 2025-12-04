#pragma once
#include <Math/Vector3.h>
#include <Math/Vector2.h>
#include <Defines.h>

struct Triangle3D {
	Vector3 a, b, c;

	Triangle3D(Vector3 a, Vector3 b, Vector3 c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Vector2 get_uv_coords(Vector3 p) {
		Vector3 e1 = b - a;
		Vector3 e2 = c - a;
		Vector3 pe = p - a;

		//We dot with the normal of the triangle to use 1 sqrtf instead of 3 when getting the areas of the sub triangles.
		Vector3 crossed = Vector3::cross(e1, e2);
		Vector3 normal = crossed.normalized();

		f32 total_area = fabs(Vector3::dot(crossed, normal));
		f32 u = Vector3::dot(normal, Vector3::cross(pe, e2)) / total_area;
		f32 v = Vector3::dot(normal, Vector3::cross(e1, pe)) / total_area;

		return Vector2(u, v);
	}

	Vector3 point_from_uv(Vector2 uv) {
		Vector3 e1 = b - a;
		Vector3 e2 = c - a;

		return e1 * uv.x + e2 * uv.y;
	}

	bool is_inside(Vector3 p) {
		Vector2 uv = get_uv_coords(p);

		return uv.x >= 0.0f && uv.y >= 0.0f && uv.x + uv.y <= 1.0f;
	}
};