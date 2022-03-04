#ifndef __MAIN__
#define __MAIN__

#include "degreeProgram.h"
#include "instructor.h"
#include "student.h"

void retrieveCourses(DEGREEPROGRAM *DPlist, DEGREEPROGRAM degreeProgram, INSTRUCTOR instructor);
void retrieveDetailStudents(STUDENT *studentList, COURSE course, SEMESTER semester);
void retrieveNameStudents(STUDENT *studentList, COURSE course,INSTRUCTOR instructor, DEGREEPROGRAM degreeProgram);

#endif