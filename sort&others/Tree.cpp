#include <stdio.h>
#include <stdlib.h>

typedef
struct node {
    int data;
    struct node *next;
} Node;
int n = 10;
int main()
{
    Node *pbeg1, *pbeg2, *pend1, *pend2, *pbeg3, *pend3;
    
    pend1 = pbeg1 = (Node *)malloc(sizeof(Node));
    pend2 = pbeg2 = (Node *)malloc(sizeof(Node));
    pend3 = pbeg3 = (Node *)malloc(sizeof(Node));
    
    pbeg1->data = 0;
    pbeg2->data = 0;
    pbeg3->data = 0;
    
    for(int i = 1; i < n; i++) {
        pend1 = pend1->next = (Node *)malloc(sizeof(Node));
        pend1->data = i;
    }
    pend1->next = NULL;
    
    for(int i = 1; i < n; i++) {
        pend2 = pend2->next = (Node *)malloc(sizeof(Node));
        pend2->data = i * 10;
    }
    pend2->next = NULL;
    
    
    Node *temp1, *temp2;
    temp1 = temp2 = (Node *)malloc(sizeof(Node));
    temp1 = pbeg1;
    temp2 = pbeg2;
    while (temp1 != NULL || temp2 != NULL) {
        for(int i = 1; i < 10; i++) {
            temp1 = temp2 = (Node *)malloc(sizeof(Node));
            pend3 = pend3->next = (Node *)malloc(sizeof(Node));
            pend3 = temp1;
            temp1 = temp1->next;
            pend3 = pend3->next = (Node *)malloc(sizeof(Node));
            pend3 = temp2;
            temp2 = temp2->next;
        }
        temp1 = temp2 = (Node *)malloc(sizeof(Node));
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    printf("ВЫШЕЛ ИЗ ЦЫКЛА");
    
    // Node *pcur3 = pbeg3;
    // while(pcur3 != NULL) {
    //     printf("%d ", pcur3->data);
    //     pcur3 = pcur3->next;
    // }
    
    Node *pcur1, *pcur2;
    pcur1 = pbeg1;
    pcur2 = pbeg2;
    while (pcur1 != NULL || pcur2 != NULL) {
        printf("%d %d ", pcur1->data, pcur2->data);
        pcur1 = pcur1->next;
        pcur2 = pcur2->next;
    }
    
    
    return 0;
}
