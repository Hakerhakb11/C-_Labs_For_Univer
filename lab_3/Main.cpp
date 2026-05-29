#include <stdio.h>
int main() {

#define n 8
    int o = 1;
    int matrix[n][n] = { 0 };
    int x;
    int y;
    int turns = 0;
    printf("Начальная позиция коня. Введите 2 числа через пробел: ");
    scanf("%d %d", &x, &y);
    int f[3] = {};
    int F[3] = { n, n, n };
    int xm[8] = { 2, 1, -2, -1, -2, -1, 2, 1 };
    int ym[8] = { 1, 2, -1, -2, 1, 2, -1, -2 };
    matrix[x][y] = o++;

    while (o <= n * n) {
        for (int i = 0; i < 8; i++) {
            turns = 0;
            int newx = x + xm[i];
            int newy = y + ym[i];
            if (newx >= 0 && newx < n && newy >= 0 && newy < n && matrix[newx][newy] == 0) {
                f[0] = newx;
                f[1] = newy;
                for (int i = 0; i < 8; i++) {
                    int nextx = newx + xm[i];
                    int nexty = newy + ym[i];
                    if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < n && matrix[nextx][nexty] == 0) {
                        turns++;
                    }
                }
                f[2] = turns;
                if (f[2] <= F[2]) {
                    F[0] = f[0];
                    F[1] = f[1];
                    F[2] = f[2];
                }

            }

        }
        x = F[0];
        y = F[1];
        matrix[x][y] = o++;
        F[0] = n;
        F[1] = n;
        F[2] = n;
        f[0] = 0;
        f[1] = 0;
        f[2] = 0;
    }

    printf("\nОтвет:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
