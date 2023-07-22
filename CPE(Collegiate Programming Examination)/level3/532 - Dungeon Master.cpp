532 - Dungeon Master
http://programming-study-notes.blogspot.tw/2014/02/uva-532-dungeon-master.html



#include <stdio.h>
#include <queue>
using namespace std;
char m[32][32][32];
int L, R, C,dis[32][32][32];
//x->N,S   y->E,W z->U,D
const int dir[6][3] = {-1,0,0, 1,0,0 , 0,-1,0 , 0,1,0 , 0,0,-1 , 0,0,1};
struct D {int x,y,z;};
int BFS(int i, int j, int k){
	dis[i][j][k] = 0;
	queue<D> q;
	q.push(D{ i,j,k });
	m[i][j][k] = '#';
	D u, v;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i) {
			v.x = u.x + dir[i][0],v.y = u.y + dir[i][1],v.z = u.z + dir[i][2];
			if (v.x<0 || v.x >= L || v.y<0 || v.y >= R || v.z<0 || v.z >= C) 
				continue;
			if (m[v.x][v.y][v.z] != '#') {
				dis[v.x][v.y][v.z] = dis[u.x][u.y][u.z] + 1;
				if (m[v.x][v.y][v.z] == 'E')
					return dis[v.x][v.y][v.z];
				m[v.x][v.y][v.z] = '#';
				q.push(v);
			}
		}
	}
	return -1;
}
int main()
{
	while (scanf("%d%d%d", &L, &R, &C),L+R+C) {
		int si, sj, sk;
		for (int i = 0; i < L; ++i) 
			for (int j = 0; j < R; ++j) {
				scanf("%s", m[i][j]);
				for (int k = 0; k < C; ++k)
					if (m[i][j][k] == 'S') 
						si = i,sj = j,sk = k;
			}
		int move = BFS(si, sj, sk);
		if (move != -1)
			printf("Escaped in %d minute(s).\n", move);
		else puts("Trapped!");
	}
	return 0;
}



#include<stdio.h>
#include<queue>
using namespace std;
int L, R, C, si, sj, sk, dis[32][32][32];
int dir[6][3] = { -1,0,0, 1,0,0, 0,-1,0, 0,1,0, 0,0,-1, 0,0,1 };
char m[32][32][32];
struct D { int x, y, z; };
int bfs() {
	m[si][sj][sk] = '#';
	dis[si][sj][sk] = 0;
	queue<D>q;
	q.push(D{ si,sj,sk });
	D u, v;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {
			v.x = u.x + dir[i][0], v.y = u.y + dir[i][1], v.z = u.z + dir[i][2];
			if (v.x < 0 || L <= v.x || v.y < 0 || R <= v.y || v.z < 0 || C <= v.z)
				continue;
			if (m[v.x][v.y][v.z] != '#') {
				dis[v.x][v.y][v.z] = dis[u.x][u.y][u.z] + 1;
				if (m[v.x][v.y][v.z] == 'E')
					return dis[v.x][v.y][v.z];
				m[v.x][v.y][v.z] = '#';
				q.push(v);
			}
		}
	}
	return -1;
}
int main() {
	while (scanf("%d %d %d", &L, &R, &C), L + R + C) {
		for(int i=0;i<L;i++)
			for (int j = 0; j < R; j++) {
				scanf("%s", m[i][j]);
				for (int k = 0; k < C; k++)
					if (m[i][j][k] == 'S')
						si = i, sj = j, sk = k;
			}
		int move = bfs();
		if (move != -1)
			printf("Escaped in %d minute(s).\n", move);
		else
			puts("Trapped!");
	}
	return 0;
}



/*
ex
3 4 5

3F
S....
.###.
.##..
###.#

2F
#####
#####
##.##
##...

1F
#####
#####
#.###
####E


1 3 3
S##
#E#
###
*/
You are trapped in a 3D dungeon and need to find the quickest way out! 
The dungeon is composed of unit cubes which may or may not be filled 
with rock. It takes one minute to move one unit north,
south, east, west, up or down. You cannot move diagonally and 
the maze is surrounded by solid rock on all sides.
Is an escape possible? If yes, how long will it take?



Input
The input file consists of a number of dungeons. Each dungeon 
description starts with a line containing three integers L, R and C 
(all limited to 30 in size).
L is the number of levels making up the dungeon.
R and C are the number of rows and columns making up the plan of each 
level.
Then there will follow L blocks of R lines each containing C 
characters. Each character describes one cell of the dungeon. 
A cell full of rock is indicated by a ‘#’ and empty cells are 
represented by a ‘.’. Your starting position is indicated by ‘S’ and 
the exit by the letter ’E’. There’s a single blank line
after each level. Input is terminated by three zeroes for L, R and C.

Output
Each maze generates one line of output. If it is possible to reach the 
exit, print a line of the form Escaped in x minute(s).
where x is replaced by the shortest time it takes to escape.
If it is not possible to escape, print the line Trapped!



Sample Input
3 4 5
S....
.###.
.##..
###.#


#####
#####
##.##
##...


#####
#####
#.###
####E


1 3 3
S##
#E#
###

1 3 3
E##
#S#
###

0 0 0

Sample Output
Escaped in 11 minute(s).
Trapped!