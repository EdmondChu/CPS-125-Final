#include <stdio.h>

int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double temp;
	int row, col, counter;
	char name[][10] = {"Superior","Michigan","Huron","Erie","Ontario","St Clair"};

	in = fopen("file.txt", "r");

	for (row = 0; row < 365; row++)
	{
		for (col = 0; col < 8; col++)
		{
			fscanf(in, "%lf", &temp);
			lakeGraph[row][col] = temp;
		}
	}
	
	printf("Swimmable Days\n");
	for (col = 2; col < 8; col++)
	{
		counter = 0;
		for (row = 0; row < 365; row++)
		{
			temp = lakeGraph[row][col];
			
			if((int)(temp*100)>2000)
			{
				counter++;
			}
		}
		printf("Lake: %s\t Swim Days: %d\n",name[col-2],counter);
	}
	
}


