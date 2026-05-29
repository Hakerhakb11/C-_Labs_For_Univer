#include <stdio.h>

int main()
{
    int o = 1;
    int k = 20;
    printf("\nПузырьковая сортировка\n");
    int m[20] = {35, 100, 11, 9, 27, 8, 83, 78, 33, 87, 52, 84, 67, 17, 68, 30, 96, 19, 43, 10};
    while (o != 0){
        o = 0;
        for (int i = 0; i < k - 1; i++){
            if (m[i] > m[i + 1]){
                int temp = m[i + 1];
                m[i + 1] = m[i];
                m[i] = temp;
                o++;
            }
            for (int i = 0; i < 20; i++) {
                printf("%1d ", m[i]);
                
            }
            
        }
        k--;
        
    }
    
    return 0;
}
