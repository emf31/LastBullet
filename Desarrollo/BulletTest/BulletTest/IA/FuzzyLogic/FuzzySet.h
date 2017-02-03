#pragma once
#include <string>
#include <cassert>


class FuzzySet
{
protected:

	//this will hold the degree of membership of a given value in this set 
	double        m_dDOM;

	//this is the maximum of the set's membership function. For instamce, if
	//the set is triangular then this will be the peak point of the triangular.
	//if the set has a plateau then this value will be the mid point of the 
	//plateau. This value is set in the constructor to avoid run-time
	//calculation of mid-point values.
	double        m_dRepresentativeValue;

public:

	FuzzySet(double RepVal);

	//return the degree of membership in this set of the given value. NOTE,
	//this does not set m_dDOM to the DOM of the value passed as the parameter.
	//This is because the centroid defuzzification method also uses this method
	//to determine the DOMs of the values it uses as its sample points.
	virtual double CalculateDOM(double val)const = 0;

	//if this fuzzy set is part of a consequent FLV, and it is fired by a rule 
	//then this method sets the DOM (in this context, the DOM represents a
	//confidence level)to the maximum of the parameter value or the set's 
	//existing m_dDOM value
	void ORwithDOM(double val);

	//accessor methods
	double GetRepresentativeVal()const;

	void               ClearDOM();
	double             GetDOM()const;
	void               SetDOM(double val);
};


