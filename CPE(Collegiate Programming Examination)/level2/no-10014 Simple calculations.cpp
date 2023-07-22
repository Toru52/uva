10014 Simple calculations.cpp



#include <cstdio>  

int main()
{
	double a[3003] = {},c[3003] = {};
	int t, n;

	while (~scanf("%d", &t))
		while (t--) {
			scanf("%d", &n);
			scanf("%lf%lf", &a[0], &a[n + 1]);
			for (int i = 1; i <= n; ++i)
				scanf("%lf", &c[i]);

			double sum1 = 0.0;
			for (int i = 1; i <= n; ++i)
				sum1 += c[i] * (n + 1 - i);
			a[1] = (a[0] * n + a[n + 1] - 2.0*sum1) / (1.0 + n);

			printf("%.2lf\n", a[1]);
			if (t) puts("");
		}
	return 0;
}



refer for math
http://blog.csdn.net/mobius_strip/article/details/50834400


There is a sequence of n + 2 elements a0, a1, . . . , an+1 
(n ≤ 3000; −1000 ≤ ai ≤ 1000). It is known that
ai =(ai−1 + ai+1)/2 − ci
for each i = 1, 2, . . . , n. You are given a0, an+1, c1, . . . , cn. 
Write a program which calculates a1.



Input
The first line is the number of test cases, followed by a blank line.
For each test case, the first line of the input contains an integer n. 
The next two lines consist of
numbers a0 and an+1 each having two digits after decimal point, 
and the next n lines contain numbers
ci (also with two digits after decimal point), one number per line.
Each test case will be separated by a single line.

Output
For each test case, the output should contain a1 in the same format as 
a0 and an+1. Print a blank line between the outputs for two 
consecutive test cases.



Sample Input
1
1
50.50
25.50
10.15

Sample Output
27.85


