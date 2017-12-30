#pragma once
#include "MathUtils.h"

namespace nostd
{
	struct Vector3
	{
		float _x, _y, _z;

		Vector3() = default;
		Vector3(float x, float y, float z) : _x{ x }, _y{ y }, _z{ z } {}
		float& operator[](int i) { return ((&_x)[i]); }
		const float& operator[](int i) const { return ((&_x)[i]); }
		Vector3& operator*=(float s) { _x *= s; _y *= s; _z *= s; return (*this); }
		Vector3& operator/=(float s) { s = 1.f / s; _x *= s; _y *= s; _z *= s; return (*this); }
		Vector3& operator+=(const Vector3& v) { _x += v._x; _y += v._y; _z += v._z; return (*this); }
		Vector3& operator-=(const Vector3& v) { _x -= v._x; _y -= v._y; _z -= v._z; return (*this); }
	};

	inline bool operator==(const Vector3& a, const Vector3& b) { return (a._x == b._x && a._y == b._y && a._z == b._z); }
	inline bool operator!=(const Vector3& a, const Vector3& b) { return !(a == b); }
	inline Vector3 operator+(const Vector3& a, const Vector3& b) { return { a._x + b._x, a._y + b._y , a._z + b._z }; }
	inline Vector3 operator-(const Vector3& a, const Vector3& b) { return { a._x - b._x, a._y - b._y , a._z - b._z }; }
	inline Vector3 operator*(const Vector3& v, float s) { return { v._x * s, v._y * s , v._z * s }; }
	inline Vector3 operator/(const Vector3& v, float s) { s = 1.f / s; return { v._x * s, v._y * s , v._z * s }; }
	inline Vector3 operator-(const Vector3& v) { return { -v._x, -v._y, -v._z }; }
	inline float squaredLength(const Vector3& v) { return v._x*v._x + v._y* v._y + v._z* v._z; }
	inline float length(const Vector3& v) { return sqrt(squaredLength(v)); }
	inline float invLength(const Vector3& v) { return 1.f/sqrt(squaredLength(v)); }
	inline Vector3 normalize(const Vector3& v) { return v * invLength(v); }
}