#include <stdio.h>

#define SIZE 10
#define TRUE 1
#define FALSE 0

void print_array(int arr[SIZE][SIZE], int* s_count, int* zombies, int* people, int* c_people);
void reset_array(int temp[SIZE][SIZE]);
void checked_infection(int arr[SIZE][SIZE], int temp[SIZE][SIZE]);
int apply_infection(int arr[SIZE][SIZE], int temp[SIZE][SIZE], int* c_people);
void remaining_zombies_people(int arr[SIZE][SIZE], int* zombies, int* people);
int main()
{
    int maps[SIZE][SIZE] = {
    {0,1,1,0,0,0,1,1,0,0},
    {1,1,1,1,0,1,1,1,2,0},
    {0,1,0,1,0,1,0,1,1,0},
    {1,1,1,2,1,1,1,1,0,0},
    {0,1,0,1,1,0,1,0,1,0},
    {0,1,1,0,2,1,0,1,0,0},
    {0,0,1,1,0,1,1,0,1,0},
    {0,1,0,1,1,0,2,1,0,0},
    {1,0,1,0,1,1,0,1,0,0},
    {0,0,1,0,0,0,1,0,0,1}
    };
 
    int infection[SIZE][SIZE];
    int second_count = 1;
    int cycle_infection_people;
    int zombies = 0;
    int people = 0;

    while (1)
    {
        reset_array(infection);

        checked_infection(maps, infection);
        if (apply_infection(maps, infection, &cycle_infection_people))
        {
            remaining_zombies_people(maps, &zombies, &people);
            print_array(maps, &second_count, &zombies, &people, &cycle_infection_people);
            second_count++;
        }
        else
        {
            break;
        }
    }

    return 0;

}
void print_array(int arr[SIZE][SIZE], int* s_count, int* zombies, int* people, int* c_people)
{
    printf("%d초 후 감염상태\n", *s_count);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("이번에 감염된 좀비 : %d, 총 좀비 : %d, 생존자수 : %d\n", *c_people, *zombies, *people);
}
void reset_array(int temp[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            temp[i][j] = 0;
        }
    }
}
void checked_infection(int arr[SIZE][SIZE], int temp[SIZE][SIZE])
{
    int dx[4] = { -1, 0, 1, 0 }; //좌 상 우 하
    int dy[4] = { 0, -1, 0, 1 };
    int arrx;
    int arry; //

    for (int i = 0; i < SIZE; i++) //3
    {
        for (int j = 0; j < SIZE; j++) //5
        {
            if (arr[i][j] == 2)
            {
                for (int k = 0; k < 4; k++)
                {
                    arrx = i + dx[k];
                    arry = j + dy[k];

                    if (arrx >= 0 && arrx < SIZE && arry >= 0 && arry < SIZE)
                    {
                        if (arr[arrx][arry] == 1)
                        {
                            temp[arrx][arry] = 1;
                        }
                    }
                }
            }
        }
    }

}

int apply_infection(int arr[SIZE][SIZE], int temp[SIZE][SIZE], int* c_people)
{
    *c_people = 0;
    int is_change = FALSE;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (temp[i][j] == 1)
            {
                arr[i][j] = 2;
                (*c_people)++;
                is_change = TRUE;
            }
        }
    }

    return is_change;
}
void remaining_zombies_people(int arr[SIZE][SIZE], int* zombies, int* people)
{
    *zombies = 0;
    *people = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (arr[i][j] == 1)
            {
                (*people)++;
            }
            else if (arr[i][j] == 2)
            {
                (*zombies)++;
            }
        }
    }
}