#include <stdio.h>

int main()
{
    int len = 0;
    int j;
    char str[50] = "     the world  is    beautiful ", str2[50], str3[50];
    
    while (str[len] != 0)
        len++;
    
    for (int i; i < len; i++)
        if (str[i] != ' ')
            str2[j++] = str[i];

    printf("\n %s\n", str2);
    j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str3[j++] = str[i];
        }
        else{
            str3[j++] = str[i];
            while (str[i] == ' ')
                i++;
            i--;
        }
    }
    printf("\n%s", str3);
    
    
    return 0;
}