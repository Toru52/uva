443 - Humble Numbers
https://github.com/morris821028/UVa/blob/master/volume004/443%20-%20Humble%20Numbers.cpp



#include<stdio.h>
int main() {
	int n, tmp, t2 = 0, t3 = 0, t5 = 0, t7 = 0,DP[5842] = { 1 };
	for (int i = 1; i < 5842; i++) {
		while (DP[t2] * 2 <= DP[i - 1])	t2++;
		while (DP[t3] * 3 <= DP[i - 1])	t3++;
		while (DP[t5] * 5 <= DP[i - 1])	t5++;
		while (DP[t7] * 7 <= DP[i - 1])	t7++;
		tmp = DP[t2] * 2;
		if (DP[t3] * 3 < tmp)	tmp = DP[t3] * 3;
		if (DP[t5] * 5 < tmp)	tmp = DP[t5] * 5;
		if (DP[t7] * 7 < tmp)	tmp = DP[t7] * 7;
		DP[i] = tmp;
	}
	while (scanf("%d", &n) == 1 && n) {
		printf("The %d", n);
		if (n % 10 == 1 && n % 100 != 11)
			printf("st");
		else if (n % 10 == 2 && n % 100 != 12)
			printf("nd");
		else if (n % 10 == 3 && n % 100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n", DP[n - 1]);
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int H[5843]{ 1,1 };
	int w,x, y, z, a = 1, b = 1, c = 1, d=1,n = 1;
	while (n != 5842) {
		w=7*H[d],x = 2 *H[a], y = 3 * H[b], z = 5 * H[c];
		H[++n] = min(min(w,x),min(y, z));
		if (H[n] == x)
			a++;
		if (H[n] == y)
			b++;
		if (H[n] == z)
			c++;
		if (H[n] == w)
			d++;
	}
	while (scanf("%d", &n) == 1 && n) {
		printf("The %d", n);
		if (n % 10 == 1 && n % 100 != 11)
			printf("st");
		else if (n % 10 == 2 && n % 100 != 12)
			printf("nd");
		else if (n % 10 == 3 && n % 100 != 13)
			printf("rd");
		else
			printf("th");
		printf(" humble number is %d.\n", H[n]);
	}
	
	return 0;
}


A number whose only prime factors are 2,3,5 or 7 is called a humble 
number. The sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 15, 16, 
18, 20, 21, 24, 25, 27, ... shows the first 20 humble numbers.
Write a program to find and print the nth element in this sequence.



Input
The input consists of one or more test cases. Each test case consists 
of one integer n with 1  n  5842.
Input is terminated by a value of zero (0) for n.

Output
For each test case, print one line saying ‘The nth humble number is 
number.’. Depending on the value of n, the correct suffix ‘st’, ‘nd’, 
‘rd’, or ‘th’ for the ordinal number nth has to be used like it is
shown in the sample output.



Sample Input
1
2
3
4
11
12
13
21
22
23
100
1000
5842
0

Sample Output
The 1st humble number is 1.
The 2nd humble number is 2.
The 3rd humble number is 3.
The 4th humble number is 4.
The 11th humble number is 12.
The 12th humble number is 14.
The 13th humble number is 15.
The 21st humble number is 28.
The 22nd humble number is 30.
The 23rd humble number is 32.
The 100th humble number is 450.
The 1000th humble number is 385875.
The 5842nd humble number is 2000000000.