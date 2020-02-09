#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i) {
		printf("%lu", (strlen(argv[i]) - 1) / 2);
		if (i != argc - 1) {
			printf(" ");
		}
	}
	return 0;
}
