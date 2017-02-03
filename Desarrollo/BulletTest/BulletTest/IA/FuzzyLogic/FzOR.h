#ifndef FUZZY_OR_H
#define FUZZY_OR_H

#include <vector>
#include <cassert>
#include "FuzzyTerm.h"

class FzOR : public FuzzyTerm
{
private:

	//an instance of this class may AND together up to 4 terms
	std::vector<FuzzyTerm*> m_Terms;

	//no assignment op necessary
	FzOR& operator=(const FzOR&);

public:

	~FzOR()
	{
		std::vector<FuzzyTerm*>::iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			delete *curTerm;
		}
	}

	//copy ctor
	FzOR(const FzOR& fa)
	{
		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = fa.m_Terms.begin(); curTerm != fa.m_Terms.end(); ++curTerm)
		{
			m_Terms.push_back((*curTerm)->Clone());
		}

	//ctors accepting fuzzy terms.
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
	}

	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
		m_Terms.push_back(op3.Clone());
	}
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
		m_Terms.push_back(op3.Clone());
		m_Terms.push_back(op4.Clone());
	}

	//virtual ctor
	FuzzyTerm* Clone()const { return new FzOR(*this); }

	double GetDOM()const
	{
		double largest = MinDouble;

		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			if ((*curTerm)->GetDOM() > largest)
			{
				largest = (*curTerm)->GetDOM();
			}
		}

		return largest;
	}

	//unused
	void ClearDOM() { assert(0 && "<FzOR::ClearDOM>: invalid context"); }
	void ORwithDOM(double val) { assert(0 && "<FzOR::ORwithDOM>: invalid context"); }
};
#endif
