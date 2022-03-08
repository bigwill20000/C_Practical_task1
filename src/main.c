#include <stdio.h>
#include <stdlib.h>
#include "../includes/main.h"
//#include "../includes/instructor.h"
//#include "../includes/student.h"



int main()
{
    //Declare link lists
    STUDENT* studentsList = NULL;
    INSTRUCTOR* instructorsList = NULL;
    DEGREEPROGRAM *degreeProgramList = NULL;
    
    COURSE course;
    INSTRUCTOR instructor;
    DEGREEPROGRAM degreeProgram;
    STUDENT student;

    
    //Initialize linked lists
    //students = (STUDENT*) (malloc(sizeof(STUDENT) * 3));    
    //instructors = (INSTRUCTOR*) (malloc(sizeof(INSTRUCTOR) * 3));
    //degreeProgram = (DEGREEPROGRAM*) (malloc(sizeof(DEGREEPROGRAM) * 3));


    // MAIN PROGRAM HERE

    return 0;
}

void start_Program(int *choice)
{
    printf("\t\tMENU\t\t\n");
    printf("\t\t====\t\t\n");
    printf("1 - Add Student\n");
    printf("2 - Add Instructors\n");
    printf("3 - Add Degree Program\n");
    printf("4 - Retrieve all Courses");
    printf("5 - Retrieve Students' Infos");
    printf("6 - Retrieve Students' Names");
    printf("7 - Exit\n");
    printf("\t\t====\t\t\n");
    printf("Input your choice : ");
    scanf("%d",choice);
    printf("\n");
}