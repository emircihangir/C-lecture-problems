#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50
char stack[N];
int stackTop = -1;

void push(char item){
    if(stackTop == N-1){
        printf("Stack is full. Cannot add %c", item);
        return;
    }

    stack[++stackTop] = item;
}
char pop(){
    if(stackTop == -1){
        printf("Stack is empty. Cannot pop any further.");
        return 0;
    }
    
    return stack[stackTop--];
}

int main(){
    char input[N];
    printf("isim giriniz: "); scanf("%s", input);
    int counter = 0;
    while(input[counter] != 0){
        push(input[counter]);
        counter += 1;
    }

    for (int i = 0; i < counter; i++)
    {
        printf("%c", pop());
    }
    
    
    printf("\n");
    return 0;
}