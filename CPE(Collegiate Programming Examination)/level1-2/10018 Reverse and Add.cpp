10018	Reverse and Add



no1.
#include<iostream>
#include<cstdio>
using namespace std;

unsigned int reverse(unsigned int num) {
	int rev = 0;
	while (num) {
		rev = rev * 10 + num % 10;
		num /= 10;
	}
	return rev;
}

int main() {
	int N, times;
	unsigned int num, rev;
	while (scanf("%d", &N) != EOF) {
		for (int i = 1; i <= N; i++) {
			scanf("%u", &num);
			times = 0;
			rev = reverse(num);
			do {
				num = num + rev;
				times++;
				rev = reverse(num);
			} while (num != rev);
			printf("%d %u\n", times, num);
		}
	}
	return 0;
}



no2.
#include<cstdio>

unsigned int reverse(unsigned int n)
{
	unsigned int rev = 0;
	while (n)
	{
		rev = rev * 10 + n % 10;
		n /= 10;
	}
	return rev;
}

int main()
{
	unsigned int rev, n,num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		scanf("%u", &n);
		int cnt = 0;
		rev = reverse(n);
		do {
			n += rev;
			cnt++;
			rev = reverse(n);
		} while (rev != n);
		printf("%d %u\n", cnt, n);
	}
}



The “reverse and add” method is simple: choose a number, reverse 
its digits and add it to the original.If the sum is not a 
palindrome (which means, it is not the same number from left to 
right and right to left), repeat this procedure.
For example:
195 Initial number
591
—–
786
687
—–
1473
3741
—–
5214
4125
—–
9339 Resulting palindrome
In this particular case the palindrome ‘9339’ appeared after the 
4th addition. This method leads to palindromes in a few step for 
almost all of the integers. But there are interesting exceptions. 
196 is the first number for which no palindrome has been found. 
It is not proven though, that there is no such a palindrome.
You must write a program that give the resulting palindrome and the 
number of iterations (additions) to compute the palindrome.
You might assume that all tests data on this problem:
• will have an answer ,
• will be computable with less than 1000 iterations (additions),
• will yield a palindrome that is not greater than 4,294,967,295.



Input
The first line will have a number N (0 < N ≤ 100) with the number 
of test cases, the next N lines will have a number P to compute its 
palindrome.

Output
For each of the N tests you will have to write a line with the 
following data : 
minimumnumberofiterations(additions)togettothepalindrome
and 
theresultingpalindromeitself 
separated by one space.



Sample Input
3
195
265
750

Sample Output
4 9339
5 45254
3 6666