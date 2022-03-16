#ifndef __MAIN__
#define __MAIN__

#include "degreeProgram.h"
#include "instructor.h"
#include "student.h"
#include "session_semester_course.h"

void appendCourse(COURSE *course);
void appendSemester(SEMESTER *semester);
SESSION inputSession(SESSION session);
void retrieveCourses(DEGREEPROGRAM *degreeProgramlist, DEGREEPROGRAM degreeProgram, INSTRUCTOR instructor);
void retrieveDetailStudents(STUDENT *studentList, COURSE course, SEMESTER semester);
void retrieveNameStudents(STUDENT *studentList, INSTRUCTOR instructor, DEGREEPROGRAM degreeProgram);

#endif