#pragma once

#include "FuzzySet.h"
#include "FuzzyTerm.h"
#include "FzSet.h"
#include <math.h>




class FzFairly : public FuzzyTerm
{
private:
	//Fuzzy set del termino
	FuzzySet& m_Set;

	//Constructor de copia en privado para no ser accedido desde fuera
	FzFairly(const FzFairly& inst) :m_Set(inst.m_Set) {}

	//No es necesario el operador de igual
	FzFairly& operator=(const FzFairly&);

public:

	//Constructor con fuzzy set
	FzFairly(FzSet& ft);

	//Devuelve el dom del fuzzySet
	double GetDOM()const;
	
	//Constructor virtual
	FuzzyTerm* Clone()const;

	//Limpia el dom de fuzzyset
	void ClearDOM();

	//Llamas al ORwithDOM del fuzzySet
	void ORwithDOM(double val);


};

