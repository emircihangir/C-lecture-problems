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
    newNode->next = NULL;
    if(head == NULL) head = newNode;
    else{
        Node* lastNode = head;
        while(lastNode->next != NULL) lastNode = lastNode->next;
    
        lastNode->next = newNode;
    }    
}

void printTheList(){
    printf("Linked list: ");
    Node* current = head;
    while(current != NULL){
        printf("%d", current->data);
        current = current->next;
        if(current != NULL) printf(" -> ");
    }
    printf("\n");
}

int listLength(){
    Node* current = head;
    int length = 0;
    while(current != NULL){
        length += 1;
        current = current->next;
    }
    return length;
}

int sumAllItems(){
    int sum = 0;

    Node* current = head;
    while(current != NULL){
        sum += current->data;
        current = current->next;
    }

    return sum;
}

int main(){
    //* Questions #1-3
    // while(1){
    //     int input;
    //     printf("> ");
    //     scanf("%d", &input);
    //     if(input != -1) insertNode(input);
    //     else{
    //         printTheList();
    //         printf("List length: %d \n", listLength());
    //         printf("Sum of all items: %d \n", sumAllItems());
    //         printf("Average of all items: %d \n", (sumAllItems() / listLength()));
    //         break;
    //     }
    // }
    
    //* Question #4
    // insertNode(1);
    // insertNode(6);
    // insertNode(2);
    // insertNode(8);
    // insertNode(23);
    // printTheList();

    // int input;
    // printf("enter number to search: "); scanf("%d", &input);
    // int index = 0;
    // Node* temp = head;
    // while(temp != NULL){
    //     if(temp->data == input) break;

    //     index += 1;
    //     temp = temp->next;
    // }
    // if(temp != NULL){
    //     printf("index of %d is %d", input, index);
    // } else{
    //     printf("couldn't find %d", input);
    // }

    //* Question #5
    // insertNode(1);
    // insertNode(6);
    // insertNode(2);
    // insertNode(8);
    // insertNode(23);
    // printTheList();

    // int input;
    // printf("enter the index: "); scanf("%d", &input);

    // Node* temp = head;
    // for(int i = 0; i < input; i++) temp = temp->next;

    // printf("the element with the index %d is %d", input, temp->data);

    printf("\n");
    return 0;
}