#pragma once

#include <vector>
#include <cassert>
#include "FuzzyTerm.h"
#include <Util.h>

class FzOR : public FuzzyTerm
{
private:

	//Vector de terminos de OR
	std::vector<FuzzyTerm*> m_Terms;

	//asignamiento con igual no es necesario y se declara privado
	FzOR& operator=(const FzOR&);

public:

	~FzOR();

	//Constructor de copia
	FzOR(const FzOR& fa);

	//Todos los constructores por terminos
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzOR(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//Constructor Virtual
	FuzzyTerm* Clone()const;

	double GetDOM()const;

	//No se usan pero vienen de virtual asi que hay que implementarlos
	void ClearDOM();
	void ORwithDOM(double val);
};
