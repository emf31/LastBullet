#include "FuzzySet.h"

//Constructor, el dom se inicializa en 0
FuzzySet::FuzzySet(double RepVal) :m_dDOM(0.0), m_dRepresentativeValue(RepVal) {}

void FuzzySet::ORwithDOM(double val) {
	if (val > m_dDOM) 
		m_dDOM = val;
}

//Obtener el Valor representativo de fuzzySet
double FuzzySet::GetRepresentativeVal()const { 
	return m_dRepresentativeValue; 
}

//Limpiar el DOM
void FuzzySet::ClearDOM() {
	m_dDOM = 0.0;
}

//Obtener el DOM
double FuzzySet::GetDOM()const {
	return m_dDOM; 
}

//Setear el DOM, tiene que ser entre 0 y 1
void  FuzzySet::SetDOM(double val){
	assert((val <= 1) && (val >= 0) && "<FuzzySet::SetDOM>: invalid value");
	m_dDOM = val;
}