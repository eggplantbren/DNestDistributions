#include <iostream>
#include "RandomNumberGenerator.h"
#include "Uniform.h"

using namespace DNest3;
using namespace std;

int main()
{
	RandomNumberGenerator::initialise_instance();

	Uniform u(0., 1.);
	u.fromPrior();

	cout<<u.get_value()<<endl;

	return 0;
}

