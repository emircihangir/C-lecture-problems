#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int studentNumber, midtermScore, finalScore;
}Student;

typedef struct{
    Student student;
    struct Node* next;
}Node;

Node* head = NULL;

void addStudent(Student student){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->student = student;

    // add to the beginning for simplicity.
    newNode->next = head;
    head = newNode;
}

void printTheList(){
    Node* current = head;

    printf("no\t\tmidterm\t\tfinal \n");
    while(current != NULL){
        printf("%d\t\t%d\t\t%d \n", current->student.studentNumber, current->student.midtermScore, current->student.finalScore);
        current = current->next;
    }
}

void searchStudent(int studentNumber){

    Node* current = head;
    while(current != NULL){
        if(current->student.studentNumber == studentNumber){
            printf("student #%d's midterm score: %d final score: %d", current->student.studentNumber, current->student.midtermScore, current->student.finalScore);
            return;
        }
        
        current = current->next;
    }

    printf("Couldn't find student #%d", studentNumber);
}

int main(){
    int N;
    printf("enter the N value: "); scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        Student newStudent;
        printf("enter studentNumber midtermScore finalScore \n");
        scanf("%d %d %d", &newStudent.studentNumber, &newStudent.midtermScore, &newStudent.finalScore);

        addStudent(newStudent);
    }
    
    // printTheList();

    // print every student's average score
    printf("\naverage scores: \n");
    Node* current = head;
    float classAverage = 0;
    while(current != NULL){
        float averageScore = (current->student.midtermScore * 0.4 + current->student.finalScore * 0.6);
        classAverage += (averageScore / N);
        printf("student #%d: %.2f \n", current->student.studentNumber, averageScore);
        current = current->next;
    }
    
    printf("\nclass average score: %.2f \n", classAverage);

    int snInput; // student number input
    printf("\nenter student number to search: "); scanf("%d", &snInput);
    searchStudent(snInput);

    printf("\n");
    return 0;
}