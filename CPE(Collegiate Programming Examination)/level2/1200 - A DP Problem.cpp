1200 - A DP Problem



#include <stdio.h>
#include <math.h>
void parse(char *s, int& A, int& B) {
	A = 0, B = 0;
	int i, g = 0, f = 0, neg = 1;
	for (i = 0; s[i]; i++) {
		if (s[i] == 'x') {
			if (g)
				A += neg*f;
			else
				A += neg;
			g = 0, f = 0, neg = 1;
		}
		else {
			if (s[i] == '-') {
				if (g)
					B += neg*f;
				g = 0, f = 0;
				neg = -1;
			}
			else if (s[i] == '+') {
				if (g)
					B += neg*f;
				g = 0, f = 0;
				neg = 1;
			}
			else
				f = f * 10 + s[i] - '0', g = 1;
			//ex 356 1st f=3 2nd f=35 3rd f=356
		}
	}
	if (g)
		B += neg*f;
}

int main() {
	int t, i;
	scanf("%d", &t);
	char s1[502], *s2;
	while (t--) {
		scanf("%s", s1);
		for (i = 0; s1[i]; i++) {
			if (s1[i] == '=') {
				s2 = s1 + i + 1;
				s1[i] = '\0';
				break;
			}
		}
		int la, lb, ra, rb;
		parse(s1, la, lb);
		parse(s2, ra, rb);
		//printf("ra %d rb %d la %d lb %d\n", ra, rb, la, lb);
		if (la == ra && lb == rb)
			puts("IDENTITY");
		else if (la == ra && lb != rb)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", (int)floor((double)(rb - lb) / (la - ra)));
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
void parse(char *s, int &X, int &NX)
{
	X = 0, NX = 0;
	int Fnum = 0, num = 0, neg = 1;
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'x') {
			if (Fnum)
				X += num*neg;
			else
				X += neg;
			neg = 1, num = 0, Fnum = 0;
		}
		else {
			if (s[i] == '+') {
				if (Fnum)
					NX += num*neg;
				neg = 1, num = 0, Fnum = 0;
			}
			else if (s[i] == '-') {
				if (Fnum)
					NX += num*neg;
				neg = -1, num = 0, Fnum = 0;
			}
			else
				Fnum = 1, num = num * 10 + s[i] - '0';
		}
	}
	if (Fnum)
		NX += num*neg;

}
int main() {
	int n;
	char s1[255], *s2;
	scanf("%d", &n);
	while (n--) {
		scanf("%s",s1);
		for (int i = 0; s1[i]; i++) 
			if (s1[i] == '='){
				s2 = s1 + i + 1;
				s1[i] = '\0';
			}
		int ax, an, bx, bn;
		parse(s1, ax, an);
		parse(s2, bx, bn);

		if (ax == bx&&an == bn)
			puts("IDENTITY");
		else if (ax == bx&&an != bn)
			puts("IMPOSSIBLE");
		else
			printf("%d\n", (int)floor(double(bn - an)/(ax - bx)));

	}
}



In this problem, you are to solve a very easy linear equation with 
only one variable x with no parentheses!
An example of such equations is like the following:
2x − 4 + 5x + 300 = 98x
An expression in its general form, will contain a ‘=’ character 
with two expressions on its sides. Each expression is made up of 
one or more terms combined by ‘+’ or ‘-’ operators. No unary plus 
or minus operators are allowed in the expressions. 
Each term is either a single integer, or an integer followed by
the lower-case character x or the single character x which is 
equivalent to 1x. You are to write a program to find the value of 
x that satisfies the equation. Note that it is possible for the 
equation to have no solution or have infinitely many. 
Your program must detect these cases too.



Input
The first number in the input line, t (1 ≤ t ≤ 10) is the number 
of test cases, followed by t lines of length at most 255 each 
containing an equation. There is no blank character in the 
equations and the variable is always represented by the lower-case
character ‘x’. The coefficients are integers in the range 
(0..1000) inclusive.

Output
The output contains one line per test case containing the 
solution of the equation. If s is the solution to the equation, 
the output line should contain ⌊s⌋ (the “floor” of s, i.e., 
the largest integer number less than or equal to s). 
The output should be ‘IMPOSSIBLE’ or ‘IDENTITY’ if the equation 
has no solution or has infinite solutions, respectively. 
Note that the output is case-sensitive.



Sample Input
2
2x-4+5x+300=98x
x+2=2+x

Sample Output
3
IDENTITY



Input
8
2x+3=0
2x-3=0
0=0x
1=0x
0x=0x
0=0
511=511
11=5

Output
-2
1
IDENTITY
IMPOSSIBLE
IDENTITY
IDENTITY
IDENTITY
IMPOSSIBLE
