#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;

void insertNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(){
    Node* node = head;
    while(node != NULL){
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL \n");
}

void clearList(){
    Node* node = head;
    while(node != NULL){
        Node* nodesNext = node->next;
        free(node);

        head = nodesNext;
        node = nodesNext;
    }
}

int main(){
    insertNode(3);
    insertNode(2);
    insertNode(45);
    insertNode(7);
    insertNode(81);
    insertNode(96);
    printList();

    clearList();

    printList();

    printf("\n");
    return 0;
}