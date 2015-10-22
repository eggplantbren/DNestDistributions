#ifndef _Uniform_
#define _Uniform_

#include "Distribution.h"
#include <vector>
#include <memory>

class Uniform:public Distribution<double>
{
	private:
		// Lower and upper limit
		std::shared_ptr<Distribution> a, b;

	public:
		Uniform(double a, double b);
		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

