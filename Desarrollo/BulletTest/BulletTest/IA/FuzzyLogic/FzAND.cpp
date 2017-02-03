#include "FzAND.h"

FzAND::~FzAND()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

//copy ctor
FzAND::FzAND(const FzAND& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.m_Terms.begin(); curTerm != fa.m_Terms.end(); ++curTerm)
	{
		m_Terms.push_back((*curTerm)->Clone());
	}
}

//ctors accepting fuzzy terms.
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
}
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
	m_Terms.push_back(op3.Clone());
}
FzAND::FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
	m_Terms.push_back(op3.Clone());
	m_Terms.push_back(op4.Clone());
}

//virtual ctor
FuzzyTerm* FzAND::Clone()const { return new FzAND(*this); }

double FzAND::GetDOM()const
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

void FzAND::ClearDOM()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
	{
		(*curTerm)->ClearDOM();
	}
}

void  FzAND::ORwithDOM(double val)
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
	{
		(*curTerm)->ORwithDOM(val);
	}
}