201 - Squares
http://mypaper.pchome.com.tw/zerojudge/post/1322631811



#include<stdio.h>
#include<algorithm>
int main() {
	int x, y, n, m, flag = 0;
	char op[2];
	while (scanf("%d", &n) == 1) {
		if (flag)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++flag);
		scanf("%d", &m);
		int H[10][10]{}, V[10][10]{}, Ans[10]{};
		while (m--) {
			scanf("%s %d %d", op, &x, &y);
			if (op[0] == 'H')	H[x][y] = 1;
			else				V[y][x] = 1;
		}
		//make size
		for (int i = n; i >= 0; i--)
			for (int j = n; j >= 0; j--) {
				//ex H[i][j]=1,H[i][j+1]=1->j 1-2 ->size=2
				if (H[i][j]) H[i][j] = H[i][j + 1] + 1;
				if (V[i][j]) V[i][j] = V[i + 1][j] + 1;
			}
		// k=square size
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = std::min(H[i][j], V[i][j]); k >= 1; k--) 
					if (H[i + k][j] >= k && V[i][j + k] >= k)
						Ans[k]++;
		int find = 0;
		for (int i = 1; i < n; i++)
			if (Ans[i])
				printf("%d square (s) of size %d\n", Ans[i], i), find = 1;
		if (!find)
			puts("No completed squares can be found.");
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
int main() {
	int x, y, n, m, cas = 0;
	char op[3];
	while (scanf("%d", &n) == 1) {
		if (cas)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++cas);
		int H[10][10]{}, V[10][10]{}, ans[10]{};
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%s %d %d", op, &x, &y);
			if (op[0] == 'H')H[x][y] = 1;
			else             V[y][x] = 1;
		}
		for(int i=n;i>0;i--)
			for (int j = n; j >0; j--) {
				if (H[i][j])H[i][j] = H[i][j + 1] + 1;
				if (V[i][j])V[i][j] = V[i + 1][j] + 1;
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = std::min(H[i][j], V[i][j]); k >= 1; k--)
					if (H[i + k][j] >= k&&V[i][j + k] >= k)
						ans[k]++;
		int flag = 0;
		for (int i = 1; i <= n; i++)
			if (ans[i])
				printf("%d square (s) of size %d\n", ans[i], i), flag = 1;
		if (!flag) 
			puts("No completed squares can be found.");
	}
	return 0;
}



A children's board game consists of a square array of dots that contains 
lines connecting some of the pairs of adjacent dots. 
One part of the game requires that the players count the number of 
squares of certain sizes that are formed by these lines. 
For example, in the gure shown below, there are 3 squares | 2 of size 
1 and 1 of size 2. (The \size" of a square is the number of lines 
segments required to form a side.)
Your problem is to write a program that automates the process of 
counting all the possible squares.



Input
The input le represents a series of game boards. 
Each board consists of a description of a square array of n2 dots 
(where 2  n  9) and some interconnecting horizontal and vertical 
lines. A record for a single board with n2 dots and m interconnecting 
lines is formatted as follows:
Line 1: n the number of dots in a single row or column of the array
Line 2: m the number of interconnecting lines
Each of the next m lines are of one of two types:
H i j indicates a horizontal line in row i which connects
the dot in column j to the one to its right in column j + 1
or
V i j indicates a vertical line in column i which connects
the dot in row j to the one below in row j + 1
Information for each line begins in column 1. The end of input is 
indicated by end-of-le. The rst record of the sample input below 
represents the board of the square above.

Output
For each record, label the corresponding output with `Problem #1', 
`Problem #2', and so forth. Output for a record consists of the number 
of squares of each size on the board, from the smallest to the largest.
lf no squares of any size exist, your program should print an appropriate
message indicating so. Separate output for successive input records by a 
line of asterisks between two blank lines, like in the sample below.



Sample Input
4
16
H 1 1
H 1 3
H 2 1
H 2 2
H 2 3
H 3 2
H 4 2
H 4 3
V 1 1
V 2 1
V 2 2
V 2 3
V 3 2
V 4 1
V 4 2
V 4 3
2
3
H 1 1
H 2 1
V 2 1

Sample Output
Problem #1
2 square (s) of size 1
1 square (s) of size 2
**********************************
Problem #2
No completed squares can be found.


