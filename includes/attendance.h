#ifndef __ATTENDANCE_SYSTEM__
#define __ATTENDANCE_SYSTEM__

typedef enum SEASON
{
    winter, Summer
} SEASON;

typedef struct SEMESTER
{
    SEASON season;
    int year;
}SEMESTER;

typedef struct COURSE
{
    int id;
    char name[100];
    INSTRUCTOR *instructor;
    SEMESTER *semester; 
    struct COURSE *next;
}COURSE;

typedef struct DEGREE_PROGRAM
{
    int id;
    char name[100];
    COURSE *courses;
    struct DEGREE_PROGRAM *next;
}DEGREE_PROGRAM;

typedef struct STUDENT
{
    char firstName[100];
    char lastName[100];
    int matriculationNumber;
    DEGREE_PROGRAM *degree;
    COURSE *courses; 
    SEMESTER *semester;
    struct STUDENT *next;
}STUDENT;
 
typedef struct INSTRUCTOR
{
    int id;
    char firstName[100];
    char lastName[100];
    char grade[100];
    char faculty[100];
    COURSE *courses;
    struct INSTRUCTOR *next;
}INSTRUCTOR;

INSTRUCTOR *hire_Instructor();
INSTRUCTOR *add_instructor(INSTRUCTOR *instructor, int Id, char *First_Name, char *Last_Name,
                           char *Grade, char *Faculty, int id_courses, char *courses_name);

STUDENT *register_student();
STUDENT *add_student(STUDENT *student, char* First_name, char* Last_name,
                     int Matriculation, char *degree_prgram,
                     char *course, int year, char *season);

COURSE *register_course();
COURSE *add_course(COURSE *course, int course_id, char *course_name,
                   char *instructor_fname, char *instructor_lname,
                   int year, char *season);

DEGREE_PROGRAM *register_degree_program();
DEGREE_PROGRAM *add_degree_program(DEGREE_PROGRAM *degree_program, int degree_Id, char *degree_name,
                                   int dp_course_id, char *dp_course_name);

void retrieve_Courses(DEGREE_PROGRAM *degree_programs, char dp_name,
                      char *instructor_fname, char *instructor_lname);

void retrieve_students_details(STUDENT *students, char *course, int year, char *season);

void retrieve_names_of_students(STUDENT *students, char *course, char *instructor_fname,
                                char *instructor_lname, char *degree_program);

#endif
