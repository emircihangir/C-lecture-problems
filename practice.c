#include <stdio.h>

int strLen(char* str){
    int length = 0;
    while(*(str + length) != 0) length += 1;
    return length;
}

int main(){
    FILE* fptr = fopen("names.txt", "r");
    FILE* fptr2 = fopen("nameLengths.txt", "w");
    char currentLine[50];
    while(fgets(currentLine, 50, fptr)){
        int lineLength = strLen(currentLine);
        // remove \n character from line
        *(currentLine + lineLength - 1) = 0;
        lineLength = strLen(currentLine);

        fprintf(fptr2, "%s\t%d\n", currentLine, lineLength);
    }
    fclose(fptr);
    fclose(fptr2);

    printf("\n");
    return 0;
}