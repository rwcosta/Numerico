#include "integral.h"

double f(double);

int main() {
	double x0 = -1,
		   x1 = 1,
		   n = 8,
		   real = 1.73395;

   	std::vector<double> x, y;

	double h = testTable(x0, x1, n, &x, &y, &f);

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Valores de x: ";
	printArr(x);

	std::cout << std::endl << "Valores de y: ";
	printArr(y);
	std::cout << std::endl;

	double res = simpson(y, n, h);
	double err = fabs(real - res);

	std::cout << "Resultado.......: " << res << std::endl;
	std::cout << "Erro............: " << err << std::endl;
}

double f(double x) {
	return 1/(pow(x, 4) + 1);
}
