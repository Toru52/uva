498 - Polly the Polynomial



#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;

int main()
{
	char s[1001];
	while (fgets(s,sizeof(s),stdin)) {
		int c[100], x[100], ct = -1, xt = -1;
		istringstream input(s);
		while (input >> c[++ct]);
		fgets(s, sizeof(s), stdin);
		istringstream read(s);
		while (read >> x[++xt]);
		for (int i = 0; i < xt; i++) {
			int sum = 0;
			for (int j = 0; j < ct; j++)
				sum += c[j] * (int)pow(x[i], ct - j - 1);
			if (i)
				printf(" ");
			printf("%d", sum);
		}
		puts("");
	}
	return 0;
}



#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;

int main()
{
	char s[1001];
	while (fgets(s, sizeof(s), stdin)) {
		int cn = -1, xn = -1, c[101], x[101];
		istringstream INc(s);
		while (INc >> c[++cn]);
		fgets(s, sizeof(s), stdin);
		istringstream INx(s);
		while (INx >> x[++xn]);
		for (int i = 0; i < xn; i++) {
			int sum = 0;
			for (int j = 0; j < cn; j++)
				sum += c[j] *(int)pow(x[i], cn - j - 1);
			if (i)
				printf(" ");
			printf("%d", sum);
		}
		puts("");
	}
}



Algebra! Remember algebra? There is a theory that as engineers 
progresses further and further in their studies, they lose 
basic math skills. This problem is designed to help you 
remember those basic algebra skills, make the world a better 
place, etc., etc.



Input
Your program should accept an even number of lines of text. 
Each pair of lines will represent one
problem. The first line will contain a list of integers 
{c0, c1, . . . , cn} which represent a set of coefficients
to a polynomial expression. The order of the polynomial is n. 
The coefficients should be paired with
the terms of the polynomial in the following manner:
c0x
n + c1x
n−1 + · · · + cnx
0
The second line of text represents a sequence of values for x,
 {x0, x1, . . . , xm}.
 
Output
For each pair of lines, your program should evaluate the 
polynomial for all the values of x (x0 through
xm) and output the resulting values on a single line.



Sample Input
-2
5 0 1 6
1 -1
7 6 -1
Sample Output
-2 -2 -2 -2
6 5 -2



ex

since -2 have just one number, so n=1-1=0 c0=-2
-2*5^0  -2*0^0  -2*1^0  6*0^0

since 1 -1 has two number , so n=2-1=1 c1=1 c0=-1
1*7^1+(-1)*7^0  1*6^1+(-1)*6^0  1*(-1)^1+(-1)*(-1)^0