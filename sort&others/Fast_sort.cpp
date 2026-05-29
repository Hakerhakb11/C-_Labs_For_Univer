#include <stdio.h>

int main()
{
    int mas[40] = {35, 235, 71, 9, 37, 30, 383, 18, 23572, 
                      87, 52, 84, 37, 532, 68, 8, 357, 12, 43, 10, 
                      2357, 59, 11, 9, 35725, 34, 83, 78, 7357, 25, 
                      52, 84, 67, 17, 68, 8, 96, 19, 43, 10};
    int n = 40;
    void sort(int m[], int n){
        int i = -1;
        if (n > 2) {
            for (int j = 0; j < n - 1; j++){
                if (m[n - 1] > m[j]){
                    i++;
                    int temp = m[i];
                    m[i] = m[j];
                    m[j] = temp;
                    
                }
            }
            int temp = m[i + 1];
            m[i + 1] = m[n - 1];
            m[n - 1] = temp;
        
            sort(m, i + 1);
            sort(m + i + 2, n - i - 2);
        }
        
    }
    
    printf("\n Быстрая сортировка:\n");
    sort(mas, n);
    
    for (int i = 0; i < n; i++){
        printf("%d ", mas[i]);
    }
    
    return 0;
}
