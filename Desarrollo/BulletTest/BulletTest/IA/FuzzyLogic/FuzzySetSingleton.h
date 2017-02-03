#ifndef FUZZYSET_SINGLETON_H
#define FUZZYSET_SINGLETON_H

#include "FuzzySet.h"
//#include "misc/utils.h"



class FuzzySet_Singleton : public FuzzySet
{
private:

	//the values that define the shape of this FLV
	double   m_dMidPoint;
	double   m_dLeftOffset;
	double   m_dRightOffset;

public:

	FuzzySet_Singleton(double       mid,
		double       lft,
		double       rgt) :FuzzySet(mid),
		m_dMidPoint(mid),
		m_dLeftOffset(lft),
		m_dRightOffset(rgt)
	{}

	//this method calculates the degree of membership for a particular value
	double     CalculateDOM(double val)const
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

};


#endif
