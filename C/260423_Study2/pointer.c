#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)
#define TRUE 1
#define FALSE 0



int get_random_number(int size)
{
	srand((unsigned int)time(NULL));

	return rand() % size;
}
int input_check(int* arr, int size, int num, int check_size)
{
	if (!(num >= 0 && num < size))
	{
		printf("input_number Value out of range\n");
		return FALSE;
	}

	for (int i = 0; i <= check_size; i++)
	{
		if (arr[i] == num)
		{
			printf("deplication is input_number\n");
			return FALSE;
		}
	}
	return TRUE;
}
void avoid_bombs(int* arr, int size)
{
	int index = get_random_number(size);
	int check_arr[10];
	int check_number = 0;
	int is_success = TRUE;
	int input_number;
	
	arr[index] = -1;

	//printf("bomb index: %d\n", index);

	for (int i = 0; i < size - 1; i++)
	{
		printf("%dth input number : ", check_number + 1);
		scanf("%d", &input_number);

		if (input_check(check_arr, size, input_number, check_number))
		{
			check_arr[check_number] = input_number;
			check_number++;
			if (arr[input_number] == -1)
			{
				printf("BOMB\n");
				is_success = FALSE;
				break;
			}
			else
			{
				printf("MISS\n");
			}
		}
		else
		{
			i--;
		}
	}
	if (is_success)
		printf("SUCCESS\n");
	else
		printf("FAIL\n");
}
int main(void)
{
	int bomb[10] = { 0 };
	int size;

	size = sizeof(bomb) / sizeof(int);

	avoid_bombs(bomb, size);

	return 0;
}