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

	long int operand1Dec = 0;
	char** rett = NULL;
	rett = (char**)calloc(3, sizeof(char*));
	if (rett == NULL)
	{
		printf("Memory allocation error\n");
		exit(1);
	}
	char *operand1 = NULL;
	char *operand2 = NULL;
	char oper = '\0';

	int count = inputCount(operand1, operand2, oper, input, rett);

	if (count == 3)
	{
		goto process1;
	}
	else if (count == 1)
	{
		goto process2;
	}
	else
	{
		printf("Error: incorrect input\n");
		goto deallocate;
	}

	process2:
		rett[0][strlen(rett[0]) - 1] = '\0';

		if (!checkDenial(rett[0] + 1, rett[0][0]))
		{
			printf("Error: incorrect input\n");
			free(rett);
			return 0;
		}

		operand1Dec = convertToDecimal(rett[0] + 1);

		outputDenial(rett[0] + 1, rett[0][0], operand1Dec);
		free(rett);
		return 0;

	process1:
		operand1 = rett[0];
		oper = rett[1][0];
		operand2 = rett[2];

		operand1Dec = convertToDecimal(operand1);
		long int operand2Dec = convertToDecimal(operand2);
	
		if (!check(operand1, operand2, oper) || !checkOperator(rett[1]))
		{
			goto deallocate;
		}

		output(operand1, operand2, oper, operand1Dec, operand2Dec);

	deallocate:
		free(rett);
		return 0;

}
