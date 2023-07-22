101	The Blocks Problem



#include<cstdio>
#include<cstring>

int main() {
	int t,n, a, b, ax, ay, bx, by,pile[30], position[30][2], block[30][30];
	char action1[10], action2[10];

	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			position[i][0] = i;
			position[i][1] = 0;
			block[i][0] = i;
			pile[i] = 1;
		}
		while (~scanf("%s", action1) && strcmp(action1, "quit")) {
			scanf("%d%s%d", &a, action2, &b);

			ax = position[a][0];
			ay = position[a][1];
			bx = position[b][0];
			by = position[b][1];
			if (ax == bx) 
				continue;
			//printf("ax %d ay %d bx %d by %d\n", ax, ay, bx, by);
			if (!strcmp(action1, "move")) {
				for (int i = ay + 1; i < pile[ax]; i++) {
					position[block[ax][i]][0] = block[ax][i];
					position[block[ax][i]][1] = pile[block[ax][i]];
					block[block[ax][i]][pile[block[ax][i]]++] = block[ax][i];
				//	printf("move block[ax][i] %d\n", block[ax][i]);
				}
				pile [ax] = ay + 1;
			}
			if (!strcmp(action2, "onto")) {
				for (int i = by + 1; i < pile[bx]; i++) {
					position[block[bx][i]][0] = block[bx][i];
					position[block[bx][i]][1] = pile[block[bx][i]];
					block[block[bx][i]][pile[block[bx][i]]++] = block[bx][i];
				//	printf("move2\n");
				}
				pile[bx] = by + 1;
			}
			for (int i = ay; i < pile[ax]; i++) {
				position[block[ax][i]][0] = bx;
				position[block[ax][i]][1] = pile[bx];
				block[bx][pile[bx]++] = block[ax][i];
			//	printf("move3 block[ax][i] %d\n",block[ax][i]);
			}
			pile[ax] = ay;
		}
		for (int i = 0; i < n; i++) {
			printf("%d:", i);
			for (int j = 0; j < pile[i]; j++)
				printf(" %d", block[i][j]);
			printf("\n");
		}
	}
	return 0;
}



#include<cstdio>
#include<cstring>
int main()
{
	int n,a,b,ax,ay,bx,by,p[30][2],block[30][30],pile[30];
	char morp[5], onorov[5];
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			p[i][0] = i;
			p[i][1] = 0;
			block[i][0] = i;
			pile[i] = 1;
		}
		while (~scanf("%s", morp) && strcmp("quit", morp)) {
			scanf("%d %s %d", &a, onorov, &b);
			ax = p[a][0];
			ay = p[a][1];
			bx = p[b][0];
			by = p[b][1];

			if (ax == bx)
				continue;
			if (!strcmp("move", morp)) {
				for (int i = ay + 1; i < pile[ax]; i++) {
					p[block[ax][i]][0] = block[ax][i];
					p[block[ax][i]][1] = pile[block[ax][i]];
					block[block[ax][i]][pile[block[ax][i]]++] = block[ax][i];
				}
				pile[ax] = ay + 1;
			}
			if (!strcmp("onto", onorov)) {
				for (int i = by + 1; i < pile[bx]; i++) {
					p[block[bx][i]][0] = block[bx][i];
					p[block[bx][i]][1] = pile[block[bx][i]];
					block[block[bx][i]][pile[block[bx][i]]++] = block[bx][i];
				}
				pile[bx] = by + 1;
			}

			for (int i = ay; i < pile[ax]; i++) {
				p[block[ax][i]][0] = bx;
				p[block[ax][i]][1] = pile[bx];
				block[bx][pile[bx]++] = block[ax][i];
			}
			pile[ax] = ay;
		}

		for (int i = 0; i < n; i++) {
			printf("%d:", i);
			for (int j = 0; j < pile[i]; j++)
				printf(" %d", block[i][j]);
			puts("");
		}
	}
}

