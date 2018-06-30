#include <stdlib.h>
#include <stdio.h>

void main()
{	
	char c;
	int i = 0;
	int count = 0;
	FILE *in = fopen("mydata.dat", "r");
	if (in == NULL)
	{
	  printf("Unable to open mydata.dat.\n");
	}

	
	i= fscanf(in, "%c", &c);
	while(count>0)
	{
	  where[count] = c;
	  count++;
	  i = fscanf(in, "%s %s ", where, where2);
	
	}
	printf("%s\n", where);
	fclose(in);
}
