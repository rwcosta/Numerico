#include "integral.h"

/* x0 e x1 intervalos de integração
   n número de divisões
   vetores x e y que armazenam os respectivos valores
   f função a ser calculada */

double testTable(double x0, double x1, int n, std::vector<double> *x, std::vector<double> *y, double (*f)(double)) {
	double h = (x1 - x0)/n;

	std::cout << "Pares x e y:" << std::endl;

	for(double i = x0, aux; i <= x1; i += h) {
		aux = f(i);

		std::cout << "(" << i << ", " << aux << ")" << std::endl;

		x->push_back(i);
		y->push_back(aux);
	}

	return h;
}

double trapezio(std::vector<double> y, int n, double h) {
	double sum = 0;

	for(int i = 1; i < n; sum += y[i], i++); 

	return h/2 * (y[0] + 2*sum + y[n]);
}

double simpson(std::vector<double> y, int n, double h) {
	double pair = 0;
	double odd = 0;

	for(int i = 1; i < n; i++)
		if((i % 2) == 0)
			pair += y[i];
		else 
			odd += y[i];

	return h/3 * (y[0] + 2*pair + 4*odd + y[n]);
}

double eulerF(double x, double y, double h, double (*f)(double, double)) {
	return y + h/2 * (f(x, y) + f(x+h, y + h*f(x, y)));
}

double eulerAp(double x0, double y0, double h, double n, double (*f)(double, double)) {
	int i = 0;
	double x = x0,
		   y = y0;

	for(; x < n; x += h, i++) {
		std::cout << i << " - " << "f(" << x << ") = " << y << std::endl;
		y = eulerF(x, y, h, f);
	}

	std::cout << i << " - " << "f(" << x << ") = " << y << std::endl;

	return y;
}

double rKuttaF(double x, double y, double h, double (*f)(double, double)) {
	double k1 = h * f(x, y),
		   k2 = h * f(x + h/2, y + k1/2),
		   k3 = h * f(x + h/2, y + k2/2),
		   k4 = h * f(x+h, y+k3);

	return y + ((double) 1/6) * (k1 + 2*(k2 + k3) + k4);
}

double rKutta4(double x0, double y0, double h, double n, double (*f)(double, double)) {
	int i = 0;
	double x = x0,
		   y = y0;

	for(; x < n; x += h, i++) {
		std::cout << i << " - " << "f(" << x << ") = " << y << std::endl;
		y = rKuttaF(x, y, h, f);
	}

	std::cout << i << " - " << "f(" << x << ") = " << y << std::endl;

	return y;
}

void printArr(std::vector<double> arr) {
    std::cout << "{";
    for(int i = 0 ; i < arr.size(); i++)
        if((i+1) != arr.size())
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << "}" << std::endl;
}
