406－Prime Cuts



#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	bool composite[1005] = { true, false };
	int prime_count[1005] = { 0,1 };
	int count = 1, N, C, start, end, prime_i;
	for (int i = 2; i <= 1000; i++) {
		if (!composite[i]) {
			for (int j = i + i; j <= 1000; j += i)
				composite[j] = 1;
			count++;// count the prime number ex 7 ->3(2 3 7)
		}
		prime_count[i] = count;
	}

	while (scanf("%d%d", &N, &C) != EOF) {
		start = prime_count[N] / 2 - C + 2;
		end = prime_count[N] / 2 + C;
		if (!(prime_count[N] % 2)) start--;
		if (start < 1) start = 1;
		if (end > prime_count[N]) end = prime_count[N];

		printf("%d %d:", N, C);
		for (prime_i = 1; prime_count[prime_i] < end; prime_i++) {
			if (!composite[prime_i])
				if (prime_count[prime_i] < end && prime_count[prime_i] >= start)
					printf(" %d", prime_i);
		}
		printf(" %d\n\n", prime_i);
	}
	return 0;
}



#include<cstdio>

int main() {
	bool composite[1005] = { true, false };
	int pcn[1005] = { 0,1 };
	int count = 1, N, C, s, end,i;
	for (int i = 2; i <= 1000; i++) {
		if (!composite[i]) {
			for (int j = i + i; j <= 1000; j += i)
				composite[j] = 1;
			count++;
		}
		pcn[i] = count;
	}

	while (scanf("%d%d", &N, &C) != EOF) {
		s = pcn[N] / 2 - C + 2;
		end = pcn[N] / 2 + C;
		if (!(pcn[N] % 2)) s--;
		if (s < 1) s = 1;
		if (end > pcn[N]) end = pcn[N];

		printf("%d %d:", N, C);
		for (i = 1; pcn[i] < end; i++) {
			if (!composite[i])
				if (pcn[i] < end && pcn[i] >= s)
					printf(" %d", i);
		}
		printf(" %d\n\n", i);
	}
}



//    if the length of the list is even
//   ex 21 2 -> since 21 is odd, 2C-1 ->2*2-1=3 
//      ->The length of list is 3

A prime number is a counting number (1, 2, 3, . . .) that is 
evenly divisible only by 1 and itself. In this problem you are 
to write a program that will cut some number of prime numbers 
from the list of prime numbers between (and including) 1 and N.
 Your program will read in a number N; determine the list
of prime numbers between 1 and N; and print the 2C prime 
numbers from the center of the list if there
are an even number of prime numbers or 2C − 1 prime numbers 
from the center of the list if there are
an odd number of prime numbers in the list.



Input
Each input set will be on a line by itself and will consist 
of 2 numbers. The first number (1 ≤ N ≤ 1000)
is the maximum number in the complete list of prime numbers 
between 1 and N. The second number (1 ≤ C ≤ N) defines the 
2C prime numbers to be printed from the center of the list 
if the length of the list is even; 
or the 2C − 1 numbers to be printed from the center of the 
list if the length of the list is odd.

Output
For each input set, you should print the number N beginning 
in column 1 followed by a space, then by the number C, 
then by a colon (:), and then by the center numbers from the 
list of prime numbers as defined above. If the size of the 
center list exceeds the limits of the list of prime numbers 
between 1 and N, the list of prime numbers 
between 1 and N (inclusive) should be printed. 
Each number from the center of the list should be preceded 
by exactly one blank. Each line of output should be followed
by a blank line. Hence, your output should follow the exact 
format shown in the sample output.



Sample Input
21 2
18 2
18 18
100 7
Sample Output
21 2: 5 7 11
18 2: 3 5 7 11
18 18: 1 2 3 5 7 11 13 17
100 7: 13 17 19 23 29 31 37 41 43 47 53 59 61 67


