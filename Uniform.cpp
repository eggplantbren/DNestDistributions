#include "Uniform.h"
#include <cassert>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "Utils.h"

using namespace std;
using namespace DNest3;

Uniform::Uniform(double a, double b)
{
	set_parameters(a, b);
}

Uniform::~Uniform()
{

}

void Uniform::set_parameters(double a, double b)
{
	assert(b > a);
	this->a = a;
	this->b = b;
}

void Uniform::fromPrior()
{
	value =	a + (b - a)*randomU();
}

double Uniform::perturb()
{
	value += (b - a)*randh();
	wrap(value, a, b);
	return 0.;
}

double Uniform::logp() const
{
	if(value < a || value > b)
			return -1E250;
	return -log(b - a);
}

