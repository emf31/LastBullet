#pragma once

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

	FzFairly(FzSet& ft);

	double GetDOM()const;
	FuzzyTerm* Clone()const;

	void ClearDOM();
	void ORwithDOM(double val);


};

