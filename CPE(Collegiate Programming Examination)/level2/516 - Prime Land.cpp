516 - Prime Land



#include<stdio.h>
#include<math.h>
#define ERROR 0.00000001

int main()
{
	int p, e;
	//a prime base number system(positive integer x ->prime number)
	while ((scanf("%d", &p) != EOF) && p != 0)
	{
		scanf("%d", &e);
		int product = 1;
		product *= (int)(pow((double)p, (double)e) + ERROR);

		while (getchar() == ' ')
		{
			scanf("%d", &p);
			scanf("%d", &e);
			product *= (int)(pow((double)p, (double)e) + ERROR);
		}
		product -= 1;

		int output[50000] = { 0 };
		int i;
		int sqrt_num = (int)sqrt((double)product);
		int max_prime = 0;
		for (i = 2; i <= sqrt_num; i++)
		{
			while (!(product % i))
			{
				product /= i;
				output[i]++;
				max_prime = (max_prime < i) ? i : max_prime;
			}
		}

		int print = 0;
		if (product > 1)
		{
			print = 1;
			printf("%d %d", product, 1);
		}
		for (; max_prime >= 2; max_prime--)
		{
			if (output[max_prime])
			{
				if (print)
					printf(" ");
				print = 1;
				printf("%d %d", max_prime, output[max_prime]);
			}
		}
		printf("\n");
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
#define ERROR 0.1
int main() {
	int p, e;
	while (scanf("%d", &p) && p) {
		scanf("%d", &e);
		int product = (int)(pow((double)p, (double)e) + ERROR);
		while (getchar() == ' ') {
			scanf("%d %d", &p, &e);
			product *= (int)(pow((double)p, (double)e) + ERROR);
		}
		product -= 1;
		int F = 0, max_prime = 0, E[50000] = {};
		int sqr = (int)sqrt((double)product);
		for (int i = 2; i <= sqr; i++) {
			while (!(product%i)) {
				product /= i;
				E[i]++;
				max_prime = (i > max_prime) ? i : max_prime;
			}
		}
		if (product > 1) {
			F = 1;
			printf("%d %d", product, 1);
		}
		for (; max_prime >= 2; max_prime--) {
			if (E[max_prime]) {
				if (F)
					printf(" ");
				F = 1;
				printf("%d %d", max_prime, E[max_prime]);
			}
		}
		puts("");
	}
}



Everybody in the Prime Land is using a prime base number system.
In this system, each positive integer x is represented as 
follows: Let {pi}∞ i=0 denote the increasing sequence of all 
prime numbers. We know that x > 1 can be represented in only 
one way in the form of product of powers of prime factors. 
This implies that there is an integer kx and uniquely
determined integers ekx 
, ekx−1, . . . , e1, e0,
(ekx > 0), that x = p
ekx
kx
· p
ekx−1
kx−1
· · · · · p
e1
1
· p
e0
0
. The sequence
(ekx
, ekx−1, . . . , e1, e0)
is considered to be the representation of x in prime base 
number system. It is really true that all numerical 
calculations in prime base number system can seem to us a 
little bit unusual, or even hard. In fact, the children in 
Prime Land learn to add to subtract numbers several years. 
On the other hand, multiplication and division is very simple.
Recently, somebody has returned from a holiday in the Computer 
Land where small smart things called computers have been used. 
It has turned out that they could be used to make addition and
subtraction in prime base number system much easier. 
It has been decided to make an experiment and
let a computer to do the operation “minus one”.
Help people in the Prime Land and write a corresponding program.
For practical reasons we will write here the prime base 
representation as a sequence of such pi and ei from the prime 
base representation above for which ei > 0. We will keep 
decreasing order with regard to pi.



Input
The input file consists of lines (at least one) each of which 
except the last contains prime base representation of just one 
positive integer greater than 2 and less or equal 32767. 
All numbers in the line are separated by one space. 
The last line contains number ‘0’.

Output
The output file contains one line for each but the last line of 
the input file. If x is a positive integer contained in a line 
of the input file, the line in the output file will contain 
x − 1 in prime base representation. All numbers in the line are 
separated by one space. There is no line in the output file
corresponding to the last “null” line of the input file.



Sample Input
17 1        //17^1-1       -> 2^4
5 1 2 1     //5^1*2^1-1    -> 3^2
509 1 59 1  //509^1*59^1-1 -> 13^1*11^1*7^1*5^1*3^1*2^1
0

Sample Output
2 4
3 2
13 1 11 1 7 1 5 1 3 1 2 1