#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

int isOctdigit(char c)
{
    if (c == '-')
    {
        return true;
    }
    else if (c >= '0' && c <= '7')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void convertToOct(long int num)
{
    if (num >= 0)
    {
        long int num2 = num;
        char* oct = NULL;
        oct = calloc(100, sizeof(char));
        int i = 0;
        if (num2 == 0)
        {
            for (int i = 0; i != 1; i++)
            {
                oct[i] = 48;
            }
        }
        while (num2 != 0)
        {
            int temp = 0;
            temp = num2 % 8;
            oct[i] = temp + 48;
            i++;
            num2 = num2 / 8;
        }
        rev(oct);
        printf("0%s (%d)\n", oct, num);
        free(oct);
    }
    else
    {
        long int num2 = -num;
        char* oct = NULL;
        oct = calloc(100, sizeof(char));
        int i = 0;
        if (num2 == 0)
        {
            for (int i = 0; i != 1; i++)
            {
                oct[i] = 48;
            }
        }
        while (num2 != 0)
        {
            int temp = 0;
            temp = num2 % 8;
            oct[i] = temp + 48;
            i++;
            num2 = num2 / 8;
        }
        rev(oct);
        printf("-0%s (%d)\n", oct, num);
        free(oct);
    }
    /*int base = 1;
    int res = 0;
    int last;
    int num2 = num;
    while (num2)
    {
        last = num2 % 8;
        num2 /= 8;
        res += last * base;
        base *= 10;
    }
    printf("0%d (%d)", res, num);*/
}

char* convertToOctrev(long int num)
{
    long int num2 = num;
    char* oct = NULL;
    oct = (char*)calloc(100, sizeof(char));
    if (oct == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    int i = 0;
    if (num2 == 0)
    {
        for (int i = 0; i != 1; i++)
        {
            oct[i] = 48;
        }
    }
    while (num2 != 0)
    {
        int temp = 0;
        temp = num2 % 8;
        oct[i] = temp + 48;
        i++;
        num2 = num2 / 8;
    }
    rev(oct);
    return(oct);
}

void tildaOct(long int num)
{
    long int num2 = -num;
    char* oct = NULL;
    oct = calloc(100, sizeof(char));
    if (oct == NULL)
    {
        printf("Memory allocation error\n");
        exit(1);
    }
    int i = 0;
    if (num2 == 0)
    {
        for (int i = 0; i != 1; i++)
        {
            oct[i] = 48;
        }
    }
    while (num2 != 0)
    {
        int temp = 0;
        temp = num2 % 8;
        oct[i] = temp + 48;
        i++;
        num2 = num2 / 8;
    }
    rev(oct);
    printf("-0%s (%d)\n", oct, num);
    free(oct);
}
