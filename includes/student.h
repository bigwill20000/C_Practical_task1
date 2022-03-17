#ifndef __STUDENT__
#define  __STUDENT__

#include "session_semester_course.h"

typedef struct STUDENT
{
    int ID;
    char firstName[100];
    char lastName[100];
    char Degree_program[100];
    COURSE course; 
    SEMESTER semester;
    struct STUDENT *next;
}STUDENT;

STUDENT *createStudent(STUDENT*);
STUDENT *addStudent(STUDENT*);
STUDENT *insertStudent_begin(STUDENT*, STUDENT*); 
STUDENT *insertStudent_pos(STUDENT*,STUDENT*); //can also be void
STUDENT *insertStudent_end(STUDENT*,STUDENT*); // can also be void
STUDENT *insertStudent_methods(STUDENT*,STUDENT*);
void appendStudent(STUDENT*);
SESSION inputStudent_season(SESSION);

STUDENT *deleteStudent_begin(STUDENT*);
STUDENT *deleteStudent_end(STUDENT*);
STUDENT *deleteStudent_pos(STUDENT*);
STUDENT *deleteStudent_methods(STUDENT*);
void delete_entire_listStudent(STUDENT*);

void displayStudent(STUDENT*); 
void displayStudent_list(STUDENT*);


#endif