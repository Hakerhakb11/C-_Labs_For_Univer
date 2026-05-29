#include <stdio.h>

int main() {
#define n 4
    int o = 1;

    int matrix[n][n];
    printf("№1.Еденичная матрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;

            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }



    printf("№2.Последовательная Mатрица:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = o++;
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }



    printf("\n№3.Матрица змейка:\n");
    o = 1;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = o++;
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i][j] = o++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }



    printf("\n№4.Матрица змейки с повтором:\n");
    o = 1;
    for (int i = 0; i < n; i++, o--) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = o++;
            }
        }
        else {
            for (int j = n - 1; j >= 0; j--) {
                matrix[i][j] = o++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }


    printf("\n№5.Матрица спираль:\n");
    int Matrix[n][n] = { 0 };
    int i = 0;
    int j = 0;
    int y = 0;
    o = 1;
    i = n / 2;
    j = (n - 1) / 2;
    Matrix[i][j] = o++;
    while (o < n * n + 1) {
        j++;
        Matrix[i][j] = o++;
        y++;
        for (int x = 0; x < y; x++) {
            i--;
            Matrix[i][j] = o++;
        }
        for (int x = 0; x < y; x++) {
            j--;
            Matrix[i][j] = o++;
        }
        if (o == n * n + 1) {
            break;
        }
        j--;
        Matrix[i][j] = o++;
        y++;
        for (int x = 0; x < y; x++) {
            i++;
            Matrix[i][j] = o++;
        }
        for (int x = 0; x < y; x++) {
            j++;
            Matrix[i][j] = o++;
        }

    }
    
    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", Matrix[i][j]);

        }
        printf("\n");
    }

    return 0;
}
