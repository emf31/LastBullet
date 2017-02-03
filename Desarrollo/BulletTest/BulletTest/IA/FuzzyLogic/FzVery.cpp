#include "FzVery.h"

FzVery::FzVery(FzSet& ft) :m_Set(ft.m_Set) {}

double FzVery::GetDOM()const
{
	return m_Set.GetDOM() * m_Set.GetDOM();
}

FuzzyTerm* FzVery::Clone()const {
	return new FzVery(*this);
}

void FzVery::ClearDOM() {
	m_Set.ClearDOM();
}

void FzVery::ORwithDOM(double val) {
	m_Set.ORwithDOM(val * val); 
}