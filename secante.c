#include <stdio.h>
#include <math.h>

double func(double);
double newX(double, double);

int main() {
    double x0 = 802.5,
           x1 = 805.0,
           e = 0.000001,
           f, x = newX(x0, x1), ant = x1, aux;
    
    printf("  0  |  %14.11f  |  %14.11f  |\n", x0, func(x0));
    printf("  1  |  %14.11f  |  %14.11f  |\n", x1, func(x1));
           
    for(int i = 2; ; i++) {
        f = func(x);
        
        printf("%3d  |  %14.11f  |  %14.11f  |\n", i, x, f);

        if(fabs(f) < e)
            break;
        
        aux = x;
        x = newX(ant, x);
        ant = aux;
    }
    
    printf("\nA raíz aproximada é: %.11f\n\n", x);
    
    return 0;
}

double func(double x) {
    return 500 + 0.150*x + 4.1 * pow(10,-5)*pow(x,2) + 2.1 * pow(10,-7)* pow(x,3) + 4.150 * pow(10,-10) *pow(x,4) + 1000 + 0.22 * x + 6.150 * pow(10,-5) * pow(x,2) + 8.150 * pow(10,-7) * pow(x,3);
}

double newX(double x0, double x1) {
    return x1 - (func(x1)*(x1-x0))/(func(x1)-func(x0));
}
