10916 - Factstone Benchmark
https://github.com/morris821028/UVa/blob/master/volume109/10916%20-%20Factstone%20Benchmark.cpp
concept
http://examist.jp/mathematics/integer/kaijyou-soinsu/


#include <stdio.h>
#include <math.h>
int main() {
	int n, i;
	while (scanf("%d", &n),n) {
		n = (n - 1960) / 10 + 2;
		double m = 1 << n;
		printf("m %f\n\n", m);
		for (i = 1; m > 0; i++)
			m -= log10(i) / log10(2),printf("log10(%d)/log10(2) %lf\n",i, log10(i) / log10(2));
		printf("%d\n", i - 2);
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	int i, n;
	while (scanf("%d", &n), n) {
		n = (n-1960) / 10 + 2;
		double m = 1<<n;
		for (i = 1; m > 0; i++)
			m -= log10(i) / log10(2);
		printf("%d\n", i - 2);
	}
	return 0;
}
/*
4 1960
8 1970
16 1980
32 1990
64 2000
128 2010
256 2020

ex
1981
->16
->2^16(65536)>n!
->n=8(40320)

1960
->4
->2^4>n!
->n=3

1970
->8
->2^8(256)>n!
->n=5(120)
*/

Amtel has announced that it will release a 128-bit computer
chip by 2010, a 256-bit computer by 2020, and so on, con-
tinuing its strategy of doubling the word-size every ten years.
(Amtel released a 64-bit computer in 2000, a 32-bit computer
in 1990, a 16-bit computer in 1980, an 8-bit computer in 1970,
and a 4-bit computer, its rst, in 1960.)
Amtel will use a new benchmark { the Factstone { to ad-
vertise the vastly improved capacity of its new chips. The
Factstone rating is dened to be the largest integer n such
that n! can be represented as an unsigned integer in a com-
puter word.
Given a year 1960  y  2160, what will be the Factstone
rating of Amtel's most recently released chip?
Input
There are several test cases. For each test case, there is one line 
of input containing y. A line containing
`0' follows the last test case.
Output
For each test case, output a line giving the Factstone rating.



Sample Input
1960
1981
0

Sample Output
3
8