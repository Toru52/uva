11565 - Simple Equations
http://blog.csdn.net/mobius_strip/article/details/50343919
concept
https://quickgrid.wordpress.com/2015/10/22/uva-problem-11565-simple-equations-solution/



#include <cstring>  
#include <cstdio>  

int main()
{
	int n, A, B, C, x, y, z;
	while (~scanf("%d", &n))
		while (n--) {
			scanf("%d%d%d", &A, &B, &C);
			int flag = 0;
			for (x = -100; x + x + x < A; ++x) {
				//x*x>=C ->minus 
				//B%x>0->continue ->denote at least B%x>0
				if (x*x >= C || x && B%x)
					continue;
				for (y = x + 1; x + y + y < A; ++y) {
					z = A - x - y;
					if (y < z && x*y*z == B &&
						x*x + y*y + z*z == C) {
						flag = 1;
						break;
					}
				}
				if (flag) break;
			}
			if (flag)
				printf("%d %d %d\n", x, y, z);
			else printf("No solution.\n");
		}
	return 0;
}



#include<stdio.h>
int main() {
	int t, A, B, C, x, y, z;
	scanf("%d", &t);
	while (t--) {
		int flag = 0;
		scanf("%d %d %d", &A, &B, &C);
		for (x = -100; x + x + x < A; x++) {
			if (x*x >= C || x&&B%x)
				continue;
			for (y = x + 1; x + y + y < A; y++) {
				z = A - y - x;
				if (y < z && x*x + y*y + z*z == C
					&& x*y*z == B) {
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf("%d %d %d\n", x, y, z);
		else
			puts("No solution.");
	}
	return 0;
}



/*
(1<=A,B,C<=10000)
->x,y,z<100 since x^2+y^2+z^2=C
->-100<x,y,z since x+y+z=A
->-100<x,y,z<100
->   x<y<z
since x start from -100,
at least x+x+x<A

at least x*x >= C,   x && B%x(should not to have remainder)

*/



Let us look at a boring mathematics problem. :-)
We have three different integers, x, y and z, which 
satisfy the following three relations:
 x + y + z = A
 xyz = B
 x2 + y2 + z2 = C
You are asked to write a program that solves for x, y 
and z for given values of A, B and C.



Input
The rst line of the input le gives the number of 
test cases N (N < 20). Each of the following N lines
gives the values of A, B and C (1  A;B;C  10000).

Output
For each test case, output the corresponding values 
of x, y and z. If there are many possible answers,
choose the one with the least value of x. 
If there is a tie, output the one with the least value 
of y.
If there is no solution, output the line 
`No solution.' instead.



Sample Input
2
1 2 3
6 6 14

Sample Output
No solution.
1 2 3