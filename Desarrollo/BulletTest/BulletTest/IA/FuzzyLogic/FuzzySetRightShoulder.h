#pragma once
#include "FuzzySet.h"


class FuzzySetRightShoulder : public FuzzySet
{
private:

	//Valores necesarios para este FuzzySet
	double   m_dPeakPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	//Constructor propio del FuzzySet
	FuzzySetRightShoulder(double peak, double LeftOffset, double RightOffset);

	//Calcula el valor concreto segun el tipo de FuzzySet que es
	double CalculateDOM(double val)const;


};


