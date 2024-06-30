// Используя код задачи 1, написать программу поиска первого и последнего слова в строке.

// Пример №1
// Данные на входе: efg abcd zzz.
// Данные на выходе: efg zzz.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char word[50];
    struct Node* next;
};

void insert(struct Node** head, char* word) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void findFirstAndLastWord(char* input) {
    struct Node* head = NULL;
    char* word = strtok(input, " ");
    
    while (word != NULL) {
        insert(&head, word);
        word = strtok(NULL, " ");
    }

    printf(head->word);
    printf(" ");

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    printf(current->word);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[100];
    fgets(input, sizeof(input), stdin);
    
    input[strcspn(input, "\n")] = 0;

    findFirstAndLastWord(input);

    return 0;
}
