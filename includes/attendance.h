#ifndef __ATTENDANCE_SYSTEM__
#define __ATTENDANCE_SYSTEM__

typedef enum season
{
    winter, Summer
} SEASON;

typedef struct semester
{
    SEASON season;
    int year;
}SEMESTER;


typedef struct course
{
    int id;
    char name[100];
    SEMESTER semester;
    COURSE *next;
}COURSE;

typedef struct degreeProgram
{
    int id;
    char name[100];
}DEGREE_PROGRAM;

typedef struct student
{
    char firstName[100];
    char lastName[100];
    int matriculationNumber;
    DEGREE_PROGRAM *program;
    COURSE  course; //coursesAttended;
    STUDENT *next;
}STUDENT;

typedef struct instructor
{
    char firstName[100];
    char lastName[100];
    char grade[100];
    char faculty[100];
    COURSE course;
    INSTRUCTOR *next;
}INSTRUCTOR;

#endif