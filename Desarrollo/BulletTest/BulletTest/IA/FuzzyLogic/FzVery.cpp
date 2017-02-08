#include "FzVery.h"

//Constructor
FzVery::FzVery(FzSet& ft) :m_Set(ft.m_Set) {}

//Devuelve el DOm al cuadrado
double FzVery::GetDOM()const
{
	return m_Set.GetDOM() * m_Set.GetDOM();
}

//Constructor virtual
FuzzyTerm* FzVery::Clone()const {
	return new FzVery(*this);
}

//Limpia el DOM del fuzzySet
void FzVery::ClearDOM() {
	m_Set.ClearDOM();
}

//Llama al ORwithDOM con el valor propio del very (al cuadrado)
void FzVery::ORwithDOM(double val) {
	m_Set.ORwithDOM(val * val); 
}