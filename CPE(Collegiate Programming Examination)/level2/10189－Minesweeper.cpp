10189－Minesweeper
http://knightzone.org/?p=1452



#include<cstdio>
#define MAX_N 100
#define MAX_M 100
#define MINE -100 // can't be added to positive number
int main() {
	int n, m, field_num = 0;
	char square;
	while (scanf("%d%d", &n, &m) != EOF
		&& !(n == 0 && m == 0)) {
		getchar(); //ignore EOL
		if (field_num) printf("\n");
		int field[MAX_N + 5][MAX_M + 5] = { 0 };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				square = getchar();
				if (square == '*') {
					field[i][j] = MINE;
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							field[i + k][j + l]++;
				}
			}
			getchar(); //ignore EOL
		}
		printf("Field #%d:\n", ++field_num);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				if (field[i][j] < 0) printf("*");
				else printf("%d", field[i][j]);
				printf("\n");
		}
	}
	return 0;
}



#include<cstdio>
#define MAX 105
#define MINE -10
int main() {
	int m, n, cnt = 0;
	char c;
	while (scanf("%d%d", &m, &n) == 2 && (m&&n)) {
		getchar();
		int field[MAX][MAX] = {};
		if (cnt)
			puts("");
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				c = getchar();
				if (c == '*') {
					field[i][j] = MINE;
					for (int k = -1; k <= 1; k++)
						for (int l = -1; l <= 1; l++)
							field[k+i][l+j]++;
				}
			}
			getchar();
		}
		printf("Field #%d:\n", ++cnt);
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++)
				if (field[i][j] < 0)
					printf("*");
				else
					printf("%d", field[i][j]);
			puts("");
		}
	}
	return 0;
}



Have you ever played Minesweeper? It’s a cute little game 
which comes within a certain Operating System which name 
we can’t really remember. Well, the goal of the game is to 
find where are all the mines within a M × N field. 
To help you, the game shows a number in a square which tells 
you how many mines there are adjacent to that square. 
For instance, supose the following 4 × 4 field with 2
mines (which are represented by an ‘*’ character):
*...
....
.*..
....
If we would represent the same field placing the hint numbers 
described above, we would end up
with:
*100
2210
1*10
1110
As you may have already noticed, each square may have at 
most 8 adjacent squares.



Input
The input will consist of an arbitrary number of fields. 
The first line of each field contains two integers
n and m (0 < n, m ≤ 100) which stands for the number of lines 
and columns of the field respectively.
The next n lines contains exactly m characters and represent 
the field.
Each safe square is represented by an ‘.’ character 
(without the quotes) and each mine square
is represented by an ‘*’ character (also without the quotes). 
The first field line where n = m = 0
represents the end of input and should not be processed.

Output
For each field, you must print the following message in a 
line alone:
Field #x:
Where x stands for the number of the field (starting from 1). 
The next n lines should contain the field with the ‘.’ 
characters replaced by the number of adjacent mines to that 
square. There must be an empty line between field outputs.



Sample Input
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0

Sample Output
Field #1:
*100
2210
1*10
1110
Field #2:
**100
33200
1*100