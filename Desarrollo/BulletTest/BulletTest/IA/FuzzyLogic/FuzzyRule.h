#pragma once


#include <vector>
#include "FuzzySet.h"
#include "FzOR.h"
#include "FzAND.h"


class FuzzyRule
{
private:

	//Termino antecendente
	const FuzzyTerm*  m_pAntecedent;

	//Termino consecuencia
	FuzzyTerm*        m_pConsequence;

	//Constructor de copia privado para que no pueda ser usado por clientes
	FuzzyRule(const FuzzyRule&);
	FuzzyRule& operator=(const FuzzyRule&);


public:

	//constructor
	FuzzyRule(const FuzzyTerm& ant, const FuzzyTerm& con);

	//destructor
	~FuzzyRule();

	//clean
	void SetConfidenceOfConsequentToZero();

	//calcula las respuestas
	void Calculate();
};

