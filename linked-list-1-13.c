#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    struct Node* previous;
    int data;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void insertNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if(head ==  NULL && tail == NULL){
        head = tail = newNode;
        newNode->previous = NULL;
        newNode->next = NULL;
    } else{
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
}

void printList(){
    Node* _node = head;
    printf("Linked list: ");
    while(_node != NULL){
        printf("%d", _node->data);
        if(_node != tail) printf(" -> ");
        _node = _node->next;
    }
    printf("\n");
}

int main(){
    insertNode(3);
    insertNode(1);
    insertNode(2);
    insertNode(3);
    insertNode(4);
    insertNode(3);
    insertNode(5);
    insertNode(3);
    printList();

    int input;
    printf("enter number to delete: "); scanf("%d", &input);

    Node* node = head;
    while(node != NULL){
        if(node->data == input){
            Node* nodesPrevious = node->previous;
            Node* nodesNext = node->next;

            if(nodesPrevious != NULL){
                nodesPrevious->next = nodesNext;
            } else{
                // update the head value.
                head = nodesNext;
            }
            if(nodesNext != NULL){
                nodesNext->previous = nodesPrevious;
            } else{
                // update the tail value.
                tail = nodesPrevious;
            }

            free(node);
            node = nodesNext;
            continue;
        }
        node = node->next;
    }

    printList();

    printf("\n");
    return 0;
}