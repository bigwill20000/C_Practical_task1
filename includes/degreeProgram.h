#ifndef __DEGREEPROGRAM__
#define __DEGREEPROGRAM__

typedef enum session
{
    winter, summer
} SESSION;

typedef struct degreeProgram
{
    int ID;
    char Name[100];
    char Course[100];
    int Year;
    SESSION Session;
    char InstructorFirstName[100];
    char InstructorLastName[100];
    struct DEGREEPROGRAM *next;
}DEGREEPROGRAM;

DEGREEPROGRAM *create(DEGREEPROGRAM*);
DEGREEPROGRAM *add(DEGREEPROGRAM*);
void append(DEGREEPROGRAM*);
SESSION input_season(SESSION);
DEGREEPROGRAM *insert_methods(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insert_begin(DEGREEPROGRAM*, DEGREEPROGRAM*);
DEGREEPROGRAM *insert_pos(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insert_end(DEGREEPROGRAM*,DEGREEPROGRAM*);


#endif
