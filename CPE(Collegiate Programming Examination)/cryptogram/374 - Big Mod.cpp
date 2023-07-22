374 - Big Mod
https://github.com/esbanarango/Competitive-Programming/blob/master/UVa/374%20-%20Big%20Mod.cpp



#include<stdio.h>
int main() {
	long b, p, m;
	while (scanf("%ld %ld %ld",&b,&p,&m)==3) {
		long r = 1,mask = 1,pow2 = b % m;
		while (mask) {
			if (p & mask)
				r = (r * pow2) % m;
			pow2 = (pow2*pow2) % m;
			mask <<= 1;
		}
		printf("%ld\n", r);
	}
	return 0;
}



Calculate
R := BP mod M
for large values of B, P, and M using an efficient algorithm. 
(That’s right, this problem has a time dependency !!!.)



Input
The input will contain several test cases, each of them as described 
below. Consecutive test cases are separated by a single blank line.
Three integer values (in the order B, P, M) will be read one number 
per line. B and P are integers in the range 0 to 2147483647 inclusive. 
M is an integer in the range 1 to 46340 inclusive.

Output
For each test, the result of the computation. 
A single integer on a line by itself.



Sample Input
3
18132
17
17
1765
3
2374859
3029382
36123
s
Sample Output
13
2
13195