#ifndef _Uniform_
#define _Uniform_

#include "Node.h"
#include <vector>
#include <memory>

class Uniform:public Node<double>
{
	private:

	public:
		Uniform(double a, double b);
		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

