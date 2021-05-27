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
    DEGREE_PROGRAM *degree;
    COURSE**  courses; //linked list of course pointers;
    STUDENT *next;
}STUDENT;

typedef struct instructor
{
    int id;
    char firstName[100];
    char lastName[100];
    char grade[100];
    char faculty[100];
    COURSE** courses;
    INSTRUCTOR *next;
}INSTRUCTOR;


INSTRUCTOR hire_instructor(int id, char* first_name, char* last_name, char* grade, char* faculty);
INSTRUCTOR* add_instructor(INSTRUCTOR instructor, INSTRUCTOR* list);
STUDENT register_student(int id, char* first_name, char* last_name, int matriculation, DEGREE_PROGRAM* degree);
STUDENT* add_student(STUDENT student, STUDENT* list);
COURSE create_course(int id, char* name, SEMESTER semester);
COURSE* add_course(COURSE course, COURSE* list);

#endif