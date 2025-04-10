#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    struct Node* previous;
    char data;
    struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;
int listLength = 0;

void insertNode(char data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->previous = tail;

    if(head == NULL && tail == NULL) head = tail = newNode;
    else{
        tail->next = newNode;
        tail = newNode;
    }
    
    listLength += 1;
}

int isPalindrome(){
    for (int i = 0; i < listLength / 2; i++)
    {
        Node* _head = head;
        Node* _tail = tail;
        for(int j = 0; j < i; j++) _head = _head->next;
        for(int j = 0; j < i; j++) _tail = _tail->previous;

        if(_head->data != _tail->data) return 0;
    }

    return 1;
}

int main(){
    char input[50];
    printf("kelime gir: "); scanf("%s", input);

    // loop through the letters of the input word.
    int currentCI = 0; // current char index.
    while(input[currentCI] != 0){
        insertNode(input[currentCI]);
        currentCI += 1;
    }

    printf("%d", isPalindrome());
    
    printf("\n");
    return 0;
}