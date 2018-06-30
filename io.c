#include <stdlib.h>
#include <stdio.h>

void main()
{
	FILE *out = fopen("mydata.dat", "w");

	if (out == NULL)
	{
	  printf("Unable to open mydata.dat\n");
	  exit(1);
	}
	fprintf(out, "Hello\n");
	fprintf(out, "my name is David.");
	fprintf(out, "One Plus One Equals %d\n", 1+1);	
	fclose(out);
}

