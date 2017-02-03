#pragma once

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

	FzVery(FzSet& ft);

	double GetDOM()const;

	FuzzyTerm* Clone()const;

	void ClearDOM();
	void ORwithDOM(double val);
};

