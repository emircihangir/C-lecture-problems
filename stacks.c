#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
int stack[N];
int top = -1;

void printStack(){
    printf("stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf(" %d", *(stack + i));
    }
    printf("\n");
}

void push(int item){
    if(top == N-1){
        printf("stack is full.\n");
        return;
    }
    stack[++top] = item;
}

void pop(){
    if(top == -1){
        printf("stack is empty.\n");
        return;
    }
    top -= 1;
}

int main(){
    // Problem 1
    // srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     int number = rand() % 10 + 1;
    //     push(number);
    // }
    // printStack();

    // Problem 2
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int number = rand() % 10 + 1;
        push(number);
    }
    printStack();
    int input;
    printf("how many to remove? "); scanf("%d", &input);
    for (int i = 0; i < input; i++) pop();
    printStack();
    

    printf("\n");
    return 0;
}