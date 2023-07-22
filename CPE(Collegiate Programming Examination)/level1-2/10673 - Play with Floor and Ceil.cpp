10673 - Play with Floor and Ceil



#include <iostream>
#include <cstdio>
#include <cmath>

int main()
{
	int t;
	long long int x, k, a, b, p, q;
	while (scanf("%d", &t) == 1) {
		while (t--) {
			scanf("%lld%lld", &x, &k);
			a = floor((double)x / k);
			b = ceil((double)x / k);
			for (p = 0; p*a <= x; p++)
				if ((x - p*a) % b == 0) {
					q = (x - p*a) / b;  
					break; 
					}
			printf("%lld %lld\n", p, q);
		}
	}
	return 0;
}



#include<cstdio>
#include<math.h>

int main()
{
	long long int n, x, k, p, q, a, b;

	scanf("%d", &n);
	while (n--)
	{
		scanf("%lld %lld", &x, &k);
		a = floor((double)x / k);
		b = ceil((double)x / k);
		for(p=0;p*a<=x;++p)
			if ((x - p*a) % b == 0)
			{
				q = (x - p*a) / b;
				break;
			}
		printf("%lld %lld\n", p, q);
	}
}

Theorem
For any two integers x and k there exists two more integers 
p and q 
It’s a fairly easy task to prove this theorem, so we’d not 
ask you to do that. We’d ask for something even easier! 
Given the values of x and k, you’d only need to find 
integers p and q that satisfies the given equation.



Input
The first line of the input contains an integer, 
T (1 ≤ T ≤ 1000) that gives you the number of test
cases. In each of the following T lines youd be given 
two positive integers x and k. You can safely
assume that x and k will always be less than 108.

Output
For each of the test cases print two integers: p and q in 
one line. These two integers are to be separated
by a single space. If there are multiple pairs of p and q 
that satisfy the equation, any one would do.
But to help us keep our task simple, please make sure that 
the values,
fit in a 64 bit signe



Sample Input
3
5 2
40 2
24444 6

Sample Output
1 1
1 1 (or 0 2)
0 6