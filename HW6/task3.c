// Напишите программу, которая находит разницу между максимальным и минимальным элементом в дереве.

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

int findMin(struct Node* root) {
    if (root == NULL) {
        return 2147483647;  // Максимальное значение int для пустого поддерева
    }
    
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    
    int min = (leftMin < rightMin) ? leftMin : rightMin;
    
    return (root->data < min) ? root->data : min;
}

int findMax(struct Node* root) {
    if (root == NULL) {
        return -2147483648;  // Минимальное значение int для пустого поддерева
    }
    
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    
    int max = (leftMax > rightMax) ? leftMax : rightMax;
    
    return (root->data > max) ? root->data : max;
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
    
    int min = findMin(root);
    int max = findMax(root);
    
    int diff = max - min;
    
    printf("Different max-min: %d\n", diff);
    
    return 0;
}
