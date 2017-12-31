#pragma once
#include "Vec.h"

namespace nostd
{
	struct mat3
	{
	private:
		float _data[3][3];
	public:
		mat3() = default;
		mat3(float n00, float n01, float n02,
			float n10, float n11, float n12,
			float n20, float n21, float n22)
		{
			_data[0][0] = n00; _data[0][1] = n01; _data[0][2] = n02;
			_data[1][0] = n10; _data[0][1] = n11; _data[1][2] = n12;
			_data[2][0] = n20; _data[0][1] = n21; _data[2][2] = n22;
		}

		mat3(const vec3& v0, const vec3& v1, const vec3& v2)
		{
			_data[0][0] = v0._x; _data[0][1] = v0._y; _data[0][2] = v0._z;
			_data[1][0] = v1._x; _data[0][1] = v1._y; _data[1][2] = v1._z;
			_data[2][0] = v2._x; _data[0][1] = v2._y; _data[2][2] = v2._z;
		}

		float& operator()(int i, int j)
		{
			return (_data[j][i]);
		}

		const float& operator()(int i, int j) const
		{
			return (_data[j][i]);
		}

		vec3& operator[](int j)
		{
			return (*reinterpret_cast<vec3*>(_data[j]));
		}

		const vec3& operator[](int j) const
		{
			return (*reinterpret_cast<const vec3*>(_data[j]));
		}
	};

	mat3 operator*(const mat3& A, const mat3& B)
	{
		return {
			A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
			A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
			A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
			A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
			A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
			A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
			A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
			A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
			A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)
		};
	}

	vec3 operator*(const mat3& M, const vec3& v)
	{
		return {
			M(0,0) * v._x + M(0,1) * v._y + M(0,2) * v._z,
			M(1,0) * v._x + M(1,1) * v._y + M(1,2) * v._z,
			M(2,0) * v._x + M(2,1) * v._y + M(2,2) * v._z,
		};
	}

	float determinant(const mat3& M)
	{
		return (M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1))
			+ M(0, 1) * (M(1, 2) * M(2, 0) - M(1, 0) * M(2, 2))
			+ M(0, 2) * (M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0)));
	}

	mat3 inverse(const mat3& M)
	{
		const vec3& a = M[0];
		const vec3& b = M[1];
		const vec3& c = M[2];

		vec3 r0 = cross(b, c);
		vec3 r1 = cross(c, a);
		vec3 r2 = cross(a, b);

		float invDet = 1.f / dot(r2, c);

		return {
			r0._x * invDet, r0._y * invDet, r0._z * invDet,
			r1._x * invDet, r1._y * invDet, r1._z * invDet,
			r2._x * invDet, r2._y * invDet, r2._z * invDet
		};
	}
}