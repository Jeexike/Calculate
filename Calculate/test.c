#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <stdlib.h>


int main()
{
	int size;
	printf("Enter the size of mass: ");
	scanf("%d", &size);
	printf("\n");
	int* mass = NULL;
	mass = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		printf("Enter the mass[%d]: ", i + 1);
		scanf("%d", &mass[i]);
		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (mass[i] > mass[j])
			{
				int temple = mass[i];
				mass[i] = mass[j];
				mass[j] = temple;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
	return 0;
}


