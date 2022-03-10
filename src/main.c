#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/main.h"
//#include "../includes/instructor.h"
//#include "../includes/student.h"



int main()
{
    //Declare link lists
    //STUDENT* studentsList = NULL;
    //INSTRUCTOR* instructorsList = NULL;
    DEGREEPROGRAM *degreeProgramList = NULL;
    
    //COURSE course;
    INSTRUCTOR instructor;
    DEGREEPROGRAM degreeProgram;
    //STUDENT student;

    int n = 3;

    /*for (int i = 0; i < n; i++)
    {
        studentsList = addStudent(studentsList);
    }*/
    
    /*for (int i = 0; i < n; i++)
    {
        instructorsList = addInstructor(instructorsList);
    }*/

    for (int i = 0; i < n; i++)
    {
        degreeProgramList = addDegreeProgram(degreeProgramList);
    }
    
    appendInstructor(&instructor);
    appendDegreeProgram(&degreeProgram);
    //appendStudent(&student);
    //appendCourse(&course);
    
    //Initialize linked lists
    //students = (STUDENT*) (malloc(sizeof(STUDENT) * 3));    
    //instructors = (INSTRUCTOR*) (malloc(sizeof(INSTRUCTOR) * 3));
    //degreeProgram = (DEGREEPROGRAM*) (malloc(sizeof(DEGREEPROGRAM) * 3));


    // MAIN PROGRAM HERE
    retrieveCourses(degreeProgramList, degreeProgram, instructor);

    return 0;
}

/*void start_Program(int *choice)
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
}*/

void appendCourse(COURSE *course)
{
    printf("Input Course's ID : ");
    scanf("%d", &(course->CourseID));
    fgetc(stdin);

    printf("Input Course's Name : ");
    fgets(course->CourseName, 100, stdin);
    course->CourseName[strlen(course->CourseName)-1] = 0;
}

void retrieveCourses(DEGREEPROGRAM *DPlist, 
        DEGREEPROGRAM degreeProgram, INSTRUCTOR instructor)
{
    DEGREEPROGRAM *DPptr = NULL;
    int count = 0;
    
    if (DPlist == NULL)
    {
        printf("There is no Degree_Program list");
        exit(0);
    }
    
    DPptr = DPlist;

    while (DPptr != NULL)
    {
        if (DPptr->ID == degreeProgram.ID 
            && strcpm(DPptr->InstructorFirstName, instructor.FirstName) == 0
            && strcmp(DPptr->InstructorLastName, instructor.LastName == 0))
        {
            printf("%d\n%s\n", DPptr->Course.CourseID, DPptr->Course.CourseName);
            count++;
        }
        printf("\n");
        DPptr = DPptr->next;
    }

    if (count == 0)
    {
        printf("No courses found under the specified instructor!\n");
    }
    
}