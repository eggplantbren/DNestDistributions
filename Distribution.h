#ifndef _Distribution_
#define _Distribution_

class Distribution
{
	protected:


	public:
		virtual void fromPrior() = 0;
		virtual double perturb() = 0;
		virtual double logp() = 0;

};

#endif

