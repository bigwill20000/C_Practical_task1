#ifndef __SESSION_SEMESTER_COURSE__
#define __SESSION_SEMESTER_COURSE__

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

#endif