#include "Uniform.h"
#include <cassert>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "Utils.h"

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
	int reps = (int)exp(log((double)x.size())*randomU());
	int which;

	for(int i=0; i<reps; i++)
	{
		which = randInt(x.size());
		x[which] += (b - a)*randh();
		wrap(x[which], a, b);
	}

	return 0.;
}

double Uniform::logp() const
{
	for(size_t i=0; i<x.size(); i++)
		if(x[i] < a || x[i] > b)
			return -1E250;
	return -log(b - a);
}

