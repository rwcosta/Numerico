#include "integral.h"

double f(double);

int main() {
	double x0 = -1,
		   x1 = 1,
		   n = 8,
		   real = 1.73395;

   	std::vector<double> x, y;

   	std::cout << std::fixed << std::setprecision(5);

	double h = testTable(x0, x1, n, &x, &y, &f);

	double res = simpson(y, n, h);
	double err = fabs(real - res);

	std::cout << std::endl << "Resultado.......: " << res << std::endl;
	std::cout << "Erro............: " << err << std::endl;
}

double f(double x) {
	return 1/(pow(x, 4) + 1);
}
