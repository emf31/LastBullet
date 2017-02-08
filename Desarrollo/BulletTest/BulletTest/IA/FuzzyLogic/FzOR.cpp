#include "fzOR.h"

//Destructor deletea todos los terminos del vector
FzOR::~FzOR()
{
	std::vector<FuzzyTerm*>::iterator curTerm;
	for (curTerm = m_Terms.begin(); curTerm != m_Terms.end(); ++curTerm)
	{
		delete *curTerm;
	}
}

//Constructor de copia
FzOR::FzOR(const FzOR& fa)
{
	std::vector<FuzzyTerm*>::const_iterator curTerm;
	for (curTerm = fa.m_Terms.begin(); curTerm != fa.m_Terms.end(); ++curTerm)
	{
		m_Terms.push_back((*curTerm)->Clone());
	}
}

//Constructores de terminos
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

//Constructor virtual
FuzzyTerm* FzOR::Clone()const { return new FzOR(*this); }

//Devuelve el DOM mas alto
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

//Sin unsar y solo devuelven mensaje en caso de error
void FzOR::ClearDOM() { assert(0 && "<FzOR::ClearDOM>: invalid context"); }
void FzOR::ORwithDOM(double val) { assert(0 && "<FzOR::ORwithDOM>: invalid context"); }