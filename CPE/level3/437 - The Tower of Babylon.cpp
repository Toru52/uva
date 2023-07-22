437 - The Tower of Babylon
http://programming-study-notes.blogspot.tw/2014/03/uva-437-tower-of-babylon.html


Longest Increasing Subsequence
http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=DPL_1_D
http://www.geeksforgeeks.org/longest-increasing-subsequence/



#include <cstdio>
#include <algorithm>
using namespace std;
struct block {int L,W,H;}B[300];
bool cmp(const block &X, const block &Y) {
	if (X.L == Y.L)
		return X.W < Y.W;
	return X.L < Y.L;
}
int main()
{
	int cas = 1, N, L, W, H;
	while (scanf("%d", &N) && N) {
		int cnt = 0;
		for (int i = 0; i < N; ++i) {
			scanf("%d %d %d", &L, &W, &H);
			B[cnt++] = { L, W, H },B[cnt++] = { L, H, W };
			B[cnt++] = { W, L, H },B[cnt++] = { W, H, L };
			B[cnt++] = { H, L, W },B[cnt++] = { H, W, L };
		}
		sort(B, B + cnt, cmp);

		int LIS[300]{}, Max = 0;
		for (int i = 0; i < cnt; ++i) {
			LIS[i] = B[i].H;
			for (int j = 0; j < i; ++j)
				if (B[i].L > B[j].L && B[i].W > B[j].W
					&& LIS[j] + B[i].H > LIS[i])
					LIS[i] = LIS[j] + B[i].H;
			if (LIS[i] > Max) 
				Max = LIS[i];
		}
		printf("Case %d: maximum height = %d\n", cas++, Max);
	}
}



#include<stdio.h>
#include<algorithm>
using namespace std;
struct block { int x, y, z; }b[300];
bool cmp(const block &L,const  block &R) {
	if (L.x == R.x)
		return L.y < R.y;
	return L.x < R.x;
}
int main() {
	int n, x, y, z, cas = 1;
	while (scanf("%d", &n), n) {
		int max = 0, cnt = 0, LIS[300]{};
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			b[cnt++] = { x,y,z }, b[cnt++] = { x,z,y };
			b[cnt++] = { y,x,z }, b[cnt++] = { y,z,x };
			b[cnt++] = { z,x,y }, b[cnt++] = { z,y,x };
		}
		sort(b, b + cnt, cmp);
		for (int i = 0; i < cnt; i++) {
			LIS[i] = b[i].z;
			for (int j = 0; j < i; j++)
				if (b[i].x > b[j].x&&b[i].y > b[j].y
					&&LIS[i] < LIS[j] + b[i].z)
					LIS[i] = LIS[j] + b[i].z;
			if (LIS[i] > max)
				max = LIS[i];
		}
		printf("Case %d: maximum height = %d\n", cas++, max);
	}
	return 0;
}



/*
ex 1 2 3
sorted

0   1 2 3
1   1 3 2
2   2 1 3
3   2 3 1 
4   3 1 2
5   3 2 1 

0   L:1 W:2
3   L:2 W:3 ->ok
0(H:3)+3(H:1)=4

2   L:2 W:1
5   L:3 W:2 ->ok
2(3)+5(1)=4
*/
Perhaps you have heard of the legend of the Tower of Babylon. Nowadays many 
details of this tale have been forgotten. So now, in line with the 
educational nature of this contest, we will tell you the whole story:
The babylonians had n types of blocks, and an unlimited supply of blocks of 
each type.
Each type-i block was a rectangular solid with linear dimensions (xi; yi; zi).
A block could be reoriented so that any two of its three dimensions 
determined the dimensions of the base and the other dimension was the height.
They wanted to construct the tallest tower possible by stacking blocks. 
The problem was that, in building a tower, one block could only be placed on 
top of another block as long as the two base dimensions of the upper block 
were both strictly smaller than the corresponding base dimensions of the 
lower block. This meant, for example, that blocks oriented to have
equal-sized bases couldn’t be stacked.
Your job is to write a program that determines the height of the tallest 
tower the babylonians can build with a given set of blocks.



Input
The input file will contain one or more test cases. The first line of each 
test case contains an integer n, representing the number of different blocks 
in the following data set. The maximum value for n is 30.
Each of the next n lines contains three integers representing the values xi, 
yi and zi. Input is terminated by a value of zero (0) for n.

Output
For each test case, print one line containing the case number 
(they are numbered sequentially starting from 1) and the height of the 
tallest possible tower in the format ‘Case case: maximum height = height’



Sample Input
1
10 20 30
2
6 8 10
5 5 5
7
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
6 6 6
7 7 7
5
31 41 59
26 53 58
97 93 23
84 62 64
33 83 27
0

Sample Output
Case 1: maximum height = 40
Case 2: maximum height = 21
Case 3: maximum height = 28
Case 4: maximum height = 342