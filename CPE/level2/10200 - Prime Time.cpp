10200 - Prime Time
http://blog.csdn.net/trq1995/article/details/45605563



#include <stdio.h>  

int prime(int n){
	for (int i = 2; i*i <= n; i++)
		if ((n%i) == 0)
			return 0;
	return 1;
}

int main(){
	int a,b,sum,num[10010] = {};

	for (int i = 0; i <= 10005; i++)
		num[i] = prime(i*i + i + 41);
	while (scanf("%d%d", &a, &b) != -1){
		sum = 0;
		for (int i = a; i <= b; i++)
			sum += num[i];
		printf("%.2f\n", sum*1.0 / (b - a + 1) * 100);      //一定要加这个1e-8，不然就是判错，我也不知道为什么，有谁知道的话请务必告诉我  
	}
	return 0;
}



Euler is a well-known matematician, and, among many other things,
he discovered that the formula
n2+n+ 41 produces a prime for 0 n<40. For n= 40, 
the formula produces 1681, which is 4141.
Even though this formula doesn't always produce a prime, 
it still produces a lot of primes. It's known
that for n  10000000, there are 47,5% of primes produced by 
the formula!
So, you'll write a program that will output how many primes 
does the formula output for a certain nterval.   


 
Input
Each line of input will be given two positive integer
a
and
b
such that 0

a

b

10000. You must
read until the end of the  le.

Output
For each pair
a
,
b
read, you must output the percentage of prime numbers produced 
by the formula in this interval (anb) rounded to two 
decimal digits.



SampleInput
0 39
0 40
39 40

SampleOutput
100.00
97.56
50.00