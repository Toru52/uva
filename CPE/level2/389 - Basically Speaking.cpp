389 - Basically Speaking



#include <stdio.h>
#include <string.h>
int main() {
	char s[50];
	int n, m;
	while (scanf("%s %d %d", s, &n, &m) == 3) {
		int i, l = strlen(s);
		long long dec = 0, j = 1;
		for (i = l - 1; i >= 0; i--) {
			if (s[i] <= '9')
				dec += (s[i] - '0')*j;
			else
				dec += (s[i] - 'A' + 10)*j;
			j *= n;
		}
		int ans[60] = {}, idx = -1;
		while (dec > 0)
			ans[++idx] = dec%m, dec /= m;
		if (idx >= 7) {
			puts("  ERROR");
			continue;
		}
		if (idx < 0) idx = 0;
		for (i = 6; i > idx; i--)
			printf(" ");
		for (i = idx; i >= 0; i--)
			printf("%c", ans[i] < 10 ? ans[i] + '0' : ans[i] + 'A' - 10);
		puts("");
	}
	return 0;
}



#include<cstdio>
#include<string.h>

int main() {
	int base1, base2;
	char s[50];
	while (scanf("%s %d %d", s, &base1, &base2)==3) {
		long long temp = 1, dec = 0;
		for (int i = strlen(s) - 1; i >= 0; i--) {
			if (s[i] <= '9')
				dec += (s[i] - '0')*temp;
			else
				dec += (s[i] - 'A' + 10)*temp;
			temp *= base1;
		}
		int conv[60] = {}, digit = -1;
		while (dec > 0)
			conv[++digit] = dec%base2, dec /= base2;
		if (digit >= 7) {
			printf("  ERROR\n");
			continue;
		}
		if (digit < 0)
			digit = 0;
		for (int i = 6; i > digit; i--)
			printf(" ");
		for (int i = digit; i >= 0; i--)
			printf("%c", conv[i] < 10 ? conv[i] + '0' : conv[i] + 'A' - 10);
		puts("");
	}
}


The Really Neato Calculator Company, Inc. has recently hired your 
team to help design their Super Neato Model I calculator. 
As a computer scientist you suggested to the company that it would 
be neato if this new calculator could convert among number bases. 
The company thought this was a stupendous idea and has asked your 
team to come up with the prototype program for doing base 
conversion. The project manager of the Super Neato Model I 
calculator has informed you that the calculator will have
the following neato features:
• It will have a 7-digit display.
• Its buttons will include the capital letters A through F 
  in addition to the digits 0 through 9.
• It will support bases 2 through 16.



Input
The input for your prototype program will consist of one base 
conversion per line. There will be three numbers per line. 
The first number will be the number in the base you are 
converting from. It may have leading ‘0’s. The second number is 
the base you are converting from. The third number is the base 
you are converting to. There will be one or more blanks 
surrounding (on either side of) the numbers. There are several 
lines of input and your program should continue to read until the 
end of file is reached.

Output
The output will only be the converted number as it would appear on 
the display of the calculator. The number should be right 
justified in the 7-digit display. If the number is to large to 
appear on the display, then print ‘ERROR’ (without the quotes) 
right justified in the display.



Sample Input
1111000 2 10
1111000 2 16
2102101 3 10
2102101 3 15
12312 4 2
1A 15 2
ABCD 16 15
03 13 10

Sample Output
120
78
1765
7CA
ERROR
11001
D071
3