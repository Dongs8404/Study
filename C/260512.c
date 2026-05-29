#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    printf("The number of parameters : %d\n", argc);
    for(int i = 1; i < argc; i++)
        printf("%s", argv[i]);
    printf("\n");
}