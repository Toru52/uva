108 Maximum Sum 
http://knightzone.org/?p=1477



#include<cstdio>
#include<climits>

int main() {
	int N,array[105][105];
	while (scanf("%d", &N) ==1) {
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				scanf("%d", &array[i][j]);
		int sub[105][105] = {};
		//extension row area
		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= N; j++)
				sub[i][j] = sub[i - 1][j] + array[i][j];
	//	puts("\n");
		int max_sum = INT_MIN;
		//That's why set i=1, since sub array can to set 0 when i=0
		//sub[0][?]->0
		//when i=1,sum canto extension to max size
		//scale up sub area(i=1) scale down sub area(i=2~)
		for (int i = 1; i <= N; i++) {
			for (int j = i; j <= N; j++) {
				int sum = 0;
				for (int k = 1; k <= N; k++) {
					sum += sub[j][k] - sub[i - 1][k];
			//		printf("%d(%d - %d) ", sum,sub[j][k],sub[i-1][k]);
	        //		printf("%d(%d,%d,%d) ", sum, i, j, k);
					if (sum > max_sum) max_sum = sum;
					if (sum < 0) sum = 0;
				}
				puts("");
			}
			puts("");
		}
		printf("%d\n", max_sum);
	}
	return 0;
}



#include<stdio.h>
#include<climits>
int main() {
	int n, array[105][105];
	while (scanf("%d", &n) == 1) {
		int sub[105][105]{}, max = INT_MIN;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &array[i][j]), sub[i][j] = array[i][j] + sub[i - 1][j];
		for(int i=1;i<=n;i++)
			for (int j = i; j <= n; j++) {
				int sum = 0;
				for (int k = 1; k <= n; k++) {
					sum += sub[j][k] - sub[i - 1][k];
					if (max < sum)max = sum;
					if (sum < 0)sum = 0;
				}
			}
		printf("%d\n", max);
	}
	return 0;
}




/*
ex
4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2

(row sub area)
0 -2 -7 0 
9 0 -13 2
5 1 -17 3
4 9 -17 1

sub area(axis(0,0))
0 -2  -7 0
9  9  -4 2
5  6 -11 3
4 13  -4 1

9 11 5 7
5 8 -2 3
4 15 5 6  ->max=15

-4 1 -3 1
-5 9 5 4

-1 8 8 6



ex2
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1

row sub area
1 1 1 1
2 2 2 2
3 3 3 3
4 4 4 4

sub area(axis(0,0))
1 2 3 4
2 4 6 8
3 6 9 12
5 8 12 16

1 2 3 4
2 4 6 8
3 6 9 12

1 2 3 4
2 4 6 8

1 2 3 4

16



ex3
4
1   2  3  4
5   6  7  8 
9  10 11 12
13 14 15 16

row extension sub area
 1  2  3  4
 6  8 10 12
15 18 21 24
28 32 36 40

column extension sub area

sub area(axis(0,0))
 1  3 6   10
 6 14 24  36
15 33 54  78
28 60 96 136

sub area(axis(1,0))
 5 11 18  26
14 30 48  68
27 57 90 126

sub area(axis(2,0))
 9 19 30  42
22 46 72 100

sub area(axis(3,0))
13 27 42 58

136
*/
one dimension. Consider satisfying a boolean expression in 
conjunctive normal form in which each conjunct consists of 
exactly 3 disjuncts. This problem (3-SAT) is NP-complete. 
The problem 2-SAT is solved quite efficiently, however. 
In contrast, some problems belong to the same complexity class
regardless of the dimensionality of the problem.
Given a 2-dimensional array of positive and negative integers, 
find the sub-rectangle with the largest sum. 
The sum of a rectangle is the sum of all the elements in that 
rectangle. In this problem the subrectangle with the largest 
sum is referred to as the maximal sub-rectangle.
A sub-rectangle is any contiguous sub-array of 
size 1  1 or greater located within the whole array.
As an example, the maximal sub-rectangle of the array:
0 􀀀2 􀀀7 0
9 2 􀀀6 2
􀀀4 1 􀀀4 1
􀀀1 8 0 􀀀2
is in the lower-left-hand corner:
9 2
􀀀4 1
􀀀1 8
and has the sum of 15.



Input
The input consists of an N  N array of integers.
The input begins with a single positive integer N on a line by 
itself indicating the size of the square
two dimensional array. This is followed by N2 integers 
separated by white-space (newlines and spaces).
These N2 integers make up the array in row-major order 
(i.e., all numbers on the first row, left-to-right,
then all numbers on the second row, left-to-right, etc.). 
N may be as large as 100. The numbers in the
array will be in the range [􀀀127; 127].

Output
The output is the sum of the maximal sub-rectangle.



Sample Input
4
0 -2 -7 0 9 2 -6 2
-4 1 -4 1 -1
8 0 -2

Sample Output
15