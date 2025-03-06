#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10
int stack[N];
int top = -1;

void printStack(){
    printf("stack: ");
    for (int i = 0; i < N; i++)
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

int main(){
    // Problem 1
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int number = rand() % 10 + 1;
        push(number);
    }
    printStack();

    printf("\n");
    return 0;
}