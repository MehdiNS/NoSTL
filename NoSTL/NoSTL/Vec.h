#pragma once
#include "MathUtils.h"
#include <cassert>

namespace nostd {
struct vec3 {
  float _x, _y, _z;

  vec3() = default;
  vec3(float x, float y, float z) : _x{x}, _y{y}, _z{z} {}
  float &operator[](int i) {
    assert(i >= 0 && i < 4);
    return ((&_x)[i]);
  }
  const float &operator[](int i) const {
    assert(i >= 0 && i < 4);
    return ((&_x)[i]);
  }
  vec3 &operator*=(float s) {
    _x *= s;
    _y *= s;
    _z *= s;
    return (*this);
  }
  vec3 &operator/=(float s) {
    s = 1.f / s;
    _x *= s;
    _y *= s;
    _z *= s;
    return (*this);
  }
  vec3 &operator+=(const vec3 &v) {
    _x += v._x;
    _y += v._y;
    _z += v._z;
    return (*this);
  }
  vec3 &operator-=(const vec3 &v) {
    _x -= v._x;
    _y -= v._y;
    _z -= v._z;
    return (*this);
  }
};

inline bool operator==(const vec3 &a, const vec3 &b) {
  return (a._x == b._x && a._y == b._y && a._z == b._z);
}
inline bool operator!=(const vec3 &a, const vec3 &b) { return !(a == b); }
inline vec3 operator+(const vec3 &a, const vec3 &b) {
  return {a._x + b._x, a._y + b._y, a._z + b._z};
}
inline vec3 operator-(const vec3 &a, const vec3 &b) {
  return {a._x - b._x, a._y - b._y, a._z - b._z};
}
inline vec3 operator*(const vec3 &v, float s) {
  return {v._x * s, v._y * s, v._z * s};
}
inline vec3 operator/(const vec3 &v, float s) {
  s = 1.f / s;
  return {v._x * s, v._y * s, v._z * s};
}
inline vec3 operator-(const vec3 &v) { return {-v._x, -v._y, -v._z}; }
inline float squaredLength(const vec3 &v) {
  return v._x * v._x + v._y * v._y + v._z * v._z;
}
inline float length(const vec3 &v) { return sqrt(squaredLength(v)); }
inline float invLength(const vec3 &v) { return 1.f / sqrt(squaredLength(v)); }
inline vec3 normalize(const vec3 &v) { return v * invLength(v); }
inline float dot(const vec3 &a, const vec3 &b) {
  return (a._x * b._x + a._y * b._y + a._z * b._z);
}
inline vec3 cross(const vec3 &a, const vec3 &b) {
  return {a._y * b._z - a._z * b._y, a._z * b._x - a._x * b._z,
          a._x * b._y - a._y * b._x};
}
inline vec3 project(const vec3 &a, const vec3 &b) {
  return {b * (dot(a, b) / dot(b, b))};
}
inline vec3 reject(const vec3 &a, const vec3 &b) {
  return {a - b * (dot(a, b) / dot(b, b))};
}
} // namespace nostd
