#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int data;
    struct Node* next;
}Node;

Node* top = NULL;

void push(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop(){
    if(top == NULL){
        printf("Stack is empty. Could not pop. \n");
        return;
    }
    printf("popped %d \n", top->data);
    top = top->next;
}

int main(){
    push(1);
    push(2);
    push(3);
    pop(); pop(); pop();

    pop();
    
    printf("\n");
    return 0;
}