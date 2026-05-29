#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma warning(disable:4996)

int pow(int x, int y)
{
	int result = 1;
	if (y == 0)
		return 1;
	else if (y > 0)
	{
		for (int i = 0; i < y; i++)
			result *= x;
		return result;
	}
}
void arrSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int value(int n, int i, int j)
{
	int result;
	result = (j * n) + (i + 1);
	return result;
}

void compare(int* answer, int a, int b)
{
	if (a > b)
		*answer = 1;
	else if (a < b)
		*answer = -1;
	else
		*answer = 0;
}
int GBB(int uNum, int cNum)
{
	if (uNum == cNum)
		return 0;
	else if ((uNum - cNum + 3) % 3 == 1)
		return 1;
	else
		return 2;
}
int main(void)
{
	//1
	//printf("%d\n", pow(2, 3));

	//2
	//int aaa[5] = { 1, 4, 2, 3, 5 };
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = i + 1; j < 5; j++)
	//	{
	//		if (aaa[i] < aaa[j])
	//		{
	//			int temp = aaa[i];
	//			aaa[i] = aaa[j];
	//			aaa[j] = temp;
	//		}
	//	}
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	printf("%d ", aaa[i]);
	//}

	//3
	//int arr[] = { 4, 1, 3, 2, 6, 5 };
	//int size;

	//size = sizeof(arr) / sizeof(int);
	//arrSort(arr, size);

	//for (int i = 0; i < 6; i++)
	//{
	//	printf("%d ", arr[i]);
	//}

	//4
	//int a = 10;
	//int* p = &a;
	//*p = 15;
	//printf("%d\n", a);

	//5
	unsigned int n, i, j;
	scanf("%d", &n);
	int** matrix = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		*(matrix + i) = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = value(n, i, j);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("| ");
		for (j = 0; j < n; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
		printf(" |\n");
	}

	//6
	int baseball_num[3];
	int user_num[3];
	int rand_num;
	int count = 0;
	int strike = 0;
	int ball = 0;
	int is_input_true;

	srand((unsigned int)time(NULL));

	for (int i = 0; i < 3; i++)
	{
		rand_num = rand() % 9 + 1;
		if (i == 0)
			is_input_true = 1;
		else
		{
			for (int j = 0; j < i; j++)
			{
				if (baseball_num[j] == rand_num)
				{
					is_input_true = 0;
					break;
				}
			}
		}
		if (is_input_true == 1)
			baseball_num[i] = rand_num;
		else
		{
			i--;
			is_input_true = 1;
		}
	}
	
	while (count < 10)
	{
		printf("input number : ");
		for (int i = 0; i < 3; i++)
			scanf("%d", &user_num[i]);
		count++;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (j == k)
				{
					if (baseball_num[j] == user_num[k])
						strike++;
				}
				else
				{
					if (baseball_num[j] == user_num[k])
						ball++;
				}
			}
		}
		if (strike == 0 && ball == 0)
			printf("OUT\n");
		else if (strike == 3)
		{
			printf("%d Strike, you win\n", strike);
			break;
		}
		else
			printf("%d strike, %d ball\n", strike, ball);

		strike = 0;
		ball = 0;
		if (count == 10)
			printf("you lose\n");
	}

	//7
	//int arr[10] = { 32, 14, 1, 30, 82, 10, 19, 7, 28, 18 };
	//int average;
	//int sum = 0;
	//int size;
	//size = sizeof(arr) / sizeof(int);

	//for (int i = 0; i < size; i++)
	//{
	//	sum += arr[i];
	//}

	//average = sum / size;

	//printf("average is %d\n", average);

	//8
	//int answer;
	//compare(&answer, 15, 13);
	//printf("%d\n", answer);
	//compare(&answer, 10, 13);
	//printf("%d\n", answer);
	//compare(&answer, 10, 10);
	//printf("%d\n", answer);
	
	//9
	//int arr[] = { 10, 1, 5, 90, 7, 23, 13, 4 };
	//int i = 0;
	//int cnt = 0;

	//while (1)
	//{
	//	int size;
	//	size = sizeof(arr) / sizeof(int);
	//	if (cnt == 3)
	//		break;
	//	else
	//		for (i = 0; i < size;i++)
	//			printf("%d ", arr[i]);
	//	cnt++;
	//}

	//10
	//int c_num;
	//int u_num;
	//int count = 0;
	//int win = 0;
	//int lose = 0;
	//int draw = 0;
	//srand((unsigned int)time(NULL));
	//while (1)
	//{
	//	if (count == 10)
	//		break;
	//	c_num = rand() % 3;
	//	printf("input : ");
	//	scanf("%d", &u_num);
	//	if (!(u_num >= 0 && u_num <= 2))
	//	{
	//		printf("Please input a value between 0 and 2\n");
	//		continue;
	//	}

	//	if (GBB(u_num, c_num) == 0)
	//		draw++;
	//	else if (GBB(u_num, c_num) == 1)
	//		win++;
	//	else
	//		lose++;
	//	count++;
	//}
	//
	//printf("win : %d, lose : %d, draw: %d\n", win, lose, draw);

	//11
	//int i, j;
	//int arr[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		arr[i][j] = (7 + i) - (j * 3);
	//	}
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}
	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		arr[i][j] = (3 - i) + (j * 3);
	//	}
	//}

	//for (int i = 0; i < 3; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		printf("%d ", arr[i][j]);
	//	}
	//	printf("\n");
	//}
	//

	//int arr[10][10];

	//for (int i = 0; i < 10; i++)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		arr[i][j] = (i * 10) + (j + 1);
	//	}
	//}
	//
	//int x1, x2, y1, y2;
	//int sum = 0;

	//printf("enter a position 1 : ");
	//scanf("%d %d", &x1, &y1);
	//printf("enter a position 2 : ");
	//scanf("%d %d", &x2, &y2);

	//for (int i = x1; i <= x2; i++)
	//{
	//	for (int j = y1; j <= y2; j++)
	//	{
	//		sum += arr[i][j];
	//	}
	//}

	//printf("sum = %d\n", sum);

	//return 0;
}