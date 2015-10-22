#ifndef _Distribution_
#define _Distribution_

template<class Type>
class Distribution
{
	protected:
		Type value;

	public:
		// Constructors
		Distribution() {}
		Distribution(Type value): value(value) {}

		// Getter
		const Type& get_value() const
		{ return value; }

		virtual ~Distribution() { }
		virtual void fromPrior() { }
		virtual double perturb() { return 0.; }
		virtual double logp() const { return 0.; }
};

#endif

