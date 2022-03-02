#ifndef __DEGREEPROGRAM__
#define __DEGREEPROGRAM__

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

DEGREEPROGRAM *create(DEGREEPROGRAM*);
DEGREEPROGRAM *add(DEGREEPROGRAM*);
void append(DEGREEPROGRAM*);
SESSION input_season(SESSION);
DEGREEPROGRAM *insert_methods(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insert_begin(DEGREEPROGRAM*, DEGREEPROGRAM*);
DEGREEPROGRAM *insert_pos(DEGREEPROGRAM*,DEGREEPROGRAM*);
DEGREEPROGRAM *insert_end(DEGREEPROGRAM*,DEGREEPROGRAM*);


#endif
