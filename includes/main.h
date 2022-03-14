#ifndef __MAIN__
#define __MAIN__

#include "degreeProgram.h"
#include "instructor.h"
#include "student.h"
#include "session_semester_course.h"

void appendCourse(COURSE *);
void retrieveCourses(DEGREEPROGRAM *, DEGREEPROGRAM, INSTRUCTOR);
void retrieveDetailStudents(STUDENT *, COURSE, SEMESTER);
void retrieveNameStudents(STUDENT *, COURSE, INSTRUCTOR, DEGREEPROGRAM);

#endif