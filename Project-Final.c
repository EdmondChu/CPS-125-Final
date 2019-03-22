#include <stdio.h>

int
main(void)
{
	FILE *in;
	double year[365], day[365], supT[365], michT[365], huronT[365], erieT[365], ontT[365], st_clrT[365];
	double temp, supA =0, michA =0, huronA=0, erieA=0, ontA=0, st_clrA =0, totalA;
	int i;
	
	in = fopen("file.txt","r");
	
	for (i = 0; i <365; i++)
	{
		fscanf(in,"%lf",&temp);
		year[i] = temp;	   
		
		fscanf(in,"%lf",&temp);
		day[i] = temp;
		
		fscanf(in,"%lf",&temp);
		supT[i] = temp;
		supA = supA + temp;
			
		fscanf(in,"%lf",&temp);
		michT[i] = temp;
		michA = michA + temp;
		
		fscanf(in,"%lf",&temp);
		huronT[i] = temp;
		huronA = huronA + temp;
		
		fscanf(in,"%lf",&temp);
		erieT[i] = temp;
		erieA = erieA + temp;
		
		fscanf(in,"%lf",&temp);
		ontT[i] = temp;
		ontA = ontA + temp;
		
		fscanf(in,"%lf",&temp);
		st_clrT[i] = temp;
		st_clrA = st_clrA + temp;
	}
	totalA = (supA/365 + michA/365 + huronA/365 + erieA/365+ ontA/365 + st_clrA/365)/6;
	
	printf("%.lf\t%.lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t\n",year[364],day[364],supT[364],michT[364],huronT[364],erieT[364],ontT[364],st_clrT[364]);
	printf("Avg Temps: %.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t\n",supA/365,michA/365,huronA/365,erieA/365,ontA/365,st_clrA/365,totalA);

	return (0);
}


