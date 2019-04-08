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
 	
	printf("Frozen Days\n");
	for (col = 2; col < 8; col++)
	{
		counter = 0;
		for (row = 0; row < 365; row++)
		{
			temp = lakeGraph[row][col];
			
			if((int)(temp*100)<0)
			{
				counter++;
			}
		}
		printf("Lake: %s\t Frozen Days: %d\n",name[col-2],counter);
	}
}


