#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

int isHexdigit(char c)
{
    if (c == '-')
    {
        return true;
    }
    else if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void convertToHex(long int num)
{
    long int num2 = 0;
    char* hex = NULL;
    hex = calloc(100, sizeof(char));
    int i = 0;
    if (num >= 0)
    {
        num2 = num;
        if (num2 == 0)
        {
            for (int i = 0; i != 1; i++)
            {
                hex[i] = 48;
            }
        }
        while (num2 != 0)
        {
            int temp = 0;
            temp = num2 % 16;
            if (temp < 10)
            {
                hex[i] = temp + 48;
            }
            else
            {
                hex[i] = temp + 87;
            }
            i++;
            num2 = num2 / 16;
        }
        rev(hex);
        printf("0x%s (%d)\n", hex, num);
        free(hex);
    }
    else
    {
        if (num2 == 0)
        {
            for (int i = 0; i != 1; i++)
            {
                hex[i] = 48;
            }
        }
        while (num2 != 0)
        {
            int temp = 0;
            temp = num2 % 16;
            if (temp < 10)
            {
                hex[i] = temp + 48;
            }
            else
            {
                hex[i] = temp + 87;
            }
            i++;
            num2 = num2 / 16;
        }
        rev(hex);
        printf("-0x%s (%d)\n", hex, num);
        free(hex);
    }
    
}

char* convertToHexrev(long int num)
{
    long int num2 = num;
    char* hex = (char*)calloc(100, sizeof(char));
    int i = 0;
    if (num2 == 0)
    {
        hex[0] = '0';
        return hex;
    }
    while (num2 != 0)
    {
        int temp = 0;
        temp = num2 % 16;
        if (temp < 10)
        {
            hex[i] = temp + '0';
        }
        else
        {
            hex[i] = temp + 'a' - 10;
        }
        i++;
        num2 = num2 / 16;
    }
    rev(hex);
    return hex;
}


void tildaHex(long int num)
{
    char* hex = NULL;
    hex = calloc(100, sizeof(char));
    long int num2 = -num;
    int i = 0;
    if (num2 == 0)
    {
        for (int i = 0; i != 1; i++)
        {
            hex[i] = 48;
        }
    }
    while (num2 != 0)
    {
        int temp = 0;
        temp = num2 % 16;
        if (temp < 10)
        {
            hex[i] = temp + 48;
        }
        else
        {
            hex[i] = temp + 87;
        }
        i++;
        num2 = num2 / 16;
    }
    rev(hex);
    printf("-0x%s (%d)\n", hex, num);
    free(hex);
}
