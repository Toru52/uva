10922 - 2 the 9s



no1.
#include <stdio.h>
#include <string.h>

int main() {
	char s[1001];
	while (scanf("%s", s) == 1) {
		if (strcmp(s, "0") == 0)
			break;
		int i, sum = 0;
		for (i = 0; s[i]; i++)
			sum += s[i] - '0';
		printf("%s is ", s);
		if (sum % 9 != 0)
			puts("not a multiple of 9.");
		else {
			int degree = 1;
			while (sum >= 10) {
				sprintf(s, "%d", sum);
				sum = 0;
				for (i = 0; s[i]; i++)
					sum += s[i] - '0';
				degree++;
			}
			printf("a multiple of 9 and has 9-degree %d.\n", degree);
		}
	}
	return 0;
}



no2.
#include<stdio.h>
#include<string.h>
int main()
{
	char s[1001];
	while (scanf("%s", s) == 1)
	{
		int sum = 0,degree=1;
		if (strcmp(s, "0") == 0)
			break;
		for (int i = 0; s[i]; i++)
			sum += s[i]-'0';
		printf("%s is ", s);
		if (sum % 9 != 0)
			printf("not a multiple of 9.\n");
		else
		{
			while (sum >= 10)
			{
				sprintf(s, "%d", sum);
				sum = 0;
				for (int i = 0; s[i]; i++)
					sum += s[i] - '0';
				degree++;
			}
			printf("a multiple of 9 and has 9-degree %d.\n", degree);
		}
	}
}
/*
Algorithm
	各位の数字の和が 9で割り切れれば、その数字は 9の倍数である
	If the sum of partof number can divide by 9,
	Then the number is multiple of 9.
*/



A well-known trick to know if an integer N is a multiple of 
nine is to compute the sum S of its digits.
If S is a multiple of nine, then so is N. 
This is a recursive test, and the depth of the recursion 
needed to obtain the answer on N is called the 9-degree of N.
Your job is, given a positive number N, determine 
if it is a multiple of nine and, if it is, its 9-degree.



Input
The input is a file such that each line contains a positive 
number. A line containing the number 0 is the end of the input.
The given numbers can contain up to 1000 digits.

Output
The output of the program shall indicate, for each input 
number, if it is a multiple of nine, and in case it is, 
the value of its nine-degree.See the sample output for an 
example of the expected formatting of the output.

9 9999 9999 9999 9999 9999

Sample Input
999999999999999999999
9
9999999999999999999999999999998
0

Sample Output
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.