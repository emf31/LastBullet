#ifndef FUZZY_FAIRLY_H
#define FUZZY_FAIRLY_H

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>

class FzFairly : public FuzzyTerm
{
private:

	FuzzySet& m_Set;

	//prevent copying and assignment
	FzFairly(const FzFairly& inst) :m_Set(inst.m_Set) {}
	FzFairly& operator=(const FzFairly&);

public:

	FzFairly(FzSet& ft) :m_Set(ft.m_Set) {}

	double GetDOM()const
	{
		return sqrt(m_Set.GetDOM());
	}

	FuzzyTerm* Clone()const { return new FzFairly(*this); }

	void ClearDOM() { m_Set.ClearDOM(); }
	void ORwithDOM(double val) { m_Set.ORwithDOM(sqrt(val)); }
};



#endif
