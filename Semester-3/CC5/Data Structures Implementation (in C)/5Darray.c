/**
 * @file 5Darray.c
 * @author Darpan Bhattacharya
 * @brief Creating a 5D array of dimensions 5x3x3x2x8
 * @version 0.1
 * @date 2022-09-19
 * 
 */
#include <stdio.h>

int main()
{
	int***** arr;
	arr = (int*****) malloc(sizeof(int****) * 5);
	for(int i = 0; i < 5; i++)
	{
		arr[i] = (int****) malloc(sizeof(int***) * 3);
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			arr[i][j] = (int***) malloc(sizeof(int**) * 3);
		}
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				arr[i][j][k] = (int**) malloc(sizeof(int*) * 2);
			}
		}
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				for(int l = 0; l < 3; l++)
				{
					arr[i][j][k][l] = (int*) malloc(sizeof(int) * 8);
				}
			}
		}
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				for(int l = 0; l < 3; l++)
				{
					for(int m = 0; m < 8; m++)
					{
						arr[i][j][k][l][m] = i+j+k+l+m;
					}
				}
			}
		}
	}
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int k = 0; k < 3; k++)
			{
				for(int l = 0; l < 3; l++)
				{
					for(int m = 0; m < 8; m++)
					{
						printf("i = %d j = %d k = %d l = %d m = %d : arr[i][j][k][l][m] = %d\n", i,j,k,l,m, arr[i][j][k][l][m]);
					}
				}
			}
		}
	}
	return 0;
}
