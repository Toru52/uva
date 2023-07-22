10591 - Happy Number
http://codercart.blogspot.tw/2016/04/uva-10591-happy-number-solution.html



#include<iostream>
using namespace std;

int happy(int n)
{
	int temp = n;
	bool visit[10000] = {};
	while (1)
	{
		int temp2 = 0;
		while (temp)
		{
			int a = temp % 10;
			temp2 += a*a;
			temp /= 10;
		}
		if (temp2 == 1) return 1;
		if (temp2 == n) return 0;
		if (visit[temp2]) return 0;
		visit[temp2] = true;
		temp = temp2;
	}
}

int main()
{
	int t, c = 1;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		if (happy(n)) printf("Case #%d: %d is a Happy number.\n", c++, n);
		else printf("Case #%d: %d is an Unhappy number.\n", c++, n);
	}
	return 0;
}



#include<stdio.h>
int happy(int n) {
	int temp = n, visit[10000] = {};
	while (1) {
		int temp2 = 0;
		while (temp) {
			int a = temp%10;
			temp2 += a*a;
			temp /= 10;
		}
		if (temp2 == 1)
			return 1;
		else if (temp2 == n || visit[temp2])
			return 0;
		visit[temp2] = true;
		temp = temp2;
	}
	return 0;
}
int main() {
	int cas, n, c = 0;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		if (happy(n))printf("Case #%d: %d is a Happy number.\n", ++c, n);
		else printf("Case #%d: %d is an Unhappy number.\n", ++c, n);
	}
}



Let the sum of the square of the digits of a positive integer
S 0 be represented by S 1. 
In a similar way, let the sum of the squares of the digits of
S 1 be represented by S 2 and so on. If S i = 1 for some
i

1, then the original integer
S
0
is said to be Happy number. A number, 
which is not happy, is called
Unhappy number. For example 7 is a Happy number since 7
!
49
!
97
!
130
!
10
!
1 and 4 is an
Unhappy number since 4
!
16
!
37
!
58
!
89
!
145
!
42
!
20
!
4.

Input
The input consists of several test cases, the number of which you 
are given in the  rst line of the input.
Each test case consists of one line containing a single positive 
integer
N
smaller than 10
9
.

Output
For each test case, you must print one of the following messages:
Case #
p
:
N
is a Happy number.
Case #
p
:
N
is an Unhappy number.
Here
p
stands for the case number (starting from 1).  
You should print the  rst message if the
number
N
is a happy number. Otherwise, print the second line.



SampleInput
3
7
4
13

SampleOutput
Case #1: 7 is a Happy number.
Case #2: 4 is an Unhappy number.
Case #3: 13 is a Happy number.

