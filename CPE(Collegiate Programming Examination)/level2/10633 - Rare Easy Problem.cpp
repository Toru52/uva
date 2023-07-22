10633 - Rare Easy Problem
https://github.com/morris821028/UVa/blob/master/volume106/10633%20-%20Rare%20Easy%20Problem.cpp



#include <stdio.h>

int main() {
	long long G;
	int i;
	while (scanf("%lld", &G), G) {
		int first = 0;
		for (i = 9; i >= 0; i--) {
			if ((G - i) % 9 == 0) {
				if (first)   putchar(' ');
				first = 1;
				printf("%lld", (G - i) / 9 * 10 + i);
			}
		}
		puts("");
	}
	return 0;
}



#include<stdio.h>
int main() {
	long long G;
	while (scanf("%lld", &G), G) {
		bool first = 0;
		for (int i = 9; i >= 0; i--) 
			if ((G-i)%9 == 0) {
				if (first)putchar(' ');
				first = true;
				printf("%lld", (G-i) / 9 * 10 + i);
			}
		puts("");
	}
	return 0;
}



/*concept
18
9-1=8

0-2=8

333
6-3=3
9-6=3

0-7=3



N
is a random number, which for some reason, is at least two 
digits. John Doe, a nondescript man,
performs an operation on
N
: he chops off the last digit to form a new number
M
, and then  nds
N
This excites him in a hard-to-justify way. He then tells you
N
Thrilled by the fascinating
back-story behind this number, you make it your life goal to  
gure out what
N
was.
By the way, John was later eaten by a tiger.



Input
Input consists of multiple lines, one line per case. 
Each line contains a single positive integer between
10 and 10
18
inclusive, giving the value of
N
Input is terminated by a line containing `
0
'.

Output
For each case, print one line containing the possible values of
N
in sorted order. Separate consecutive
numbers with a single space.



SampleInput
18
0

SampleOutput
19 2