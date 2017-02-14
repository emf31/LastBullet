#pragma once

//Clase padre de los terminos fuzzy

//Es una interfaz
class FuzzyTerm
{
public:

	virtual ~FuzzyTerm() {}

	//constructor virtual
	virtual FuzzyTerm* Clone()const = 0;

	//Cantidad DOM de cada uno
	virtual double      GetDOM()const = 0;

	//Clear el DOM de cada uno
	virtual void       ClearDOM() = 0;

	//Updatear DOM virtual
	virtual void       ORwithDOM(double val) = 0;


};

