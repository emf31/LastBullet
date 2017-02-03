#include "fzOR.h"

FzOR::~FzOR()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

//copy ctor
FzOR::FzOR(const FzOR& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.m_Terms.begin(); curTerm != fa.m_Terms.end(); ++curTerm)
	{
		m_Terms.push_back((*curTerm)->Clone());
	}
}
//ctors accepting fuzzy terms.
FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
}

FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
	m_Terms.push_back(op3.Clone());
}
FzOR::FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4)
{
	m_Terms.push_back(op1.Clone());
	m_Terms.push_back(op2.Clone());
	m_Terms.push_back(op3.Clone());
	m_Terms.push_back(op4.Clone());
}

//virtual ctor
FuzzyTerm* FzOR::Clone()const { return new FzOR(*this); }

double FzOR::GetDOM()const
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
void FzOR::ClearDOM() { assert(0 && "<FzOR::ClearDOM>: invalid context"); }
void FzOR::ORwithDOM(double val) { assert(0 && "<FzOR::ORwithDOM>: invalid context"); }