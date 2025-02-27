#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int* array, int wanted, int leftIndex, int rightIndex){
    int middleIndex = (leftIndex + rightIndex) / 2;
    int miElement = *(array + middleIndex);

    if(wanted < miElement){
        return binarySearch(array, wanted, leftIndex, middleIndex - 1);
    }
    else if(miElement < wanted){
        return binarySearch(array, wanted, middleIndex + 1, rightIndex);
    }
    else{
        return middleIndex;
    }
}

int main(){
    // Problem 6
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int result = binarySearch(array, 10, 0, 10);
    printf("%d", result);

    printf("\n");
    return 0;
}