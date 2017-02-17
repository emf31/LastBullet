#include "FuzzyRule.h"

//constructor
FuzzyRule::FuzzyRule(const FuzzyTerm& ant,
	const FuzzyTerm& con) :m_pAntecedent(ant.Clone()),
	m_pConsequence(con.Clone())
{}

//destructor
FuzzyRule::~FuzzyRule() {
	delete m_pAntecedent; delete m_pConsequence; 
}

//Limpiar el Dom
void FuzzyRule::SetConfidenceOfConsequentToZero() {
	m_pConsequence->ClearDOM();
}

//Calcula la regla con el DOM
void FuzzyRule::Calculate()
{
	m_pConsequence->ORwithDOM(m_pAntecedent->GetDOM());
}