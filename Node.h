#ifndef _Node_
#define _Node_

#include <ostream>

template<class Type>
class Node
{
	protected:
		Type value;

	public:
		// Constructors
		Node() {}
		Node(Type value): value(value) {}

		// Getter
		const Type& get_value() const
		{ return value; }

		virtual ~Node() { }
		virtual void fromPrior() { }
		virtual double perturb() { return 0.; }
		virtual double logp() const { return 0.; }
		virtual void print(std::ostream& out) const { out<<value; }
};

template<class Type>
std::ostream& operator << (std::ostream& out, const Node<Type>& a)
{
	a.print(out);
	return out;
}

#endif

