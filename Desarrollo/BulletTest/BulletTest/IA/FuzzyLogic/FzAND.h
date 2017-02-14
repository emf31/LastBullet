#pragma once

#include <vector>
#include <cassert>
#include "FuzzyTerm.h"
#include <Util.h>

class FzAND : public FuzzyTerm
{
private:

	//vector de terminos de AND
	std::vector<FuzzyTerm*> m_Terms;

	//No necesitas el operador igual asi que lo declaras privado
	FzAND& operator=(const FzAND&);

public:
	//Destructor
	~FzAND();

	//Constructor de copia
	FzAND(const FzAND& fa);

	//Constructores de con los terminos
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3);
	FzAND(FuzzyTerm& op1, FuzzyTerm& op2, FuzzyTerm& op3, FuzzyTerm& op4);

	//Construtor Virtual
	FuzzyTerm* Clone()const;

	//Devuelve el DOM
	double GetDOM()const;

	//Limpia el DOM
	void  ClearDOM();

	//LLamas a la funcion con el mismo nombre de todas los terminos
	void  ORwithDOM(double val);
};
