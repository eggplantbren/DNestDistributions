#ifndef _Uniform_
#define _Uniform_

#include "Distribution.h"
#include <vector>

class Uniform:public Distribution
{
	private:
		// Lower and upper limit
		double a, b;

		// The variables
		std::vector<double> x;

	public:
		Uniform(int size);
		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

