#pragma once
#include "Matrix.h"

namespace nostd
{
	struct quat
	{
		float _x, _y, _z, _w;

		quat() = default;
		quat(float x, float y, float z, float w) : _x{ x }, _y{ y }, _z{ z }, _w{ w } {}
		quat(const vec3& v, float w) : _x{ v._x }, _y{ v._y }, _z{ v._z }, _w{ w } {}

		const vec3& GetVector() const
		{
			return (reinterpret_cast<const vec3&>(_x));
		}

		mat3 GetRotationMatrix();
		void SetRotationMatrix(const mat3& M);
	};

	quat operator*(const quat& q1, const quat& q2)
	{
		return {
			q1._w * q2._x + q1._x * q2._w + q1._y * q2._z - q1._z * q2._y,
			q1._w * q2._y - q1._x * q2._z + q1._y * q2._w + q1._z * q2._x,
			q1._w * q2._z + q1._x * q2._y - q1._y * q2._x + q1._z * q2._w,
			q1._w * q2._w - q1._x * q2._x - q1._y * q2._y - q1._z * q2._z,
		};
	}
}