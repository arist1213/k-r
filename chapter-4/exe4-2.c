#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char s[]);

int main() {
	char *test_data[] = {
		"1.091313",
		"123.123",
		"1234.1234",
		"12345.12345",
		"901311.091313",
		"1213.80918231",
		"0.90291031",
		"123.45e-4",
		"1.0E-6",
		"1.35E+6",
		"1.1E-6",
		"-1.35E+6",
	};
	size_t i;
	for (i = 0; i < (sizeof test_data/ sizeof test_data[0]); i++)
		printf("%12s\t%g\n", test_data[i], atof(test_data[i]));

	return 0;
}

/* atof: convert string s to string, enhanced version to parse science notation */
double atof(char s[]) {
	double val, power;
	int i, sign, sign_nota, k;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i]=='-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power=1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if (s[i] == 'e' || s[i] == 'E') {		
		i++;
		sign_nota = (s[i] == '+') ? 1 : -1;
		if (s[i]=='+'||s[i]=='-')
			i++;
		/* 科学计数位数 */
		for (k = 0; isdigit(s[i]); i++)
			k = 10 * k + (s[i] - '0');

		if (sign_nota > 0) {
			return  (pow(10, k) * sign * val) / power;
		} else {
			return  (sign * val) / (power * pow(10, k));
		}

	} else {
		return sign * val / power;
	}
}
