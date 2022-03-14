instructor.o: instructor.c
	gcc -Wall -g -std=c99 -c instructor.c

degreeProgram.o: degreeProgram.c
	gcc -Wall -g -std=c99 -c degreeProgram.c

student.o: student.c
	gcc -Wall -g -std=c99 -c student.c 

main.o: main.c
	gcc -Wall -g -std=c99 -c main.c

main_start: instructor.o degreeProgram.o student.o main.o
	gcc instructor.o degreeProgram.o student.o main.o -o main_start