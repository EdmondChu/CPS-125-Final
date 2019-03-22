#include <stdio.h>

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

int main(void)
{
	FILE *in;
	double lakeGraph [365][8];
	double lakeA [6];
	double temp, totalA, warmestA, coldestA;
	int row, col;
	
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
	
	for (col = 2; col < 8; col++)
	{
		lakeA[col-2] = avgTemp (col,lakeGraph);
		printf("%.2lf\t",lakeA[col-2]);
	}

	return (0);
}



