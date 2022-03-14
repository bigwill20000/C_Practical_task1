#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/session_semester_course.h"
#include "../includes/degreeProgram.h"

DEGREEPROGRAM *createDegreeProgram(DEGREEPROGRAM *degreeProgram)
{
    degreeProgram = (DEGREEPROGRAM*)malloc(sizeof(DEGREEPROGRAM));
    if(degreeProgram == NULL)
        return NULL;
    return degreeProgram;
}

DEGREEPROGRAM *addDegreeProgram(DEGREEPROGRAM *list)
{
    DEGREEPROGRAM *newDegreeProgram = NULL;
    newDegreeProgram = createDegreeProgram(newDegreeProgram);
    appendDegreeProgram(newDegreeProgram);

    if (list == NULL)
        list = newDegreeProgram;
    else
        list = insertDegreeProgram_methods(list, newDegreeProgram);
    return list;
}

void appendDegreeProgram(DEGREEPROGRAM *degreeProgram)
{
    SESSION session = 0;

    printf("Input Degree Program ID : ");
    scanf("%d", &(degreeProgram->ID));
    fgetc(stdin);

    printf("Input Degree Program's Name : ");
    fgets(degreeProgram->Name, 100, stdin);
    degreeProgram->Name[strlen(degreeProgram->Name)-1] = 0;

    printf("Input lecturer's First Name : ");
    fgets(degreeProgram->InstructorFirstName, 100, stdin);
    degreeProgram->InstructorFirstName[strlen(degreeProgram->InstructorFirstName)-1] = 0;

    printf("Input lecturer's Last Name : ");
    fgets(degreeProgram->InstructorLastName, 100, stdin);
    degreeProgram->InstructorLastName[strlen(degreeProgram->InstructorLastName)-1] = 0;

    printf("Input Program's Course ID : ");
    scanf("%d", &(degreeProgram->Course.CourseID));
    fgetc(stdin);

    printf("Input Program's Course Name : ");
    fgets(degreeProgram->Course.CourseName, 100, stdin);
    degreeProgram->Course.CourseName[strlen(degreeProgram->Course.CourseName)-1] = 0;

    printf("Input the Session (insert 'w'or'W','s'or'S') : ");
    degreeProgram->semester.session = inputDegreeProgram_season(session);
    fgetc(stdin);

    printf("Input Academic year : ");
    scanf("%d", &(degreeProgram->semester.Year));
    fgetc(stdin);
    
    degreeProgram->next = NULL;
}

SESSION inputDegreeProgram_season(SESSION session)
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

DEGREEPROGRAM *insertDegreeProgram_methods(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    int method;
    printf("\nInsert DegreeProgram Methods : \n");
    printf("1 - insert DegreeProgram at the begining.\n");
    printf("2 - insert DegreeProgram at a specified position.\n");
    printf("3 - insert DegreeProgram at the end.\n");
    printf("Input your Insert method : ");
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = insertDegreeProgram_begin(list,newDegreeProgram); //update head list
    else if(method == 2)
        list = insertDegreeProgram_pos(list,newDegreeProgram); // can also be void
    else
        list = insertDegreeProgram_end(list, newDegreeProgram); // can also be void
    return list;  
}

DEGREEPROGRAM *insertDegreeProgram_begin(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    newDegreeProgram->next = list;
    list = newDegreeProgram;
    return list;
}

DEGREEPROGRAM *insertDegreeProgram_pos(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    int pos, i;
    DEGREEPROGRAM *ptr = 0;
    printf("Input the position of the new node : ");
    scanf("%d", &pos);
    if(pos == 0)
        list = insertDegreeProgram_begin(list, newDegreeProgram);    
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
        newDegreeProgram->next = ptr->next;
        ptr->next = newDegreeProgram;
    }
    return list;
}

DEGREEPROGRAM *insertDegreeProgram_end(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    DEGREEPROGRAM *ptr = NULL;
    ptr = list;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newDegreeProgram; 

    return list;
}

DEGREEPROGRAM *deleteDegreeProgram_begin(DEGREEPROGRAM *list)
{
    DEGREEPROGRAM *ptr = NULL;
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

DEGREEPROGRAM *deleteDegreeProgram_end(DEGREEPROGRAM *list)
{
    DEGREEPROGRAM *temp, *ptr;

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

DEGREEPROGRAM *deleteDegreeProgram_pos(DEGREEPROGRAM *list)
{
    int i, pos;
    DEGREEPROGRAM *temp, *ptr;
    printf("Input the position to be deleted: ");
    scanf("%d",&pos);

    if (pos==0)
    {
        list = deleteDegreeProgram_begin(list);
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

DEGREEPROGRAM *deleteDegreeProgram_methods(DEGREEPROGRAM *list)
{
    int method;
    if(list == NULL)
    {
        printf("List is Empty!\n\n"); 
        exit(0);
    }
    
    printf("\nDelete Degree Program Methods : \n");
    printf("1 - Delete DegreeProgram at the begining.\n");
    printf("2 - Delete DegreeProgram at a specified position.\n");
    printf("3 - Delete DegreeProgram at the end.\n");
    printf("Input your delete Degree_Program method : ");
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = deleteDegreeProgram_begin(list);
    else if(method == 2)
        list = deleteDegreeProgram_pos(list);
    else
        list = deleteDegreeProgram_end(list); 
    return list;
}

void displayDegreeProgram(DEGREEPROGRAM *degreeProgram)
{
    printf("Program's ID : %d\n",degreeProgram->ID);
    printf("Degree's Name : %s\n", degreeProgram->Name);
    printf("Lecturer's First Name : %s\n", degreeProgram->InstructorFirstName);
    printf("Lecturer's Last Name : %s\n", degreeProgram->InstructorLastName);
    printf("Course's ID: %d\n", degreeProgram->Course.CourseID);
    printf("Course's Name : %s\n", degreeProgram->Course.CourseName);

    if(degreeProgram->semester.session == winter)
        printf("Session : Winter Session\n");
    else 
        printf("Session : Summer Session\n");

    printf("Academic year : %d\n",degreeProgram->semester.Year);
    
    printf("\n");    
}

void displayDegreeProgram_list(DEGREEPROGRAM *list)
{
    DEGREEPROGRAM *ptr = NULL;
    if(list == NULL)
    {
        printf("List is Empty!\n\n"); 
        exit(0);
    }
    
    ptr = list;
    printf("\t\tThe list of Degree Programs :\t\t\n");
    printf("\t\t=======================\t\t\n\n");
    while (ptr != NULL)
    {
        displayDegreeProgram(ptr);
        ptr = ptr->next;
    } 
}
