10377 - Maze Traversal
http://blog.csdn.net/mobius_strip/article/details/46772231



#include <cstring>  
#include <cstdio>  

char maps[62][62];
char towards[5] = "NESW";
int  dxy[4][2] = { -1,0, 0,1, 1,0, 0,-1 };
                 //  w    n    e    s
int main()
{
	int  R, C, T, X, Y, F, x, y;
	char command;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d ", &R, &C);
		for (int i = 0; i < R; ++i)
			fgets(maps[i],sizeof(maps),stdin);
		scanf("%d%d", &X, &Y);
		F = 0; X--; Y--;
		while ((command = getchar()) != 'Q') {
			if (command == 'R')
				F = (F + 1) % 4;
			else if (command == 'L')
				F = (F + 3) % 4;
			else if (command == 'F') {
				x = X + dxy[F][0];
				y = Y + dxy[F][1];
				if (x >= 0 && x < R && y >= 0 && y < C && maps[x][y] != '*') 
					X = x,Y = y;
			}
		}
		printf("%d %d %c\n", X + 1, Y + 1, towards[F]);
		if (T) printf("\n");
	}
	return 0;
}



#include<cstdio>
#include<string>
int main() {
	int xy[4][2] = { -1,0,0,1,1,0,0,-1 };
	char maps[62][62];
	char dic[5] = "NESW";
	char C;
	int cas,r,c,x,y,mx,my,F;
	scanf("%d ", &cas);
	while (cas--) {
		scanf("%d %d ", &r, &c);
		for (int i = 0; i < r; i++)
			fgets(maps[i], sizeof(maps), stdin);
		scanf("%d %d ", &mx, &my);
		F = 0, mx--, my--;
		while ((C = getchar()) != 'Q') {
			if (C == 'R')
				F = (F + 1) % 4;
			else if (C == 'L')
				F = (F + 3) % 4;
			else if (C == 'F') {
				x = mx + xy[F][0];
				y = my + xy[F][1];
				if (0 <= x && 0 <= y&&x < r&&y < c&&maps[x][y] != '*')
					mx = x, my = y;
			}
		}
		printf("%d %d %c\n", mx + 1, my + 1, dic[F]);
		if (cas)
			puts("");
	}
	return 0;
}



A common problem in arti cial intelligence is negotiation of a
maze.  A maze has corridors and walls.
The robot can proceed along corridors, 
but cannot go through walls.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases following, 
each of them as described below.  
This line is followed by a blank line, 
and there is also a blank line between two consecutive inputs.
For this problem, you will input the dimensions of a maze, 
as two integer values on the  rst line.
Of the two numbers, the  rst is the number of rows and the 
second is the number of columns.  
Neither the number of rows nor columns will exceed 60.
Following these numbers will be a number of rows, as speci ed 
previously.  In each row there will be a character for each 
column, with the row terminated by the end of line.  
Blank spaces are corridors, asterisks are walls.  
There needn't be any exits from the maze.
Following the maze, will be an initial row and column speci 
ed as two integers on one line.  
This gives the initial position of the robot.  
Initially the robot will be facing North (toward the  rst row).
The remaining input will consist of commands to the robot,
with any amount of interspersed white-space.  
The valid commands are:
R
rotate the robot 90 degrees clockwise (to the right)
L
rotate the robot 90 degrees counter-clockwise (to the left)
F
move the robot forward, unless a wall prevents this, 
in which case do nothing
Q
quit the program, printing out the current robot row, 
column and orientation

Output
For  each  test  case,  the  output  must  follow  the  
description  below.   The  outputs  of  two
consecutive cases will be separated by a blank line.
The  nal row and column must be integers separated by a space.
The orientation must be one of
N
,
W
,
S
,
E
and separated from the column by a space.



SampleInput
1
7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ

SampleOutput
5 6 W

