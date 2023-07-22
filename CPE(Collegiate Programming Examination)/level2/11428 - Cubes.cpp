11428 - Cubes  
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/11428%20-%20Cubes.cpp
http://mypaper.pchome.com.tw/zerojudge/post/1322892741
reference
http://math.nakaken88.com/textbook/standard-cubic-factorization-and-volume/



#include <stdio.h>

int main() {
	int n, x[10001], y[10001];
	bool done[10001]{};

	for (int i = 1; i <= 57; ++i) {
		int j = 1;
		while ((n = 3 * i*i*j + 3 * i*j*j + j*j*j) <= 10000) {
			if (!done[n]) {
				y[n] = i;
				x[n] = i + j;
				done[n] = true;
			}
			++j;
		}
	}
	while (true) {
		scanf("%d", &n);
		if (n == 0) 
			break;
		if (!done[n])
			puts("No solution");
		else
			printf("%d %d\n", x[n], y[n]);
	}
	return 0;
}



#include <stdio.h>

int main() {
	int n,x[10001], y[10001];
	bool flag[10001]{};
	for (int i = 2; i <= 60; i++) 
		for (int j = i - 1; j >= 1; j--) {
			int n = i*i*i - j*j*j;
			if (n <= 10000 && !flag[n]) {
				flag[n] = 1;
				x[n] = i;y[n] = j;
			}
		}
	while (scanf("%d", &n) == 1 && n) {
		if (flag[n])
			printf("%d %d\n", x[n], y[n]);
		else
			puts("No solution");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, x[10005]{}, y[10005]{};
	bool flag[10005]{};
	for(int i=2;i<60;i++)
		for (int j = i - 1; j > 0; j--) {
			int n = i*i*i - j*j*j;
			if (n <= 10000 && !flag[n]) {
				flag[n] = 1;
				x[n] = i, y[n] = j;
			}
		}
	while (scanf("%d", &n),n)
		if (flag[n])
			printf("%d %d\n", x[n], y[n]);
		else
			puts("No solution");
	return 0;
}
/*
concept
x^3-y^3=(x-y)(x^2+xy+y^2)
(x+y)^3=x^3+3x^2y+3xy^2+y^3
->3x^2y+3xy^2+y^3=(x+y)^3-x^3


*/

Given a positive integer N you will have to nd two positive 
integers x and y such that: N = x3 􀀀 y3



Input
The input le contains at most 100 lines of inputs. 
Each line contains a positive integer N (0 < N 10000). 
Input is terminated by a line containing a single zero. 
This line should not be processed.

Output
For each line of input produce one or more lines of output.
Each of these lines contains two positive integers x, y 
separated by a single space, such that N = x3 􀀀y3. 
If there is no such integer values of x and y then produce 
the line `No solution' instead. If there is more than one 
solution then output the one with smallest value of y.



Sample Input
7
37
12
0

Sample Output
2 1
4 3
No solution
