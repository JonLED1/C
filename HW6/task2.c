//Напишите программу, которая возвращает сумму всех элементов в дереве.


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int sumOfTree(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    return root->data + sumOfTree(root->left) + sumOfTree(root->right);
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->left->left->left = createNode(1);
    root->left->right->left = createNode(6);
    root->right->left = createNode(13);
    root->right->right = createNode(18);
    
    int sum = sumOfTree(root);
    
    printf("Sum: %d\n", sum);
    
    return 0;
}
