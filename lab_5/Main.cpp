#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int m;
    int j = 1;
    int temp = 0;
    printf("Введите количество элементов:");
    scanf("%d", &n);
    
    char *str = (char*)malloc(n);
    int mas[n];
    for (int i = 0; i < n; i++){
        printf("Введите значения элементов:");
        scanf("%d", &m);
        mas[i] = m;
    }

    printf("Всего элементов: %d\n", n);
    
    printf("Весь массив: ");
    for (int i = 0; i < n; i++)
        printf("%d", mas[i]);
    
    for (int i = 0; i < n - 1; i++) {
        if (mas[i] == mas[i + 1]) {
            j++;
            if (j > temp) {
                temp = j;
            }
        }
        else{
            j = 1;
        }
    }
    
    printf("\nОтвет: %d", temp);
    
    return 0;
}
