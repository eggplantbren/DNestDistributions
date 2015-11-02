#include "Normal.h"
#include <cassert>
#include <cmath>
#include "RandomNumberGenerator.h"
#include "Utils.h"

using namespace std;
using namespace DNest3;

Normal::Normal(Node* mu, Node* sigma)
{
	parents.assign({mu, sigma});
	this->mu = mu;
	this->sigma = sigma;
	mu->add_child(this);
	sigma->add_child(this);
}

Normal::~Normal()
{

}

void Normal::fromPrior()
{
	value =	mu->get_value() + sigma->get_value()*randn();
}

double Normal::perturb()
{
	double logH = 0.;

	logH -= -0.5*pow((value - mu->get_value())/sigma->get_value(), 2);
	value += sigma->get_value()*randh();
	logH += -0.5*pow((value - mu->get_value())/sigma->get_value(), 2);

	return logH;
}

double Normal::logp() const
{
	return -0.5*log(2*M_PI) - log(sigma->get_value())
				-0.5*pow((value - mu->get_value())/sigma->get_value(), 2);
}

