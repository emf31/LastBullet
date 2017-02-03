#pragma once
#include "FuzzySet.h"

//#include "misc/utils.h"



class FuzzySetRightShoulder : public FuzzySet
{
private:

	//the values that define the shape of this FLV
	double   m_dPeakPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	FuzzySetRightShoulder(double peak, double LeftOffset, double RightOffset);

	//this method calculates the degree of membership for a particular value
	double CalculateDOM(double val)const;


};


