#pragma once

#include "FuzzySet.h"
#include <Util.h>



class FuzzySetSingleton : public FuzzySet
{
private:

	//the values that define the shape of this FLV
	double   m_dMidPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	FuzzySetSingleton(double mid,double lft, double rgt);

	//this method calculates the degree of membership for a particular value
	double     CalculateDOM(double val)const;
};

