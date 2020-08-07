#include "integral.h"

double f(double, double);

int main() {
	double x0 = 0,
		   y0 = 1000,
		   n = 5,
		   h = 0.5;
	std::cout << std::fixed << std::setprecision(5);

	double res = rKutta4(x0, y0, h, n, &f);

	std::cout << std::endl << "Resultado.......: " << res << std::endl;
}

double f(double x, double y) {
	return 2 * pow(10, -6) * (100000 - y) * y;
}
