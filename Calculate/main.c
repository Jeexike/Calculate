#define _CRT_SECURE_NO_WARNINGS


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

int main()
{
	const int n = 100;
	char input[100];
	printf("Enter the expression: ");
	fgets(input, n, stdin);

	//char *token = strtok(input, " ");
	char *operand1 = NULL;
	char *operand2 = NULL;
	char oper = NULL;
	char** tokens = NULL;
	//int count = 0;

	tokens = operandsOper(operand1, operand2, oper, input);

	operand1 = tokens[0];
	oper = tokens[1][0];
	operand2 = tokens[2];

	/*while (token != NULL)
	{
		if (count < 3)
		{
			if (count == 2)
			{
				int operandLen = strlen(token);
				if (token[operandLen - 1] == '\n') {
					operandLen -= 1;
				}
				operand2 = token;
				operand2[operandLen] = '\0';
			}
			else if (count == 0)
			{
				operand1 = (char*)malloc(sizeof(char) * (strlen(token) + 1));
				strcpy(operand1, token);
			}
			else if (count == 1)
			{
				oper = *token;
			}
		}
		else
		{
			printf("Error: incorrect input\n");
			exit(1);
		}
		count++;
		token = strtok(NULL, " ");
	}*/

	long int operand1Dec = convertToDecimal(operand1);
	long int operand2Dec = convertToDecimal(operand2);

	chek(operand1, operand2, oper);

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
			printf("0x%s (%d)", convertToHexrev(operand1Dec & operand2Dec), operand1Dec & operand2Dec);
			break;
		case '|':
			printf("0x%s (%d)", convertToHexrev(operand1Dec | operand2Dec), operand1Dec | operand2Dec);
			break;
		case '^':
			printf("0x%s (%d)", convertToHexrev(operand1Dec ^ operand2Dec), operand1Dec ^ operand2Dec);
			break;
		case '~':
			convertToHex(NULL);
			break;
		default:
			printf("Error: incorrect input\n");
			exit(1);
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
			printf("0%s (%d)", convertToOctrev(operand1Dec & operand2Dec), operand1Dec & operand2Dec);
			break;
		case '|':
			printf("0%s (%d)", convertToOctrev(operand1Dec | operand2Dec), operand1Dec | operand2Dec);
			break;
		case '^':
			printf("0%s (%d)", convertToOctrev(operand1Dec ^ operand2Dec), operand1Dec ^ operand2Dec);
			break;
		case '~':
			convertToHex(NULL);
			break;
		default:
			printf("Error: incorrect input\n");
			exit(1);
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
			printf("%s (%d)", convertToDuoret(operand1Dec & operand2Dec), operand1Dec & operand2Dec);
			break;
		case '|':
			printf("%s (%d)", convertToDuoret(operand1Dec | operand2Dec), operand1Dec | operand2Dec);
			break;
		case '^':
			printf("%s (%d)", convertToDuoret(operand1Dec ^ operand2Dec), operand1Dec ^ operand2Dec);
			break;
		case '~':
			printf("-%s (%d)", convertToDuoret(~operand1Dec), ~operand1Dec);
			break;
		default:
			printf("Error: incorrect input\n");
			exit(1);
		}
	}
	free(tokens);
	return 0;

}