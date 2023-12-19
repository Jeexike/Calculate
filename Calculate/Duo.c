#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

int isDuodigit(char c)
{
    if (c == '-')
    {
        return true;
    }
    else if (c >= '0' && c <= '1')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char* convertToDuoret(long int num)
{
    long int num2 = num;
    char* duo = (char*)calloc(100, sizeof(char));
    int i = 0;
    if (num2 == 0)
    {
        for (int i = 0; i != 1; i++)
        {
                duo[i] = 48;
        }
    }
    while (num2 != 0)
    {
        int temp = 0;
        temp = num2 % 2;
        duo[i] = temp + 48;
        i++;
        num2 = num2 / 2;
    }
    rev(duo);
    return duo;
}

void convertToDuo(long int num)
{
    int base = 1;
    long int res = 0;
    int last;
    long int num2 = num;
    while (num2) {
        last = num2 % 2;
        num2 /= 2;
        res += last * base;
        base *= 10;
    }
    printf("%d (%d)\n", res, num);
}

void tilda(long int num)
{
    int base = 1;
    long int res = 0;
    int last;
    long int num2 = num;
    while (num2) {
        last = num2 % 2;
        num2 /= 2;
        res += last * base;
        base *= 10;
    }
    printf("%d (%d)\n", res, num);
}