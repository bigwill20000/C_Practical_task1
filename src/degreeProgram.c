#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "degreeProgram.h"

DEGREEPROGRAM *create(DEGREEPROGRAM *degreeProgram)
{
    degreeProgram = (DEGREEPROGRAM*)malloc(sizeof(DEGREEPROGRAM));
    if(degreeProgram == NULL)
        return NULL;
    return degreeProgram;
}

DEGREEPROGRAM *add(DEGREEPROGRAM *list)
{
    DEGREEPROGRAM *newDegreeProgram = NULL;
    newDegreeProgram = create(newDegreeProgram);
    append(newDegreeProgram);

    if (list == NULL)
        list = newDegreeProgram;
    else
        //list = insert_methods(list, newDegreeProgram);
    return list;
}

void append(DEGREEPROGRAM *degreeProgram)
{
    SESSION session = 0;
    printf("Input Degree Program ID : ");
    scanf("%d", &(degreeProgram->ID));
    fgetc(stdin);

    printf("Input Degree Program's Name : ");
    fgets(degreeProgram->Name, 100, stdin);
    degreeProgram->Name[strlen(degreeProgram->Name)-1] = 0;

    printf("Input Degree Program's Course : ");
    fgets(degreeProgram->Course, 100, stdin);
    degreeProgram->Course[strlen(degreeProgram->Course)-1] = 0;

    printf("Input Academic year : ");
    scanf("%d", &(degreeProgram->Year));
    fgetc(stdin);

    printf("Input the Session (insert 'w'or'W','s'or'S') : ");
    degreeProgram->Session = input_season(session);
    fgetc(stdin);

    printf("Input instructor's First Name : ");
    fgets(degreeProgram->InstructorFirstName, 100, stdin);
    degreeProgram->InstructorFirstName[strlen(degreeProgram->InstructorFirstName)-1] = 0;

    printf("Input instructor's Last Name : ");
    fgets(degreeProgram->InstructorLastName, 100, stdin);
    degreeProgram->InstructorLastName[strlen(degreeProgram->InstructorLastName)-1] = 0;
    
    degreeProgram->next = NULL;
}

SESSION input_season(SESSION session)
{
    char ch;
    scanf(" %c",&ch);// leave a white space before %c 
                              // to avoid printing twice
    while (ch!='w' && ch!='W' && ch!='s' && ch!='S')
    {
        printf("Input another character : ");
        scanf(" %c",&ch);// leave a white space before %c 
                              // to avoid printing twice
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

DEGREEPROGRAM *insert_methods(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    int method;
    printf("\nInsert-methods : \n");
    printf("1 - insert at the begining.\n");
    printf("2 - insert at a specified position.\n");
    printf("3 - insert at the end.\n");
    printf("Input your method : ");
    scanf("%d", &method);
    while (method!=1 && method!=2 && method!=3)
    {
        printf("Try again : ");
        scanf("%d", &method);
    }
    if (method == 1)
        list = insert_begin(list,newDegreeProgram); //update head list
    else if(method == 2)
        list = insert_pos(list,newDegreeProgram); // can also be void
    else
        list = insert_end(list, newDegreeProgram); // can also be void
    return list;  
}

DEGREEPROGRAM *insert_begin(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    newDegreeProgram->next = list;
    list = newDegreeProgram;
    return list;
}

DEGREEPROGRAM *insert_pos(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
{
    int pos, i;
    DEGREEPROGRAM *ptr = 0;
    printf("Input the position of the new node : ");
    scanf("%d", &pos);
    if(pos == 0)
        list = insert_begin(list, newDegreeProgram);    
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

DEGREEPROGRAM *insert_end(DEGREEPROGRAM *list, DEGREEPROGRAM *newDegreeProgram)
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