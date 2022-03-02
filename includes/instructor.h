#ifndef __INSTRUCTOR__
#define __INSTRUCTOR__

typedef enum session
{
    winter, summer
} SESSION;

typedef struct semester
{
    SESSION session;
    int Year;
}SEMESTER;

typedef struct course
{
    int CourseID;
    char CourseName[100];
}COURSE;

typedef enum grade
{
    bachelor, 
    master,
    doctorate
} GRADE;

typedef struct INSTRUCTOR
{
    int ID;
    char FirstName[100];
    char LastName[100];
    char Faculty[100];
    COURSE Course;
    SEMESTER semester;
    GRADE Grade;
    struct INSTRUCTOR *next;
}INSTRUCTOR;

//void start_Program(int*);
INSTRUCTOR *create(INSTRUCTOR*);
INSTRUCTOR *add(INSTRUCTOR*);
INSTRUCTOR *insert_begin(INSTRUCTOR*, INSTRUCTOR*); 
INSTRUCTOR *insert_pos(INSTRUCTOR*,INSTRUCTOR*); //can also be void
INSTRUCTOR *insert_end(INSTRUCTOR*,INSTRUCTOR*); // can also be void
INSTRUCTOR *insert_methods(INSTRUCTOR*,INSTRUCTOR*);
void append(INSTRUCTOR*);
SESSION input_season(SESSION);
GRADE input_grade(GRADE);

INSTRUCTOR *delete_begin(INSTRUCTOR*);
INSTRUCTOR *delete_end(INSTRUCTOR*);
INSTRUCTOR *delete_pos(INSTRUCTOR*);
INSTRUCTOR *delete_methods(INSTRUCTOR*);

void display(INSTRUCTOR*);
void display_list(INSTRUCTOR*);
//void delete_entire_list(INSTRUCTOR*)

#endif
