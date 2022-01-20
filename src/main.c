#include <stdio.h>
#include <stdlib.h>
#include "../includes/instructors.h"
#include "../includes/student.h"


int main()
{
    //Declare link lists
    STUDENT* students = NULL;
    INSTRUCTOR* instructors = NULL;

    //Initialize linked lists
    students = (STUDENT*) (malloc(sizeof(STUDENT) * 3));
    instructors = (INSTRUCTOR*) (malloc(sizeof(INSTRUCTOR) * 3));

    // MAIN PROGRAM HERE

    return 0;
}