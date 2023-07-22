11550 - Demanding Dilemma
https://github.com/morris821028/UVa/blob/master/volume115/11550%20-%20Demanding%20Dilemma.cpp

graph theorical
http://mathtrain.jp/graph
incidence matrix
https://wwws.kobe-c.ac.jp/deguchi/c/tree/graph0.html
http://www.robot.t.u-tokyo.ac.jp/asamalab/lectures/lecture4/files/optimization111215prn.pdf#search=%27incidence+matrix+%E8%A1%8C%E5%88%97%27
http://mathworld.wolfram.com/IncidenceMatrix.html



#include <stdio.h>

int main() {

	int t,n, m,vg[10][100];

	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &vg[i][j]);
		int g[10][10]{}, err = 0, x, y;
		for (int i = 0; i < m && !err; i++) {//from left to top
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (vg[j][i]) {//from top to bottom
					if (cnt == 0)    x = j;
					else            y = j;
					cnt++;
				}
			}
			if (cnt != 2)    err = 1;
			else {
				if (g[x][y]) err = 1;//no duplicate
				g[x][y] = g[y][x] = 1;
			}
		}
		puts(err ? "No" : "Yes");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int t, m, n, vg[10][100];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &vg[i][j]);
		int g[10][10]{}, yes = 1, x, y;
		for (int i = 0; i < n&&yes; i++) {
			int cnt = 0;
			for (int j = 0; j < m; j++) 
				if (vg[j][i]) {
					if (cnt == 0)
						x = j;
					else
						y = j;
					cnt++;
				}
			if (cnt != 2)
				yes = 0;
			else
				if (g[x][y])
					yes = 0;
				else
					g[x][y] = g[y][x] = 1;
		}
		puts((yes == 1) ? "Yes" : "No");
	}
	return 0;
}



/*
ex 
M(incidence matrix)

1 1 0
0 1 1
1 0 1

1
0
1
->1 3

1
1
0
->1 2

0
1
1
->2 3

->yes

M
1
1
0
->1 2

->yes

M
1 1 0
1 1 1
1 0 0

1
1
1
->1 2 3 (No incidence matrix)

1
1
0
->1 2

0
1
0
->2 (No incidence matrix)
*/


A simple undirected graph is an ordered pair G = (V;E) 
where V is a non-empty set of vertices, and
E is a set of unordered pairs (u; v) where u and v are in V and 
u ̸= v. If S is a set, dene jSj as the size of S.
An incidence matrix M is a jV jjEj matrix where M(i; j) is 1 
if edge j is incident to vertex i (edge j is either (i; u) or (u; i))
and 0 otherwise.
Given an n  m matrix, can it be an incidence matrix of a simple 
undirected graph G = (V;E) where jV j = n and jEj = m?



Input
The rst line of the input contains an integer t (1  t  41),
 the number of test cases.
Each test case starts with a line with two integers n 
(1  n  8) and m (0  m  n(n 􀀀 1)=2).
Then n lines containing m integers (0's or 1's) each follow such 
that the j-th number on the i-th line is M(i; j).

Output
For each test case print `Yes' if the incidence matrix given in the
input can be an incidence matrix of
some simple undirected graph, otherwise print `No'.



Sample Input
3
3 3
1 1 0
0 1 1
1 0 1
3 1
1
1
0
3 3
1 1 0
1 1 1
1 0 0

Sample Output
Yes
Yes
No