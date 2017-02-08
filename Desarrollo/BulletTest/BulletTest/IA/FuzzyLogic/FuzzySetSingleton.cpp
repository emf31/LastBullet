#include "FuzzySetSingleton.h"

//Constructor
FuzzySetSingleton::FuzzySetSingleton(double       mid,
	double       lft,
	double       rgt) :FuzzySet(mid),
	m_dMidPoint(mid),
	m_dLeftOffset(lft),
	m_dRightOffset(rgt)
{};

double FuzzySetSingleton::CalculateDOM(double val)const
{
	if ((val >= m_dMidPoint - m_dLeftOffset) &&
		(val <= m_dMidPoint + m_dRightOffset))
	{
		return 1.0;
	}

	//out of range of this FLV, return zero
	else
	{
		return 0.0;
	}
}