#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stdout, "Usage: %s number\n", argv[0]);
		return 1;
	}

	double in_val = atof(argv[1]);
	double out_val = sqrt(in_val);
	fprintf(stdout, "The square root of %g is %g\n",
	        in_val, out_val);

	return 0;
}
