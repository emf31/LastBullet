#include "fzSet.h"

//Constructor
FzSet::FzSet(FuzzySet& fs) :m_Set(fs) {}

//COnstructor virtual
FuzzyTerm* FzSet::Clone()const {
	return new FzSet(*this);
}

//Obtiene el DOM
double FzSet::GetDOM()const {
	return m_Set.GetDOM();
}

//Limpia el DOM
void FzSet::ClearDOM() {
	m_Set.ClearDOM();
}

//Setea el DOM
void FzSet::ORwithDOM(double val) {
	m_Set.ORwithDOM(val);
}