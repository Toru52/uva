141 - The Spot Game 
http://mypaper.pchome.com.tw/zerojudge/post/1323212514



#include <iostream>
#include <map>
using namespace std;
void rotate(int x[][50], int n) {
	int y[50][50], i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			y[j][n - i - 1] = x[i][j];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			x[i][j] = y[i][j];
}
int main() {
	int n;
	while (scanf("%d", &n), n) {
		map<string, int> r;
		int m = 2 * n, board[50][50] = {}, x, y;
		int flag = -1, move;
		char cmd[3];
		for (int i = 0; i < m; i++) {
			scanf("%d %d %s", &x, &y, cmd);
			if (flag != -1)  continue;
			x--, y--;
			if (cmd[0] == '+')
				board[x][y] = 1;
			else    board[x][y] = 0;
			string s = "";
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					s += (board[j][k] + '0');
			if (r[s] == 1) {
				flag = i & 1;
				move = i;
				continue;
			}
			for (int rr = 0; rr < 4; rr++) {
				string s = "";
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						s += (board[j][k] + '0');//, printf("%d ", board[j][k]);
				r[s] = 1;//record N*N array
				rotate(board, n);
			}
		}
		if (flag == -1)
			puts("Draw");
		else
			printf("Player %d wins on move %d\n", !flag + 1, move + 1);
	}
	return 0;
}



#include<iostream>
#include<map>
using namespace std;
int n;
void rotate(int x[][50]){
	int temp[50][50];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[j][n - i - 1] = x[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 50; j++)
			x[i][j]=temp[i][j];
}
int main() {
	while (scanf("%d", &n),n) {
		map<string, int>r;
		int x, y, board[50][50]{};
		int move, flag = -1;
		char cmd;
		for (int i = 0; i < n * 2; i++) {
			scanf("%d %d %c", &x, &y, &cmd);
			if (flag != -1)continue;
			x--, y--;
			if (cmd == '+')board[x][y] = 1;
			else board[x][y] = 0;
			string s = "";
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					s += (board[j][k] + '0');
			if (r[s] == 1) {
				move = i, flag = i & 1;
				continue;
			}
			for (int ro = 0; ro < 4; ro++) {
				string s = "";
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						s += (board[j][k] + '0');
				r[s] = 1;
				rotate(board);
			}
		}
		if (flag == -1)puts("Draw");
		else printf("Player %d wins on move %d\n",!flag+1,move+1 );
	}
	return 0;
}



/*
ex1
2
1 1 +
->
10
00

01
00

00
01

00
10

2 2 +
->
10
01

01
10

10
01

01
10

2 2 -
->repeated as case 1 
 
1 2 +



ex2
2
1 1 +
->
10
00

01
00

00
01

00
10

2 2 +
->
10
01

01
10

10
01

01
10
1 2 +
->
11
01

01
11

10
11

11
10

2 2 -
->
11
00

01
01

00
11

10
10

->draw
*/


The game of Spot is played on an N N board as shown below for N = 4. 
During the game, alternate players may either place a black counter (spot)
in an empty square or remove one from the board, thus producing a variety 
of patterns. If a board pattern (or its rotation by 90 degrees or 180 
degrees) is repeated during a game, the player producing that pattern 
loses and the other player wins. 
The game terminates in a draw after 2N moves if no duplicate pattern is 
produced before then. Consider the following patterns:
If the first pattern had been produced earlier, then any of the following 
three patterns (plus one other not shown) would terminate the game, 
whereas the last one would not.



Input
Input will consist of a series of games, each consisting of the size of 
the board, N (2  N  50) followed, on separate lines, by 2N moves, 
whether they are all necessary or not. Each move will consist of the 
coordinates of a square (integers in the range 1::N) followed by a blank 
and a character ‘+’ or ‘-’ indicating the addition or removal of a spot 
respectively. You may assume that all moves are legal, 
that is there will never be an attempt to place a spot on an occupied 
square, nor to remove a non-existent
spot. Input will be terminated by a zero (0).

Output
Output will consist of one line for each game indicating which player won 
and on which move, or that game ended in a draw. 
See the Sample Output below for the exact format



Sample Input
2
1 1 +
2 2 +
2 2 -
1 2 +
2
1 1 +
2 2 +
1 2 +
2 2 -
0
Sample Output
Player 2 wins on move 3
Draw