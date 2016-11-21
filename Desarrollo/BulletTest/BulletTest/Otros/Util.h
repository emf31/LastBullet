#pragma once
#define _USE_MATH_DEFINES	//Asi puedo usar pi
#include <math.h>
#include <random>

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include "vec3.hpp"


const float pif = static_cast<float>(M_PI);
const float degToRadMultiplier = pif / 180.0f;

float DegToRad(float deg);
float RadToDeg(float rad);

float absf(float val);

float Lerp(float first, float second, float interpolation);

float Randf();

float Randf(float min, float max);



btVector3 bt(const Vec3<float> &vec);

Vec3<float> cons(const btVector3 &bt);
