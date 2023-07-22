11352 - Crazy King
http://blog.csdn.net/mobius_strip/article/details/50393877



#include <cstring>  
#include <cstdio>  

char maps[101][101];
int  dxy[8][2] = { -2,-1, -2,1, 2,-1, 2,1, -1,-2, -1,2, 1,-2, 1,2 };
int  Dxy[8][2] = { -1,-1,-1,0,-1,1,1,-1,1,0,1,1,0,-1,0,1 };
int  Q[10001], S[10001];

int bfs(int sx, int sy, int n, int m)
{
	if (sx < 0 || sy < 0) return 0;
	int move = 0, save = 1;
	Q[0] = sx * 100 + sy;
	while (move < save) {
		int now = Q[move++];
		//printf("now %d move %d\n", now,move-1);
		for (int k = 0; k < 8; ++k) {
			int x = now / 100 + Dxy[k][0];
			int y = now % 100 + Dxy[k][1];
			
			if (x >= 0 && x < n && y >= 0 && y < m) {
				if (maps[x][y] == 'B') 
					return S[move - 1] + 1;
				if (maps[x][y] == '.') {
					//printf("(%d,%d) save %d\n", x, y,save);
					maps[x][y] = 'X';
					Q[save] = 100 * x + y;//Q->(x,y position (100~ high position 0~width position))
					S[save] = S[move - 1] + 1;//dp(step count)
				    //printf("Q[%d]=%d S[%d]=%d\n", save, Q[save], save, S[save]);
					save++;
				}
			}
		}
	}
	return 0;
}

int main()
{
	int t, n, m;
	while (~scanf("%d", &t))
		while (t--) {
			scanf("%d%d", &n, &m);
			for (int i = 0; i < n; ++i)
				scanf("%s", maps[i]);

			int s_x = -1, s_y = -1;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					if (maps[i][j] == 'A') 
						s_x = i, s_y = j;
					if (maps[i][j] != 'Z') 
						continue;
					for (int k = 0; k < 8; ++k) {
						if (i + dxy[k][0] < 0 || i + dxy[k][0] >= n) continue;
						if (j + dxy[k][1] < 0 || j + dxy[k][1] >= m) continue;
						if (maps[i + dxy[k][0]][j + dxy[k][1]] == '.')
							maps[i + dxy[k][0]][j + dxy[k][1]] = 'X';
					}
				}
			int step = bfs(s_x, s_y, n, m);
			if (step)
				printf("Minimal possible length of a trip is %d\n", step);
			else printf("King Peter, you can't go now!\n");
		}
	return 0;
}



#include<cstdio>
#include<cstring>
char maps[101][101];
int p[10001], s[10001];
int kxy[8][2] = { -1,-1, -1,0, -1,1, 0,1, 1,1, 1,0, 1,-1, 0,-1 };
int zxy[8][2] = {-2,1, -2,-1, -1,2, -1,-2, 1,2, 1,-2, 2,1, 2,-1};
int bfs(int sx, int sy, int n, int m) {
	if (sx < 0 || sy < 0)
		return 0;
	int move = 0, save = 1;
	p[0] = sx * 100 + sy;
	while (move < save) {
		int now = p[move++];
		for (int k = 0; k < 8; k++) {
			int x = now / 100 + kxy[k][0], y = now % 100 + kxy[k][1];
			if (0 <= x&&x < n && 0 <= y&&y < m) {
				if (maps[x][y] == 'B')
					return s[move - 1] + 1;
				if (maps[x][y] == '.') {
					maps[x][y] = 'X';
					p[save] = x * 100 + y;
					s[save] = s[move - 1] + 1;
					save++;
				}
			}
		}
	}
	return 0;
}
int main() {
	int t, n, m;
	while (~scanf("%d", &t)) {
		while (t--) {
			int sx = -1, sy = -1;
			scanf("%d %d", &n, &m);
			for (int i = 0; i < n; i++)
				scanf("%s", &maps[i]);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++) {
					if (maps[i][j] == 'A')
						sx = i, sy = j;
					if (maps[i][j] != 'Z')continue;
					for (int k = 0; k < 8; k++) {
						int x = i + zxy[k][0], y = j + zxy[k][1];
						if (x < 0 || n <= x)continue;
						if (y < 0 || m <= y)continue;
						if (maps[x][y] == '.')
							maps[x][y] = 'X';
					}
				}
			int steps = bfs(sx, sy, n, m);
			if (steps)printf("Minimal possible length of a trip is %d\n", steps);
			else puts("King Peter, you can't go now!");
		}
	}
	return 0;
}




King Peter lives in kingdom A, and his daughter in kingdom B. 
King recieved a letter telling that her daughter gave birth to 
a child. King is incredibly curious to see his grandchild! 
Unfortunately that`s not gonna be that easy.
Kingdoms A and B are separated by a forest. 
There are lots of enemies in the forest, 
and King is not that curious to see them. 
If they attack king on his way to kingdom B, 
then he will never ever see his grandchild and daughter again 
because of lethal consequences.
Security Council of the King disposes information about location 
of the enemies, which makes the things easier for king. 
For some unknown reason a forest is M  N chessboard. 
(M is the number of rows, and N is the number of columns). 
N;M  100 are positive integers.
Enemies of the King can ride horses as showed in the picture. 
Usually horses ride (or jump) that way in Chess. 
Unfortunately king can't take an airplane from point A to point B 
because it is not invented yet. So he moves the same way as chess-king 
does (refer to picture for details).
King can`t move to a square X, if a horse of the enemy is on that 
square. While the king is moving
horses are not, but if at least one horse can reach square X 
in one move, then king can't move to that
square (except for the case when square X is either kingdom A or B).
You are the chief of Electronic Intelligence dapartment of kingdom A 
(by the way the computers are already invented). 
And you`re asked to nd the length of the shortest route L from 
kingdom A to B, as king can`t wait any longer.



Input
The rst line of input contains the number of tests T  100. 
The rst line of each test contains 2
numbers M and N. Then M lines follow each containing N symbols 
from the set S = f`.', `Z', `A', `B'g. `.' means that square is not 
occupied. `Z' | horse occupies that square. `A' | kingdom A, `B'
| kingdom B. Each test contains exactly one kingdom A and B.

Output
Find number L for each test and print line `Minimal possible length 
of a trip is L' if King can reach kingdom B. Replace L with 
corresponding number. If King can`t safely reach the kingdom B
print line `King Peter, you can't go now!'.



Sample Input
4
5 5
.Z..B
..Z..
Z...Z
.Z...
A....
3 2
ZB
.Z
AZ
6 5
....B
.....
.....
..Z..
.....
A..Z.
3 3
ZZ.
...
AB.

Sample Output
King Peter, you can't go now!
Minimal possible length of a trip is 2
King Peter, you can't go now!
Minimal possible length of a trip is 1

