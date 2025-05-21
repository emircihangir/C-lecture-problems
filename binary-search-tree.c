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

int main(){
    // Problem 1
    // insertNode(5);
    // insertNode(3);
    // insertNode(19);
    // insertNode(4);
    // insertNode(2);
    // inOrder(root);

    printf("\n");
    return 0;
}