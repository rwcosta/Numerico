#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream> // cout, endl
#include <iomanip>	// fixed, setprecision
#include <cmath>	// pow, M_PI
#include <vector>	// vector

double testTable(double, double, int n, std::vector<double> *, std::vector<double> *, double (*f)(double)); // Função que gera os valores de x e y
double trapezio(std::vector<double>, int, double);															// Método do trapézio
double simpson(std::vector<double>, int, double);															// Método do simpson
double eulerF(double, double, double, double (*f)(double, double));											// Fórmula do Y de Euler
double eulerAp(double, double, double, double, double (*f)(double, double));								// Método de Euler Aperfeiçoado
double rKuttaF(double, double, double, double (*f)(double, double));										// Fórmula do Y de Runge Kutta
double rKutta4(double, double, double, double, double (*f)(double, double));								// Método de Runge Kutta 4ª ordem	
void printArr(std::vector<double>);																			// Função para exibir os valores de um vetor

#endif //INTEGRAL_H
