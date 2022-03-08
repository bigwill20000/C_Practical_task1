#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instructor.h"

/*void start_Program(int *choice)
{
    printf("\t\tMENU\t\t\n");
    printf("\t\t====\t\t\n");
    printf("1 - Add Instructor\n");
    printf("2 - Display Instructors\n");
    printf("3 - Delete Instructor\n");
    printf("4 - Exit\n");
    printf("\t\t====\t\t\n");
    printf("Input your choice : ");
    scanf("%d",choice);
    printf("\n");
    getchar();
}*/

INSTRUCTOR *createInstructor(INSTRUCTOR *instructor)
{
    instructor = (INSTRUCTOR*)malloc(sizeof(INSTRUCTOR));
    if(instructor == NULL)
        return NULL;
    return instructor;
}

INSTRUCTOR *addInstructor(INSTRUCTOR *list)
{
    INSTRUCTOR *newInstructor = NULL;
    newInstructor = createInstructor(newInstructor); // to be passed in the insert method
    appendInstructor(newInstructor);

    if(list == NULL)
        list = newInstructor; //update the head list
    else
        list = insertInstructor_methods(list,newInstructor);
    return list;
}

INSTRUCTOR *insertInstructor_begin(INSTRUCTOR *list, INSTRUCTOR *newInstructor)
{
    newInstructor->next = list;
    list = newInstructor;
    return list;
} 

INSTRUCTOR *insertInstructor_pos(INSTRUCTOR *list, INSTRUCTOR *newInstructor)
{
    int pos, i;
    INSTRUCTOR *ptr = NULL;
    printf("Input the position of the new node : ");
    scanf("%d", &pos);
    if(pos == 0)
        list = insertInstructor_begin(list,newInstructor);    
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
        newInstructor->next = ptr->next;
        ptr->next = newInstructor;
    }
    return list;
}

INSTRUCTOR *insertInstructor_end(INSTRUCTOR *list, INSTRUCTOR *newInstructor)
{
    INSTRUCTOR *ptr = NULL;

    ptr = list;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newInstructor; 

    return list;
}

INSTRUCTOR *insertInstructor_methods(INSTRUCTOR *list, INSTRUCTOR *newInstructor)
{
    int method;
    printf("\nInsert Instructor Methods : \n");
    printf("1 - insert Instructor at the begining.\n");
    printf("2 - insert Instructor at a specified position.\n");
    printf("3 - insert Instructor at the end.\n");
    printf("Input your method : ");
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = insertInstructor_begin(list,newInstructor); //update head list
    else if(method == 2)
        list = insertInstructor_pos(list,newInstructor); // can also be void
    else
        list = insertInstructor_end(list, newInstructor); // can also be void
    return list;  
}

void appendInstructor(INSTRUCTOR *instructor)
{
    SESSION session = 0;
    GRADE grade = 0;

    printf("Input instructor ID : ");
    scanf("%d", &(instructor->ID));
    fgetc(stdin);

    printf("Input instructor's First Name : ");
    fgets(instructor->FirstName, 100, stdin);
    instructor->FirstName[strlen(instructor->FirstName)-1] = 0;

    printf("Input instructor's Last Name : ");
    fgets(instructor->LastName, 100, stdin);
    instructor->LastName[strlen(instructor->LastName)-1] = 0;

    printf("Input instructor's Faculty : ");
    fgets(instructor->Faculty, 100, stdin);
    instructor->Faculty[strlen(instructor->Faculty)-1] = 0;

    printf("Input Course's ID : ");
    scanf("%d", &(instructor->Course.CourseID));
    fgetc(stdin);

    printf("Input Course's Name : ");
    fgets(instructor->Course.CourseName, 100, stdin);
    instructor->Course.CourseName[strlen(instructor->Course.CourseName)-1] = 0;
    
    printf("Input the Session (insert 'w'or'W','s'or'S') : ");
    instructor->semester.session = inputInstructor_season(session);
    fgetc(stdin);

    printf("Input Academic year : ");
    scanf("%d", &(instructor->semester.Year));
    fgetc(stdin);

    printf("Input Grade (insert 'b'or'B','m'or'M','d'or'D') : ");
    instructor->Grade = inputInstructor_grade(grade);
    fgetc(stdin);
    
    instructor->next = NULL;
}

