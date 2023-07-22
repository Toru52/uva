 10196 - Check The Check 
http://mypaper.pchome.com.tw/zerojudge/post/1322192665
 
 concept
 http://www.it610.com/article/1826512.htm
 
 
 
#include<stdio.h>
char Map[8][9];
int bkx, bky, wkx, wky;
                //Rook                   //bishop
				                         //whitepawn   //black pawn
int K[8][2] = { 0,1, 0,-1, 1,0, -1,0    ,1,1, 1,-1,    -1,1 , -1,-1 };
int S[8][2] = {2,1 ,2,-1 ,-2,1 ,-2,-1 ,1,2, 1,-2 ,-1,2, -1,-2 };
int find(int x, int y, int Dx, int Dy, int w, int a) {
	int t = 1;
	do {
		//if maps[x][y]=='.' ->repeat
		if (Map[x][y] != '.') {
			//upper(0) or lower(1)
			int p = (Map[x][y] >= 'a');
			//White must to use upper , otherwise return
			//black same as white
			if (p != w) return 0;
			else {
				//upper->state lower->upper
				int tp = Map[x][y] - p * ('a' - 'A');
				
				switch (tp) {
				case 'P': {if (w == 0) {//lower(white pawn)#white is bottom
					if ((a == 4 || a == 5) && t == 1)
						return 1;
				}
						  else {//upper #black is top
							  if ((a == 6 || a == 7) && t == 1)
								  return 1;
						  }
				}break;
				case 'R':if (a < 4) return 1; break;
				case 'B':if (a > 3) return 1; break;
				case 'Q':return 1; break;
				}
				return 0;
			}
		}
		x += Dx, y += Dy, t++;
	} while (x >= 0 && y >= 0 && x < 8 && y < 8);
	return 0;
}
int Check(int x, int y, int who) {
	if (bkx < 0 || wkx < 0) return 0;
	int r = 0;
	for (int i = 0; i < 8; i++) {
		r = find(x + K[i][0], y + K[i][1], K[i][0], K[i][1], who, i);
		if (r) break;
	}
	for (int i = 0; i< 8; i++) {
		int xx = x + S[i][0], yy = y + S[i][1];
		if (xx < 0 || xx > 7 || yy < 0 || yy > 7) continue;
		if (Map[xx][yy] == 'n' || Map[xx][yy] == 'N') {
			int p = Map[xx][yy] == 'n';//white or black
			if (p == who) return 1;
		}
	}
	return r;
}
int main() {
	int cas = 0;
	while (1) {
		char flag = 1;
		int bkx = -1, bky = -1, wkx = -1, wky = -1;
		for (int i = 0; i < 8; i++) {
			scanf("%s", &Map[i]);
			for (int j = 0; j < 8; j++) {
				if (Map[i][j] != '.') flag = 0;
				if (Map[i][j] == 'k') bkx = i, bky = j;
				if (Map[i][j] == 'K') wkx = i, wky = j;
			}
		}
		if (flag == 1) break;
		printf("Game #%d: ", ++cas);
		if (Check(wkx, wky, 1))
			puts("white king is in check.");
		else if (Check(bkx, bky, 0))
			puts("black king is in check.");
		else puts("no king is in check.");
	}
	return 0;
}



#include<stdio.h>
char Map[8][9];
int K[8][2] = { 0,1, 0,-1, 1,0, -1,0    ,1,1, 1,-1,    -1,1 , -1,-1 };
int S[8][2] = { 2,1 ,2,-1 ,-2,1 ,-2,-1 ,1,2, 1,-2 ,-1,2, -1,-2 };
int find(int x, int y, int Dx, int Dy, int w, int a) {
	int t = 1;
	do {
		if (Map[x][y] != '.') {
			int p = (Map[x][y] >= 'a');
			if (p != w) return 0;
			else {
				int tp = Map[x][y] - p * ('a' - 'A');
				switch (tp) {
				case 'P': {
					if ((w == 0&&(a == 4 || a == 5) && t == 1)
						||(w!=0&&(a == 6 || a == 7) && t == 1))
							return 1;
				}break;
				case 'R':if (a < 4) return 1; break;
				case 'B':if (a > 3) return 1; break;
				case 'Q':return 1; break;
				}
				return 0;
			}
		}
		x += Dx, y += Dy, t++;
	} while (x >= 0 && y >= 0 && x < 8 && y < 8);
	return 0;
}
int Check(int x, int y, int who) {
	for (int i = 0; i < 8; i++) 
		if(find(x + K[i][0], y + K[i][1], K[i][0], K[i][1], who, i))
			return 1;
	for (int i = 0; i< 8; i++) {
		int xx = x + S[i][0], yy = y + S[i][1];
		if (xx < 0 || xx > 7 || yy < 0 || yy > 7) continue;
		if (Map[xx][yy] == 'n' || Map[xx][yy] == 'N') {
			int p = Map[xx][yy] == 'n';//white or black
			if (p == who) return 1;
		}
	}
	return 0;
}
int main() {
	int cas = 0;
	while (1) {
		char flag = 1;
		int bkx = -1, bky = -1, wkx = -1, wky = -1;
		for (int i = 0; i < 8; i++) {
			scanf("%s", &Map[i]);
			for (int j = 0; j < 8; j++) {
				if (Map[i][j] != '.') flag = 0;
				if (Map[i][j] == 'k') bkx = i, bky = j;
				if (Map[i][j] == 'K') wkx = i, wky = j;
			}
		}
		if (flag == 1) break;
		printf("Game #%d: ", ++cas);
		if (Check(wkx, wky, 1))
			puts("white king is in check.");
		else if (Check(bkx, bky, 0))
			puts("black king is in check.");
		else puts("no king is in check.");
	}
	return 0;
}



