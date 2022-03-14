#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/session_semester_course.h"
#include "../includes/main.h"

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
    printf("\n");
    printf("Create Degree_Program List of Three Elements:\n");

    for (int i = 1; i <= n; i++)
    {
        degreeProgramList = addDegreeProgram(degreeProgramList);
        printf("\n");
    }
    
    printf("\n");
    printf("Input the Info of the Instructor to retrieve his/her Courses\n");
    appendInstructor(&instructor);
    printf("\n");

    printf("Input the infos of the Degree_Program to be searched\n");
    appendDegreeProgram(&degreeProgram);
    printf("\n");
    //appendStudent(&student);
    //appendCourse(&course);
    
    printf("Retrieve all the courses under a specified Instructor:\n");
    retrieveCourses(degreeProgramList, degreeProgram, instructor);

    return 0;
}

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
            && strcmp(DPptr->InstructorFirstName, instructor.FirstName) == 0
            && strcmp(DPptr->InstructorLastName, instructor.LastName) == 0)
        {
            printf("Course's ID : %d\nCourse's Name : %s\n",
            DPptr->Course.CourseID, DPptr->Course.CourseName);
            count++;
        }
        DPptr = DPptr->next;
    }

    if (count == 0)
    {
        printf("No courses found under the specified instructor!\n");
    }
}