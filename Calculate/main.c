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

	long int operand1Dec = NULL;
	char** rett = NULL;
	rett = (char**)calloc(3, sizeof(char*));
	char *operand1 = NULL;
	char *operand2 = NULL;
	char oper = NULL;

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
		rett = denial(rett[0]);
		operand1 = rett[1];
		oper = rett[0][0];

		operand1Dec = convertToDecimal(operand1);

		if (!checkDenial(operand1, oper))
		{
			goto deallocate;
		}

		outputDenial(operand1, oper, operand1Dec);
		return 0;

	process1:
		operand1 = rett[0];
		oper = rett[1][0];
		operand2 = rett[2];

		operand1Dec = convertToDecimal(operand1);
		long int operand2Dec = convertToDecimal(operand2);
	
		if (!check(operand1, operand2, oper) && !checkOperator(oper))
		{
			goto deallocate;
		}

		output(operand1, operand2, oper, operand1Dec, operand2Dec);

	deallocate:
		free(rett);
		return 0;

}