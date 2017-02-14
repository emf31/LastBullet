#pragma once

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>

class FzVery : public FuzzyTerm
{
private:

	FuzzySet& m_Set;

	//Constructor de copia en privado
	FzVery(const FzVery& inst) :m_Set(inst.m_Set) {}

	//Operador igual en privado para que se tenga acceso
	FzVery& operator=(const FzVery&);


public:

	//Constructor del fuzzySet
	FzVery(FzSet& ft);

	//Devuelv el DOM del set
	double GetDOM()const;

	//Constructor virtual
	FuzzyTerm* Clone()const;

	//Limpia el DOM
	void ClearDOM();

	//LLama al ORwithDOM del fuzzyset
	void ORwithDOM(double val);
};

