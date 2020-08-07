#include <stdio.h>
#include <math.h>

double func(double);
double dFunc(double);

int main() {
    double x = 804.5,
           e = 0.00000001,
           f;
    
    for(int i = 0; ; i++) {
        f = func(x);
        
        printf("%3d  |  %14.20f  |  %14.20f  |\n", i, x, f);

        if(fabs(f) < e)
            break;
        
        x -= func(x)/dFunc(x);
    }
    
    printf("\nA raíz aproximada é: %.20f\n\n", x);
    
    return 0;
}

double func(double x) {
    return 1.66*pow(10,-9)*pow(x,3) + 6.3*pow(10,-7)*pow(x,2) + 8.2* pow(10,-5)*x - 1.23*pow(10,-4)*(1500-x) - 2.445 * pow(10,-6)*pow((1500-x),2)-0.07;
}

double dFunc(double x) {
    return 4.980000000000001*pow(10, -9)*pow(x, 2) + 1.26*pow(10, -6)*x + 4.89*pow(10, -6)*(1500-x) + 2.05*pow(10, -4);
}
