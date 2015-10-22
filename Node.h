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
		std::vector< std::shared_ptr<Node> > parents;
		std::vector< std::shared_ptr<Node> > children;

	public:
		// Constructors
		Node() {}
		Node(Type value): value(value) {}

//		// When a node is made with this one as a parent, tell me!!
//		void add_child(Node& node)
//		{ children.push_back(std::shared_ptr<Node>(&node)); }

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

