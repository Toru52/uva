543	Goldbach's Conjecture



#include<stdio.h>
int prime[1000005] = { 1, 0, 0 };

int main()
{
	int i, j;
	for (i = 2; i <= 1000000; i++)
		if (!prime[i])
			for (j = i + i; j <= 1000000; j += i)
				prime[j] = 1;
	int n;
	while (scanf("%d", &n) != EOF && n != 0)
	{
		int print = 0;
		for (i = 2; i <= n; i++)
			if (!prime[i] && !prime[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				print = 1;
				break;
			}
		if (!print)
			printf("Goldbach's conjecture is wrong.\n");
	}
}



#include<stdio.h>
int Nprime[1000001] = {};

int main() {
	int n;
	for (int i = 2; i <= 1000000; i++)
		if (!Nprime[i])
			for (int j = 2 * i; j <= 1000000; j+=i)
				Nprime[j] = 1;
	while (scanf("%d",&n) && n) {
		int F = 0;
		for(int i=2;i<=n;i++)
			if (!Nprime[i] && !Nprime[n-i]) {
				printf("%d = %d + %d\n", n, i, n - i);
				F = 1;
				break;
			}
		if (!F)
			puts("Goldbach's conjecture is wrong.");
	}
}



In 1742, Christian Goldbach, a German amateur mathematician, 
sent a letter to Leonhard Euler in which he made the following 
conjecture: Every number greater than 2 can be written as the sum 
of three prime numbers. Goldbach was considering 1 as a primer 
number, a convention that is no longer followed. Later on, Euler 
re-expressed the conjecture as: Every even number greater than or 
equal to 4 can be expressed as the sum of two prime numbers.



For example:
• 8 = 3 + 5. Both 3 and 5 are odd prime numbers.
• 20 = 3 + 17 = 7 + 13.
• 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23.
Today it is still unproven whether the conjecture is right. 
(Oh wait, I have the proof of course, but it is too long to write 
it on the margin of this page.) Anyway, your task is now to verify 
Goldbach’s conjecture as expressed by Euler for all even numbers
less than a million.



Input
The input file will contain one or more test cases.
Each test case consists of one even integer n with 6 ≤ n < 1000000.
Input will be terminated by a value of 0 for n.

Output
For each test case, print one line of the form n = a + b, where a 
and b are odd primes. Numbers and operators should be separated by 
exactly one blank like in the sample output below. If there is more
than one pair of odd primes adding up to n, choose the pair where 
the difference b − a is maximized. If there is no such pair, print 
a line saying ‘Goldbach's conjecture is wrong.’



Sample Input
8
20
42
0

Sample Output
8 = 3 + 5
20 = 3 + 17
42 = 5 + 37