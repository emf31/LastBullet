#pragma once

#include "FuzzySet.h"
#include <Util.h>



class FuzzySetLeftShoulder : public FuzzySet
{
private:

	//Valores necesarios para este FuzzySet
	double   m_dPeakPoint;
	double   m_dRightOffset;
	double   m_dLeftOffset;

public:

	//Constructor propio del FuzzySet
	FuzzySetLeftShoulder(double peak, double LeftOffset, double RightOffset);

	//Calcula el valor concreto segun el tipo de FuzzySet que es
	double CalculateDOM(double val)const;


};

