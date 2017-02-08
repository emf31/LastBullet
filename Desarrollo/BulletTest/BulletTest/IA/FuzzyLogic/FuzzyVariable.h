#pragma once
#pragma warning (disable:4786)

#include <map>
#include <iosfwd>
#include <string>

class FuzzySet;
class FzSet;
class FuzzyModule;


class FuzzyVariable
{
private:

	//TypeDef para los FuzzySets que se guardan y despues acceder a ellos de manera mas sencilla
	typedef std::map<std::string, FuzzySet*>  MemberSets;

	//Constructor de copia en privado
	FuzzyVariable(const FuzzyVariable&);

	//Declaracioón del mapa de fuzzysets del typedef
	MemberSets m_MemberSets;

	//Variables del rango inferior y superior
	double m_dMinRange;
	double m_dMaxRange;

	//Metodo que sirve para setear el rango superior e inferior y los posteriores fuzzySets se adecuaran a este rango
	void AdjustRangeToFit(double min, double max);

	//Destrucctor de FuzzyVariable
	~FuzzyVariable();

	//Clase amiga FuzzyMOdule para poder acceder a sus valores
	friend class FuzzyModule;


public:

	//Construcctor de FuzzyVariable
	FuzzyVariable();

	//Metodos que crean Instancias de un fuzzySet propio de un fuzzyset concreto
	//Estos metodos devuelve un objeto tipo fzset que es una clase proxy representativa de fuzzyset
	//y tiene referencia al fuzzyset original

	FzSet  AddLeftShoulderSet(std::string name, double minBound, double peak, double maxBound);

	FzSet  AddRightShoulderSet(std::string name, double minBound, double peak, double maxBound);

	FzSet  AddTriangularSet(std::string name, double minBound, double peak, double maxBound);

	FzSet  AddSingletonSet(std::string name, double minBound, double peak, double maxBound);


	//Fuzzifica un calor calculado los DOM de las variables que tiene
	void Fuzzify(double val);

	//Defuzzifica por Max averabe
	double DeFuzzifyMaxAv()const;

	//Deffucifica por centroid, necesita un parametro qu esta en module para hacerlo
	double DeFuzzifyCentroid(int NumSamples)const;


	//Escribe los DOM
	std::ostream& WriteDOMs(std::ostream& os);
};




