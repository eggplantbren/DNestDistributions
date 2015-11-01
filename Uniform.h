#ifndef _Uniform_
#define _Uniform_

#include "Node.h"
#include <vector>
#include <memory>

class Uniform:public Node<double>
{
	private:
		// Limits
		const Node<double>& a, b;

	public:
		Uniform(const Node<double>& a, const Node<double>& b);
		~Uniform();

		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

