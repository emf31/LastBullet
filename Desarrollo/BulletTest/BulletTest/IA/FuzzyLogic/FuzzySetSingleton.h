#pragma once

#include "FuzzySet.h"
#include <Util.h>



class FuzzySetSingleton : public FuzzySet
{
private:

	//Valores necesarios para este FuzzySet
	double   m_dMidPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	//Constructor propio del FuzzySet
	FuzzySetSingleton(double mid,double lft, double rgt);

	//Calcula el valor concreto segun el tipo de FuzzySet que es
	double     CalculateDOM(double val)const;
};

