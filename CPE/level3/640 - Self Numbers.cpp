640 - Self Numbers
http://mypaper.pchome.com.tw/zerojudge/post/1322663980

about
https://en.wikipedia.org/wiki/Self_number



#include<stdio.h>
char x[1000001];//no self number (generator)
int main() {
	int j, tmp;
	for (int i = 1; i <= 999999; i++) {
		j = i, tmp = 0;
		while (j) {
			tmp += j % 10;
			j /= 10;
		}
		if (tmp + i <= 1000000)
			x[tmp + i] = 1;
	}
	for (int i = 1; i <= 1000000; i++)
		if (!x[i])
			printf("%d\n", i);
	return 0;
}



#include<stdio.h>
char g[1000001];
int main() {
	for (int i = 1; i <= 999999; i++) {
		int j = i, tmp = 0;
		while (j)
			tmp += j % 10, j /= 10;
		if (tmp + i <= 1000000)
			g[tmp + i] = 1;
	}
	for (int i = 1; i <= 1000000; i++)
		if (!g[i])
			printf("%d\n", i);
	return 0;
}



/*
1
2(1+1) no
3
4(2+2) no
5
6(3+3) no
7
8(4+4) no
9
,
,
,
21(1+5+15) no
*/
In 1949 the Indian mathematician D.R. Kaprekar discovered a class of 
numbers called self-numbers.
For any positive integer n, define d(n) to be n plus the sum of the 
digits of n. (The d stands for digitadition, a term coined by Kaprekar.) 
For example, d(75) = 75 + 7 + 5 = 87. Given any positive integer n as a 
starting point, you can construct the infinite increasing sequence of 
integers n, d(n), d(d(n)), d(d(d(n))), .... 
For example, if you start with 33, the next number is 33 + 3 + 3 = 39, 
the next is 39 + 3 + 9 = 51, the next is 51 + 5 + 1 = 57, 
and so you generate the sequence
33, 39, 51, 57, 69, 84, 96, 111, 114, 120, 123, 129, 141, ...
The number n is called a generator of d(n). In the sequence above, 
33 is a generator of 39, 39 is a generator of 51, 51 is a generator of 57,
and so on. Some numbers have more than one generator:
for example, 101 has two generators, 91 and 100. 
A number with no generators is a self 􀀀number.
There are thirteen self-numbers less than 
100: 1, 3, 5, 7, 9, 20, 31, 42, 53, 64, 75, 86, and 97.
Write a program to output all positive self-numbers less than or equal 
1000000 in increasing order, one per line.



Sample Output
13579
20
31
42
53
64
||
<-- a lot more numbers
|
9903
9914
9925
9927
9938
9949
9960
9971
9982
9993
|||
