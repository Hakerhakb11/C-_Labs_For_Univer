#include <stdio.h>
#include <math.h>

int main()
{   
    int i, S;
    int S1 = 0, S2 = 0, n = 5,
        x[] = {3, 5, 12, 9, 5},
        y[] = {4, 11, 8, 5, 6};
    
    for (i = 0; i < n - 1; i++){
        S1 += x[i] * y[i + 1];
    }
    S1 += x[n - 1] * y[0];
    
    for (i = 0; i < n - 1; i++){
        S2 += x[i + 1] * y[i];
    }
    S2 += x[0] * y[n - 1];
        S = 0.5 * fabs(S1 - S2);
        printf ("Площадь равна: %d", S);
        
        return 0;
    
}