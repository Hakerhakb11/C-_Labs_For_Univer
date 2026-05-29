#include <stdio.h>
#include <string.h>

int main()
{
    int i, j;
    int o = 0;
    char* words[100];
    char str[100] = "люди не знают, чего они хотят";

    char* str2 = strtok(str, " ");
    while (str2 != NULL) {
        words[o++] = str2;
        str2 = strtok(NULL, " ");
    }

    printf("Введите номера для обмена (от 0 до %d): ", o - 1);
    scanf("%d %d", &i, &j);
    if (i >= o || j >= o) {
        printf("Ошибка. Введённые номера больше количества слов данного предложения");
        return 1;
    }

    char* temp = words[i];
    words[i] = words[j];
    words[j] = temp;

    for (int k = 0; k < o; k++) {
        printf("%s ", words[k]);
    }

    return 0;
}