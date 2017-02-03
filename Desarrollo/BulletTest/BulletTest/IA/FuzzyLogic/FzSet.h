#pragma once

#include "FuzzyTerm.h"
#include "FuzzySet.h"

class FzAND;

class FzSet : public FuzzyTerm
{
private:

	//let the hedge classes be friends 
	friend class FzVery;
	friend class FzFairly;

private:

	//a reference to the fuzzy set this proxy represents
	FuzzySet& m_Set;

public:

	FzSet(FuzzySet& fs);

	FuzzyTerm* Clone()const;
	double     GetDOM()const;
	void       ClearDOM();
	void       ORwithDOM(double val);
};


