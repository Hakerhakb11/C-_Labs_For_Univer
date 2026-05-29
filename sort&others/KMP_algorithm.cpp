#include <stdio.h>
#include <string.h>
int main()
{
    char src[100] = "aabaaxxxxaabaabx";
    int p[100] = {0};
    
    int len = strlen(src);
    
    for (int i = 1; i < len; i++) {
        int j = p[i - 1];
        
        while (src[i] != src[j] && j > 0) {
            j = p[j - 1];
        }
        
        if (src[i] == src[j]) {
            p[i] = j + 1;
        } else {
            p[i] = 0;
        }
    }
    
    printf("%s\n", src);
    for (int i = 0; i < len; i++) {
        printf("%d", p[i]);
    }
    
    return 0;
}