position[i][1] =pile
->get to know that which positoned the number
ex 

position[i][0]=bx
->i is in 1~9, which number belong to i 

block[i][j]
->i is in 1~9 , j is position from left to right.


Background 
Many areas of Computer Science use simple, abstract domains for 
both analytical and empirical studies. For example, 
an early AI study of planning and robotics (STRIPS) used a block 
world in which a robot arm performed tasks involving the 
manipulation of blocks.
In this problem you will model a simple block world under 
certain rules and constraints. Rather than determine how to 
achieve a specified state, you will ``program'' a robotic arm 
to respond to a limited set of commands.

The Problem 
The problem is to parse a series of commands that instruct a 
robot arm in how to manipulate blocks that lie on a flat table. 
Initially there are n blocks on the table (numbered from 0 to n-1)
 with block bi adjacent to block bi+1 for all  
 $0 \leq i < n-1$ as shown in the diagram below:
 
\begin{figure}
\centering
\setlength{\unitlength}{0.0125in} %
\begin{picture}
(2...
...raisebox{0pt}[0pt][0pt]{$\bullet
\bullet \bullet$ }}}
\end{picture}
\end{figure}
Figure: Initial Blocks World

The valid commands for the robot arm that manipulates blocks are:
move a onto b
where a and b are block numbers, puts block a onto block b 
after returning any blocks that are stacked on top of blocks 
a and b to their initial positions.

move a over b
where a and b are block numbers, puts block a onto the top of 
the stack containing block b, after returning any blocks that 
are stacked on top of block a to their initial positions.

pile a onto b
where a and b are block numbers, moves the pile of blocks 
consisting of block a, and any blocks that are stacked above 
block a, onto block b. All blocks on top of block b are moved 
to their initial positions prior to the pile taking place. 
The blocks stacked above block a retain their order when moved.

pile a over b
where a and b are block numbers, puts the pile of blocks 
consisting of block a, and any blocks that are stacked above 
block a, onto the top of the stack containing block b. 
The blocks stacked above block a retain their original order 
when moved.

quit
terminates manipulations in the block world.
Any command in which a = b or in which a and b are in the same 
stack of blocks is an illegal command. All illegal commands 
should be ignored and should have no affect on the configuration 
of blocks.



The Input 

The input begins with an integer n on a line by itself 
representing the number of blocks in the block world. 
You may assume that 0 < n < 25.
The number of blocks is followed by a sequence of block 
commands, one command per line. Your program should process all 
commands until the quit command is encountered.
You may assume that all commands will be of the form specified 
above. There will be no syntactically incorrect commands.



The Output 
The output should consist of the final state of the blocks world.
 Each original block position numbered i ( $0 \leq i < n$ where 
 n is the number of blocks) should appear followed immediately 
 by a colon. If there is at least a block on it, the colon must 
 be followed by one space, followed by a list of blocks that 
 appear stacked in that position with each block number 
 separated from other block numbers by a space. 
 Don't put any trailing spaces on a line.
There should be one line of output for each block position 
(i.e., n lines of output where n is the integer on the first 
line of input).



Sample Input 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 over 5
move 2 over 1
move 4 over 9
quit

Sample Output 
 0: 0
 1: 1 9 2 4
 2:
 3: 3
 4:
 5: 5 8 7 6
 6:
 7:
 8:
 9:

 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
quit

 0: 0
 1: 1 9 8 7 6
 2: 2
 3: 3
 4: 4
 5: 5 
 6:
 7:
 8:
 9:
 
 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
move 8 over 5
quit

 0: 0
 1: 1 9 
 2: 2
 3: 3
 4: 4
 5: 5 8
 6: 6
 7: 7
 8:
 9:
 
 
10
move 9 onto 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 6
pile 8 onto 5
quit

 0: 0
 1: 1 9 
 2: 2
 3: 3
 4: 4
 5: 5 8 7 6
 6: 
 7: 
 8:
 9: