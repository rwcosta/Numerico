#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream> // cout, endl
#include <iomanip>	// fixed, setprecision
#include <cmath>	// pow, M_PI
#include <vector>	// vector

double testTable(double, double, int n, std::vector<double> *, std::vector<double> *, double (*f)(double)); // Função que gera os valores de x e y
double trapezio(std::vector<double>, int, double);															// Método do trapézio
double simpson(std::vector<double>, int, double);															// Método do simpson
void printArr(std::vector<double>);																			// Função para exibir os valores de um vetor

#endif //INTEGRAL_H
