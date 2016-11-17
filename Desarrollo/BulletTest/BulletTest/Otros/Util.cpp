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
