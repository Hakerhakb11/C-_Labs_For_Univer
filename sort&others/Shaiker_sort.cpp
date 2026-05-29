#include <stdio.h>

int main()
{   
    int j;
    int temp;
    int L = 20;
    int o = 1;
    int k = 20;
    
    printf("\nШейкерная сортировка\n");
    int m[20] = {35, 100, 11, 9, 27, 8, 83, 78, 33, 87, 
                52, 84, 67, 17, 68, 30, 96, 19, 43, 10};
    while (o != 0){
        o = 0;
        for (int i = 20 - k; i < L - 1; i++){
            if (m[i] > m[i + 1]){
                int temp = m[i + 1];
                m[i + 1] = m[i];
                m[i] = temp;
                o++;
                j = i;
            }
            for (int i = 0; i < 20; i++) {
                printf("%1d ", m[i]);
                
            }

        }
        k--;
        L--;
        for (int i = 0; j > 0; j--){
            if (m[j] < m[j - 1]){
                temp = m[j - 1];
                m[j - 1] = m[j];
                m[j] = temp;
            }
            for (int i = 0; i < 20; i++) {
                printf("%1d ", m[i]);
                
            }
                
        }
        
    }
    
    return 0;
}
