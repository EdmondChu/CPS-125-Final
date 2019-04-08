#include <stdio.h>

int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double temp, tDay;
	int wDay[6], cDay[6];
	int dayInMonth [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int row, col,counter, num;
	char str[][6] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sept","Oct","Nov","Dec"};
	char name[][10] = {"Superior","Michigan","Huron","Erie","Ontario","St Clair"};
	
	in = fopen("file.txt","r");	   
	for (row = 0; row < 365; row++)
	{
		for (col = 0; col < 8; col++)
		{
			fscanf(in, "%lf", &temp);
			lakeGraph[row][col] = temp;
		}
	}
	
	/*Checking Array for warmest day*/
	for (col = 2; col < 8 ; col++)
	{
		tDay = lakeGraph[0][col];
	
		for (row = 1; row < 365; row++)
		{
			if ((int)(1000*tDay) < (int)(1000*lakeGraph[row][col]))
			{
				tDay = lakeGraph[row][col];
				wDay[col-2] = row+1;
			}
		}
	}
	
	/*Checking Array for coldest day*/
	for (col = 2; col < 8 ; col++)
	{
		tDay = lakeGraph[0][col];
	
		for (row = 1; row < 365; row++)
		{
			if ((int)(1000*tDay) > (int)(1000*lakeGraph[row][col]))
			{
				tDay = lakeGraph[row][col];
				cDay[col-2] = row+1;
			}
		}
	}
	
	/*Converting to date/month format*/
	
	printf("Warmest Temperature\n");
	for(row = 0; row < 6; row++)
	{
		num = wDay[row];
		counter = 0;
		for(col = 0 ; col <12; col++)
		{
			if(num > dayInMonth[col])
			{
				num = num - dayInMonth[col];
				counter++;
			}
		}
		printf("Lake: %s\tTemp = %.2lf\tDate = %s %d, 2017\n",name[row],lakeGraph[wDay[row]-1][row+2],str[counter],num);
	
	}
	
	printf("\nColdest Temperature\n");
	for(row = 0; row < 6; row++)
	{
		num = cDay[row];
		counter = 0;
		for(col = 0 ; col <12; col++)
		{
			if(num > dayInMonth[col])
			{
				num = num - dayInMonth[col];
				counter++;
			}
		}
		printf("Lake: %s\tTemp = %.2lf\tDate = %s %d, 2017\n",name[row],lakeGraph[cDay[row]-1][row+2],str[counter],num);
	
	}
}

