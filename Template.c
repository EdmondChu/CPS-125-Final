#include <stdio.h>

int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double temp;
	int row, col;

	in = fopen("file.txt", "r");

	for (row = 0; row < 365; row++)
	{
		for (col = 0; col < 8; col++)
		{
			fscanf(in, "%lf", &temp);
			lakeGraph[row][col] = temp;
		}
	}
}


