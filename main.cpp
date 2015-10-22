#include <iostream>
#include "Uniform.h"

using namespace std;

int main()
{
	Uniform u(5., 10.);
	u.fromPrior();

	return 0;
}

