#include "integral.h"

/* x0 e x1 intervalos de integração
   n número de divisões
   vetores x e y que armazenam os respectivos valores
   f função a ser calculada */

double testTable(double x0, double x1, int n, std::vector<double> *x, std::vector<double> *y, double (*f)(double)) {
	double h = (x1 - x0)/n;

	for(double i = x0; i <= x1; i += h) {
		x->push_back(i);
		y->push_back(f(i));
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

void printArr(std::vector<double> arr) {
    std::cout << "{";
    for(int i = 0 ; i < arr.size(); i++)
        if((i+1) != arr.size())
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << "}" << std::endl;
}
