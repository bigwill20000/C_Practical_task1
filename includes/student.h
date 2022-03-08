#ifndef __STUDENT__
#define  __STUDENT__

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

//void start_Program(int*);
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

void displayStudent(STUDENT*); 
void displayStudent_list(STUDENT*);
//void delete_entire_list(INSTRUCTOR*)

#endif