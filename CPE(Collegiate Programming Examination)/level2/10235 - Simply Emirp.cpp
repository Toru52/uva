10235 - Simply Emirp
http://maplewing.blogspot.tw/2011/02/uva10235simply-emirp.html



#include<stdio.h>

int prime[1000005] = { 1, 1, 0 };

int main()
{
	int i, j;
	for (i = 2; i <= 1000000; i++)
		if (!prime[i])
			for (j = i + i; j <= 1000000; j += i)
				prime[j] = 1;

	int N;
	while (scanf("%d", &N) != EOF)
	{
		int N_origin = N;
		int N_reverse = 0;
		while (N)
		{
			N_reverse *= 10;
			N_reverse += N % 10;
			N /= 10;
		}
		if (prime[N_origin])
			printf("%d is not prime.\n", N_origin);
		else if (prime[N_reverse] || N_origin == N_reverse)
			printf("%d is prime.\n", N_origin);
		else
			printf("%d is emirp.\n", N_origin);
	}

	return 0;
}



#include<stdio.h>
int prime[1000005] = { 1,1,0 };
int main() {
	for (int i = 2; i <= 1000000; i++)
		if (!prime[i])
			for (int j = i + i; j <= 1000000; j += i)
				prime[j] = 1;
	int n;
	while (~scanf("%d", &n)) {
		int rn = 0, on = n;
		while (n) {
			rn *= 10;
			rn += n % 10;
			n /= 10;
		}
		if (prime[on])
			printf("%d is not prime.\n", on);
		else if (rn == on || prime[rn])
			printf("%d is prime.\n", on);
		else
			printf("%d is emirp.\n", on);
	}
	return 0;
}



An integer greater than 1 is called a prime number 
if its only positive divisors (factors) are 1 and itself.
Prime numbers have been studied over the years by a lot 
of mathematicians. 
Applications of prime numbers arise in Cryptography and
Coding Theory among others. Have you tried reversing a 
prime? For most primes, you get a composite 
(43 becomes 34).
An Emirp (Prime spelt backwards) is a Prime that gives 
you a different Prime when its digits are reversed.
For example, 17 is
Emirp
because 17 as well as 71 are Prime.
In this problem, you have to decide whether a number
N
is Non-prime or Prime or
Emirp
. Assume
that 1
<N<
1000000.
Interestingly, Emirps are not new to NTU students. 
We have been boarding 199 and 179 buses for
quite a long time!



Input
Input consists of several lines specifying values for N.

Output
For each N given in the input, 
output should contain one of the following:
1.`N is not prime.
', if N is not a Prime number.
2.
`
N
is prime.
', if
N
is Prime and
N
is not
Emirp
.
3.
`
N
is emirp.
', if
N
is
Emirp
.



SampleInput
17
18
19
179
199

SampleOutput
17 is emirp.
18 is not prime.
19 is prime.
179 is emirp.
199 is emirp.