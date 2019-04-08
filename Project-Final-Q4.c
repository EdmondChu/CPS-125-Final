#include <stdio.h>

int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double temp;
	int dayInMonth [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int wInfo[2], cInfo[2];
	int row, col, num, counter;
	char str[][6] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
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
	
	/*Checking array for warmest lake*/
	/*Warmest*/
	temp = lakeGraph[0][2];	   
	for (col = 2; col < 8; col++)
	{
		for (row = 0; row < 365; row++)
		{
			if ((int)(100*temp) <(int)(100*lakeGraph[row][col]))
			{
				temp = lakeGraph[row][col];
				wInfo[0] = row+1;
				wInfo[1] = col;
			}
		}
	} 
	
	/*Coldest*/
	temp = lakeGraph[0][2];	   
	for (col = 2; col < 8; col++)
	{
		for (row = 0; row < 365; row++)
		{
			if ((int)(100*temp) >(int)(100*lakeGraph[row][col]))
			{
				temp = lakeGraph[row][col];
				cInfo[0] = row+1;
				cInfo[1] = col;
			}
		}
	} 
	
	/*Converting to day/month format*/
	/*Warmest*/
	printf("Warmest Temperature\n");
	num = wInfo[0];
	counter = 0;
	for(col = 0 ; col <12; col++)
	{
		if(num > dayInMonth[col])
		{
			num = num - dayInMonth[col];
			counter++;
		}
	}
	printf("Lake: %s\tTemp = %.2lf\tDate = %s %d, 2017\n",name[wInfo[1]-2],lakeGraph[wInfo[0]][wInfo[1]],str[counter],num);

	/*Coldest*/
	printf("\nColdest Temperature\n");
	num = cInfo[0];
	counter = 0;
	for(col = 0 ; col <12; col++)
	{
		if(num > dayInMonth[col])
		{
			num = num - dayInMonth[col];
			counter++;
		}
	}
	printf("Lake: %s\tTemp = %.2lf\tDate = %s %d, 2017\n",name[cInfo[1]-2],lakeGraph[cInfo[0]][cInfo[1]],str[counter],num);

}

