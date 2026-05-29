#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning[disable:4996]
#define TRUE 1

typedef struct{
    int index;
    char name[20];
    int stdNum;
    char phoneNum[20];
    char address[50];
}information;

void printMenu(){
    printf("1. Add a student information\n");
    printf("2. Print all student information\n");
    printf("3. Save the file\n");
    printf("4. Load from the file\n");
    printf("5. Exit\n");
    printf("Input :");
}

void addStudent(information* student, int *idx)                                                                                                                                                                                                                                                                                                                                                                                                                                 
{
    student[*idx].index = *idx + 1;
    printf("name : ");
    scanf("%s", student[*idx].name);
    printf("stdNum : ");
    scanf("%d", &student[*idx].stdNum);
    printf("phoneNum : ");
    scanf("%s", student[*idx].phoneNum);
    printf("address : ");
    scanf("%s", student[*idx].address);
    (*idx)++;
}

void printStudent(information* student, int idx)
{
    if(idx == 0)
    {
        printf("not information\n");
        return;
    }

    for( int i = 0; i<idx; i++)
    {
        printf("index : %d\n", student[i].index);
        printf("index : %s\n", student[i].name);
        printf("index : %d\n", student[i].stdNum);
        printf("index : %s\n", student[i].phoneNum);
        printf("index : %s\n", student[i].address);
    }
}


int main(void)
{
    information student[50];
    int idx = 0;
    int num;
    
    while(TRUE)
    {
        printMenu();
        scanf("%d", &num);

        switch(num)
        {
            case 1:
                addStudent(student, &idx);
                break;
            case 2:
                printStudent(student, idx);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                return 0;
            default:
                break;
        }
    }

    return 0;
}