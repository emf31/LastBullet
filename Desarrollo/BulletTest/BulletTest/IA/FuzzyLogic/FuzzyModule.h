#pragma once
#pragma warning (disable:4786)

#include <vector>
#include <string>
#include <map>
#include <iosfwd>

#include "FuzzySet.h"
#include "FuzzyVariable.h"
#include "FuzzyRule.h"
#include "FzOR.h"
#include "FzAND.h"
#include "FzSet.h"
#include "FzVery.h"
#include "FzFairly.h"



class FuzzyModule
{

private:

	typedef std::map<std::string, FuzzyVariable*> VarMap;

	//mapa de vairables que se define con un typedef
	VarMap m_Variables;

	//a vector containing all the fuzzy rules
	std::vector<FuzzyRule*>   m_Rules;


	//Metodo que se usa en deffuzify, sirve para limpiar DOM
	inline void SetConfidencesOfConsequentsToZero();


public:

	//Metodos que se pueden realizar para defuzzificar, por ahora solo hay maxaverage y centroid
	enum DefuzzifyMethod { max_av, centroid };

	//enumeracion para calcular el centroid
	enum { NumSamples = 15 };

	//destrucctor
	~FuzzyModule();

	//Crea las variables y las mete en el mapa
	FuzzyVariable&  CreateFLV(const std::string& VarName);

	//añade reglas al vector de reglas
	void AddRule(FuzzyTerm& antecedent, FuzzyTerm& consequence);

	//Fuzzifica las variable que tenga el mismo nombre que la key
	inline void     Fuzzify(const std::string& NameOfFLV, double val);

	//Dada la key deffuzzifica (de normal lo hace con max_average)
	inline double    DeFuzzify(const std::string& key,
		DefuzzifyMethod    method = max_av);


	//Escribe todos los dom
	std::ostream&   WriteAllDOMs(std::ostream& os);

};

///////////////////////////////////////////////////////////////////////////////

//----------------------------- Fuzzify ---------------------------------------

//  Llama al metod de fuzzify del que le pasan la key

inline void FuzzyModule::Fuzzify(const std::string& NameOfFLV, double val)
{
	//first make sure the key exists
	assert((m_Variables.find(NameOfFLV) != m_Variables.end()) &&
		"<FuzzyModule::Fuzzify>:key not found");

	m_Variables[NameOfFLV]->Fuzzify(val);
}

//---------------------------- DeFuzzify --------------------------------------

//  Defuzzifica segun la key que le pasan y el metodo

inline double
FuzzyModule::DeFuzzify(const std::string& NameOfFLV, DefuzzifyMethod method)
{
	assert((m_Variables.find(NameOfFLV) != m_Variables.end()) &&
		"<FuzzyModule::DeFuzzifyMaxAv>:key not found");

	SetConfidencesOfConsequentsToZero();

	std::vector<FuzzyRule*>::iterator curRule = m_Rules.begin();
	for (curRule; curRule != m_Rules.end(); ++curRule)
	{
		(*curRule)->Calculate();
	}

	switch (method)
	{
	case centroid:

		return m_Variables[NameOfFLV]->DeFuzzifyCentroid(NumSamples);

		break;

	case max_av:

		return m_Variables[NameOfFLV]->DeFuzzifyMaxAv();

		break;
	}

	return 0;
}



//-------------------------- SetConfidenceOfConsequentToZero ---------------------------------
//
//  Va llamando SetConfidenceOfConsequentToZero de cada regla
//-----------------------------------------------------------------------------
inline void FuzzyModule::SetConfidencesOfConsequentsToZero()
{
	std::vector<FuzzyRule*>::iterator curRule = m_Rules.begin();
	for (curRule; curRule != m_Rules.end(); ++curRule)
	{
		(*curRule)->SetConfidenceOfConsequentToZero();
	}
}
