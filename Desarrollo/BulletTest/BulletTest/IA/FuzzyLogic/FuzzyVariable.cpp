#include "fuzzyvariable.h"
#include "fzOR.h"
#include "fzAND.h"
#include "FuzzySetTriangle.h"
#include "FuzzySetLeftShoulder.h"
#include "FuzzySetRightShoulder.h"
#include "FuzzySetSingleton.h"
#include "FzSet.h"
#include <Util.h>
#include <cassert>
#include <iostream>
#include <algorithm>

//------------------------------ Construcctor -----------------------------------------

FuzzyVariable::FuzzyVariable() :m_dMinRange(0.0), m_dMaxRange(0.0) {}

FuzzyVariable::~FuzzyVariable()
{
	MemberSets::iterator it;
	for (it = m_MemberSets.begin(); it != m_MemberSets.end(); ++it)
	{
		delete it->second;
	}
}

//--------------------------- Fuzzificar -----------------------------------------

// Calcula el valor de cada DOM y los setea en la variable

void FuzzyVariable::Fuzzify(double val)
{
	assert((val >= m_dMinRange) && (val <= m_dMaxRange) &&
		"<FuzzyVariable::Fuzzify>: value out of range");

	MemberSets::const_iterator curSet;
	for (curSet = m_MemberSets.begin(); curSet != m_MemberSets.end(); ++curSet)
	{
		curSet->second->SetDOM(curSet->second->CalculateDOM(val));
	}
}


//--------------------------- Defuzzificar por Max average ----------------------------------

// Defuzzifica el valor por la media de la maxima de los set
// salida = sum (maxima * DOM) / sum (DOMs) 

double FuzzyVariable::DeFuzzifyMaxAv()const
{
	double bottom = 0.0;
	double top = 0.0;

	MemberSets::const_iterator curSet;
	for (curSet = m_MemberSets.begin(); curSet != m_MemberSets.end(); ++curSet)
	{
		bottom += curSet->second->GetDOM();

		top += curSet->second->GetRepresentativeVal() * curSet->second->GetDOM();
	}

	if (isEqual(0, bottom)) return 0.0;

	return top / bottom;
}

//------------------------- Defuzzificar por centroid ---------------------------------

//  Deffuzzifica usando el metodo de centroid

double FuzzyVariable::DeFuzzifyCentroid(int NumSamples)const
{
	double StepSize = (m_dMaxRange - m_dMinRange) / (double)NumSamples;

	double TotalArea = 0.0;
	double SumOfMoments = 0.0;

	for (int samp = 1; samp <= NumSamples; ++samp)
	{
		MemberSets::const_iterator curSet = m_MemberSets.begin();
		for (curSet; curSet != m_MemberSets.end(); ++curSet)
		{
			double contribution =
				MinOf(curSet->second->CalculateDOM(m_dMinRange + samp * StepSize),
					curSet->second->GetDOM());

			TotalArea += contribution;

			SumOfMoments += (m_dMinRange + samp * StepSize)  * contribution;
		}
	}


	if (isEqual(0, TotalArea)) return 0.0;

	return (SumOfMoments / TotalArea);
}

//------------------------- AddTriangularSet ----------------------------------

FzSet FuzzyVariable::AddTriangularSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	m_MemberSets[name] = new FuzzySetTriangle(peak,
		peak - minBound,
		maxBound - peak);
	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*m_MemberSets[name]);
}

//--------------------------- AddLeftShoulder ---------------------------------

FzSet FuzzyVariable::AddLeftShoulderSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	m_MemberSets[name] = new FuzzySetLeftShoulder(peak, peak - minBound, maxBound - peak);

	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*m_MemberSets[name]);
}


//--------------------------- AddRightShoulder ---------------------------------

FzSet FuzzyVariable::AddRightShoulderSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	m_MemberSets[name] = new FuzzySetRightShoulder(peak, peak - minBound, maxBound - peak);

	//adjust range if necessary
	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*m_MemberSets[name]);
}


//--------------------------- AddSingletonSet ---------------------------------

FzSet FuzzyVariable::AddSingletonSet(std::string name,
	double       minBound,
	double       peak,
	double       maxBound)
{
	m_MemberSets[name] = new FuzzySetSingleton(peak,
		peak - minBound,
		maxBound - peak);

	AdjustRangeToFit(minBound, maxBound);

	return FzSet(*m_MemberSets[name]);
}

//---------------------------- AdjustRangeToFit -------------------------------

//  setea los rangos en caso de que sean mas exagerados que antes

void FuzzyVariable::AdjustRangeToFit(double minBound, double maxBound)
{
	if (minBound < m_dMinRange) m_dMinRange = minBound;
	if (maxBound > m_dMaxRange) m_dMaxRange = maxBound;
}

//---------------------------- WriteDOMs --------------------------------------
std::ostream& FuzzyVariable::WriteDOMs(std::ostream& os)
{
	MemberSets::iterator it;
	for (it = m_MemberSets.begin(); it != m_MemberSets.end(); ++it)
	{

		os << "\n" << it->first << " is " << it->second->GetDOM();
	}

	os << "\nMin Range: " << m_dMinRange << "\nMax Range: " << m_dMaxRange;

	return os;

}