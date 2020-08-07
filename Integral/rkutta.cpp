#include "integral.h"

double f(double, double);

int main() {
	double x0 = 0,
		   y0 = 0,
		   n = 5,
		   h = 0.5,
		   real = 49.375;

	std::cout << std::fixed << std::setprecision(10);

	double res = rKutta4(x0, y0, h, n, &f);
	double err = fabs(real - res);

	std::cout << std::endl << "Resultado.......: " << res << std::endl;
	std::cout << "Erro............: " << err << std::endl << std::endl;
}

double f(double x, double y) {
	return (2000 - 2*y)/(200-x);
}
