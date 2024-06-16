//Написать алгоритм перевода из инфиксной записи в обратную польскую. 
// Для его реализации нужны данные по приоритетам операций.
//  Реализовать алгоритм, используя побитовые операции (&, |, ^).


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//  является ли символ оператором
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '&' || c == '|');
}

// приоритет оператора
int getPriority(char op) {
    if (op == '^') {
        return 3;
    } else if (op == '*' || op == '/') {
        return 2;
    } else if (op == '+' || op == '-') {
        return 1;
    } else if (op == '&' || op == '|') {
        return 0;
    }
    return -1; // Неподдерживаемый оператор
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char stack[MAX_SIZE];
    int top = -1;
    
    while (infix[i] != '\0') {
        if (infix[i] == '(') {
            stack[++top] = '(';
            i++;
        } else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;
            i++;
        } else if (isOperator(infix[i])) {
            while (top != -1 && getPriority(stack[top]) >= getPriority(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
            i++;
        } else {
            postfix[j++] = infix[i++];
        }
    }
    
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    printf("Input: ");
    fgets(infix, MAX_SIZE, stdin);
    
    infixToPostfix(infix, postfix);
    
    printf("Output: %s", postfix);
    
    return 0;
}
