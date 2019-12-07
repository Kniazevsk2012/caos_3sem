typedef enum {
	PlusZero = 0x00,
	MinusZero = 0x01,
	PlusInf = 0xF0,
	MinusInf = 0xF1,
	PlusRegular = 0x10,
	MinusRegular = 0x11,
	PlusDenormal = 0x20,
	MinusDenormal = 0x21,
	SignalingNaN = 0x30,
	QuietNaN = 0x31
} float_class_t;

extern		float_class_t
classify(double *value_ptr)
{
	unsigned long long value = *((unsigned long long *)value_ptr);

	const unsigned long long max_exp = 0x7FF;
	const unsigned long long mantissa_first_bit = value & (1ULL << 51ULL);

	const unsigned long long sign = value >> 63ULL;
	const unsigned long long exp = (value << 1ULL) >> 53ULL;
	const unsigned long long mantissa = (value << 12ULL) >> 12ULL;

	if (exp == 0) {
		if (mantissa == 0) {
			if (sign == 0) {
				return PlusZero;
			} else if (sign == 1) {
				return MinusZero;
			}
		} else {
			if (sign == 0) {
				return PlusDenormal;
			} else if (sign == 1) {
				return MinusDenormal;
			}
		}
	} else {
		if (exp == max_exp) {
			if (mantissa == 0) {
				if (sign == 0) {
					return PlusInf;
				} else {
					return MinusInf;
				}
			} else {
				if (mantissa_first_bit == 0) {
					return SignalingNaN;
				} else {
					return QuietNaN;
				}
			}
		} else {
			if (sign == 0) {
				return PlusRegular;
			} else if (sign == 1) {
				return MinusRegular;
			}
		}
	}
	return 0;
}
