// Напишите программу, которая удаляет из списка все элементы с нечетным порядковым номером.

// Пример №1
// Данные на входе: aa ss dd ff gg hh jj kk ll.
// Данные на выходе: aa dd gg jj ll

// Пример №2
// Данные на входе: aa ss dd ff gg hh jj kk ll tt.
// Данные на выходе: aa dd gg jj ll


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strdup(const char *s);

struct Node {
    char* data;
    struct Node* next;
};

void insertNode(struct Node** head, char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = strdup(data);
    newNode->next = *head;
    *head = newNode;
}

void printOddElements(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printOddElements(head->next);
    static int count = 1;
    if (count % 2 != 0) {
        printf("%s ", head->data);
    }
    count++;
}

int main() {
    char str[] = "aa ss dd ff gg hh jj kk ll tt";
    struct Node* head = NULL;

    char* token = strtok(str, " ");
    while (token != NULL) {
        insertNode(&head, token);
        token = strtok(NULL, " ");
    }

    printOddElements(head);
    printf("\n");

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp->data);
        free(temp);
    }

    return 0;
}
