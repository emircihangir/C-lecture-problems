#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int* aPtr = (int*)malloc(sizeof(int));
    *aPtr = 5;
    printf("%X\n\n", aPtr);
    free(aPtr);
    printf("%X\n\n", aPtr);
    free(&aPtr);
    printf("%X\n\n", aPtr);

    printf("\n");
    return 0;
}