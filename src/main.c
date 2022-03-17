#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/session_semester_course.h"
#include "../includes/main.h"

int main()
{
    //Declare link lists
    STUDENT* studentsList = NULL;
    DEGREEPROGRAM *degreeProgramList = NULL;
    
    //Declare variables to be used
    COURSE course;
    SEMESTER semester;
    INSTRUCTOR instructor;
    DEGREEPROGRAM degreeProgram;

    int n = 3;

    printf("\n");
    printf("Create a Student List of Three Elements:\n");

    for (int i = 0; i < n; i++)
    {
        studentsList = addStudent(studentsList);
    }
    
    printf("\n");
    printf("Create Degree_Program List of Three Elements:\n");

    for (int i = 1; i <= n; i++)
    {
        degreeProgramList = addDegreeProgram(degreeProgramList);
        printf("\n");
    }
    
    printf("\n");
    printf("Input the infos of the Instructor to retrieve his/her Courses\n");
    appendInstructor(&instructor);
    printf("\n");

    printf("Input the infos of the Degree_Program to be searched\n");
    appendDegreeProgram(&degreeProgram);
    printf("\n");

    printf("Input the infos of the Course to be searched\n");
    appendCourse(&course);
    printf("\n");

    printf("Input the infos of the targeted Semester\n");
    appendSemester(&semester);
    printf("\n");
    
    printf("Retrieve all the courses under a specified Instructor:\n");
    retrieveCourses(degreeProgramList, degreeProgram, instructor);
    printf("\n");

    printf("Retrieve the details of all students for a course"
           "for a particular semester\n");
    retrieveDetailStudents(studentsList, course, semester);
    printf("\n");

    printf("Retrieve the name of students of a course given"
          " given by an instructor for a specified degree program:\n");
    retrieveNameStudents(studentsList, instructor, degreeProgram);
    printf("\n");

    delete_entire_listStudent(studentsList);
    delete_entire_listDegreeProgram(degreeProgramList);

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

void appendSemester(SEMESTER *semester)
{
    SESSION session = 0;
    printf("Input the Session (insert 'w'or'W','s'or'S') : ");
    semester->session = inputSession(session);
    fgetc(stdin);

    printf("Input Academic year : ");
    scanf("%d", &(semester->Year));
    fgetc(stdin);
}

SESSION inputSession(SESSION session)
{
    char ch;
    // leave a white space before %c to avoid printing twice
    scanf(" %c",&ch); 

    while (ch!='w' && ch!='W' && ch!='s' && ch!='S')
    {
        printf("Input another character : ");
        // leave a white space before %c to avoid printing twice
        scanf(" %c",&ch); 
    }   
    
    switch (ch)
    {
    case 'w' : session = winter;
        break;
    case 'W' : session = winter;
        break;
    case 's' : session = summer;
        break;
    case 'S' : session = summer;
        break;
    }
    return session;
}

void retrieveCourses(DEGREEPROGRAM *degreeProgramlist, 
        DEGREEPROGRAM degreeProgram, INSTRUCTOR instructor)
{
    DEGREEPROGRAM *degreeProgramPtr = NULL;
    int countDegreeProgram = 0;
    
    if (degreeProgramlist == NULL)
    {
        printf("There is no Degree_Program list");
        exit(0);
    }
    
    degreeProgramPtr = degreeProgramlist;

    while (degreeProgramPtr != NULL)
    {
        if (degreeProgramPtr->ID == degreeProgram.ID 
            && strcmp(degreeProgramPtr->InstructorFirstName, instructor.FirstName) == 0
            && strcmp(degreeProgramPtr->InstructorLastName, instructor.LastName) == 0)
        {
            printf("Course's ID : %d\nCourse's Name : %s\n",
            degreeProgramPtr->Course.CourseID, degreeProgramPtr->Course.CourseName);
            countDegreeProgram++;
        }
        degreeProgramPtr = degreeProgramPtr->next;
    }

    if (countDegreeProgram == 0)
    {
        printf("No courses found under the specified instructor!\n");
    }
}

void retrieveDetailStudents(STUDENT *studentList, COURSE course, SEMESTER semester)
{
    STUDENT *studentPtr = NULL;
    int countStudent = 0;

    if (studentList == NULL)
    {
        printf("There is no Student List\n");
        exit(0);
    }

    studentPtr = studentList;
    
    while (studentPtr != NULL)
    {
        if (studentPtr->course.CourseID == course.CourseID
            && studentPtr->course.CourseName == course.CourseName
            && studentPtr->semester.session == semester.session
            && studentPtr->semester.Year == semester.Year)
        {
            printf("Student ID: %d\nStudent's first name: %s\nStudent's last name: %s\n"
                "Student's degree program: %s\nCourse's ID: %d\n Course's name: %s\n"
                "Semester's session: %d\nSemester's year: %d\n",
            studentPtr->ID, studentPtr->firstName, studentPtr->lastName,
            studentPtr->Degree_program, studentPtr->course.CourseID,
            studentPtr->course.CourseName, studentPtr->semester.session,
            studentPtr->semester.Year);
            countStudent++;
        }
        studentPtr = studentPtr->next;
    }

    if (countStudent == 0)
    {
        printf("No Students' details found under the specified instructor!\n");
    }
}

void retrieveNameStudents(STUDENT *studentList, INSTRUCTOR instructor, 
    DEGREEPROGRAM degreeProgram)
{
    STUDENT *studentPtr = NULL;
    int count_student = 0;

    if (studentList == NULL)
    {
        printf("There is no student List available\n");
        exit(0);
    }
    studentPtr = studentList;

    while (studentPtr != NULL)
    {
        if (studentPtr->course.CourseID == instructor.Course.CourseID
            && studentPtr->course.CourseName == instructor.Course.CourseName
            && studentPtr->Degree_program == degreeProgram.Name)
        {
            printf("Student first name: %s\nStudent's last name: %s\n",
                studentPtr->firstName, studentPtr->lastName);
        }
        studentPtr = studentPtr->next;
    }
    if (count_student == 0)
    {
        printf("There is no list of students available");
    }
}