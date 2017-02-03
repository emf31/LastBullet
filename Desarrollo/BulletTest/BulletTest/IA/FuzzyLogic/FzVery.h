#ifndef FUZZY_VERY_H
#define FUZZY_VERY_H

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>

class FzVery : public FuzzyTerm
{
private:

	FuzzySet& m_Set;

	//prevent copying and assignment by clients
	FzVery(const FzVery& inst) :m_Set(inst.m_Set) {}
	FzVery& operator=(const FzVery&);


public:

	FzVery(FzSet& ft) :m_Set(ft.m_Set) {}

	double GetDOM()const
	{
		return m_Set.GetDOM() * m_Set.GetDOM();
	}

	FuzzyTerm* Clone()const { return new FzVery(*this); }

	void ClearDOM() { m_Set.ClearDOM(); }
	void ORwithDOM(double val) { m_Set.ORwithDOM(val * val); }
};

#endif

