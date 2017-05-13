#pragma once
#define _USE_MATH_DEFINES	//Asi puedo usar pi
#include <math.h>
#include <random>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include "vec3.hpp"
#include <Vec2f.h>

#include <algorithm>

//! float constant para convertir de rad a deg
const float RADTODEG = 180.0f / (float)M_PI;

const float pif = static_cast<float>(M_PI);
const float degToRadMultiplier = pif / 180.0f;
const double  MaxDouble = (std::numeric_limits<double>::max)();
const double   MinDouble = (std::numeric_limits<double>::min)();

float DegToRad(float deg);
float RadToDeg(float rad);

float absf(float val);

float Lerp(float first, float second, float interpolation);

float Randf();

float Randf(float min, float max);

int Randi();

int Randi(int min, int max);


float clip(float n, float lower, float upper);

bool compareVec3(const Vec3<float>& lhs, const Vec3<float>& rhs);


btVector3 bt(const Vec3<float> &vec);

Vec3<float> cons(const btVector3 &bt);

Vec2f vec3ToVec2(const Vec3<float> &vec);

inline bool isEqual(float a, float b)
{
	if (fabs(a - b) < 1E-12)
	{
		return true;
	}

	return false;
}


inline bool isEqual(double a, double b)
{
	if (fabs(a - b) < 1E-12)
	{
		return true;
	}

	return false;
}




template <class T>
inline T MinOf(const T& a, const T& b)
{
	if (a<b) 
		return a; 
	
	return b;
}
