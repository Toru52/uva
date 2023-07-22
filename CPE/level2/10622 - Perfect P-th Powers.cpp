10622 - Perfect P-th Powers
https://github.com/morris821028/UVa/blob/master/volume106/10622%20-%20Perfect%20P-th%20Powers.cpp

#include <stdio.h>
#include <math.h>

int main() {
	long long n, tn,j,k;
	while (scanf("%lld", &n) == 1 && n) {
		if (n < 0)   tn = -n;
		else        tn = n;
		long long sq = sqrt(tn);
		int ans = 1;
		for (int i = -sq; i <= sq; i++) {
			if (i == 0 || i == 1 || i == -1)  continue;
			for (j = 1, k = 0; j < tn && j > -tn; j *= i, k++);	
			//printf("i %d j %lld k %lld\n", i,j,k);
			if (j == n) 
				if (k > ans)
					ans = k;
		}
		printf("%d\n", ans);
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	long long n, tn, i, j, k;
	while (scanf("%lld", &n) && n) {
		if (n < 0)tn = -n;
		else tn = n;
		long long sq = sqrt(tn);
		int ans = 1;
		for (i = -sq; i <= sq; i++) {
			if (i == 0 || i == 1 || i == -1)continue;
			for (j = 1, k = 0; j<tn&&j>-tn; j *= i, k++);
			if (j == n)
				if (k > ans)
					ans = k;
		}
		printf("%d\n", ans);
	}
	return 0;
}



We say that
x
is a perfect square if, for some integer
b
,
x
=
b
2
.
Similarly,
x
is a perfect cube if,  for some integer
b
,
x
=
b
3
.
More generally,
x
is a perfect p
th
power if, for some integer
b
,
x
=
b
p
.  Given an integer
x
you are to determine the largest
p
such that
x
is a perfect p
th
power.
Input
Each test case is given by a line of input containing
x
.  The
value of
x
will have magnitude at least 2 and be within the
range of a (32-bit)
int
in C, C++, and Java.  A line containing
`
0
' follows the last test case.
Output
For each test case, output a line giving the largest integer
p
such that
x
is a perfect p
th
power.
SampleInput
17
1073741824
25
0
SampleOutput
1
30
2