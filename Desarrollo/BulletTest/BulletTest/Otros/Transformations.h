#ifndef TRANSFORMATIONS_H
#define TRANSFORMATIONS_H
//------------------------------------------------------------------------
//
//  Name:   Transformations.h
//
//  Desc:   Functions for converting 2D vectors between World and Local
//          space.
//
//  Author: Mat Buckland (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <vector>

#include "vec2f.h"
#include "C2DMatrix.h"
#include "Transformations.h"






//--------------------------- WorldTransform -----------------------------
//
//  given a std::vector of 2D vectors, a position, orientation and scale,
//  this function transforms the 2D vectors into the object's world space
//------------------------------------------------------------------------
inline std::vector<Vec2f> WorldTransform(std::vector<Vec2f> &points,
	const Vec2f   &pos,
	const Vec2f   &forward,
	const Vec2f   &side,
	const Vec2f   &scale)
{
	//copy the original vertices into the buffer about to be transformed
	std::vector<Vec2f> TranVec2fs = points;

	//create a transformation matrix
	C2DMatrix matTransform;

	//scale
	if ((scale.x != 1.0) || (scale.y != 1.0))
	{
		matTransform.Scale(scale.x, scale.y);
	}

	//rotate
	matTransform.Rotate(forward, side);

	//and translate
	matTransform.Translate(pos.x, pos.y);

	//now transform the object's vertices
	matTransform.TransformVec2fs(TranVec2fs);

	return TranVec2fs;
}

//--------------------------- WorldTransform -----------------------------
//
//  given a std::vector of 2D vectors, a position and  orientation
//  this function transforms the 2D vectors into the object's world space
//------------------------------------------------------------------------
inline std::vector<Vec2f> WorldTransform(std::vector<Vec2f> &points,
	const Vec2f   &pos,
	const Vec2f   &forward,
	const Vec2f   &side)
{
	//copy the original vertices into the buffer about to be transformed
	std::vector<Vec2f> TranVec2fs = points;

	//create a transformation matrix
	C2DMatrix matTransform;

	//rotate
	matTransform.Rotate(forward, side);

	//and translate
	matTransform.Translate(pos.x, pos.y);

	//now transform the object's vertices
	matTransform.TransformVec2fs(TranVec2fs);

	return TranVec2fs;
}

//--------------------- PointToWorldSpace --------------------------------
//
//  Transforms a point from the agent's local space into world space
//------------------------------------------------------------------------
inline Vec2f PointToWorldSpace(const Vec2f &point,
	const Vec2f &AgentHeading,
	const Vec2f &AgentSide,
	const Vec2f &AgentPosition)
{
	//make a copy of the point
	Vec2f TransPoint = point;

	//create a transformation matrix
	C2DMatrix matTransform;

	//rotate
	matTransform.Rotate(AgentHeading, AgentSide);

	//and translate
	matTransform.Translate(AgentPosition.x, AgentPosition.y);

	//now transform the vertices
	matTransform.TransformVec2fs(TransPoint);

	return TransPoint;
}

//--------------------- VectorToWorldSpace --------------------------------
//
//  Transforms a vector from the agent's local space into world space
//------------------------------------------------------------------------
inline Vec2f VectorToWorldSpace(const Vec2f &vec,
	const Vec2f &AgentHeading,
	const Vec2f &AgentSide)
{
	//make a copy of the point
	Vec2f TransVec = vec;

	//create a transformation matrix
	C2DMatrix matTransform;

	//rotate
	matTransform.Rotate(AgentHeading, AgentSide);

	//now transform the vertices
	matTransform.TransformVec2fs(TransVec);

	return TransVec;
}


//--------------------- PointToLocalSpace --------------------------------
//
//------------------------------------------------------------------------
inline Vec2f PointToLocalSpace(const Vec2f &point,
	Vec2f &AgentHeading,
	Vec2f &AgentSide,
	Vec2f &AgentPosition)
{

	//make a copy of the point
	Vec2f TransPoint = point;

	//create a transformation matrix
	C2DMatrix matTransform;

	double Tx = -AgentPosition.Dot(AgentHeading);
	double Ty = -AgentPosition.Dot(AgentSide);

	//create the transformation matrix
	matTransform._11(AgentHeading.x); matTransform._12(AgentSide.x);
	matTransform._21(AgentHeading.y); matTransform._22(AgentSide.y);
	matTransform._31(Tx);           matTransform._32(Ty);

	//now transform the vertices
	matTransform.TransformVec2fs(TransPoint);

	return TransPoint;
}

//--------------------- VectorToLocalSpace --------------------------------
//
//------------------------------------------------------------------------
inline Vec2f VectorToLocalSpace(const Vec2f &vec,
	const Vec2f &AgentHeading,
	const Vec2f &AgentSide)
{

	//make a copy of the point
	Vec2f TransPoint = vec;

	//create a transformation matrix
	C2DMatrix matTransform;

	//create the transformation matrix
	matTransform._11(AgentHeading.x); matTransform._12(AgentSide.x);
	matTransform._21(AgentHeading.y); matTransform._22(AgentSide.y);

	//now transform the vertices
	matTransform.TransformVec2fs(TransPoint);

	return TransPoint;
}

//-------------------------- Vec2DRotateAroundOrigin --------------------------
//
//  rotates a vector ang rads around the origin
//-----------------------------------------------------------------------------
inline void Vec2DRotateAroundOrigin(Vec2f& v, double ang)
{
	//create a transformation matrix
	C2DMatrix mat;

	//rotate
	mat.Rotate(ang);

	//now transform the object's vertices
	mat.TransformVec2fs(v);
}

//------------------------ CreateWhiskers ------------------------------------
//
//  given an origin, a facing direction, a 'field of view' describing the 
//  limit of the outer whiskers, a whisker length and the number of whiskers
//  this method returns a vector containing the end positions of a series
//  of whiskers radiating away from the origin and with equal distance between
//  them. (like the spokes of a wheel clipped to a specific segment size)
//----------------------------------------------------------------------------
inline std::vector<Vec2f> CreateWhiskers(unsigned int  NumWhiskers,
	double        WhiskerLength,
	double        fov,
	Vec2f      facing,
	Vec2f      origin)
{
	//this is the magnitude of the angle separating each whisker
	double SectorSize = fov / (double)(NumWhiskers - 1);

	std::vector<Vec2f> whiskers;
	Vec2f temp;
	double angle = -fov*0.5;

	for (unsigned int w = 0; w<NumWhiskers; ++w)
	{
		//create the whisker extending outwards at this angle
		temp = facing;
		Vec2DRotateAroundOrigin(temp, angle);
		whiskers.push_back(origin + WhiskerLength * temp);

		angle += SectorSize;
	}

	return whiskers;
}


#endif