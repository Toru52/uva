22.11461 - Square Numbers


no1
#include <cstdio>

int main() {
	int squares[1000];
	int a, b;

	for (int i = 0; i * i <= 100000; i++) 
		squares[i] = i * i;
	
	while (scanf("%d %d", &a, &b)) {
		if (a == 0 && b == 0)
			break;
		int count = 0;
		for (int i = 1; i < 1000; i++) {
			if (b < squares[i])
				break;
			if (a <= squares[i]) 
				count++;
		}
		printf("%d\n", count);
	}
}


no2
#include<cstdio>

int main()
{
	long long  from, to;

	while (~scanf("%lld%lld", &from, &to) && (from || to))
	{
		int cnt = 0;
		for (long long i = 1; i <= to; i++)
			if (from<=i*i&&i*i <= to)
				cnt++;
		printf("%d\n", cnt);
	}
}


A square number is an integer number whose square root is also an 
integer. For example 1, 4, 81 are some square numbers. 
Given two numbers a and b you will have to find out how many
square numbers are there between a and b (inclusive).

Input
The input file contains at most 201 lines of inputs. Each line contains 
two integers a and b (0 < a ≤b ≤ 100000). 
Input is terminated by a line containing two zeroes. 
This line should not be processed.

Output
For each line of input produce one line of output. 
This line contains an integer which denotes how many square numbers 
are there between a and b (inclusive).



Sample Input
1 4
1 10
0 0

1 4
1 10
1 100000
0 0

Sample Output
2
3

2
3
316

1-99855
1-46300