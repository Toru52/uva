19.10783	Odd Sum



no1.
#include <stdio.h>

int main(int argc, char *argv[]) {
	int T;
	scanf("%d", &T);
	int index;
	for (index = 1; index <= T; index++) {
		int A, B;
		scanf("%d%d", &A, &B);
		int sum = 0, i;
		for (i = A; i <= B; i++) {
			if (i % 2 == 1)   
				sum += i;
		}
		printf("Case %d: %d\n", index, sum);
	}
	return 0;
}


no2.
#include<cstdio>

int main()
{
	int cas,from,to;
	scanf("%d", &cas);
	for (int i = 1; i <= cas; i++)
	{
		int sum = 0;
		scanf("%d%d", &from, &to);
		if (from % 2 == 0)
			from++;
		while (from <= to)
		{
			sum += from;
			from += 2;
		}
		printf("Case %d: %d\n", i, sum);
	}
}



Given a range [a, b], you are to find the summation of all the odd 
integers in this range. 
For example,
the summation of all the odd integers in the range [3, 9] is 
3 + 5 + 7 + 9 = 24.



Input
There can be at multiple test cases. The first line of input gives 
you the number of test cases, T(1 ≤ T ≤ 100). Then T test cases 
follow. Each test case consists of 2 integers a and 
b (0 ≤ a ≤ b ≤ 100) in two separate lines.

Output
For each test case you are to print one line of output – 
the serial number of the test case followed by the summation of 
the odd integers in the range [a, b].



Sample Input
2
1
5
3
5

Sample Output
Case 1: 9
Case 2: 8