#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    struct TreeNode* left;
    struct TreeNode* right;
    int data;
}TreeNode;

TreeNode* root = NULL;

void insertNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if(root == NULL) root = newNode;
    else{
        TreeNode* _node = root;
        while(1){
            if(data <= _node->data){
                if(_node->left != NULL) _node = _node->left;
                else{
                    // place the newNode to the left
                    _node->left = newNode;
                    break;
                }
            } else{
                if(_node->right != NULL)_node = _node->right;
                else{
                    // place the newNode to the right
                    _node->right = newNode;
                    break;
                }
            }
        }
    }
}

void preOrder(TreeNode* currentNode){
    if(currentNode == NULL) return;

    printf("%d ", currentNode->data);
    preOrder(currentNode->left);
    preOrder(currentNode->right);
}

void inOrder(TreeNode* currentNode){
    if(currentNode == NULL) return;

    inOrder(currentNode->left);
    printf("%d ", currentNode->data);
    inOrder(currentNode->right);
}

void postOrder(TreeNode* currentNode){
    if(currentNode == NULL) return;

    postOrder(currentNode->left);
    postOrder(currentNode->right);
    printf("%d ", currentNode->data);
}

void reverseOrder(TreeNode* currentNode){
    if(currentNode == NULL) return;

    reverseOrder(currentNode->right);
    printf("%d ", currentNode->data);
    reverseOrder(currentNode->left);
}

int evenCounter = 0;
void howManyEvens(TreeNode* currentNode){
    if(currentNode == NULL) return;

    howManyEvens(currentNode->left);
    if((currentNode->data % 2) == 0) evenCounter += 1;
    howManyEvens(currentNode->right);
}

int search(int data, TreeNode* currentNode, int stepCounter){
    if(currentNode == NULL) return -1;
    if(currentNode->data == data) return stepCounter;

    if(data < currentNode->data) return search(data, currentNode->left, stepCounter+1);
    if(data > currentNode->data) return search(data, currentNode->right, stepCounter+1);
}

TreeNode* searchNode(int data, TreeNode* currentNode){
    if(currentNode == NULL) return NULL;
    if(currentNode->data == data) return currentNode;

    if(data < currentNode->data) return searchNode(data, currentNode->left);
    if(data > currentNode->data) return searchNode(data, currentNode->right);
}

void addToAll(int n, TreeNode* currentNode){
    if(currentNode == NULL) return;

    addToAll(n, currentNode->left);
    currentNode->data += n;
    addToAll(n, currentNode->right);
}

int main(){
    // Problem 1
    // insertNode(5);
    // insertNode(3);
    // insertNode(19);
    // insertNode(4);
    // insertNode(2);
    // inOrder(root);

    // Problem 3
    // insertNode(2);
    // insertNode(5);
    // insertNode(4);
    // insertNode(3);
    // insertNode(6);
    // insertNode(19);
    // insertNode(8);
    // reverseOrder(root);

    // Problem 4
    // insertNode(2);
    // insertNode(5);
    // insertNode(4);
    // insertNode(3);
    // insertNode(6);
    // insertNode(19);
    // insertNode(8);
    // howManyEvens(root);
    // printf("%d ", evenCounter);

    // Problem 5
    // insertNode(2);
    // insertNode(5);
    // insertNode(4);
    // insertNode(3);
    // insertNode(6);
    // insertNode(19);
    // insertNode(8);
    // int result = search(19, root, 0);
    // if(result != -1) printf("found in %d steps.", result);
    // else printf("not found");

    // Problem 6
    // insertNode(2);
    // insertNode(5);
    // insertNode(4);
    // insertNode(3);
    // insertNode(6);
    // insertNode(19);
    // insertNode(8);
    // TreeNode* result = searchNode(8, root);
    // if(result != NULL) inOrder(result);
    // else printf("not found");
    
    // Problem 7
    insertNode(2);
    insertNode(5);
    insertNode(4);
    insertNode(3);
    insertNode(6);
    insertNode(19);
    insertNode(8);

    printf("before: "); inOrder(root);
    printf("\n");
    addToAll(2, root);
    printf("after:  "); inOrder(root);

    printf("\n");
    return 0;
}