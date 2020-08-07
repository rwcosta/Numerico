#include <stdio.h>
#include <math.h>

double func(double);

int main() {
    double a = 1.5,
           b = 2.0,
           e = 0.000001,
           f, x;
           
    for(int i = 0; ; i++) {
        x = (a+b)/2;
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
    return cos(x) - x/(150 + pow(x, 2));
}
