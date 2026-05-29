#include <stdio.h>

int main(){
    
    int o, x, y, u, i, j;
    #define n 10
    o = 1;
    x = 1;
    y = 1;
    int matrix[n][n] = {0};
    printf("Матрица 1 \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = o++;
            printf("%3d", matrix[i][j]);
            if (i == j){
                for (int x = 1; x < n - i; x++){
                    j++;
                    matrix[i][j] = 0;
                    printf("%3d", matrix[i][j]);
                    
                }
            
            }
            
        }
        
        printf("\n");
        
    }
    printf("\n");
    printf("Матрица 2 \n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = j + 1;
            printf("%3d", matrix[i][j]);
            if (i == j){
                for (int x = 1; x < n - i; x++){
                    j++;
                    matrix[i][j] = 0;
                    printf("%3d", matrix[i][j]);
                    
                }
            
            }
            
        }
        
        printf("\n");
        
    }
    
    o = 1;
    int Matrix[n][n] = {0};
    if (n % 2 == 0){
        y = 1;
        u = 1;
    }
    else{
        y = 0;
        u = 0;
    }
    printf("\n");
    printf("Матрица 3\n");
    for (int i = 0; i < n; i++){
        if (i <= n / 2 - u){
            for (int j = n / 2 - y; j < n; j++){
                Matrix[i][j] = o++;   
                if (o > x){
                    x = x + 2;
                    y++;
                    o = 1;
                
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", Matrix[i][j]);
        }
        printf("\n");
    }
    
    o = 1;
    int matrix4[n][n] = { 0 };
    printf("\n");
    printf("Матрица 4\n");
    i = 0;
    j = 0;
    matrix4[i][j] = o++;
        while(i < n - 1){
            if (i == 0) {
                j++;
                matrix4[i][j] = o++;
                while (j != 0) {
                    i++; j--;
                    matrix4[i][j] = o++;
                }
                i++;
                matrix4[i][j] = o++;

            }
            else{
                i--; j++;
                matrix4[i][j] = o++;
                continue;
            }
        }
            
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matrix4[i][j]);
        }
        printf("\n");
    }
    return 0;
}
