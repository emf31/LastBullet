#include "FzFairly.h"

FzFairly::FzFairly(FzSet& ft) :m_Set(ft.m_Set) {}

double FzFairly::GetDOM()const
{
	return sqrt(m_Set.GetDOM());
}

FuzzyTerm* FzFairly::Clone()const {
	return new FzFairly(*this); 
}

void FzFairly::ClearDOM() {
	m_Set.ClearDOM(); 
}

void FzFairly::ORwithDOM(double val) {
	m_Set.ORwithDOM(sqrt(val)); 
}