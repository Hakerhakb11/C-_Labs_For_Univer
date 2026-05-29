#include <stdio.h>
#include <stdlib.h>
typedef
struct node {
    int data;
    struct node *next;
} Node;
Node *pbeg = NULL, *pend = NULL, *temp;
int n = 0;
int current = 1;
int k;

void print_list() {
    Node *pcur = pbeg;

    while(pcur != NULL) {
        printf("%d ", pcur->data);
        pcur = pcur->next;
    }
    printf("\n\n");
}


int create_list(int n) {
    pend = pbeg = (Node *)malloc(sizeof(Node));
    pbeg->data = 0;
    for(int i = 1; i < n; i++) {
        pend = pend->next = (Node *)malloc(sizeof(Node));
        pend->data = i * 5;
    }
    pend->next = NULL;
    printf("\nСписок на '%d' элементов создан:\n", n);
    print_list();
    return n;
}


int search_by_num() {
    if (n <= 0) {
        printf("Список ешё не создан.\n");
        return 0;
    }
    int j;
    temp = pbeg;
    printf("Введите номер элемента:");
    scanf("%d", &j);
    if (j > n) {
        printf("\nЧисло (%d), превышает размер списка в (%d).\n", j, n);
        return 0;
    }
    for(int i = 1; i < j; i++) {
        temp = temp->next;
    }
    printf("\nЭлемент (%d) = '%d'\n", j, temp->data);
}


int search_by_value() {
    if (n <= 0) {
        printf("Список ешё не создан.\n");
        return 0;
    }
    int j;
    temp = pbeg;
    int k = 1;
    printf("Введите значение элемента:");
    scanf("%d", &j);
    for(int i = 1; i < n; i++) {
        if (temp->data == j) {
            break;
        }
        temp = temp->next;
        k++;
    }
    if (temp->data != j) {
        printf("\nЧисла %d нет в списке", j);
        return 0;
    }
    printf("\nЗначение (%d) содержит элемент = '%d'\n", j, k);
}


void add_to_start(int k) {
    Node *elem;
    temp = elem = (Node *)malloc(sizeof(Node));
    elem->data = k;
    temp = pbeg;
    pbeg = elem;
    elem = temp;
    pbeg->next = elem;
    n++;
    printf("Новый список с добавлением в начало: \n");
    print_list();
}


void add_to_end(int k) {
    Node *elem;
    elem = temp = (Node *)malloc(sizeof(Node));
    elem->data = k;
    pend->next = elem;
    temp = elem;
    elem = pend;
    pend = temp;
    pend->next = NULL;
    n++;
    printf("Новый список с добавлением в конец: \n");
    print_list();
}


void add_to_center(int k) {
    Node *elem;
    elem = temp = (Node *)malloc(sizeof(Node));
    elem->data = k;
    int j = n/2;
    temp = pbeg;
    for(int i = 1; i < j; i++) {
        temp = temp->next;
    }
    elem->next = temp->next;
    temp->next = elem;
    n++;
    printf("Новый список с добавлением в центр: \n");
    print_list();
}


int delete_by_num() {
    if (n <= 0) {
        printf("Список ешё не создан.\n");
        return 0;
    }
    int j;
    printf("Введите номер элемента для удаления:");
    scanf("%d", &j);
    if (j > n) {
        printf("\nЧисло (%d), превышает размер списка в (%d).\n", j, n);
        return 0;
    }
    Node *delete;
    if (j <= 1) {
        delete = pbeg;
        pbeg = pbeg->next;
        
    } else {
        temp = pbeg;
        for(int i = 0; i < j - 2; i++) {
            temp = temp->next;
        }
        delete = temp->next;
        temp->next = temp->next->next;
    }
    free(delete);
    n--;
    printf("\nЭлемент (%d) был удалён.\n", j);
    print_list();
}


int main()
{
    while(current != 0) {
        printf("\n------------------------------------------------------\n\
    Лабораторная работа №7:\n\n\
    1)Создать список с введённым количеством элементов\n\
    2)Найти элемент по номеру\n\
    3)Найти элемент по значению\n\
    4)Добавить элемент в начало\n\
    5)Добавить элемент в конец\n\
    6)Добавить элемент в центр\n\
    7)Удалить элемент по номеру\n\
    0)Завершение программы\n\n\
    Выберите действие: ");

        scanf("%d", &current);
        if (current == 1) {
            printf("Количество элементов: ");
            scanf("%d", &n);
            create_list(n);
            continue;
        }
        if (current == 2) {
            search_by_num();
            continue;
        }
        if (current == 3) {
            search_by_value();
            continue;
        }
        if (current == 4) {
            if (n <= 0) {
            printf("Список ешё не создан.\n");
            continue;
            }
            printf("Введите элемент который будет вставлен в начало");
            scanf("%d", &k);
            add_to_start(k);
            continue;
        }
        if (current == 5) {
            if (n <= 0) {
                printf("Список ешё не создан.\n");
                continue;
            }
            printf("Введите элемент который будет вставлен в конец");
            scanf("%d", &k);
            add_to_end(k);
            continue;
        }
        if (current == 6) {
            if (n <= 0) {
                printf("Список ешё не создан.\n");
                continue;
            }
            printf("Введите элемент который будет вставлен в середину");
            scanf("%d", &k);
            add_to_center(k);
            continue;
        }
        if (current == 7) {
            delete_by_num();
            continue;
        }
    }
    
    return 0;
}
