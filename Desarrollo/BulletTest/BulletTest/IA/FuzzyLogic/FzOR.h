#pragma once

#include <vector>
#include <cassert>
#include "FuzzyTerm.h"
#include <Util.h>

class FzOR : public FuzzyTerm
{
private:

	//an instance of this class may AND together up to 4 terms
	std::vector<FuzzyTerm*> m_Terms;

	//no assignment op necessary
	FzOR& operator=(const FzOR&);

public:

	~FzOR();

	//copy ctor
	FzOR(const FzOR& fa);
	//ctors accepting fuzzy terms.
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2);

	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//virtual ctor
	FuzzyTerm* Clone()const;

	double GetDOM()const;

	//unused
	void ClearDOM();
	void ORwithDOM(double val);
};
