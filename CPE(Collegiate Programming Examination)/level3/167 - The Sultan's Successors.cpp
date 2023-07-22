167 - The Sultan's Successors
https://github.com/morris821028/UVa/blob/master/volume001/167%20-%20The%20Sultan's%20Successors.cpp



#include <stdio.h>
#include <stdlib.h>
int t,ans,map[8][8], x[8], y[8], used[8];

//a,b=present position
// work of bishops
int check(int a, int b, int idx) {
	for (int i = 0; i < idx; i++)
		if (abs(x[i] - a) == abs(y[i] - b))
			return 0;
	return 1;
}
//idx->x,i->y
void dfs(int idx, int sum) {
	//(2056) route in 8!(40320)
	if (idx == 8) {
		if (sum > ans)
			ans = sum;
		return;
	}
	for (int i = 0; i < 8; i++) 
		   //rooks
		if (used[i] == 0 && check(idx, i, idx) != 0) {
			used[i] = 1;
			x[idx] = idx, y[idx] = i;
			//idx+1 try to go to forward a step
			dfs(idx + 1, sum + map[idx][i]);
			used[i] = 0;
		}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 8; i++) 
			for (int j = 0; j < 8; j++)
				scanf("%d", &map[i][j]),used[i] = 0;	
		ans = 0;
		dfs(0, 0);
		printf("%5d\n", ans);
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int a, b, t, ans, used[8]{}, x[8]{}, y[8]{}, map[8][8]{};
int check(int a, int b) {
	for (int i = 0; i < a; i++)
		if (abs(x[i] - a) == abs(y[i] - b))
			return 0;
	return 1;
}
void dfs(int idx, int sum) {
	if (idx == 8) {
		if (ans < sum)
			ans = sum;
		return;
	}
	for (int i = 0; i < 8; i++) {
		if (!used[i] && check(idx, i)) {
			used[i] = 1;
			x[idx] = idx, y[idx] = i;
			dfs(idx + 1, sum + map[idx][i]);
			used[i] = 0;
		}
	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				scanf("%d", &map[i][j]), used[i] = 0;
		ans = 0;
		dfs(0, 0);
		printf("%5d\n", ans);
	}
	return 0;
}



/*
ex
1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1


6 8
7 4
*/
The Sultan of Nubia has no children, so she has decided that the 
country will be split into up to k separate parts on her death and 
each part will be inherited by whoever performs best at some test. 
It is possible for any individual to inherit more than one or indeed 
all of the portions. To ensure that only highly intelligent people 
eventually become her successors, the Sultan has devised an 
ingenious test. 
In a large hall filled with the splash of fountains and the delicate 
scent of incense have been placed k chessboards. 
Each chessboard has numbers in the range 1 to 99 written on each 
square and is supplied with 8 jewelled chess queens. 
The task facing each potential successor is to place the 8 queens
on the chess board in such a way that no queen threatens another one,
and so that the numbers on the squares thus selected sum to a number 
at least as high as one already chosen by the Sultan. 
(For those unfamiliar with the rules of chess, this implies that 
each row and column of the board contains
exactly one queen, and each diagonal contains no more than one.)
Write a program that will read in the number and details of the 
chessboards and determine the highest scores possible for each board 
under these conditions. (You know that the Sultan is both a good 
chess player and a good mathematician and you suspect that her score 
is the best attainable.)



Input
Input will consist of k (the number of boards), on a line by itself, 
followed by k sets of 64 numbers, each set consisting of eight lines 
of eight numbers. Each number will be a positive integer less than
100. There will never be more than 20 boards.

Output
Output will consist of k numbers consisting of your k scores, 
each score on a line by itself and right
justified in a field 5 characters wide.



Sample Input
1
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24
25 26 27 28 29 30 31 32
33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48
48 50 51 52 53 54 55 56
57 58 59 60 61 62 63 64

Sample Output
260