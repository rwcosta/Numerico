#include "integral.h"

double f(double, double);

int main() {
	double x0 = 0,
		   y0 = 0,
		   n = 5,
		   h = 0.5;

	std::cout << std::fixed << std::setprecision(10);

	double res = eulerAp(x0, y0, h, n, &f);
	std::cout << std::endl << "Resultado.......: " << res << std::endl;
}

double f(double x, double y) {
	return (2000 - 2*y)/(200-x);
}
