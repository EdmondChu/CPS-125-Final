#include <stdio.h>

int
main(void)
{
	FILE *in;
	double year[365], day[365], supT[365], michT[365], huronT[365], erieT[365], ontT[365], st_clrT[365];
	double temp;
	int i;
	
	in = fopen("fileT","r");
	
	for (i = 0; i <365; i++)
	{
		fscanf(in,"%lf",&temp);
		year[i]=temp ;	  
		fscanf(in,"%lf",&temp);
		day[i] = temp;
		fscanf(in,"%lf",&temp);
		supT[i] = temp;
		fscanf(in,"%lf",&temp);
		michT[i] = temp;
		fscanf(in,"%lf",&temp);
		huronT[i] = temp;
		fscanf(in,"%lf",&temp);
		erieT[i] = temp;
		fscanf(in,"%lf",&temp);
		ontT[i] = temp;
		fscanf(in,"%lf",&temp);
		st_clrT[i] = temp;
	
	}
	
	printf("%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t",year[1],day[1],supT[1],michT[1],huronT[1],erieT[1],ontT[1],st_clrT[1]);

	return (0);
}

