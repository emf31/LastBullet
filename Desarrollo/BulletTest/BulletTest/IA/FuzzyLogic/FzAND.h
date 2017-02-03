#pragma once

#include <vector>
#include <cassert>
#include "FuzzyTerm.h"
#include <Util.h>

class FzAND : public FuzzyTerm
{
private:

	//an instance of this class may AND together up to 4 terms
	std::vector<FuzzyTerm*> m_Terms;

	//disallow assignment
	FzAND& operator=(const FzAND&);

public:

	~FzAND();
	//copy ctor
	FzAND(const FzAND& fa);

	//ctors accepting fuzzy terms.
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//virtual ctor
	FuzzyTerm* Clone()const;

	double GetDOM()const;

	void  ClearDOM();

	void  ORwithDOM(double val);
};
