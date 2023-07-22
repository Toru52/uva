10443 - Rock 
http://blog.csdn.net/mobius_strip/article/details/48540837



#include <cstring>  
#include <cstdio>  

int main()
{
	char maps[101][101],temp[101][101];
	int  dxy[4][2] = { 0,1, 1,0, -1,0, 0,-1 };
	int t, n, m, d;
	while (~scanf("%d", &t))
		while (t--) {
			scanf("%d%d%d", &n, &m, &d);
			for (int i = 0; i < n; ++i)
				scanf("%s", maps[i]);

			for (int k = 0; k < d; ++k) {
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						temp[i][j] = maps[i][j];

				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						for (int p = 0; p < 4; ++p) {
							int x = i + dxy[p][0];
							int y = j + dxy[p][1];
							if (x < 0 || x >= n || y < 0 || y >= m)
								continue;
							if (maps[x][y] == 'S' && maps[i][j] == 'P')
								temp[i][j] = 'S';
							if (maps[x][y] == 'P' && maps[i][j] == 'R')
								temp[i][j] = 'P';
							if (maps[x][y] == 'R' && maps[i][j] == 'S')
								temp[i][j] = 'R';
						}
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						maps[i][j] = temp[i][j];
			}
			for (int i = 0; i < n; ++i)
				puts(maps[i]);
			if (t) puts("");
		}
	return 0;
}



#include<cstdio>
#include<cstring>
using namespace std;
int main() {
	int N, r, c,n;
	char maps[105][105], temp[105][105];
	int xy[4][2] = { 0,1 ,1,0, 0,-1, -1,0 };
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d %d", &r, &c, &n);
		for (int i = 0; i < r; i++)
			scanf("%s", &maps[i]);
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					temp[i][j] = maps[i][j];
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					for (int p = 0; p < 4; p++) {
						int x = i + xy[p][0];
						int y = j + xy[p][1];
						if (x < 0 || y < 0 || r <= x || c <= y)
							continue;
						if (maps[x][y] == 'R'&&maps[i][j] == 'S')
							temp[i][j] = 'R';
						if (maps[x][y] == 'S'&&maps[i][j] == 'P')
							temp[i][j] = 'S';
						if (maps[x][y] == 'P'&&maps[i][j] == 'R')
							temp[i][j] = 'P';
					}
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					maps[i][j] = temp[i][j];
		}
		for (int i = 0; i < r; i++)
			puts(maps[i]);
		if (N)
			puts("");
	}
	return 0;
}



Bart's sister Lisa has created a new civilization on a two-
dimensional grid. At the outset each grid location may be oc-
cupied by one of three life forms:
Rocks
,
Scissors
, or
P apers
.
Each day, differing life forms occupying horizontally or ver-
tically adjacent grid locations wage war. In each war, Rocks
always defeat Scissors, Scissors always defeat Papers, and Pa-
pers always defeat Rocks. At the end of the day, the victor
expands its territory to include the loser's grid position. The
loser vacates the position.
Your job is to determine the territory occupied by each
life form after
n
days.
Input
The  rst line of input contains
t
, the number of test cases.
Each test case begins with three integers not greater than
100:
r
and
c
, the number of rows and columns in the grid,
and
n
. The grid is represented by the
r
lines that follow, each
with
c
characters. Each character in the grid is `
R
', `
S
', or `
P
',
indicating that it is occupied by Rocks, Scissors, or Papers 
respectively.

Output
For each test case, print the grid as it appears at the end of the
n-th day. Leave an empty line between
the output for successive test cases.



SampleInput
2
3 3 1
RRR
RSR
RRR
3 4 2
RSPR
SPRS
PRSP

SampleOutput
RRR
RRR
RRR
RRRS
RRSP
RSPR