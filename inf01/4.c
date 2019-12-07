#include <stdio.h>

int
main(int argc, char **argv)
{
	const int	alphabet_size = 26;
	const int	number_size = 10;
	unsigned long long result = 0;
	unsigned long long tmp = 0;
	int		current_char = 0;
	while ((current_char = getchar()) != EOF) {
		if (current_char == '&') {
			result &= tmp;
			tmp = 0;
		} else if (current_char == '|') {
			result |= tmp;
			tmp = 0;
		} else if (current_char == '^') {
			result ^= tmp;
			tmp = 0;
		} else if (current_char == '~') {
			result = (~result);
		} else if ('0' <= current_char && current_char <= '9') {
			tmp |= 1ULL << (current_char - '0');
		} else if ('A' <= current_char && current_char <= 'Z') {
			tmp |= 1ULL << (current_char - 'A' + number_size);
		} else if ('a' <= current_char && current_char <= 'z') {
			tmp |= 1ULL << (current_char - 'a' + number_size + alphabet_size);
		}
	}

	int		final_result = 0;
	for (int i = 0; i < number_size + alphabet_size + alphabet_size; ++i) {
		if (i < number_size) {
			final_result = i + '0';
		}
		if (number_size <= i && i < number_size + alphabet_size) {
			final_result = i - number_size + 'A';
		}
		if (number_size + alphabet_size <= i) {
			final_result = i - number_size - alphabet_size + 'a';
		}
		if ((result >> i) & 1) {
			printf("%c", final_result);
		}
	}
	return 0;
}
