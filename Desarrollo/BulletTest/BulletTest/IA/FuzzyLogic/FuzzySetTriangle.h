#pragma once

#include "FuzzySet.h"
#include <Util.h>



class FuzzySetTriangle : public FuzzySet
{
private:

	//Valores necesarios para este FuzzySet
	double   m_dPeakPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	//Constructor propio del FuzzySet
	FuzzySetTriangle(double mid, double lft, double rgt);

	//Calcula el valor concreto segun el tipo de FuzzySet que es
	double CalculateDOM(double val)const;
};
