#include "Uniform.h"
#include <cassert>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "Utils.h"

using namespace std;
using namespace DNest3;

Uniform::Uniform(Node* a, Node* b)
{
	parents.assign({a, b});
	this->a = a;
	this->b = b;
	a->add_child(this);
	b->add_child(this);
}

Uniform::~Uniform()
{

}

void Uniform::fromPrior()
{
	value =	a->get_value() + (b->get_value() - a->get_value())*randomU();
}

double Uniform::perturb()
{
	value += (b->get_value() - a->get_value())*randh();
	wrap(value, a->get_value(), b->get_value());
	return 0.;
}

double Uniform::logp() const
{
	if(value < a->get_value() || value > b->get_value())
			return -1E250;
	return -log(b->get_value() - a->get_value());
}

