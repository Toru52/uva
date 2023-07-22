11371 - Number Theory for Newbies
https://github.com/morris821028/UVa/blob/master/volume113/11371%20-%20Number%20Theory%20for%20Newbies.cpp



#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main() {
	char s[100];
	while (scanf("%s", s) == 1) {
		int len = strlen(s);
		sort(s, s + len);
		//ex 3210 ->0123 ->1023
		for (int i = 0; i < len; i++) 
			if (s[i] != '0') {
				swap(s[0], s[i]);
				break;
			}
		//	printf("%s\n", s);
		long long a, b;
		sscanf(s, "%lld", &b);
		sort(s, s + len);
		for (int i = 0,int  j = len - 1; i < j; i++, j--)
			swap(s[i], s[j]);
		sscanf(s, "%lld", &a);
		printf("%lld - %lld = %lld = 9 * %d\n", a, b, a - b, (a - b) / 9);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char cmp(char a, char b) { return a>b; }
int main() {
	char str[100];
	while (scanf("%s",str) == 1) {
		int len = strlen(str);
		sort(str, str + len);
		for(int i=0;i<len;i++)
			if (str[i] != '0') {
				swap(str[0], str[i]);
				break;
			}
		long long l, h;
		sscanf(str, "%lld",&l);
		sort(str, str + len, cmp);
		sscanf(str, "%lld",&h);
		printf("%lld - %lld = %lld = 9 * %lld\n", h, l, h - l, (h - l) / 9);
	}
	return 0;
}




Given any positive integer, if we permute its digits, 
the difference between the number we get and the
given number will always be divisible by 9.
For example, if the given number is 123, we may rearrange the 
digits to get 321. The difference = 321 - 123 = 198, 
which is a multiple of 9 (198 = 9  22).
We can prove this fact fairly easily, 
but since we are not having a maths contest, we instead try to
illustrate this fact with the help of a computer program.



Input
Each line of input gives a positive integer n ( 2000000000). You are to nd two integers a and b
formed by rearranging the digits of n, such that a 􀀀 b is
maximum. a and b should NOT have leading zeros

Output
You should then show that a 􀀀 b is a multiple of 9, by 
expressing it as `9 * k', where k is an integer.
See the sample output for the correct output format



Sample Input
123
2468

Sample Output
321 - 123 = 198 = 9 * 22
8642 - 2468 = 6174 = 9 * 686