#include "FuzzyRule.h"

FuzzyRule::FuzzyRule(const FuzzyTerm& ant,
	const FuzzyTerm& con) :m_pAntecedent(ant.Clone()),
	m_pConsequence(con.Clone())
{}

FuzzyRule::~FuzzyRule() {
	delete m_pAntecedent; delete m_pConsequence; 
}

void FuzzyRule::SetConfidenceOfConsequentToZero() {
	m_pConsequence->ClearDOM();
}

void FuzzyRule::Calculate()
{
	m_pConsequence->ORwithDOM(m_pAntecedent->GetDOM());
}