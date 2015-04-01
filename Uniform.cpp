#include "Uniform.h"
#include <cassert>
#include "RandomNumberGenerator.h"

using namespace std;
using namespace DNest3;

Uniform::Uniform(int size)
:x(size)
{

}

void Uniform::fromPrior()
{
	assert(b > a);

	double range = b - a;
	for(size_t i=0; i<x.size(); i++)
		x[i] = a + range*randomU();
}

double Uniform::perturb()
{
	assert(b > a);

	double range = b - a;
	for(size_t i=0; i<x.size(); i++)
		x[i] = a + range*randomU();
}

