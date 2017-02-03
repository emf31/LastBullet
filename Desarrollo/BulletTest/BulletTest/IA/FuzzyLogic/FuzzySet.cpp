#include "FuzzySet.h"

FuzzySet::FuzzySet(double RepVal) :m_dDOM(0.0), m_dRepresentativeValue(RepVal) {}

void FuzzySet::ORwithDOM(double val) {
	if (val > m_dDOM) 
		m_dDOM = val;
}

double FuzzySet::GetRepresentativeVal()const { 
	return m_dRepresentativeValue; 
}

void FuzzySet::ClearDOM() {
	m_dDOM = 0.0;
}

double FuzzySet::GetDOM()const {
	return m_dDOM; 
}

void  FuzzySet::SetDOM(double val){
	assert((val <= 1) && (val >= 0) && "<FuzzySet::SetDOM>: invalid value");
	m_dDOM = val;
}