#ifndef ATTENDACE
#define ATTENDACE

typedef enum
{
    winter, Summer
} season;

typedef struct
{
    char *firstName;
    char *lastName;
    int matriNumber;
    char *degreeProgram;
    char *coursesAttended;
    
}student;

typedef struct
{
    char *firstName;
    char *lastName;
    char *academicGrade;
    char *faculty;
    course courseTaught;
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


typedef struct 
{
    int courseID;
    char *courseName;
    semester Semester;

}course;

#endif