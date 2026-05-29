#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct {
	char name[30];
	int kor;
	int eng;
	int math;
}student;

int main(void)
{
	FILE* f = fopen("./score.csv", "rt");
	FILE* f2 = fopen("./total_score.csv", "wt");
	
	student stu[20];
	int idx = 0; //while문을 사용하기위해 idx값을 이동시켜주기위한 변수
	float average;
	int sum;
	//fscanf 반환값이 int형(받아온 인자갯수) 현재 name, kor, eng, math로 총 4개 return 받으면서 fscanf도 실행
	while (fscanf(f, "%[^,], %d, %d, %d", stu[idx].name, &stu[idx].kor, &stu[idx].eng, &stu[idx].math) == 4)
	{	
		//첫번째 행을 받아온 값을 바로계산해서 바로 fprintf로 total_score.csv에 뿌려줌
		sum = stu[idx].kor + stu[idx].eng + stu[idx].math;
		average = sum / 3.0;
		fprintf(f2, "%s, %d, %d, %d, %d, %0.2f", stu[idx].name, stu[idx].kor, stu[idx].eng, stu[idx].math, sum, average);
		idx++;
	}

	fclose(f);
	fclose(f2);

	return 0;
}