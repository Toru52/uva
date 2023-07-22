913 - Joana and the Odd Numbers



no1.
#include <cstdio>

int main() {
	long long N;
	while (scanf("%lld", &N) == 1) {
		long long num = (N / 2 + 1);
		num *= num;
		printf("%lld\n", (num * 2 - 1) * 3 - 6);
	}
}



no2.
#include<iostream>

int main()
{
	long long n;
	while (scanf("%lld", &n) == 1){
		n = n / 2 + 1;
		n *= n;
		printf("%lld\n", (2 * n - 1) * 3 - 6);
	}
}



reference
http://www.chikyo.co.jp/maths/pdf/free03.pdf#search='%E5%A5%87%E6%95%B0+%E5%92%8C'



concept 
 The sum of odd for from 1 to (2n-1)= n^2

Joana loves playing with odd numbers. In the other day, she started
writing, in each line, an odd number of odd numbers. It looked as
follows:
1
3 5 7
9 11 13 15 17
19 21 23 25 27 29 31
...
On a certain line Joana wrote 55 odd numbers. Can you discover
the sum of the last three numbers written in that line? 
Can you do this more generally for a given quantity of odd numbers?
Given the number N of odd numbers in a certain line, your task is
to determine the sum of the last three numbers of that line.



Input
The input is a sequence of lines, one odd number N (1 < N <
1000000000) per line



Output
For each input line write the sum of the last three odd numbers 
written by Joana in that line with N numbers. 
This sum is guaranteed to be less than 263.



Sample Input
3
5
7

Sample Output
15
45
87