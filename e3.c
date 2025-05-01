#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) head = newNode;
    else{
        struct Node* lastNode = head;
        while(lastNode->next != NULL) lastNode = lastNode->next;
    
        lastNode->next = newNode;
    }    
}

void printTheList(){
    printf("Linked list: ");
    struct Node* current = head;
    while(current != NULL){
        printf("%d", current->data);
        current = current->next;
        printf(" -> ");
    }
    printf("NULL \n");
}

int main(){
    
    int array[6] = {2,6,4,12,18,2};
    for (int i = 0; i < 6; i++)
    {
        insertNode(array[i]);
    }

    printTheList();

    struct Node* a = head;
    struct Node* b = head->next;

    while(b != NULL){
        int average = (a->data + b->data) / 2;
        printf("%d %d %d \n", a->data, b->data, average);

        // add average after a
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = average;
        a->next = newNode;
        newNode->next = b;
        
        a = b;
        b = b->next;
    }

    printTheList();
    
    printf("\n");
    return 0;
}