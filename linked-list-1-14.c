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
    insertNode(1);
    insertNode(6);
    insertNode(2);
    insertNode(8);
    insertNode(42);
    insertNode(23);
    printList();

    int input;
    printf("enter an index: "); scanf("%d", &input);

    Node* node = head;
    int counter = 0;
    while(node != NULL){
        if(counter == input){
            printf("deleting nodes after the number %d \n", node->data);
        } else if(counter > input){
            // delete the node.
            Node* nodesPrevious = node->previous;
            Node* nodesNext = node->next;
            if(nodesPrevious != NULL) nodesPrevious->next = nodesNext;
            else head = nodesNext;
            if(nodesNext != NULL) nodesNext->previous = nodesPrevious;
            else tail = nodesPrevious;

            free(node);

            counter += 1;
            node = nodesNext;
            continue;
        }

        counter += 1;
        node = node->next;
    }
    
    printList();

    printf("\n");
    return 0;
}