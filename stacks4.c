#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
int stack[N];
int stackTop = -1;

void push(int item){
    if(stackTop == N - 1){
        printf("Stack is full. Cannot add %d", item);
        return;
    }
    stackTop += 1;
    stack[stackTop] = item;
}
int stackIsEmpty(){
    return (stackTop == -1);
}
int pop(){
    if(stackIsEmpty() == 0){
        int poppedItem = stack[stackTop];
        stackTop -= 1;
        return poppedItem;
    }
    else{
        printf("Stack is empty. Cannot pop any further.");
        return 0;
    }
}
void printStack(){
    if(stackIsEmpty()){
        printf("Stack is empty. \n");
        return;
    }

    printf("stack:");
    for (int i = 0; i <= stackTop; i++)
    {
        printf(" %d", stack[i]);
    }
    printf("\n");
}

int queue[N]; // linear queue
int queueFront = -1;
int queueRear = -1;

void enqueue(int item){
    if(queueRear != N-1) queue[++queueRear] = item;
    else{
        printf("Queue is full. Cannot add %d", item);
        return;
    }

    if(queueFront == -1) queueFront = 0;
}
void dequeue(){
    if(queueFront == queueRear){
        queueFront = -1;
        queueRear = -1;
        return;
    }
    queueFront += 1;
}
void printQueue(){
    printf("queue:");
    for (int i = queueFront; i <= queueRear; i++)
    {
        printf(" %d", queue[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));

    // initialize the stack
    for (int i = 0; i < N; i++){
        int item = rand() % 11;
        push(item);
    }
    
    printStack();

    int input;
    printf("how many values do you want to transfer to the queue? "); scanf("%d", &input);
    for (int i = 0; i < input; i++) enqueue(pop());
    
    printQueue();
    printStack();

    printf("\n");
    return 0;
}