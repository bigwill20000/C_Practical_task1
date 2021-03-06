#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/session_semester_course.h"
#include "../includes/student.h"


STUDENT *createStudent(STUDENT *student)
{
    student =(STUDENT*) malloc(sizeof(STUDENT));
    if(student == NULL)
        return NULL;
    return student;
}

STUDENT *addStudent(STUDENT* list)
{
    STUDENT *newStudent = NULL;
    newStudent = createStudent(newStudent);
    appendStudent(newStudent);

    if (list == NULL)
        list = newStudent;
    else    
        list = insertStudent_methods(list, newStudent);
    return list;
}

void appendStudent(STUDENT *student)
{
    SESSION session = 0;

    printf("Input student's ID : ");
    scanf("%d", &(student->ID));
    fgetc(stdin);

    printf("Input student's First Name : ");
    fgets(student->firstName, 100, stdin);
    student->firstName[strlen(student->firstName)-1] = 0;

    printf("Input student's Last Name : ");
    fgets(student->lastName, 100, stdin);
    student->lastName[strlen(student->lastName)-1] = 0;

    printf("Input Degree Program  : ");
    fgets(student->Degree_program, 100, stdin);
    student->Degree_program[strlen(student->Degree_program)-1] = 0;

    printf("Input Course's ID : ");
    scanf("%d", &(student->ID));
    fgetc(stdin);

    printf("Input Course's Name : ");
    fgets(student->course.CourseName, 100, stdin);
    student->course.CourseName[strlen(student->course.CourseName)-1] = 0;
    
    printf("Input the Session (insert 'w'or'W','s'or'S') : ");
    student->semester.session = inputStudent_season(session);
    fgetc(stdin);

    printf("Input Academic year : ");
    scanf("%d", &(student->semester.Year));
    fgetc(stdin);
    
    student->next = NULL;
}

SESSION inputStudent_season(SESSION session) //zu extrahieren!!!
{
    char ch;
    // leave a white space before %c to avoid printing twice
    scanf(" %c",&ch); 

    while (ch!='w' && ch!='W' && ch!='s' && ch!='S')
    {
        printf("Input another character : ");
        // leave a white space before %c to avoid printing twice
        scanf(" %c",&ch); 
    }   
    
    switch (ch)
    {
    case 'w' : session = winter;
        break;
    case 'W' : session = winter;
        break;
    case 's' : session = summer;
        break;
    case 'S' : session = summer;
        break;
    }
    return session;
}
STUDENT *insertStudent_begin(STUDENT *list, STUDENT *newStudent)
{
    newStudent->next = list;
    list = newStudent;
    return list;
}

STUDENT *insertStudent_pos(STUDENT *list, STUDENT *newStudent)
{
    int pos, i;
    STUDENT *ptr = NULL;
    printf("Input the position of the new node : ");
    scanf("%d", &pos);
    if(pos == 0)
        list = insertStudent_begin(list,newStudent);    
    else
    {
        for(i=0,ptr=list;i<pos-1;i++)
        {
            ptr = ptr->next;
            if (ptr == NULL) 
            {
                printf("Position not found!\n");
                exit(0); //return NULL;
            }
        }
        newStudent->next = ptr->next;
        ptr->next = newStudent;
    }
    return list;
}

STUDENT *insertStudent_end(STUDENT *list, STUDENT *newStudent)
{
    STUDENT *ptr = NULL;

    ptr = list;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newStudent; 

    return list;
}

STUDENT *insertStudent_methods(STUDENT *list, STUDENT *newStudent)
{
    int method;
    printf("\nInsert Student Methods : \n");
    printf("1 - insert Student at the begining.\n");
    printf("2 - insert Student at a specified position.\n");
    printf("3 - insert Student at the end.\n");
    printf("Input your insert Student method : ");

    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = insertStudent_begin(list,newStudent); //update head list
    else if(method == 2)
        list = insertStudent_pos(list,newStudent); // can also be void
    else
        list = insertStudent_end(list, newStudent); // can also be void
    return list;
}

STUDENT *deleteStudent_begin(STUDENT *list)
{
    STUDENT *ptr = NULL;
    if (list->next == NULL)
    {
        free(list);
        list = NULL;
    }
    else
    {
        ptr = list;
        list = list->next;
        free(ptr);
    } 
    return list;
}

STUDENT *deleteStudent_end(STUDENT *list)
{
    STUDENT *temp, *ptr;

    if (list->next == NULL)
    {
        ptr = list;
        list = NULL;
        free(ptr);
    }
    else
    {
        ptr = list;
        while (ptr->next!=NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
    }
    return list;
}

STUDENT *deleteStudent_pos(STUDENT *list)
{
    int i, pos;
    STUDENT *temp, *ptr;
    printf("Input the position to be deleted: ");
    scanf("%d",&pos);

    if (pos==0)
    {
        list = deleteStudent_begin(list);
    }
    else
    {
        ptr = list;
        for(i=0;i<pos;i++)
        {
            temp = ptr;
            ptr = ptr->next;
            if (ptr==NULL)
            {
                printf("Position not Found!\n");
                exit(0);
            }
        }
        temp->next = ptr->next;
        free(ptr);
    }
    return list;
}

STUDENT *deleteStudent_methods(STUDENT *list)
{
    int method;
    if(list == NULL)
    {
        printf("List of Students is Empty!\n\n"); 
        exit(0);
    }
    
    printf("\nDelete Student Methods : \n");
    printf("1 - Delete Student at the begining.\n");
    printf("2 - Delete Student at a specified position.\n");
    printf("3 - Delete Student at the end.\n");
    printf("4 - Delete entire list of Students\n");
    printf("\n- Input your delete Degree_Program method : ");
    
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3 && method != 4)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = deleteStudent_begin(list);
    else if(method == 2)
        list = deleteStudent_pos(list);
    else if(method == 3)
        list = deleteStudent_end(list); 
    else
        delete_entire_listStudent(list);
    return list;
}

void delete_entire_listStudent(STUDENT *list)
{
    STUDENT *current = list;
    STUDENT *next = NULL;
    if(list == NULL)
    {
        printf("List of students is Empty!\n\n"); 
        exit(0);
    }

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    list = NULL;

    printf("The list of students has been emptied!\n");
    //exit(0);
}

void displayStudent(STUDENT* student)
{

    printf("ID : %d\n",student->ID);
    printf("Fist Name : %s\n", student->firstName);
    printf("Last Name : %s\n", student->lastName);
    printf("Degree Program : %s\n",student->Degree_program);
    printf("Course ID : %d\n",student->ID);
    printf("Course Name : %s\n",student->course.CourseName);

    if(student->semester.session == winter)
        printf("Session : Winter Session\n");
    else 
        printf("Session : Summer Session\n");

    printf("Academic year : %d\n",student->semester.Year);
    
    printf("\n");    
}

void displayStudent_list(STUDENT *list)
{
    STUDENT *ptr = NULL;
    if(list == NULL)
    {
        printf("List is Empty!\n\n"); 
        exit(0);
    }
    
    ptr = list;
    printf("\t\tThe list of Students :\t\t\n");
    printf("\t\t=======================\t\t\n\n");
    while (ptr != NULL)
    {
        displayStudent(ptr);
        ptr = ptr->next;
    } 
}
