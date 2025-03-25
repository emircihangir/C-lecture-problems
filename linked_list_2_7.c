#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char customerName[50], address[50], product[50];
}Order;

typedef struct{
    Order order;
    struct Node* next;
}Node;

Node* firstNode = NULL;
Node* lastNode = NULL;

void enqueue(Order order){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->order = order;
    newNode->next = NULL;

    if(lastNode != NULL) lastNode->next = newNode;
    lastNode = newNode;

    if(firstNode == NULL) firstNode = lastNode;
}

void dequeue(){
    if(firstNode == NULL){
        printf("Queue is empty. Cannot dequeue. \n");
        return;
    }

    firstNode = firstNode->next;
}

void printQueue(){
    printf("name \t address \t product \n");
    printf("--------------------------------\n");

    for(Node* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
        printf("%s \t %s \t %s \n", currentNode->order.customerName, currentNode->order.address, currentNode->order.product);
}

int main(){
    Order firstOrder = {"emir", "malatya", "pen"};

    Order secondOrder = {"ahmet", "istanbul", "book"};

    enqueue(firstOrder);
    enqueue(secondOrder);

    printQueue();
    printf("\n");

    dequeue();
    printQueue();
    printf("\n");
    
    dequeue();
    printQueue();
    printf("\n");

    dequeue();

    printf("\n");
    return 0;
}