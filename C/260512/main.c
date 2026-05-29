#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996)

//int main(int argc, char* argv[])
//{
//    printf("The number of parameters : %d\n", argc);
//    for (int i = 1; i < argc; i++)
//        printf("%s", argv[i]);
//    printf("\n");
//
//    if (argc < 2)
//    {
//        printf("Need more parameters\n");
//        return 1;
//    }
//
//    int row = atoi(argv[1]);
//    int col = atoi(argv[2]);
//    int count = 1;
//    // 3*4 배열 만들기
//
//    int** array = (int**)malloc(sizeof(int*) * col);
//    for (int i = 0; i < col; i++)
//        array[i] = (int*)malloc(sizeof(int) * row);
//
//    for (int i = 0; i < col; i++)
//    {
//        for (int j = 0; j < row; j++)
//        {
//            array[i][j] = count++;
//            printf("%d ", array[i][j]);
//        }
//        printf("\n");
//    }
//
//    return 0;
//}

//int main(int argc, char* argv[])
//{
//	FILE* f = fopen(argv[1], "rt");
//	int math, kor, eng;
//	char name[20];
//	char dummy[20];
//
//	fscanf(f, "%s %s %s %s", dummy, dummy, dummy, dummy);
//	fscanf(f, "%[^,], %d, %d, %d", name, &math, &kor, &eng);
//
//	printf("%s's Average : %f\n", name, (math + kor + eng) / 3.0);
//
//	fscanf(f, "%[^,], %d, %d, %d", name, &math, &kor, &eng);
//
//	printf("%s's Average : %f\n", name, (math + kor + eng) / 3.0);
//
//	fclose(f);
//
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	FILE* f = fopen(argv[1], "rt");
//	char name[20];
//	char phone_number[20];
//	char input_name[20];
//
//	printf("input name : ");
//	scanf("%s", input_name);
//
//	while(fscanf(f, "%[^,], %s", name, phone_number) == 2)
//	{
//		if(strcmp(name, input_name) == 0)
//			printf("%s\n",  phone_number);
//	}
//
//	fclose(f);
//	return 0;
//}

//int main(int argc, char* argv[])
//{
//	FILE* f = fopen(argv[1], "rt");
//	FILE* f2 = fopen(argv[2], "wt");
//a
//	char name[20];
//	char phone_number[20];
//
//	//fscanf의 return 값은 저장한갯수 따라서 2개저장하면 return값은 2
//	while(fscanf(f, "%[^,], %s", name, phone_number) == 2)
//	{
//		fprintf(f2, "%s, %s", name, phone_number);
//	}
//
//	fclose(f);
//	fclose(f2);
//
//	return 0;
//}

int main(int argc, char* argv[])
{
	FILE* f = fopen(argv[1], "rt");

	char name[20];
	int count = 0;

	while(fscanf(f, "%s", name) == 1)
	{
		if (strcmp(name, "ERROR") == 0)
			count++;
	}
	printf("ERROR's count : %d\n", count);
	
	fclose(f);
	return 0;
}