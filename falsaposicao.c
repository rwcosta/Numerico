#include <stdio.h>
#include <math.h>

double func(double);
double newX(double, double);

int main() {
    double a = 1.0,
           b = 2.0,
           e = 0.000001,
           f, x;
           
    for(int i = 0; ; i++) {
        x = newX(a, b);
        f = func(x);
        
        printf("%3d  |  %14.11f  |  %14.11f  |  %14.11f  |  %14.11f  |\n", i, a, b, x, f);

        if(fabs(f) < e)
            break;
        
        if(f < 0)
            b = x;
        else
            a = x;
    }
    
    printf("\nA raíz aproximada é: %.11f\n\n", x);
    
    return 0;
}

double func(double x) {
    return cos(x) - x/(746 + pow(x, 2));
}

double newX(double a, double b) {
    return (a*func(b) - b*func(a))/(func(b)-func(a));
}
