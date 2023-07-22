583 - Prime Factors   
http://maplewing.blogspot.tw/2011/02/uva583prime-factors.html



#include<stdio.h>
#include<math.h>
#define ERROR 0.00000001
int g,np[100005]{ 1,1 };
int main() {
	for (int i = 2; i <= 100000; i++)
		if (!np[i])
			for (int j = i + i; j <= 100000; j+=i)
				np[j] = 1;
	while (scanf("%d", &g), g) {
		printf("%d =", g);
		if (g < 0)
			printf(" -1 x"), g = -g;
		int sg = ((int)sqrt((double)g) + ERROR);
		int x = 0;
		for (int i = 2; i <= sg; i++) 
			if(!np[i])
				//g mod i =0
				while (!(g%i)) {
					g /= i;
					if (x)
						printf(" x");
					x = 1;
					printf(" %d", i);
				}
		if (g > 1) {
			if (x)
				printf(" x");
			printf(" %d", g);
		}
		puts("");
	}
	return 0;
}



Webster defines prime as:
prime (prim) n. [ME, fr. MF, fem. of prin first, L primus; akin to L 
prior] 1: first in time: original 2 a: having no factor except itself 
and one ⟨3 is a  number⟩ b : having no common factor except one ⟨12 
and 25 are relatively ⟩ 3 a: first in rank, authority or
significance: principal b: having the highest quality or value ⟨ 
television time ⟩ [from Webster’s New Collegiate Dictionary]
The most relevant definition for this problem is 2a: An integer g > 1 is 
said to be prime if and only if its only positive divisors are itself 
and one (otherwise it is said to be composite). For example, 
the number 21 is composite; the number 23 is prime. 
Note that the decompositon of a positive number g into its prime factors,
i.e., g = f1  f2      fn
is unique if we assert that fi > 1 for all i and fi  fj for i < j.
One interesting class of prime numbers are the so-called Mersenne primes 
which are of the form 2p 􀀀 1. 
Euler proved that 231 􀀀 1 is prime in 1772 — all without the aid of a 
computer.



Input
The input will consist of a sequence of numbers. Each line of input will 
contain one number g in the range 􀀀231 < g < 231, but different of -1 
and 1. The end of input will be indicated by an input line having a 
value of zero.

Output
For each line of input, your program should print a line of output 
consisting of the input number and its prime factors. 
For an input number g > 0, g = f1  f2      fn, 
where each fi is a prime number greater than unity 
(with fi  fj for i < j), the format of the output line should be
g = f1 x f2 x : : : x fn
When g < 0, if j g j= f1  f2      fn, 
the format of the output line should be g = -1 x f1 x f2 x : : : x fn



Sample Input
-190
-191
-192
-193
-194
195
196
197
198
199
200
0

Sample Output
-190 = -1 x 2 x 5 x 19
-191 = -1 x 191
-192 = -1 x 2 x 2 x 2 x 2 x 2 x 2 x 3
-193 = -1 x 193
-194 = -1 x 2 x 97
195 = 3 x 5 x 13
196 = 2 x 2 x 7 x 7
197 = 197
198 = 2 x 3 x 3 x 11
199 = 199
200 = 2 x 2 x 2 x 5 x 5