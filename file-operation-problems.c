#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getMax(int array[], int array_length)
{
    int max = array[0];
    for (int i = 1; i < array_length; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    return max;
}

void printArray(int* array, int length)
{
    for (int i = 0; i < length; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void retrieveLinesNumbers(int* resultArray, char* line){
    int i = 0, intSoFar = 0, raAC = 0;
    while(*(line + i) != 0){
        char currentChar = *(line + i);
        if(currentChar != 9){
            intSoFar *= 10;
            intSoFar += (currentChar - '0');
        }
        else{
            *(resultArray + raAC) = intSoFar;
            raAC += 1;
            intSoFar = 0;
        }
        i++;
    }
}

int len(char* string){
    int length = 0;
    while(*(string + length) != 0) length+=1;
    return length;
}

void removeNewlineChar(char* string){
    int i = 0;
    while(*(string + i) != 10) i+= 1;
    *(string + i) = 0;
}

int main(){
    srand(time(NULL));
    // Problem 1
    // int input;
    // FILE* fptr = fopen("a-file.txt", "w");
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d. sayıyı giriniz: ", (i + 1)); scanf("%d", &input);
    //     fprintf(fptr, "%d\n", input);
    // }
    
    // Problem 2
    // FILE* fptr = fopen("randomNumber.txt", "w");
    // for (int row = 0; row < 10; row++)
    // {
    //     for (int column = 0; column < 5; column++)
    //     {
    //         fprintf(fptr, "%d\t", (rand() % 11));
    //     }
    //     fprintf(fptr, "\n");
    // }
    
    // Problem 3
    // FILE* fptr = fopen("randomNumber.txt", "r");
    // FILE* fptr2 = fopen("randomNumbersModified.txt", "w");
    // if(fptr == NULL || fptr2 == NULL){
    //     printf("Unable to open the file.\n");
    //     return 1;
    // }
    // int rowMaximums[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     int currentRowNumbers[5];
    //     for (int j = 0; j < 5; j++)
    //     {
    //         fscanf(fptr, "%d", currentRowNumbers + j);
    //     }
    //     rowMaximums[i] = getMax(currentRowNumbers, 5);
    // }
    // fseek(fptr, 0, SEEK_SET);
    // char currentLine[100];
    // for(int i = 0; i < 10; i++){
    //     fgets(currentLine, 100, fptr);
    //     currentLine[len(currentLine) - 1] = 0;
    //     fprintf(fptr2, "%s -> %d\n", currentLine, rowMaximums[i]);
    // }
    // fclose(fptr);
    // fclose(fptr2);

    // Problem 4
    // FILE* fptr = fopen("names.bin", "wb");
    // char input[100];
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("isim giriniz: "); scanf("%s", input);
    //     int l = len(input);
    //     *(input + l) = '\n';
    //     *(input + l + 1) = 0;
    //     fwrite(input, l + 1, 1, fptr);
    // }
    // fclose(fptr);
    
    // Problem 6
    
    return 0;
}