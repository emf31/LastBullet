#include "Util.h"
#include <ctime>

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

int Randi()
{
	std::srand(std::time(0));
	return std::rand();
}

int Randi(int min, int max)
{
	return Randi() % (max - min + 1) + min;
}

float clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}

btVector3 bt(const Vec3<float>& vec)
{
	return btVector3(vec.getX(), vec.getY(), vec.getZ());
}

Vec3<float> cons(const btVector3 & bt)
{
	return Vec3<float>(bt.getX(), bt.getY(), bt.getZ());
}

Vec2f vec3ToVec2(const Vec3<float>& vec)
{
	return Vec2f(vec.getX(),vec.getZ());
}


