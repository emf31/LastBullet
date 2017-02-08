#pragma once
#include <string>
#include <cassert>


class FuzzySet
{
protected:

	//Dom, tiene la cantidad del fuzzyset
	double m_dDOM;


	//Es el maximo que se puede representar en la funcion
	double m_dRepresentativeValue;

public:

	//Constructor de un FuzzySet
	FuzzySet(double RepVal);

	//Devuelve el grado de DOM de ese set, depende de cada implementacion en concreto y por eso el virtual
	virtual double CalculateDOM(double val)const = 0;

	//Compara el valor que se le pas con m_dom, si es superior se le setea
	void ORwithDOM(double val);

	//Devuelve el m_dRepresentativeValue
	double GetRepresentativeVal()const;

	//Limpiar DOM
	void ClearDOM();

	//DevolverDOM
	double GetDOM()const;

	//Setear DOM
	void  SetDOM(double val);
};


