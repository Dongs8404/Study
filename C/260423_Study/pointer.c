#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0

void analyze(int* arr, int n, int* sum, int* max, int* min)
{
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			*max = arr[i];
			*min = arr[i];
		}
		else
		{
			if (*max < arr[i])
				*max = arr[i];

			if (*min > arr[i])
				*min = arr[i];
		}
		*sum += arr[i];
	}
}

int partial_sum(int* arr, int n, int start)
{
	int sum = 0;

	for (int i = start; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
void multiply_all(int* arr, int n)
{
	printf("배열의 모든값 2배 출력: ");
	for (int i = 0; i < n; i++)
	{
		arr[i] *= 2;
		printf("%d ", arr[i]);
	}
}

int find_max_index(int* arr, int n)
{
	int max = 0;
	int index;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			max = arr[i];
			index = i;
		}
		else
		{
			if (arr[i] > max)
			{
				max = arr[i];
				index = i;
			}
		}
	}
	return index;
}
void remove_duplicate(int* arr, int n)
{
	int zero_index = n - 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j <= zero_index; j++)
		{
			if (arr[i] == arr[j])
			{
				for (int k = j; k < zero_index; k++)
				{
					arr[k] = arr[k + 1];
				}
				arr[zero_index] = 0;
				zero_index--;
				j--;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

void avoid_bombs(int* arr, int n)
{
	int random;
	int input_number;
	int is_fail = FALSE;
	int check_arr[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int check_num = 0;
	srand((unsigned int)time(NULL));

	random = rand() % n;
	arr[random] = -1;

	for (int i = 0; i < n - 1; i++)
	{
		printf("폭탄피하기");
		printf("index 번호 입력");
		scanf("%d", &input_number);
		for (int j = 0; j < n; j++)
		{
			if (!(input_number >= 0 && input_number < n))
			{
				printf("input_number Value out of range");
				j--;
				continue;
			}
			else if (check_arr[j] == input_number)
			{
				printf("input_number is duplicate");
				j--;
				continue;
			}
			else
			{
				check_arr[check_num] = input_number;
				check_num++;
				break;
			}
		}

		if (arr[input_number] == -1)
		{
			is_fail = TRUE;
			break;
		}
	}
	if (is_fail)
	{
		printf("FAIL\n");
	}
	else
	{
		printf("SUCCESS\n");
	}
}
int main(void)
{
	//1, 사용자로부터 5개의 수를 배열에 입력받아 아래의 함수를 구현해보자
	// void analyze(int *arr, int n, int *sum, int* max, int *min)

	//int input_number[5];
	//int size;
	//int sum = 0;
	//int max;
	//int min;

	//size = sizeof(input_number) / sizeof(int);

	//printf("배열 5개 값 입력: ");
	//for (int i = 0; i < size; i++)
	//{
	//	scanf("%d", &input_number[i]);
	//}

	//analyze(input_number, size, &sum, &max, &min);

	//printf("sum : %d, max : %d, min : %d\n", sum, max, min);

	//2. 사용자로부터 5개의 수를 배열에 입력받는다. 그 이후 배열의 시작 인덱스를 받아서 그 위치부터 배열의 끝까지 합을 구하는프로그램
	//int partial_sum(int *arr, int n, int start)
	//ex) int arr[5] = {1,2,3,4,5}, partial_sum(arr, 5, 3) 이면 9가 출력됨
	//int input_number[5];
	//int size;
	//int start_index;
	//size = sizeof(input_number) / sizeof(int);

	//printf("5개의 정수 입력 : ");
	//
	//for (int i = 0; i < size; i++)
	//{
	//	scanf("%d", &input_number[i]);
	//}
	//
	//printf("시작 Index 입력: ");
	//scanf("%d", &start_index);

	//printf("index %d부터 %d 값의 합: %d\n", start_index, size - 1, partial_sum(input_number, size, start_index));

	//3. 사용자로부터 5개의 수를 배열에 입력받아 배열의 모든 값을 두배로 만드는 함수를 만들어보자
	//void multiply_all(int *arr, int n)
	//int input_number[5];
	//int size;

	//size = sizeof(input_number) / sizeof(int);

	//printf("5개의 정수 입력 : ");
	//
	//for (int i = 0; i < size; i++)
	//{
	//	scanf("%d", &input_number[i]);
	//}
	//
	//multiply_all(input_number, size);

	//4. 사용자로부터 5개의 수를 배열에 입력받아 배열에서 가장 큰 값의 "위치(index)"를 반환하는 함수를 만들어보자
	//int find_max_index(int *arr, int n)

	//int input_number[5];
	//int size;

	//size = sizeof(input_number) / sizeof(int);

	//printf("5개의 정수 입력 : ");
	//
	//for (int i = 0; i < size; i++)
	//{
	//	scanf("%d", &input_number[i]);
	//}
	//

	//printf("배열의 가장큰값을 가지는 index 위치는 %d\n", find_max_index(input_number, size));

	//5. 배열의 중복 값을 제거하고 남는 값만 앞쪽에 배치하는 프로그램을 만들어보자(중복값은 0으로 처리)
	
	//int input_number[10] = { 5, 4, 6, 5, 8, 3, 2, 3, 4, 3 };
	//int size;

	//size = sizeof(input_number) / sizeof(int);
	//
	//remove_duplicate(input_number, size);


	//6. 폭탄 피하기 게임을 만들어보자

	//int bomb[10] = { 0 };
	//int size;
	//
	//size = sizeof(bomb) / sizeof(int);

	//avoid_bombs(bomb, size);


	return 0;
}