#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void headInsert(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAfter(struct Node* refNode, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = refNode->next;
    refNode->next = newNode;
}

void printList(){
    printf("\nLinked list: ");
    struct Node* current = head;
    while(current != NULL){
        printf("%d", current->data);
        current = current->next;
        if(current != NULL) printf(" -> ");
    }
    printf("\n");
}

int main(){
    int input;
    while(1){
        printf("enter a number: "); scanf("%d", &input);
        if(input == -1) break;

        if(head == NULL) headInsert(input);
        else{
            struct Node* currentNode = head;
            if(input < head->data) headInsert(input);
            else{
                while(1){
                    if((currentNode->next == NULL) || (currentNode->next->data > input)){
                        insertAfter(currentNode, input);
                        break;
                    }
                    currentNode = currentNode->next;
                }
            }
        }

        printList();
    }
    
    printf("\n");
    return 0;
}