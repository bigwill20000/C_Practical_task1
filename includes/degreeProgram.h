#ifndef __DEGREEPROGRAM__
#define __DEGREEPROGRAM__

#include "session_semester_course.h"

typedef struct DEGREEPROGRAM
{
    int ID;
    char Name[100];
    char InstructorFirstName[100];
    char InstructorLastName[100];
    COURSE Course;
    SEMESTER semester;
    struct DEGREEPROGRAM *next;
}DEGREEPROGRAM;

DEGREEPROGRAM *createDegreeProgram(DEGREEPROGRAM*);
DEGREEPROGRAM *addDegreeProgram(DEGREEPROGRAM*);
void appendDegreeProgram(DEGREEPROGRAM*);
SESSION inputDegreeProgram_season(SESSION);
DEGREEPROGRAM *insertDegreeProgram_methods(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insertDegreeProgram_begin(DEGREEPROGRAM*, DEGREEPROGRAM*);
DEGREEPROGRAM *insertDegreeProgram_pos(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insertDegreeProgram_end(DEGREEPROGRAM*,DEGREEPROGRAM*);

DEGREEPROGRAM *deleteDegreeProgram_begin(DEGREEPROGRAM*);
DEGREEPROGRAM *deleteDegreeProgram_end(DEGREEPROGRAM*);
DEGREEPROGRAM *deleteDegreeProgram_pos(DEGREEPROGRAM*);
DEGREEPROGRAM *deleteDegreeProgram_methods(DEGREEPROGRAM*);
void delete_entire_listDegreeProgram(DEGREEPROGRAM*);

void displayDegreeProgram(DEGREEPROGRAM*);
void displayDegreeProgram_list(DEGREEPROGRAM*);

#endif
