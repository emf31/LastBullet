#pragma once

#include <iostream>

class Vec2f
{
public:
	float x, y;

	Vec2f();
	Vec2f(float X, float Y);

	bool Zero() {
		return x == 0 && y == 0;
	}

	Vec2f operator*(float scale) const;
	Vec2f operator/(float scale) const;
	Vec2f operator+(const Vec2f &other) const;
	Vec2f operator-(const Vec2f &other) const;
	Vec2f operator*(const Vec2f &other) const;
	Vec2f operator/(const Vec2f &other) const;
	Vec2f operator-() const;

	const Vec2f &operator*=(float scale);
	const Vec2f &operator/=(float scale);
	const Vec2f &operator+=(const Vec2f &other);
	const Vec2f &operator-=(const Vec2f &other);
	const Vec2f &operator*=(const Vec2f &other);
	const Vec2f &operator/=(const Vec2f &other);

	bool operator==(const Vec2f &other) const;
	bool operator!=(const Vec2f &other) const;

	float Magnitude() const;
	float MagnitudeSquared() const;
	void NormalizeThis();
	Vec2f Normalize() const;
	float Dot(const Vec2f &other) const;
	Vec2f Project(const Vec2f &other) const; // Projection of this on to other

	
};

inline float Vec2DDistanceSq(const Vec2f &v1, const Vec2f &v2)
{

	float ySeparation = v2.y - v1.y;
	float xSeparation = v2.x - v1.x;

	return ySeparation*ySeparation + xSeparation*xSeparation;
}


Vec2f operator*(float scale, const Vec2f &v);
std::ostream &operator<<(std::ostream &output, const Vec2f &v);

