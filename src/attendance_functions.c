#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/attendance.h";

INSTRUCTOR *hire_Instructor()
{
    INSTRUCTOR *instructor = (INSTRUCTOR*)malloc(sizeof(INSTRUCTOR));
    instructor->next = NULL;
    return instructor;
}

INSTRUCTOR *add_instructor(INSTRUCTOR *instructor, int Id, char *First_Name, char *Last_Name,
                           char *Grade, char *Faculty, int id_courses, char *courses_name)
{
    INSTRUCTOR *temp, *ptr;
    //1. Create Element:
    temp = hire_Instructor();
    temp->id = Id;
    strcpy(temp->firstName, First_Name);
    strcpy(temp->lastName, Last_Name);
    strcpy(temp->grade, Grade);
    strcpy(temp->faculty, Faculty);
    temp->courses->id = id_courses;
    strcpy(temp->courses->name, courses_name);

    //2.0 Insert (if list empty)
    if (instructor == NULL)
    {
        instructor = temp;
    }
    //2.1 Insert if not NULL
    else
    {
        ptr = instructor;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;   //2.1.1 Find the last adress
        }
        ptr->next = temp;
    }
    return instructor;
}

DEGREE_PROGRAM *register_degree_program()
{
    DEGREE_PROGRAM *degree_program = (DEGREE_PROGRAM*)malloc(sizeof(DEGREE_PROGRAM));
    degree_program->next = NULL;
    return degree_program;
}

DEGREE_PROGRAM *add_degree_program(DEGREE_PROGRAM *degree_program, int degree_Id, char *degree_name,
                                   int dp_course_id, char *dp_course_name)
{
    DEGREE_PROGRAM *temp, *ptr;
    //1. Create Element:
    temp = register_degree_program();
    temp->id = degree_Id;
    strcpy(temp->name, degree_name);
    temp->courses->id = dp_course_id;
    strcpy(temp->courses->name, dp_course_name);

    //2.0 Insert (if list empty)
    if (degree_program == NULL)
    {
        degree_program = temp;
    }
    //2.1 Insert if not NULL
    else
    {
        ptr = degree_program;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;   //2.1.1 Find the last adress
        }
        ptr->next = temp;
    }
    return degree_program;
}

STUDENT *register_student()
{
    STUDENT *student = (STUDENT*)malloc(sizeof(STUDENT));
    student->next = NULL;
    return student;
}

STUDENT *add_student(STUDENT *student, char* First_name, char* Last_name,
                     int Matriculation, char *degree_prgram,
                     char *course, int year, char *season)
{
    STUDENT *temp, *ptr;
    //1. Create Element:
    temp = register_student();
    strcpy(temp->firstName, First_name);
    strcpy(temp->lastName, Last_name);
    temp->matriculationNumber = Matriculation;

    //2.0 Insert (if list empty)
    if (student == NULL)
    {
        student = temp;
    }
    //2.1 Insert of not empty
    else
    {
        ptr = student;
        while (ptr->next != NULL)
        {
            ptr = ptr->next; 
        }
        ptr->next = temp;
    }
    return student;
}

COURSE *register_course()
{
    COURSE *course = (COURSE*)malloc(sizeof(COURSE));
    course->next = NULL;
    return course;
}

COURSE *add_course(COURSE *course, int course_id, char *course_name,
                   char *instructor_fname, char *instructor_lname,
                   int year, char *season)
{
    COURSE *temp, *ptr;
    //1. Create Element:
    temp = register_course();
    temp->id = course_id;
    strcpy(temp->name, course_name);
    strcpy(temp->instructor->firstName, instructor_fname);
    strcpy(temp->instructor->lastName, instructor_lname);
    temp->semester->year = year;
    strcpy(temp->semester->season, season);

    //2.0 Insert if list empty
    if(course == NULL)
    {
        course = temp;
    }
    //2.1 Insert if not empty
    else
    {
        ptr = course;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return course;
}

void retrieve_Courses(DEGREE_PROGRAM *degree_programs, char dp_name,
                      char *instructor_fname, char *instructor_lname)
{
    DEGREE_PROGRAM *ptr1 = degree_programs; //pointer at the begining of the list of degree programs
    printf("Lectures given by (Pr) %s %s :\n", instructor_fname, instructor_lname);
    while (ptr1 != NULL)
    {

        if ( ptr1->name == dp_name && ptr1->courses->instructor->firstName == instructor_fname
            && ptr1->courses->instructor->lastName == instructor_lname);
        {
            printf("%s\n", ptr1->courses->name);
        }
        ptr1 = ptr1->next;
    }
    
}

void retrieve_students_details(STUDENT *students, char *course, int year, char *season)
{
    STUDENT *ptr = students;
    while (ptr != NULL)
    {
        if (ptr->courses->name == course &&
            ptr->courses->semester->year == year &&
            ptr->courses->semester->season == season)
        {
            printf("First Name: %s\nLast Name: %s\nMatriculation Number: %d\n"
                   "Degree program: %s\nYear: %d\n Season: %s\n",
                   ptr->firstName, ptr->lastName, ptr->matriculationNumber, ptr->degree->name,
                   ptr->semester->year,ptr->semester->season);
            printf("\n\n");
        }
        ptr = ptr->next;
    }
}

void retrieve_names_of_students(STUDENT *students, char *course, char *instructor_fname,
                                char *instructor_lname, char *degree_program)
{
    STUDENT *ptr = students;
    while (ptr != NULL)
    {
        if(ptr->courses->name == course &&
           ptr->courses->instructor->firstName == instructor_fname &&
           ptr->courses->instructor->lastName == instructor_lname &&
           ptr->degree->name == degree_program)
        {
            printf("First name: %s  Last Name: %s\n", ptr->firstName, ptr->lastName);
        }
        ptr = ptr->next;
    }
    
}
