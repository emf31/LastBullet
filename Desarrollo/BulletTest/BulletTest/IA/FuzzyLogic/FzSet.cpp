#include "fzSet.h"

FzSet::FzSet(FuzzySet& fs) :m_Set(fs) {}

FuzzyTerm* FzSet::Clone()const {
	return new FzSet(*this);
}

double FzSet::GetDOM()const {
	return m_Set.GetDOM();
}

void FzSet::ClearDOM() {
	m_Set.ClearDOM();
}

void FzSet::ORwithDOM(double val) {
	m_Set.ORwithDOM(val);
}