SESSION inputInstructor_season(SESSION session)
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

GRADE inputInstructor_grade(GRADE grade)
{
    char ch;
    // leave a white space before %c to avoid printing twice
    scanf(" %c",&ch);  

    while (ch!='b' && ch!='B' && ch!='m' && ch!='M'
            && ch!='d' && ch!='D')
        {
            printf("Input another character:");
            // leave a white space before %c to avoid printing twice
            scanf(" %c",&ch);
        }

    switch (ch)
    {
    case 'b' : grade = bachelor;
        break;
    case 'B' : grade = bachelor;
        break;
    case 'm' : grade = master;
        break;
    case 'M' : grade = master;
        break;
    case 'd' : grade = doctorate;
        break;
    case 'D' : grade = doctorate;
        break;
    }
    return grade;
}

INSTRUCTOR *deleteInstructor_begin(INSTRUCTOR *list)
{
    INSTRUCTOR *ptr = NULL;
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

INSTRUCTOR *deleteInstructor_end(INSTRUCTOR *list)
{
    INSTRUCTOR *temp, *ptr;

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

INSTRUCTOR *deleteInstructor_pos(INSTRUCTOR *list)
{
    int i, pos;
    INSTRUCTOR *temp, *ptr;
    printf("Input the position to be deleted: ");
    scanf("%d",&pos);

    if (pos==0)
    {
        list = deleteInstructor_begin(list);
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

INSTRUCTOR *deleteInstructor_methods(INSTRUCTOR *list)
{
    int method;
    if(list == NULL)
    {
        printf("List is Empty!\n\n"); 
        exit(0);
    }
    
    printf("\nDelete-methods : \n");
    printf("1 - Delete Instructor at the begining.\n");
    printf("2 - Delete Instructor at a specified position.\n");
    printf("3 - Delete Instructor at the end.\n");
    printf("Input your delete Instructor method : ");
    
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = deleteInstructor_begin(list);
    else if(method == 2)
        list = deleteInstructor_pos(list);
    else
        list = deleteInstructor_end(list); 
    return list;
}

void displayInstructor(INSTRUCTOR* instructor)
{

    printf("Instructor's ID : %d\n",instructor->ID);

    if(instructor->Grade == bachelor)
        printf("Instructor's Grade : Bachelor\n");
    else if (instructor->Grade == master)
        printf("Instructor's Grade : Master\n");
    else
        printf("Instructor's Grade : Doctorate\n");

    printf("Fist Name : %s\n", instructor->FirstName);
    printf("Last Name : %s\n", instructor->LastName);
    printf("Course's ID: %d\n", instructor->Course.CourseID);
    printf("Course's Name : %s\n",instructor->Course.CourseName);
    printf("Faculty : %s\n", instructor->Faculty);

    if(instructor->semester.session == winter)
        printf("Session : Winter Session\n");
    else 
        printf("Session : Summer Session\n");

    printf("Academic year : %d\n",instructor->semester.Year);
    
    printf("\n");    
}

void displayInstructor_list(INSTRUCTOR *list)
{
    INSTRUCTOR *ptr = NULL;
    if(list == NULL)
    {
        printf("List is Empty!\n\n"); 
        exit(0);
    }
    
    ptr = list;
    printf("\t\tThe list of instructors :\t\t\n");
    printf("\t\t=======================\t\t\n\n");
    while (ptr != NULL)
    {
        displayInstructor(ptr);
        ptr = ptr->next;
    } 
}