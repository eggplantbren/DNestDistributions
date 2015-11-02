#include <iostream>
#include "RandomNumberGenerator.h"
#include "Uniform.h"

using namespace DNest3;
using namespace std;

int main()
{
	RandomNumberGenerator::initialise_instance();

	Node<double> C1(0.);
	Node<double> C2(1.);

	Uniform u1(&C1, &C2);
	u1.fromPrior();

	Uniform u2(&C1, &u1);
	u2.fromPrior();

	cout<<u1<<' '<<u2<<endl;

	return 0;
}

