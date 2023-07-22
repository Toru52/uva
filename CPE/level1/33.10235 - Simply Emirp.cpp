10235 - Simply Emirp



#include<stdio.h>
#include<math.h>

int main()
{
	int n, root, rn, mod;
	long int i;
	while (scanf("%d", &n) == 1) {

		root = ceil(sqrt(n));
		mod = 1;

		for (i = 2; i <= root; i++)
			if (n%i == 0) { mod = 0; break; }

		if (mod == 0)
			printf("%d is not prime.\n", n);

		else {
			rn = 0;
			for (i = n; i != 0; i = i / 10)
				rn = rn * 10 + i % 10;

			root = ceil(sqrt(rn));
			mod = 1;

			for (i = 2; i <= root; i++)
				if (rn%i == 0) { mod = 0; break; }

			if (mod == 1 && n != rn)
				printf("%d is emirp.\n", n);
			else
				printf("%d is prime.\n", n);
		}
	}
	return 0;
}



/*Algorithm.Sieve of Eratosthenes

root = ceil(sqrt(n));
mod = 1;
for (i = 2; i <= root; i++)
if (n%i == 0) { mod = 0; break; }


Convert number
		for (i = n; i != 0; i = i / 10)
				rn = rn * 10 + i % 10;
*/



no2.
#include<stdio.h>
#include<math.h>

int main()
{
	int n,root;
	while (~scanf("%d", &n))
	{
		int mod = 1;
		root = ceil(sqrt(n));

		for (int i = 2; i <= root; i++)
			if (n%i == 0) { mod = 0; break; }
		
		if (mod == 0)
			printf("%d is not prime.\n", n);
		else
		{
			int rn = 0;
			for (int i = n; i != 0; i /= 10)
				rn =rn* 10 + i % 10;
			root = ceil(sqrt(rn));
			for (int i = 2; i <= root; i++)
				if (rn%i == 0) { mod = 0; break; }
			if (mod != 0 && rn != n)
				printf("%d is emirp.\n", n);
			else
				printf("%d is prime.\n", n);
		}	
	}
}






An integer greater than 1 is called a prime number if its only 
positive divisors (factors) are 1 and itself.
Prime numbers have been studied over the years by a lot of 
mathematicians. Applications of prime
numbers arise in Cryptography and Coding Theory among others.
Have you tried reversing a prime? For most primes, you get a 
composite (43 becomes 34). An Emirp (Prime spelt backwards) is 
a Prime that gives you a different Prime when its digits are 
reversed.
For example, 17 is Emirp because 17 as well as 71 are Prime.
In this problem, you have to decide whether a number N is 
Non-prime or Prime or Emirp. Assume that 1 < N < 1000000.
Interestingly, Emirps are not new to NTU students. 
We have been boarding 199 and 179 buses for quite a long time!



Input
Input consists of several lines specifying values for N.
Output
For each N given in the input, output should contain one of the 
following:
1. ‘N is not prime.’, if N is not a Prime number.
2. ‘N is prime.’, if N is Prime and N is not Emirp.
3. ‘N is emirp.’, if N is Emirp.



Sample Input
17
18
19
179
199

Sample Output
17 is emirp.
18 is not prime.
19 is prime.
179 is emirp.
199 is emirp.