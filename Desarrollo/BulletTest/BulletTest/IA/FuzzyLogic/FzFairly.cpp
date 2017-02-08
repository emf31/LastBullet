#include "FzFairly.h"

//COnstructor
FzFairly::FzFairly(FzSet& ft) :m_Set(ft.m_Set) {}

//Devuelve el DOM de fairly del set (con la raiz cuadrada)
double FzFairly::GetDOM()const
{
	return sqrt(m_Set.GetDOM());
}

//Constructor virtual
FuzzyTerm* FzFairly::Clone()const {
	return new FzFairly(*this); 
}

//Limpias el DOm
void FzFairly::ClearDOM() {
	m_Set.ClearDOM(); 
}

//Seteas DOM con el sqrt al fuzzyset
void FzFairly::ORwithDOM(double val) {
	m_Set.ORwithDOM(sqrt(val)); 
}