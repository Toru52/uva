10500 - Robot maps
http://mypaper.pchome.com.tw/zerojudge/post/1323951256




#include <stdio.h>
#include <string.h>
int n, m, move;
int dir[4][2] = {  -1,0 , 0,1 , 1,0 , 0,-1  };
char s[3], g[20][20], used[20][20];

int color(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m||used[x][y] == 1)
		return 0;
	used[x][y] = 1;
	return 1;
}
void dfs(int x, int y) {
	int tx, ty;
	move++;
	for (int i = 0; i < 4; i++) {
		tx = x + dir[i][0], ty = y + dir[i][1];
		if (color(tx, ty) == 1 && g[tx][ty] == '0') {
			dfs(tx, ty);
			break;
		}
	}
	color(x + 1, y);color(x - 1, y);color(x, y + 1);color(x, y - 1);
}
void printLine(int n) {
	putchar('|');
	for (int i = 0; i < n; i++)
		printf("---|");
	puts("");
}
int main() {
	int x,y;
	while (scanf("%d %d", &n, &m) == 2 && n) {
		scanf("%d %d", &x, &y);
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				scanf("%s", s),g[i][j] = s[0];	
		x--, y--;  move = 0;  used[x][y] = 1;	
		dfs(x, y);
		puts("");
		for (int i = 0; i < n; i++) {
			printLine(m);
			putchar('|');
			for (int j = 0; j < m; j++) {
				putchar(' ');
				if (used[i][j])
					putchar(g[i][j]);
				else
					putchar('?');
				printf(" |");
			}
			puts("");
		}
		printLine(m);
		puts("");
		printf("NUMBER OF MOVEMENTS: %d\n", move - 1);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int n, m, move;
int xy[4][2] = { -1,0, 0,1, 1,0, 0,-1 };
char s[3], map[20][20], used[20][20];
int che(int x, int y) {
	if (x < 0 || y < 0 || n <= x || m <= y || used[x][y] == 1)
		return 0;
	used[x][y] = 1;
	return 1;
}
void dfs(int x, int y) {
	int nx, ny;
	move++;
	for (int i = 0; i < 4; i++) {
		nx = x + xy[i][0], ny = y + xy[i][1];
		if (che(nx, ny) == 1 && map[nx][ny] == '0') {
			dfs(nx, ny);
			break;
		}
	}
	che(x - 1, y), che(x + 1, y), che(x, y - 1), che(x, y + 1);
}
void line() {
	putchar('|');
		for (int i = 0; i < m; i++)
			printf("---|");
	puts("");
}
int main() {
	int x, y;
	while(scanf("%d %d",&n,&m),n!=0){
		memset(used, 0,sizeof(used));
		scanf("%d %d", &x, &y);
		move = 0; x--, y--; used[x][y] = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%s", s), map[i][j] = s[0];
		dfs(x, y);
		puts("");
		for (int i = 0; i < n; i++) {		
			line();
			putchar('|');
			for (int j = 0; j < m; j++) {			
				if (used[i][j])
					printf(" %c |", map[i][j]);
				else
					printf(" ? |");
			}
			puts("");
		}
		line();
		puts("");
		printf("NUMBER OF MOVEMENTS: %d\n", --move);
	}
	return 0;
}





The ACM factory produces and stores very dangerous products. 
This is why no human operator is allowed to enter the store room 
and only specialised robots can access the place to store new 
products or to retrieve them for their sell. The ACM factory is 
testing a movil robot which is able to build a partial map of 
the continuously changing environment of the store.
The robot can be initially placed at any position of the store. 
Before starting moving, the robot
initialises every cell of its map as a `
?
', which means `
unknowncell
'. In the beginning, the robot knows
that its starting cell is empty and records this information 
into its map. Then, the robot reads its four
sensors, which will return the state (`
X
' if occupied, `
0
' if empty) of the four cells around it: NORTH,
EAST, SOUTH, WEST. This information is properly recorded in the 
robot's map. Then it will move
to the  rst

unvisited free cell and repeat the process until it can not move 
any further because all the
cells around it are occupied or have already been visited. 
Then the robot outputs its partial map of
the store.
(

) The order used by the robot to select its movements is 
clockwise, starting from the North orientation.

Input
The input  le consists of a series of sets each containig 2 +
N
lines. First line speci es the size of the
map, i.e. two integers
N
and
M
separated by one space, where 0
<N

10 and 0
<M

10. The
second line speci es the starting point of the robot in the map, 
i.e. two integers
x
ini
and
y
ini
separated
by one space, where 1

x
ini

N
and 1

y
ini

M
. In each of the next
N
lines there must be
M
characters `
X
' or `
0
' separated by one space, where `
X
' represents obstacles and `
0
' represents empty
squares. The map must be a correct one, which means the initial 
position of the robot must be always an empty cell. 
The end of the  le is reached the size of the next map is
N
= 0 and
M
= 0.
Output
The application outputs an empty line, followed by the robot map,
an empty line, and a line containing a message of the movements 
needed to reach that map.
The robot map must be shown using the next format (
s
2f
`
X
', `
0
', `
?
'
g
):
|---|$---| ... M ... |---|
| s |$ s | ... M ... | s |
|---|$---| ... M ... |---|
| s |$ s | ... M ... | s |
|---|$---| ... M ... |---|
... N ...
|---|$---| ... M ... |---|
| s |$ s | ... M ... | s |
|---|$---| ... M ... |---|



SampleInput
5 5
1 3
X X 0 0 X
X X 0 0 X
X 0 X 0 X
X 0 0 0 X
X X X X X
5 5
1 1
0 0 X X X
X X 0 0 X
X 0 0 0 X
X 0 0 0 X
X X X X X
0 0

SampleOutput
|---|---|---|---|---|
| ? | X | 0 | 0 | X |
|---|---|---|---|---|
| ? | X | 0 | 0 | X |
|---|---|---|---|---|
| X | 0 | X | 0 | X |
|---|---|---|---|---|
| X | 0 | 0 | 0 | X |
|---|---|---|---|---|
| ? | X | X | X | ? |
|---|---|---|---|---|
NUMBER OF MOVEMENTS: 7
|---|---|---|---|---|
| 0 | 0 | X | ? | ? |
|---|---|---|---|---|
| X | X | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|
| ? | ? | ? | ? | ? |
|---|---|---|---|---|
NUMBER OF MOVEMENTS: 1