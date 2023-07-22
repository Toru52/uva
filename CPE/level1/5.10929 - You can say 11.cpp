10929 - You can say 11

No.10929
#include <stdio.h>
#include <string.h>

int main() {
	char s[1001];

	while (scanf("%s", s) == 1) {

		if (strcmp(s, "0") == 0)
			break;
		int i, l = strlen(s), sum = 0;
		for (i = l - 1; i >= 0; i -= 2)
			sum += s[i] - '0';
		for (i = l - 2; i >= 0; i -= 2)
			sum -= s[i] - '0';
		printf("%s ", s);
		if (sum % 11 == 0)
			puts("is a multiple of 11.");
		else
			puts("is not a multiple of 11.");
	}
	return 0;
}





 Your job is, given a positive number N, determine 
if it is a multiple of eleven.

Input
 The input is a file such that each line contains 
a positive number. A line containing the number ‘0’ is 
the end of the input. The given numbers can contain up 
to 1000 digits.

Output
 The output of the program shall indicate, for each input number,
if it is a multiple of eleven or not.

Sample Input
112233
30800
2937
323455693
5038297
112234
0

Sample Output
112233 is a multiple of 11.
30800 is a multiple of 11.
2937 is a multiple of 11.
323455693 is a multiple of 11