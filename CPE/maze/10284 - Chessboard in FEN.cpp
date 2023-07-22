10284 - Chessboard in FEN
http://mypaper.pchome.com.tw/zerojudge/post/1325080676


#include <stdio.h>
#include <string.h>
void FEN(char s[], char g[][8]) {
	int row = 0, column = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '/')
			row++, column = 0;
		else if (s[i] >= '0' && s[i] <= '9') 
			while (s[i] > '0') {
				g[row][column] = ' ', column++;
				s[i]--;
			}
		else
			g[row][column] = s[i], column++;
	}
}
void color(int x, int y, char c, int attack[][8], char g[][8]) {
	if (c == 'p') {
		if (x + 1 < 8 && y + 1 < 8)
			attack[x + 1][y + 1] = 1;
		if (x + 1 < 8 && y - 1 >= 0)
			attack[x + 1][y - 1] = 1;
		return;
	}
	if (c == 'P') {
		if (x - 1 >= 0 && y + 1 < 8)
			attack[x - 1][y + 1] = 1;
		if (x - 1 >= 0 && y - 1 >= 0)
			attack[x - 1][y - 1] = 1;
		return;
	}
	c |= 32;
	int dx[] = { 0,0,1,-1,1,1,-1,-1 };
	int dy[] = { 1,-1,0,0,1,-1,1,-1 };
	int tx, ty;
	if (c == 'n') {
		int ddx[] = { 2,2,-2,-2,1,1,-1,-1 };
		int ddy[] = { 1,-1,1,-1,2,-2,2,-2 };
		for (int i = 0; i < 8; i++) {
			tx = x + ddx[i], ty = y + ddy[i];
			if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8)
				continue;
			attack[tx][ty] = 1;
		}
		return;
	}
	if (c == 'b') {
		for (int i = 4; i < 8; i++) {
			tx = x + dx[i], ty = y + dy[i];
			while (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
				if (g[tx][ty] != ' ')    break;
				attack[tx][ty] = 1;
				tx = tx + dx[i], ty = ty + dy[i];
			}
		}
		return;
	}
	if (c == 'r') {
		for (int i = 0; i < 4; i++) {
			tx = x + dx[i], ty = y + dy[i];
			while (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
				if (g[tx][ty] != ' ')    break;
				attack[tx][ty] = 1;
				tx = tx + dx[i], ty = ty + dy[i];
			}
		}
		return;
	}
	if (c == 'q') {
		for (int i = 0; i < 8; i++) {
			tx = x + dx[i], ty = y + dy[i];
			while (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
				if (g[tx][ty] != ' ')    break;
				attack[tx][ty] = 1;
				tx = tx + dx[i], ty = ty + dy[i];
			}
		}
		return;
	}
	if (c == 'k') {
		for (int i = 0; i < 8; i++) {
			tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= 8 || ty >= 8)
				continue;
			attack[tx][ty] = 1;
		}
		return;
	}
}
int main() {
	char s[999], g[8][8];

	while (scanf("%s", s) == 1) {
		char g[8][8] = {};
		FEN(s, g);
		int attack[8][8] = {};
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (g[i][j] != ' ')
					color(i, j, g[i][j], attack, g);
			}
		}
		int ret = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (g[i][j] == ' ' && attack[i][j] == 0)
					ret++;
		printf("%d\n", ret);
	}
	return 0;
}



In the
FEN
(Forsyth-Edwards Notation), a chessboard is described as follows:

The Board-Content is speci ed starting with the top row and ending 
with the bottom row.

Character `
/
' is used to separate data of adjacent rows.

Each row is speci ed from left to right.

White pieces are identi ed by uppercase piece letters:
PNBRQK
.

Black pieces are identi ed by lowercase piece letters:
pnbrqk
.

Empty squares are represented by the numbers one through eight.

A number used represents the count of contiguous empty squares along a 
row.

Each row's sum of numbers and characters must equal 8.
As for example:
5k1r/2q3p1/p3p2p/1B3p1Q/n4P2/6P1/bbP2N1P/1K1RR3
,
is the
FEN
notation description of the following chessboard:
The chessboard of the beginning of a chess game is described in
FEN
as:
rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR
Your task is simple:  given a chessboard description in a
FEN
notation you are asked to compute
the number of unoccupied squares on the board which are not attacked 
by any piece.



Input
Input is a sequence of lines, each line containing a
FEN
description of a chessboard.  Note that the
description does not necessarily give a legal chess position.  
Input lines do not contain white space.

Output
For  each line  of  input,  output  one  line  containing an  
integer which  gives the  number  of  unoccupied
squares which are not attacked.



SampleInput
5k1r/2q3p1/p3p2p/1B3p1Q/n4P2/6P1/bbP2N1P/1K1RR3
rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR

SampleOutput
3
16