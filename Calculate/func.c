#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "func.h"


void rev(char* mass)
{
    char *out = NULL;
    out = (char*)malloc(sizeof(char) * strlen(mass));
    strncpy(out, mass, strlen(mass));
    for (int i = strlen(mass); i > 0; i--)
    {
        mass[strlen(mass) - i] = out[i - 1];
    }
    free(out);
}

void chek(char* operand1, char* operand2, char* oper)
{
	if (oper == '+' || oper == '-' || oper == '*' || oper == '%' || oper == '&' || oper == '|' || oper == '^')
	{
		if (operand1[0] == '-' && (oper != '&' && oper != '|' && oper != '^'))
		{
			if ((operand1[1] == '0' && operand2[0] != '0' && operand1[2] != '\0')
				|| (operand1[1] != '0' && operand2[0] == '0' && operand2[1] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
			else if (((operand1[2] == 'x' && operand2[1] != 'x') || (operand1[2] != 'x' && operand2[1] == 'x') ||
				(operand1[2] == 'X' && operand2[1] != 'X') || (operand1[2] != 'X' && operand2[1] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
		}
		else if (operand2[0] == '-' && (oper != '&' && oper != '|' && oper != '^'))
		{
			if ((operand1[0] == '0' && operand2[1] != '0' && operand1[1] != '\0')
				|| (operand1[0] != '0' && operand2[1] == '0' && operand2[2] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
			else if (((operand1[1] == 'x' && operand2[2] != 'x') || (operand1[1] != 'x' && operand2[2] == 'x') ||
				(operand1[1] == 'X' && operand2[2] != 'X') || (operand1[1] != 'X' && operand2[2] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
		}
		else if ((operand1[0] == '-' || operand2[0] == '-') && (oper == '&' || oper == '|' || oper == '^'))
		{
			printf("Error: incorrect input\n");
			exit(1);
		}
		else
		{
			if ((operand1[0] == '0' && operand2[0] != '0' && operand1[1] != '\0')
				|| (operand1[0] != '0' && operand2[0] == '0' && operand2[1] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
			else if (((operand1[1] == 'x' && operand2[1] != 'x') || (operand1[1] != 'x' && operand2[1] == 'x') ||
				(operand1[1] == 'X' && operand2[1] != 'X') || (operand1[1] != 'X' && operand2[1] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				exit(1);
			}
		}
	}
	else
	{
		if ((operand1[0] == '0' && operand2[0] != '0')
			|| (operand1[0] != '0' && operand2[0] == '0'))
		{
			printf("Error: incorrect input\n");
			printf("Error: the number systems do not match\n");
			exit(1);
		}
		else if ((operand1[1] == 'x' && operand2[1] != 'x') || (operand1[1] != 'x' && operand2[1] == 'x') ||
			(operand1[1] == 'X' && operand2[1] != 'X') || (operand1[1] != 'X' && operand2[1] == 'X'))
		{
			printf("Error: incorrect input\n");
			printf("Error: the number systems do not match\n");
			exit(1);
		}
	}
}

char** operandsOper(char* operand1, char* operand2, char oper, char* input)
{
	char** rett = NULL;
	rett = (char**)malloc(3 * sizeof(char*));
	rett[0] = NULL;
	rett[1] = NULL;
	rett[2] = NULL;
	char* token = strtok(input, " ");
	int count = 0;
	while (token != NULL)
	{
		if (count < 3)
		{
			if (count == 2)
			{
				int operandLen = strlen(token);
				if (token[operandLen - 1] == '\n') {
					operandLen -= 1;
				}
				rett[2] = token;
				rett[2][operandLen] = '\0';
			}
			else if (count == 0)
			{
				rett[0] = token;
			}
			else if (count == 1)
			{
				rett[1] = token;
			}
		}
		else
		{
			printf("Error: incorrect input\n");
			exit(1);
		}
		count++;
		token = strtok(NULL, " ");
	}
	return rett;
}