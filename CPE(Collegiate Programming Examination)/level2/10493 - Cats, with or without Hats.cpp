10493 - Cats, with or without Hats
http://mypaper.pchome.com.tw/zerojudge/post/1324680464



#include <stdio.h>

int main() {
	long long n, m;
	while (scanf("%lld %lld", &n, &m) == 2) {
		if (n == 0)  break;
		printf("%lld %lld ", n, m);
		if (n == 1 && m == 1)
			puts("Multiple");
		else if (n == 1 || (n*m - 1) % (n - 1))
			puts("Impossible");
		else
			printf("%lld\n", (n*m - 1) / (n - 1));
	}
	return 0;
}



#include<stdio.h>
int main() {
	long long n, m;
	while (scanf("%lld %lld", &n, &m), n != 0) {
		printf("%lld %lld ", n, m);
		if (n == 1 && m == 1)
			puts("Multiple");
		else if ((n==1)||(m*n - 1) % (n - 1))
			puts("Impossible");
		else if ((m*n - 1) / (n - 1))
			printf("%lld\n", (m*n - 1) / (n - 1));
	}
	return 0;
}



A cat wears a hat if and only if it has
N
cats in its hat.
There is exactly one cat that is not inside any other cat's hat.
If there are
M
cats without hats, how many cats are there?



Input
Input consists of several test cases. For each case, there would
be two integers,
N
and
M
, where 1

N<
100000 and 1

M<
100000. The input ends with a case where
N
= 0. You
must not process this test case.

Output
For each test case, print
N
and
M
. Then if the total number
of cats can be expressible uniquely in an integer, print the
number. If the case is impossible print the word `
Impossible
'
without quotes. If there are multiple answers, print the word
`
Multiple
' without the quotes.



SampleInput
2 5
3 4
3 3
0 0

SampleOutput
2 5 9
3 4 Impossible
3 3 4