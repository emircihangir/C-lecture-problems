#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 50
char stack[N];
int top = -1;

void printStack(){
    printf("stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf(" %d", *(stack + i));
    }
    printf("\n");
}

void push(char item){
    if(top == N-1){
        printf("stack is full.\n");
        return;
    }
    stack[++top] = item;
}

char pop(){
    if(top == -1){
        printf("stack is empty.\n");
        return 0;
    }
    return *(stack + (top--));
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
    // srand(time(NULL));
    // for (int i = 0; i < 10; i++)
    // {
    //     int number = rand() % 10 + 1;
    //     push(number);
    // }
    // printStack();
    // int input;
    // printf("how many to remove? "); scanf("%d", &input);
    // for (int i = 0; i < input; i++) pop();
    // printStack();
    
    // Problem 5
    char input[50];
    printf("enter a word: "); scanf("%s", input);
    for (int i = 0; *(input + i) != 0; i++) push(*(input + i));
    for (int i = 0; *(input + i) != 0; i++) printf("%c", pop());

    printf("\n");
    return 0;
}