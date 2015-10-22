#include "Uniform.h"
#include <cassert>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "Utils.h"

using namespace std;
using namespace DNest3;

Uniform::Uniform(double a, double b)
{
	assert(b > a);
	parents.push_back(shared_ptr< Node<double> >(new Node<double>(a)));
	parents.push_back(shared_ptr< Node<double> >(new Node<double>(b)));
}

void Uniform::fromPrior()
{
	value = parents[0]->get_value() +
				(parents[1]->get_value() - parents[0]->get_value())*randomU();
}

double Uniform::perturb()
{
	value += (parents[1]->get_value() - parents[0]->get_value())*randh();
	wrap(value, parents[0]->get_value(), parents[1]->get_value());
	return 0.;
}

double Uniform::logp() const
{
	if(value < parents[0]->get_value() || value > parents[1]->get_value())
			return -1E250;
	return -log(parents[1]->get_value() - parents[0]->get_value());
}

