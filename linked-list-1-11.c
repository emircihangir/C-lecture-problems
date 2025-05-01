#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int data;
    struct Node* next;
}Node;

Node* head1 = NULL;
Node* head2 = NULL;

void insertNode(int data, int linkedListNumber){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;

    if(linkedListNumber == 1){
        if(head1 == NULL){ // linked list is empty.
            head1 = newNode;
            newNode->next = NULL;
        } else{ // linked list is not empty.
            // retrieve the last node.
            Node* temp = head1;
            while(temp->next != NULL) temp = temp->next;

            // link the newNode to the last node.
            temp->next = newNode;
            newNode->next = NULL;
        }
        
    } else{
        if(head2 == NULL){ // linked list is empty.
            head2 = newNode;
            newNode->next = NULL;
        } else{ // linked list is not empty.
            // retrieve the last node.
            Node* temp = head2;
            while(temp->next != NULL) temp = temp->next;

            // link the newNode to the last node.
            temp->next = newNode;
            newNode->next = NULL;
        }
    }
}

void printTheList(int headNumber){
    printf("Linked list #%d: ", headNumber);
    Node* current;
    if(headNumber == 1) current = head1;
    else current = head2;
    while(current != NULL){
        printf("%d", current->data);
        current = current->next;
        if(current != NULL) printf(" -> ");
    }
    printf("\n");
}

void addToHead(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head2;
    head2 = newNode;
}

int main(){
    insertNode(1, 1);
    insertNode(6, 1);
    insertNode(2, 1);
    insertNode(8, 1);
    insertNode(23, 1);
    printTheList(1);
    
    Node* _node = head1;
    while(_node != NULL){
        addToHead(_node->data);
        _node = _node->next;
    }

    printTheList(2);
    
    printf("\n");
    return 0;
}