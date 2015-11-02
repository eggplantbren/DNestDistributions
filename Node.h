#ifndef _Node_
#define _Node_

#include <ostream>
#include <vector>
#include <memory>

template<class Type>
class Node
{
	protected:
		// The value of this node (usually Type will be double)
		Type value;

		// Pointers to any parents and children
		std::vector< Node* > parents;
		std::vector< Node* > children;

	public:
		// Constructors
		Node() {}
		Node(Type value): value(value) {}

		// Getter
		const Type& get_value() const
		{ return value; }

		// Add to children
		void add_child(Node* child)
		{ children.push_back(child); }

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

