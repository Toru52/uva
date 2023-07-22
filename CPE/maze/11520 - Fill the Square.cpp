11520 - Fill the Square
http://mypaper.pchome.com.tw/zerojudge/post/1323172766



#include <stdio.h>

int main() {
	int t, n, k, l, cas = 0;
	char map[20][20];

	scanf("%d", &t);
	while (t--) {
		printf("Case %d:\n", ++cas);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", map[i]);
		int d[4][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				if (map[i][j] == '.') {
					for (k = 'A'; k <= 'Z'; k++) {
						map[i][j] = k;
						for (l = 0; l < 4; l++) {
							if (d[l][0] + i < 0 || d[l][0] + i >= n ||
								d[l][1] + j < 0 || d[l][1] + j >= n)
								continue;
							if (map[i][j] == map[i + d[l][0]][j + d[l][1]])
								break;
						}
						if (l == 4)  break;
					}
				}
		for (int i = 0; i < n; i++)
			puts(map[i]);
	}
	return 0;
}



In this problem, you have to draw a square using uppercase 
English Alphabets.
To be more precise, you will be given a square grid with 
some empty blocks and others already lled
for you with some letters to make your task easier. 
You have to insert characters in every empty cell
so that the whole grid is lled with alphabets. 
In doing so you have to meet the following rules:
1. Make sure no adjacent cells contain the same letter; 
two cells are adjacent if they share a common edge.
2. There could be many ways to ll the grid. 
You have to ensure you make the lexicographically
smallest one. Here, two grids are checked in row major 
order when comparing lexicographically.



Input
The rst line of input will contain an integer that will 
determine the number of test cases. Each case
starts with an integer n (n  10), 
that represents the dimension of the grid. 
The next n lines will contain n characters each. 
Every cell of the grid is either a `.' or a letter from 
[A, Z]. Here a `.' represents an empty cell.

Output
For each case, rst output `Case #:' (# replaced by case 
number) and in the next n lines output the input matrix 
with the empty cells lled heeding the rules above.



Sample Input
2
3
...
...
...
3
...
A..
...

Sample Output
Case 1:
ABA
BAB
ABA
Case 2:
BAB
ABA
BAB
