11185	Ternary



no1
#include<stdio.h>

void Base3(int n) {
	if (n == 0)   
		return;
	Base3(n / 3);
	printf("%d", n % 3);
}
int main() {
	int n;
	while (scanf("%d", &n) == 1 && n >= 0) {
		if (n == 0) { puts("0"); continue; }
		Base3(n);
		puts("");
	}
}



no2
#include<stdio.h>

void Base3(int n)
{
	if (n == 0)
		return;
	Base3(n / 3);
	printf("%d", n % 3);
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n >= 0)
	{
		if (n == 0) { puts("0"); continue; }
		Base3(n);
		puts("");
	}
}

You will be given a decimal number. You will have to 
convert it to its ternary (Base 3) equivalent.



Input
The input file contains at most 100 lines of inputs. 
Each line contains a non-negative decimal integer
N (N < 1000000001). Input is terminated by a line 
containing a negative value. This line should not
be processed.

Output
For each line of input produce one line of output. 
This line contains the ternary equivalent of decimal
value N.



Sample Input
10
100
1000
-1

Sample Output
101
10201
1101001