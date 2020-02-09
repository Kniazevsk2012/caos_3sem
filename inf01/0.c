#include <stdio.h>
#include <stdlib.h>

int
main(int argc, char *argv[])
{
	double		x;
	long		y;
	scanf("%lf %lx", &x, &y);
	long		z = strtol(argv[1], NULL, 27);

	double		result = x + y + z;
	printf("%.3f", result);

	return 0;
  }
