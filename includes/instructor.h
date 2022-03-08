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
INSTRUCTOR *createInstructor(INSTRUCTOR*);
INSTRUCTOR *addInstructor(INSTRUCTOR*);
INSTRUCTOR *insertInstructor_begin(INSTRUCTOR*, INSTRUCTOR*); 
INSTRUCTOR *insertInstructor_pos(INSTRUCTOR*,INSTRUCTOR*); //can also be void
INSTRUCTOR *insertInstructor_end(INSTRUCTOR*,INSTRUCTOR*); // can also be void
INSTRUCTOR *insertInstructor_methods(INSTRUCTOR*,INSTRUCTOR*);
void appendInstructor(INSTRUCTOR*);
SESSION inputInstructor_season(SESSION);
GRADE inputInstructor_grade(GRADE);

INSTRUCTOR *deleteInstructor_begin(INSTRUCTOR*);
INSTRUCTOR *deleteInstructor_end(INSTRUCTOR*);
INSTRUCTOR *deleteInstructor_pos(INSTRUCTOR*);
INSTRUCTOR *deleteInstructor_methods(INSTRUCTOR*);

void displayInstructor(INSTRUCTOR*);
void displayInstructor_list(INSTRUCTOR*);
//void delete_entire_listInstructor(INSTRUCTOR*)

#endif
