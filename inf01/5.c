#include <stdio.h>

int
ascii_check(const int symbol)
{
	if (symbol <= 127 && symbol >= 0) {
		return 1;
	}
	return 0;
}

int
octets_count(int symbol)
{
	if ((symbol >> 5) == 6) {
		return 2;
	}
	if ((symbol >> 4) == 14) {
		return 3;
	}
	if ((symbol >> 3) == 30) {
		return 4;
	}
	if ((symbol >> 2) == 62) {
		return 5;
	}
	if ((symbol >> 1) == 126) {
		return 6;
	}
	return 0;
}

int
main(int argc, char **argv)
{
	int		ascii_count = 0;
	int		not_ascii_count = 0;
	int		symbol = getchar();

	while (symbol != EOF) {
		if (ascii_check(symbol)) {
			++ascii_count;
		} else {
			int		octets_number = octets_count(symbol);
			if (octets_number < 2 || octets_number > 6) {
				printf("%i %i", ascii_count, not_ascii_count);
				return 1;
			}
			int		next_char = 0;
			for (int i = 1; i < octets_number; ++i) {
				if ((next_char = getchar()) == EOF || (next_char >> 6) != 2) {
					printf("%i %i", ascii_count, not_ascii_count);
					return 1;
				}
			}
			++not_ascii_count;
		}
		symbol = getchar();
	}
	printf("%i %i", ascii_count, not_ascii_count);
	return 0;
}
