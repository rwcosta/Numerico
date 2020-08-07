#include "integral.h"

double f(double);

int main() {
	double x0 = 0,
		   x1 = M_PI,
		   n = 6,
		   real = 0;

   	std::vector<double> x, y;

   	std::cout << std::fixed << std::setprecision(17);

	double h = testTable(x0, x1, n, &x, &y, &f);

	double res = trapezio(y, n, h);
	double err = fabs(real - res);

	std::cout << std::endl << "Trapezio" << std::endl;
	std::cout << "Resultado.......: " << res << std::endl;
	std::cout << "Erro............: " << err << std::endl << std::endl;

	res = simpson(y, n, h);
	err = fabs(real - res);

	std::cout << "Simpson" << std::endl;
	std::cout << "Resultado.......: " << res << std::endl;
	std::cout << "Erro............: " << err << std::endl;
}

double f(double x) {
	return 2 * sin(2*x);
}
