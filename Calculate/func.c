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
	if (out == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
    strncpy(out, mass, strlen(mass));
    for (int i = strlen(mass); i > 0; i--)
    {
        mass[strlen(mass) - i] = out[i - 1];
    }
    free(out);
}

bool checkOperator(char* oper)
{
	if (strlen(oper) > 1)
	{
			return false;
	}
}

bool check(char* operand1, char* operand2, char oper)
{
	if (oper == '+' || oper == '-' || oper == '*' || oper == '%' || oper == '&' || oper == '|' || oper == '^')
	{
		if (operand1[0] == '-' && (oper != '&' && oper != '|' && oper != '^'))
		{
			if ((operand1[1] == '0' && operand2[0] != '0' && operand1[2] != '\0')
				|| (operand1[1] != '0' && operand2[0] == '0' && operand2[1] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				return false;
			}
			else if (((operand1[2] == 'x' && operand2[1] != 'x') || (operand1[2] != 'x' && operand2[1] == 'x') ||
				(operand1[2] == 'X' && operand2[1] != 'X') || (operand1[2] != 'X' && operand2[1] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				return false;
			}
		}
		else if (operand2[0] == '-' && (oper != '&' && oper != '|' && oper != '^'))
		{
			if ((operand1[0] == '0' && operand2[1] != '0' && operand1[1] != '\0')
				|| (operand1[0] != '0' && operand2[1] == '0' && operand2[2] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				return false;
			}
			else if (((operand1[1] == 'x' && operand2[2] != 'x') || (operand1[1] != 'x' && operand2[2] == 'x') ||
				(operand1[1] == 'X' && operand2[2] != 'X') || (operand1[1] != 'X' && operand2[2] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				return false;
			}
		}
		else if ((operand1[0] == '-' || operand2[0] == '-') && (oper == '&' || oper == '|' || oper == '^'))
		{
			printf("Error: incorrect input\n");
			return false;
		}
		else
		{
			if ((operand1[0] == '0' && operand2[0] != '0' && operand1[1] != '\0')
				|| (operand1[0] != '0' && operand2[0] == '0' && operand2[1] != '\0'))
			{
				printf("Error: the number systems do not match\n");
				return false;
			}
			else if (((operand1[1] == 'x' && operand2[1] != 'x') || (operand1[1] != 'x' && operand2[1] == 'x') ||
				(operand1[1] == 'X' && operand2[1] != 'X') || (operand1[1] != 'X' && operand2[1] == 'X')))
			{
				printf("Error: the number systems do not match\n");
				return false;
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
			return false;
		}
		else if ((operand1[1] == 'x' && operand2[1] != 'x') || (operand1[1] != 'x' && operand2[1] == 'x') ||
			(operand1[1] == 'X' && operand2[1] != 'X') || (operand1[1] != 'X' && operand2[1] == 'X'))
		{
			printf("Error: incorrect input\n");
			printf("Error: the number systems do not match\n");
			return false;
		}
	}
}

bool checkDenial(char* operand1, char oper)
{
	if (oper == '~')
	{
		if (operand1[0] == '0' && (operand1[1] == 'x' || operand1[1] == 'X'))
		{
			return true;
		}
		else if (operand1[0] == '0' && (operand1[1] != 'x' && operand1[1] != 'X'))
		{
			return true;
		}
		else if (operand1[0] != '-')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

int inputCount(char* operand1, char* operand2, char oper, char* input, char** rett)
{
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
				if (!checkOperator(token))
				{
					count += 1000;
				}
				rett[1] = token;
			}
		}

		count++;
		token = strtok(NULL, " ");
	}

	return count;
}

void output(char* operand1, char* operand2, char oper, long int operand1Dec, long int operand2Dec)
{
	char* result = NULL;
	if ((operand1[1] == 'x' || operand1[1] == 'X') || (operand1[0] == '-' && (operand1[2] == 'x' || operand1[2] == 'X')) ||
		(operand2[1] == 'x' || operand2[1] == 'X') || (operand2[0] == '-' && (operand2[2] == 'x' || operand2[2] == 'X')))
	{
		switch (oper)
		{
		case '+':
			convertToHex(operand1Dec + operand2Dec);
			break;
		case '-':
			convertToHex(operand1Dec - operand2Dec);
			break;
		case '*':
			convertToHex(operand1Dec * operand2Dec);
			break;
		case '%':
			if (operand2Dec == 0)
			{
				printf("Error: incompatibility between operation and operand\n");
				break;
			}
			convertToHex(operand1Dec % operand2Dec);
			break;
		case '&':
			result = convertToHexrev(operand1Dec & operand2Dec);
			printf("0x%s (%d)\n", result, operand1Dec & operand2Dec);
			free(result);
			break;
		case '|':
			result = convertToHexrev(operand1Dec | operand2Dec);
			printf("0x%s (%d)\n", result, operand1Dec | operand2Dec);
			free(result);
			break;
		case '^':
			result = convertToHexrev(operand1Dec ^ operand2Dec);
			printf("0x%s (%d)\n", result, operand1Dec ^ operand2Dec);
			free(result);
			break;
		default:
			printf("Error: incorrect input\n");
		}
	}
	else if ((operand1[0] == '0' && operand1[1] != '\0') ||
		(operand1[0] == '-' && operand1[1] == '0' && operand1[2] != '\0'))
	{
		switch (oper)
		{
		case '+':
			convertToOct(operand1Dec + operand2Dec);
			break;
		case '-':
			convertToOct(operand1Dec - operand2Dec);
			break;
		case '*':
			convertToOct(operand1Dec * operand2Dec);
			break;
		case '%':
			if (operand2Dec == 0)
			{
				printf("Error: incompatibility between operation and operand\n");
				break;
			}
			convertToOct(operand1Dec % operand2Dec);
			break;
		case '&':
			result = convertToOctrev(operand1Dec & operand2Dec);
			printf("0%s (%d)\n", result, operand1Dec & operand2Dec);
			free(result);
			break;
		case '|':
			result = convertToOctrev(operand1Dec | operand2Dec);
			printf("0%s (%d)\n", result, operand1Dec | operand2Dec);
			free(result);
			break;
		case '^':
			result = convertToOctrev(operand1Dec ^ operand2Dec);
			printf("0%s (%d)\n", result, operand1Dec ^ operand2Dec);
			free(result);
			break;
		default:
			printf("Error: incorrect input\n");
		}
	}
	else
	{
		switch (oper)
		{
		case '+':
			convertToDuo(operand1Dec + operand2Dec);
			break;
		case '-':
			convertToDuo(operand1Dec - operand2Dec);
			break;
		case '*':
			convertToDuo(operand1Dec * operand2Dec);
			break;
		case '%':
			if (operand2Dec == 0)
			{
				printf("Error: incompatibility between operation and operand\n");
				break;
			}
			convertToDuo(operand1Dec % operand2Dec);
			break;
		case '&':
			result = convertToDuoret(operand1Dec & operand2Dec);
			printf("%s (%d)\n", result, operand1Dec & operand2Dec);
			free(result);
			break;
		case '|':
			result = convertToDuoret(operand1Dec | operand2Dec);
			printf("%s (%d)\n", result, operand1Dec | operand2Dec);
			free(result);
			break;
		case '^':
			result = convertToDuoret(operand1Dec ^ operand2Dec);
			printf("%s (%d)\n", result, operand1Dec ^ operand2Dec);
			free(result);
			break;
		default:
			printf("Error: incorrect input\n");
		}
	}
}

void outputDenial(char* operand1, char oper, long int operand1Dec)
{
	if (operand1[1] == 'x' || operand1[1] == 'X')
	{
		switch (oper)
		{
			case '~':
				tildaHex(~operand1Dec);
				break;
			default:
				printf("Error: incorrect input\n");
		}
	}
	else if (operand1[0] == '0' && operand1[1] != '\0')
	{
		switch (oper)
		{
			case '~':
				tildaOct(~operand1Dec);
				break;
			default:
				printf("Error: incorrect input\n");
		}
	}
	else
	{
		switch (oper)
		{
			case '~':
				tilda(~operand1Dec);
				break;
			default:
				printf("Error: incorrect input\n");
		}
	}
}