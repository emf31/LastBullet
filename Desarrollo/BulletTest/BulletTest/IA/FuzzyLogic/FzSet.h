#pragma once

#include "FuzzyTerm.h"
#include "FuzzySet.h"

class FzAND;

class FzSet : public FuzzyTerm
{
private:

	//Las clases edge son clases amigas para su uso
	friend class FzVery;
	friend class FzFairly;

	//Referencia al fuzzyset que representa
	FuzzySet& m_Set;

public:

	//COnstructor con el fuzzyset que hace referencia
	FzSet(FuzzySet& fs);

	//Constructor Virtual
	FuzzyTerm* Clone()const;

	//Obtiene el DOM
	double     GetDOM()const;

	//Limpia el DOM
	void       ClearDOM();

	//LLama al OR with DOM del fuzzySet
	void       ORwithDOM(double val);
};


