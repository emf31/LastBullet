#ifndef FUZZY_AND_H
#define FUZZY_AND_H

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

	~FzAND()
	{
		std::vector<FuzzyTerm*>::iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			delete *curTerm;
		}
	}

	//copy ctor
	FzAND(const FzAND& fa)
	{
		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = fa.m_Terms.begin(); curTerm != fa.m_Terms.end(); ++curTerm)
		{
			m_Terms.push_back((*curTerm)->Clone());
		}
	}

	//ctors accepting fuzzy terms.
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
	}
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
		m_Terms.push_back(op3.Clone());
	}
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
	{
		m_Terms.push_back(op1.Clone());
		m_Terms.push_back(op2.Clone());
		m_Terms.push_back(op3.Clone());
		m_Terms.push_back(op4.Clone());
	}

	//virtual ctor
	FuzzyTerm* Clone()const { return new FzAND(*this); }

	double GetDOM()const
	{
		double smallest = MaxDouble;

		std::vector<FuzzyTerm*>::const_iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			if ((*curTerm)->GetDOM() < smallest)
			{
				smallest = (*curTerm)->GetDOM();
			}
		}

		return smallest;
	}

	void  ClearDOM()
	{
		std::vector<FuzzyTerm*>::iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			(*curTerm)->ClearDOM();
		}
	}

	void  ORwithDOM(double val)
	{
		std::vector<FuzzyTerm*>::iterator curTerm;
		for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
		{
			(*curTerm)->ORwithDOM(val);
		}
	}
};

#endif