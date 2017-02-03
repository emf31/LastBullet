#pragma once

#include "FuzzySet.h"
#include <Util.h>
//#include "misc/utils.h"



class FuzzySetLeftShoulder : public FuzzySet
{
private:

	//the values that define the shape of this FLV
	double   m_dPeakPoint;
	double   m_dRightOffset;
	double   m_dLeftOffset;

public:

	FuzzySetLeftShoulder(double peak, double LeftOffset, double RightOffset);

	//this method calculates the degree of membership for a particular value
	double CalculateDOM(double val)const;


};

