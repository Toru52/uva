10189 - Minesweeper



no1.
#include<stdio.h>
int main()
{
	char field[100][101];
	int x[8], y[8], m, n, f = 1;

	while (scanf("%d%d", &n, &m) && (n || m))
	{
		if (f>1)    
			printf("\n");
		for (int i = 0; i<n; i++)
			scanf("%s", field[i]);
		for (int i = 0; i<n; i++)
			for (int j = 0; j<m; j++)
				if (field[i][j] == '.')
				{
					int c = 0;
					for (int k = i - 1; k <= i + 1; k++)
						for (int l = j - 1; l <= j + 1; l++)
							if (k >= 0 && k<n&&l >= 0 && l<m&&field[k][l] == '*')
								c++;

					field[i][j] = c + 48;
				}
		printf("Field #%d:\n", f++);
		for (int i = 0; i<n; i++)
			printf("%s\n", field[i]);
	}
	return 0;
}



no2.
#include<cstdio>

int main()
{
	int n, m,cas=0,flag=0;
	char field[101][101];
	while (scanf("%d%d", &n, &m) && (n || m))
	{
		if (flag)
			puts("");
		flag++;
		for (int i = 0; i < n; i++)
			scanf("%s", &field[i]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m;j++)
				if (field[i][j] == '.')
				{
					int cnt = 0;
					for (int k = i - 1; k <= i + 1; k++)
						for (int o = j - 1; o <= j + 1; o++)
							if (0 <= k&&k < n && 0 <= o&&o < m&&field[k][o] == '*')
								cnt++;

					field[i][j] = cnt + 48;
				}
		printf("Field #%d:\n", ++cas);
		for (int i = 0; i < n; i++)
			printf("%s\n", field[i]);
	}
}



Have you ever played Minesweeper? It’s a cute little game which 
comes within a certain Operating System which name we can’t 
really remember. Well, the goal of the game is to find where 
are all the mines within a M × N field. To help you, the game 
shows a number in a square which tells you how many mines 
there are adjacent to that square. For instance, supose the 
following 4 × 4 field with 2 mines 
(which are represented by an ‘*’ character):

*...
....
.*..
....

If we would represent the same field placing the hint numbers 
described above, we would end up with:

*100
2210
1*10
1110

As you may have already noticed, each square may 
have at most 8 adjacent squares.



Input
The input will consist of an arbitrary number of fields. The 
first line of each field contains two integers n and m 
(0 < n, m ≤ 100) which stands for the number of lines and 
columns of the field respectively.The next n lines contains 
exactly m characters and represent the field. Each safe square 
is represented by an ‘.’ character (without the quotes) and 
each mine square is represented by an ‘*’ character (also 
without the quotes). The first field line where n = m = 0
represents the end of input and should not be processed.

Output
For each field, you must print the following message in a line 
alone:
Field #x:

 Where x stands for the number of the field (starting from 1). 
The next n lines should contain the field with 
the ‘.’ characters replaced by the number of adjacent mines to 
that square. There must be an empty line between field outputs.



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