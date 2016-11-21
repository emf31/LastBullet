#include "Util.h"

float DegToRad(float deg)
{
	return deg * degToRadMultiplier;
}

float RadToDeg(float rad)
{
	return rad / degToRadMultiplier;
}

float absf(float val)
{
	if (val > 0)
		return val;
	else
		return -val;
}

float Lerp(float first, float second, float interpolation)
{
	return first + (second - first) * interpolation;
}

float Randf()
{
	return rand() / static_cast<float>(RAND_MAX);
}
float Randf(float min, float max)
{
	return min + Randf() * (max - min);
}

btVector3 bt(const Vec3<float>& vec)
{
	return btVector3(vec.getX(), vec.getY(), vec.getZ());
}

Vec3<float> cons(const btVector3 & bt)
{
	return Vec3<float>(bt.getX(), bt.getY(), bt.getZ());
}
