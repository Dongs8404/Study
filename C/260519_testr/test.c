//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define TRUE 1
//
//#pragma warning(disable: 4996)
//typedef struct {
//    int index;
//    char name[20];
//    int stdNum;
//    char phoneNum[20];
//    char address[50];
//}information;
//
//void printMenu() {
//    printf("1. Add a student information\n");
//    printf("2. Print all student information\n");
//    printf("3. Save the file\n");
//    printf("4. Load from the file\n");
//    printf("5. Exit\n");
//    printf("Input : ");
//}
//
//void addStudent(information* student, int* idx)
//{
//    student[*idx].index = *idx + 1;
//    printf("name : ");
//    scanf("%s", student[*idx].name);
//    printf("stdNum : ");
//    scanf("%d", &student[*idx].stdNum);
//    printf("phoneNum : ");
//    scanf("%s", student[*idx].phoneNum);
//    printf("address : ");
//    scanf("%s", student[*idx].address);
//    (*idx)++;
//}
//
//void printStudent(information* student, int idx)
//{
//    if (idx == 0)
//    {
//        printf("not information\n");
//        return;
//    }
//
//    for (int i = 0; i < idx; i++)
//    {
//        printf("index : %d\n", student[i].index);
//        printf("name : %s\n", student[i].name);
//        printf("stdNum : %d\n", student[i].stdNum);
//        printf("phonNum : %s\n", student[i].phoneNum);
//        printf("address : %s\n", student[i].address);
//    }
//}
//void saveFile(information* student, int idx)
//{
//    FILE* f = fopen("./student.txt", "w");
//
//    if (f == NULL)
//    {
//        printf("file open failed\n");
//        return;
//    }
//
//    fprintf(f, "%d\n", idx);
//
//    for (int i = 0; i < idx; i++)
//    {
//        fprintf(f, "%d\n", student[i].index);
//        fprintf(f, "%s\n", student[i].name);
//        fprintf(f, "%d\n", student[i].stdNum);
//        fprintf(f, "%s\n", student[i].phoneNum);
//        fprintf(f, "%s\n", student[i].address);
//    }
//
//    fclose(f);
//}
//
//void loadFile(information* student, int* idx)
//{
//    FILE* f = fopen("./student.txt", "r");
//
//    if (f == NULL)
//    {
//        printf("file open failed\n");
//        return;
//    }
//
//    fscanf(f, "%d", idx);
//
//    for (int i = 0; i < *idx; i++)
//    {
//        fscanf(f, "%d", &student[i].index);
//        fscanf(f, "%s", student[i].name);
//        fscanf(f, "%d", &student[i].stdNum);
//        fscanf(f, "%s", student[i].phoneNum);
//        fscanf(f, "%s", student[i].address);
//    }
//
//    fclose(f);
//}
//
//
//int main(void)
//{
//    information student[50];
//    int idx = 0;
//    int num;
//
//    while (TRUE)
//    {
//        printMenu();
//        scanf("%d", &num);
//
//        switch (num)
//        {
//        case 1:
//            addStudent(student, &idx);
//            break;
//        case 2:
//            printStudent(student, idx);
//            break;
//        case 3:
//            saveFile(student, idx);
//            break;
//        case 4:
//            loadFile(student, &idx);
//            break;
//        case 5:
//            return 0;
//        default:
//            break;
//        }
//    }
//
//    return 0;
//}