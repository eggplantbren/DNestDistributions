#ifndef _Uniform_
#define _Uniform_

#include "Node.h"
#include <vector>
#include <memory>

class Uniform:public Node<double>
{
	private:
		// Aliases
		Node* a;
		Node* b;

	public:
		Uniform(Node* a, Node* b);
		~Uniform();

		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