Your task is to write a program that reads a chess board conguration and 
answers if there's a king under attack (i.e. \in check"). 
A king is in check if it's in a square which is attacked by an oponnet's
piece (i.e. it's in square which can be taken by an oponnet's piece in his 
next move).
White pieces will be represented by uppercase letters whereas black pieces 
will be represented by lowercase letters. White side will always be on the 
bottom of the board and black side will always be on the top of the board.
For those unfamiliar with chess, here are the movements of each piece:
Pawn (p or P): can only move straight ahead, one square at a time. 
But it takes pieces diagonally
(and that's what concerns to you in this problem).
Knight (n or N) : have a special movement and 
it's the only piece that can jump over other pieces.
The knight movement can be viewed as an \L". See the example bellow.
Bishop (b or B) : can move any number of squares diagonally 
(forward or backward).
Rook (r or R) : can move any number of squares vertically or horizontally 
(forward or backward).
Queen (q or Q) : can move any number of squares in any direction 
(diagonally, horizontally or verti-cally, forward or backward).
King (k or K) : can move one square at a time, in any direction 
(diagonally, horizontally or vertically, forward or backward).
Movements examples (`*' indicates where the piece can take another pieces):
Pawn Rook Bishop Queen King Knight
........ ...*.... .......* ...*...* ........ ........
........ ...*.... *.....*. *..*..*. ........ ........
........ ...*.... .*...*.. .*.*.*.. ........ ..*.*...
........ ...*.... ..*.*... ..***... ..***... .*...*..
...p.... ***r**** ...b.... ***q**** ..*k*... ...n....
..*.*... ...*.... ..*.*... ..***... ..***... .*...*..
........ ...*.... .*...*.. .*.*.*.. ........ ..*.*...
........ ...*.... *.....*. *..*..*. ........ ........
Remember that the knight is the only piece that can jumper over other 
pieces. The pawn movement will depend on its side. If it's a black pawn, 
it can only move one square diagonally down the board.
If it's a white pawn, it can only move one square diagonally up the board. 
The example above is a black pawn as it's a lowercase `p'
(we say \move" meaning the squares where the pawn can move to when it
takes another piece).



Input
There will be an arbitrary number of board congurations on the input. 
Each board will consist of 8 lines of 8 characters each. A `.' character 
will represent an empty square. Upper and lower case letters 
(as dened above) will represent the pieces. 
There will be no invalid characters (i.e. pieces) and
there won't be a conguration where both kings are in check. 
You must read until you nd an empty board 
(i.e. a board that is formed only of `.' characters) 
which should not be processed. 
There will be an empty line between each pair of board congurations. 
In all boards (except the last one which is empty) will appear both the 
white king and the black king (one, and only one of each).

Output
For each board conguration read you must output one of the following 
answers:
Game #d: white king is in check.
Game #d: black king is in check.
Game #d: no king is in check.
Where d stands for the game number (starting from 1).



Sample Input
..k.....
ppp.pppp
........
.R...B..
........
........
PPPPPPPP
K.......

rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR

rnbqk.nr
ppp..ppp
....p...
...p....
.bPP....
.....N..
PP..PPPP
RNBQKB.R

........
........
........
........
........
........
........
........

Sample Output
Game #1: black king is in check.
Game #2: no king is in check.
Game #3: white king is in check.

 
 
 