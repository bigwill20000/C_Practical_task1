#ifndef ATTENDACE
#define ATTENDACE

typedef enum
{
    winter, Summer
} season;

typedef struct student
{
    char *firstName;
    char *lastName;
    int matriculationNumber;
    degreeProgram *DegreeProgram;
    course coursesAttended;
    struct  student *next;
}student;

typedef struct instructor
{
    char *firstName;
    char *lastName;
    char *academicGrade;
    char *faculty;
    course courseTaught;
    struct instructor *next;
}instructor;

typedef struct 
{
    int DegreeProgramID;
    char *nameOfTheDegree;
}degreeProgram;

typedef struct 
{
    season Season;
    int year;
}semester;


typedef struct course
{
    int courseID;
    char *courseName;
    semester Semester;
    struct course *next;
}course;

#endif