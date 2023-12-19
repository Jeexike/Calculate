#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"

long int convertToDecimal(char* num)
{
    long int decimal = 0;
    if ((num[0] == '0' && (num[1] == 'x' || num[1] == 'X')) ||
        (num[0] == '-' && num[1] == '0' && (num[2] == 'x' || num[2] == 'X')))
    {
        if (num[0] != '-')
        {
            for (int i = 2; num[i] != '\0'; i++)
            {
                if (!isHexdigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                if (num[i] >= 'a' && num[i] <= 'f')
                {
                    decimal = decimal * 16 + (num[i] - 'a' + 10);
                }
                else if (num[i] >= 'A' && num[i] <= 'F')
                {
                    decimal = decimal * 16 + (num[i] - 'A' + 10);
                }
                else
                {
                    decimal = decimal * 16 + (num[i] - '0');
                }
            }
            return decimal;
        }
        else
        {
            for (int i = 3; num[i] != '\0'; i++)
            {
                if (!isHexdigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                if (num[i] >= 'a' && num[i] <= 'f')
                {
                    decimal = decimal * 16 + (num[i] - 'a' + 10);
                }
                else if (num[i] >= 'A' && num[i] <= 'F')
                {
                    decimal = decimal * 16 + (num[i] - 'A' + 10);
                }
                else
                {
                    decimal = decimal * 16 + (num[i] - '0');
                }
            }
            return -decimal;
        }
        
    }
    else if ((num[0] == '0' && num[1] != '\0') ||
        (num[0] == '-' && num[1] == '0' && num[2] != '\0'))
    {
        if (num[0] != '-')
        {
            for (int i = 1; num[i] != '\0'; i++)
            {
                if (!isOctdigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                decimal = decimal * 8 + (num[i] - '0');
            }
            return decimal;
        }
        else
        {
            for (int i = 2; num[i] != '\0'; i++)
            {
                if (!isOctdigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                decimal = decimal * 8 + (num[i] - '0');
            }
            return -decimal;
        }
        
    }
    else if ((num[0] != '0' || (num[0] == '-' && num[1] != '0')) || (num[0] == '0' && num[1] == '\0'))
    {
        if (num[0] != '-')
        {
            for (int i = 0; num[i] != '\0'; i++)
            {
                if (!isDuodigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                decimal = decimal * 2 + (num[i] - '0');
            }
            return decimal;
        }
        else
        {
            for (int i = 1; num[i] != '\0'; i++)
            {
                if (!isDuodigit(num[i]))
                {
                    printf("Error: incorrect input\n");
                    exit(1);
                }
                decimal = decimal * 2 + (num[i] - '0');
            }
            return -decimal;
        }
    }
}