#include <iostream>
#include "RandomNumberGenerator.h"
#include "Uniform.h"

using namespace DNest3;
using namespace std;

int main()
{
	RandomNumberGenerator::initialise_instance();

	Uniform u1(0., 1.);
	u1.fromPrior();

	Uniform u2(5., 10.);
	u2.fromPrior();

	cout<<u1<<' '<<u2<<endl;

	return 0;
}

