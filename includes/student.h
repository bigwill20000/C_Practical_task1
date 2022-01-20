#ifndef __STUDENT__
#define  __STUDENT__

typedef enum session
{
    winter, summer
} SESSION;

typedef struct STUDENT
{
    int ID;
    char firstName[100];
    char lastName[100];
    char Course[100];
    char Degree_program[100]; 
    SESSION session;
    int year;
    struct STUDENT *next;
}STUDENT;

//void start_Program(int*);
STUDENT *create(STUDENT*);
STUDENT *add(STUDENT*);
STUDENT *insert_begin(STUDENT*, STUDENT*); 
STUDENT *insert_pos(STUDENT*,STUDENT*); //can also be void
STUDENT *insert_end(STUDENT*,STUDENT*); // can also be void
STUDENT *insert_methods(STUDENT*,STUDENT*);
void append(STUDENT*);
SESSION input_season(SESSION);

STUDENT *delete_begin(STUDENT*);
STUDENT *delete_end(STUDENT*);
STUDENT *delete_pos(STUDENT*);
STUDENT *delete_methods(STUDENT*);

void display(STUDENT*); 
void display_list(STUDENT*);
//void delete_entire_list(INSTRUCTOR*)

#endif