356 - Square Pegs And Round Holes



#include <stdio.h>
#include <math.h>

int main() {
	int n,flag = 0;
	while (scanf("%d", &n) == 1) {
		if (flag)
			puts("");
		flag = 1;
		int t1 = 0, t2 = 0;
		double r = n - 0.5, r1, r2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				r1 = sqrt(i*i + j*j);
				r2 = sqrt(i*i + j*j + 2 * i + 2 * j + 2);
				if (r1 <= r && r2 <= r)
					t1++,printf("i %d j %d r1 %.3f r2 %.3f\n",i,j,r1,r2);
				if (r1 <= r && r2 > r)
					t2++, printf("2   i %d j %d r1 %.3f r2 %.3f\n", i, j, r1, r2);
			}
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, t2 * 4);
		printf("There are %d cells completely contained in the circle.\n", t1 * 4);
	}
	return 0;
}



#include<cstdio>
#include<math.h>
int main()
{
	int n,flag=0;
	while (~scanf("%d", &n)) {
		if (flag)
			puts("");
		flag = 1;
		int c1 = 0, c2 = 0;
		double r = n - 0.5, r1, r2;

		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++) {
				r1 = sqrt(i*i + j*j);
				r2 = sqrt(i*i + j*j + i * 2 + j * 2 + 2);
				if (r1 <= r&&r2 <= r)
					c1++;
				if (r1 <= r&&r2 > r)
					c2++;
			}
		printf("In the case n = %d, %d cells contain segments of the circle.\n", n, c2 * 4);
		printf("There are %d cells completely contained in the circle.", c1 * 4);
	}
}



A circle 2n − 1 units in diameter has been drawn centered on a 2n by 
2n chessboard. The construction for n = 3 is illustrated below.
Write a program that will determine the number of cells of the board 
which contain a segment of the circle and the number of cells of the 
board which lie entirely inside the circle.



Input
Each line of the input file will contain a positive integer no 
greater than 150.

Output
For each input value n, write two statements on consecutive lines 
of the output file in the format indicated in the sample output. 
Follow this with a blank line to separate your output for 
successive inputs.



Sample input
3
4

Sample output
In the case n = 3, 20 cells contain segments of the circle.
There are 12 cells completely contained in the circle.
In the case n = 4, 28 cells contain segments of the circle.
There are 24 cells completely contained in the circle.