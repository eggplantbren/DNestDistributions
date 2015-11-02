#ifndef _Normal_
#define _Normal_

#include "Node.h"
#include <vector>
#include <memory>

class Normal:public Node<double>
{
	private:
		// Aliases
		Node* mu;
		Node* sigma;

	public:
		Normal(Node* mu, Node* sigma);
		~Normal();

		void fromPrior();
		double perturb();
		double logp() const;

};

#endif

