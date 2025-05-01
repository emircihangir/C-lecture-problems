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
        if(current != NULL) printf(" -> ");
    }
    printf("\n");
}

// int listLength(){
//     Node* current = head;
//     int length = 0;
//     while(current != NULL){
//         length += 1;
//         current = current->next;
//     }
//     return length;
// }

// int sumAllItems(){
//     int sum = 0;

//     Node* current = head;
//     while(current != NULL){
//         sum += current->data;
//         current = current->next;
//     }

//     return sum;
// }

// void printR(Node* currentNode){
//     if(currentNode == NULL) return;

//     printf("%d ", currentNode->data);
//     if(currentNode->next != NULL) printf("-> ");
    
//     printR(currentNode->next);
// }

// void printRreverse(Node* currentNode){
//     if(currentNode == NULL) return;

//     printRreverse(currentNode->next);

//     printf("%d ", currentNode->data);
//     if(currentNode != head) printf("-> ");
// }

double listAverage(){
    double average = 0;
    int itemCount = 0;
    struct Node* _node = head;
    while(_node != NULL){
        average += _node->data;
        itemCount += 1;
        _node = _node->next;
    }
    average /= itemCount;
    return average;
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

    //* Question #9, #10
    // insertNode(1);
    // insertNode(6);
    // insertNode(2);
    // insertNode(8);
    // insertNode(23);
    // printR(head);
    // printf("\n");
    // printRreverse(head);

    //* Question #12
    insertNode(3);
    insertNode(4);
    insertNode(1);
    insertNode(5);
    insertNode(2);
    printTheList();

    double la = listAverage();
    printf("list average: %f \n", la);

    struct Node* _previousNode = NULL;
    struct Node* _node = head;

    while(_node != NULL){
        if(_node->data < la){
            if(_node == head){
                // delete the head node.
                struct Node* _nodesNext = _node->next;
                free(_node);
                _node = _nodesNext;
                head = _nodesNext;
                continue;
            } else{
                // delete the current node.
                _previousNode->next = _node->next;
                struct Node* _nodesNext = _node->next;
                free(_node);
                _node = _nodesNext;
                continue;
            }
        }
        _previousNode = _node;
        _node = _node->next;
    }

    printTheList();

    printf("\n");
    return 0;
}