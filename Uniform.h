#ifndef _Uniform_
#define _Uniform_

#include "Node.h"
#include <vector>
#include <memory>

class Uniform:public Node<double>
{
	private:
		// Limits
		double a, b;

	public:
		Uniform(double a, double b);
		~Uniform();

		void set_parameters(double a, double b);
		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

