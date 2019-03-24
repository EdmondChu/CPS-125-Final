#include <stdio.h>

/*Methods for Question 1*/
double avgTemp (int colNum, double chart[385][8])
{
	int i;
	double avg = 0;
	
	for (i = 0; i < 365; i ++)
	{
		avg += chart[i][colNum];
	}
	
	return(avg/365);
}

/*Methods for Question 2*/
int warmestLake(double lakeT [6])
{	
	int i =0, temp = (int)(100*lakeT[0]), rCol = 0;
	
	for(i = 1 ;i < 5; i++)
	{
		if((int)(100*lakeT[i]) > temp)
		{
			temp = (int)(100*lakeT[i]);
			rCol = i;
		}
	}

	return (rCol);
}

int coldestLake(double lakeT [6])
{	
	int i =0, temp = (int)(100*lakeT[0]), rCol = 0;
	
	for(i = 1 ;i < 5; i++)
	{
		if((int)(100*lakeT[i]) < temp)
		{
			temp = (int)(100*lakeT[i]);
			rCol = i;
		}
	}

	return (rCol);
}

void aboveAverage (double lAverage[], double AverageT)
{
	int i;
	
	printf("2b)\t\t\t");
	for(i = 0; i< 6; i++)
	{
		if((int)(100*lAverage[i])-(int)(100*AverageT) > 0)
		printf("Above\t");
		else
		printf("Below\t");
	}
}
/*Question 3 Methods*/
int warmestDay (double lG[365][8], int colN)
{
	int day, i;
	double hTemp = lG[0][colN];
	
	for (i = 1 ; i< 365; i++) 
	{
		if ((int)(100*lG[i][colN])>(int)(100*hTemp))
		{
			hTemp = lG[i][colN];
			day = i;
		} 
	}
	return day;
}


int coldestDay (double lG[365][8], int colN)
{
	int day, i;
	double lTemp = lG[0][colN];
	
	for (i = 1 ; i< 365; i++) 
	{
		if ((int)(100*lG[i][colN])<(int)(100*lTemp))
		{
			lTemp = lG[i][colN];
			day = i;
		} 
	}
	return day;
}
/*Main Method*/
int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double lakeA [6];
	double temp, totalA = 0;
	char str[][10] = {"Year","Date","Superior","Michigan","Huron","Erie","Ontario","St Clair"};
	int wDay[6], cDay[6];
	int row, col, warmCol, coldCol;
	
	in = fopen("file.txt","r");
	
	for (row = 0; row <365; row++)
	{
		for(col = 0; col < 8; col++)
		{
			fscanf(in,"%lf",&temp);
			lakeGraph[row][col] = temp;	   
		}
	}	 	 

	printf("\tYear\tDate\tSup\tMich\tHuron\tErie\tOnt\tSt Clar\tTotal\n");	  
	printf("\t%.lf\t%.lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t\n",lakeGraph[364][0],lakeGraph[364][1],lakeGraph[364][2],lakeGraph[364][3],lakeGraph[364][4],lakeGraph[364][5],lakeGraph[364][6],lakeGraph[364][7]);

	printf("1)\t\t\t");
	
	/*Question 1*/
	
	for (col = 2; col < 8; col++)
	{
		lakeA[col-2] = avgTemp (col,lakeGraph);
		printf("%.2lf\t",lakeA[col-2]);
		totalA += lakeA[col-2];
	}
	
	totalA= totalA/6;
	printf("%.2lf\n",totalA);
	
	/*Question 2 */

	warmCol = warmestLake(lakeA);
	coldCol = coldestLake(lakeA);
	printf("2a)\tWarmest = %s \t\tColdest = %s\n",str[warmCol+2], str[coldCol+2]);
	aboveAverage(lakeA, totalA);
	
	/*Question 3*/
	printf("\n 3)");
	for (col = 0 ; col < 6 ; col++)
	{
		wDay[col] = warmestDay(lakeGraph, col);
		cDay[col] = coldestDay(lakeGraph, col);
		printf("\t%s:\tH:%d\tL:%d",str[col+2],wDay[col],cDay[col]);
	}	
	return (0);
}

