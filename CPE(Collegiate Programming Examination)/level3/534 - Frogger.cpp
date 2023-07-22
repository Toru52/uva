534 - Frogger
https://github.com/lamphanviet/competitive-programming/blob/master/uva-online-judge/accepted-solutions/534%20-%20Frogger.cpp



#include <stdio.h>
#include<algorithm>
#include <math.h>
int x[205], y[205];
double D(int i, int j) {
	int a = x[i] - x[j], b = y[i] - y[j];
	return sqrt(a*a + b*b);
}
int main() {
	double a[205][205]{};
	int n,cas = 0;
	while (scanf("%d",&n),n) {
		for (int i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for (int i = 0; i<n; i++)
			for (int j = i; j<n; j++)
				a[i][j] = a[j][i] = D(i, j);
		for (int k = 0; k<n; k++)
			for (int i = 0; i<n; i++)
				for (int j = 0; j<n; j++)       //avoid to zero distance
					a[i][j] = std::min(a[i][j], std::max(a[i][k], a[k][j]));
		printf("Scenario #%d\n", ++cas);
		//since a[0][0] is zero distance,a[0][1] is shortest path except a[0][0]
		printf("Frog Distance = %.3lf\n\n", a[0][1]);
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
#include<math.h>
int x[205], y[205];
double D(int i, int j) {
	int a = x[j] - x[i], b = y[j] - y[i];
	return sqrt(a*a + b*b);
}
int main() {
	int n, cas = 0;
	double a[205][205];
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = a[j][i] = D(i, j);
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					a[i][j] = std::min(a[i][j], std::max(a[i][k], a[k][j]));
		printf("Scenario #%d\n", ++cas);
		printf("Frog Distance = %.3lf\n\n", a[0][1]);
	}
	return 0;
}



Freddy Frog is sitting on a stone in the middle of a lake. 
Suddenly he notices Fiona Frog who is sitting on another stone. 
He plans to visit her, but since the water is dirty and full of tourists’ 
sunscreen, he wants to avoid swimming and instead reach her by jumping.
Unfortunately Fiona’s stone is out of his jump range. 
Therefore Freddy considers to use other stones as intermediate stops and 
reach her by a sequence of several small jumps.
To execute a given sequence of jumps, a frog’s jump range obviously must 
be at least as long as the longest jump occuring in the sequence.
The frog distance (humans also call it minimax distance) between two 
stones therefore is defined as the minimum necessary jump range over all 
possible paths between the two stones.
You are given the coordinates of Freddy’s stone, 
Fiona’s stone and all other stones in the lake. 
Your job is to compute the frog distance between Freddy’s and Fiona’s stone.



Input
The input file will contain one or more test cases. The first line of each 
test case will contain the number of stones n (2 ≤ n ≤ 200). 
The next n lines each contain two integers xi
, yi (0 ≤ xi
, yi ≤ 1000)
representing the coordinates of stone #i. Stone #1 is Freddy’s stone, stone 
#2 is Fiona’s stone, the other n − 2 stones are unoccupied. 
There’s a blank line following each test case. Input is terminated
by a value of zero (0) for n.

Output
For each test case, print a line saying ‘Scenario #x’ and a line saying 
‘Frog Distance = y’ where x
is replaced by the test case number (they are numbered from 1) and y is 
replaced by the appropriate real number, printed to three decimals. 
Put a blank line after each test case, even after the last one.



Sample Input
2
0 0
3 4
3
17 4
19 4
18 5
0

Sample Output
Scenario #1
Frog Distance = 5.000
Scenario #2
Frog Distance = 1.414