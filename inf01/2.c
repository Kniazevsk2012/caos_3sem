#include <stdint.h>

uint16_t
satsum(uint16_t x, uint16_t y)
{
	uint16_t	sum = x + y;
	if ((sum < x) || (sum < y)) {
		sum = 0;
		sum -= 1;
	}
	return sum;
}
