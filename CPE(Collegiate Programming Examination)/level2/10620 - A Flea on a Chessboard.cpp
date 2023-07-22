10620 - A Flea on a Chessboard

http://blog.csdn.net/keshuai19940722/article/details/36935531
http://www.xuebuyuan.com/2144205.html

#include <cstdio>

int main() {
	int i, s, x, y, dx, dy;
	while (scanf("%d%d%d%d%d", &s, &x, &y, &dx, &dy)&& s) {
		for (i = 0; i < 2 * s; i++) {
			if ((x%s)&&(y%s)&&((x/s+y/s)%2)) {
				printf("After %d jumps the flea lands at (%d, %d).\n", i, x, y);
				break;
			}
			x += dx; y += dy;
		}
		if (i == 2 * s)
			printf("The flea cannot escape from black squares.\n");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int i, s, x, y, dx, dy;
	while (scanf("%d%d%d%d%d", &s, &x, &y, &dx, &dy) && s) {
		for (i = 0; i < s * 2; i++) {
			if ((x%s) && (y%s) && ((x / s + y / s) % 2)) {
				printf("After %d jumps the flea lands at (%d, %d).\n", i, x, y);
				break;
			}
			x += dx, y += dy;
		}
		if (i == s * 2)
			puts("The flea cannot escape from black squares.");
	}
	return 0;
}



/*test
#include <cstdio>
int map[100][100];
int s;
void ini() {
	for (int i = 1; i <= s * 2; i++)
		for (int j = 1; j <= s * 2; j++)
			if (i <= s&&j <= s)
				map[i][j] = 1;
			else
				map[i][j] = 0;
}
void make_map() {
	for (int i = 1; i <= s * 2; i++) {
		for (int j = 1; j <= s * 2; j++)
			if (map[i][j] == 1)
				printf("1");
			else if (map[i][j] == 3)
				printf("@");
			else if (map[i][j] == 2)
				printf("S");
			else
				printf(".");
		puts("");
	}
	puts("");
}

int main() {
	int i, x, y, dx, dy;
	while (scanf("%d%d%d%d%d", &s, &x, &y, &dx, &dy)&& s) {
		ini();
		map[x][y] = 2;
		for (i = 0; i < 2 * s; i++) {
			if ((x%s)&&(y%s)&&((x/s+y/s)%2)) {
				printf("After %d jumps the flea lands at (%d, %d).\n", i, x, y);
				break;
			}
			x += dx; y += dy;
			map[x][y] = 3;
		}
		if (i == 2 * s)
			printf("The flea cannot escape from black squares.\n");
		make_map();
	}
	return 0;
}
}*/



An in nite chessboard is obtained by extend-
ing a  nite chessboard to the right and up in-
 nitely. Each square of the chessboard is either
black or white with the side of
S
milimiters,
0
<S<
1000.  The leftmost bottom square
of the chessboard is black. A  ea is possitioned
on the chessboard at the point (
x;y
) (given in
milimeters) and makes jumps by jumping
dx
milimeters to the right and
dy
milimiters up,
0
<dx;dy
, that is, a  ea at position (
x;y
) after
one jump lands at position (
x
+
dx;y
+
dy
).
Given the starting position of the  ea on the
board your task is to  nd out after how many
jumps the  ea will reach a white square. If the
 ea lands on a boundary between two squares then it does not count 
 as landing on the white square.
Note that it is possible that the  ea never reaches a white square


Input
Each test case consists of one line of input containing  
ve non-negative numbers separated by white
space and giving
S
,
x
,
y
,
dx
, and
dy
. An input line containing  ve zeroes follows the last test case.

Output
For test case print one line of output in the format shown in the 
sample.



SampleInput
10 2 3 3 2
100 49 73 214 38
25 0 0 5 25
407 1270 1323 1 1
18 72 6 18 6
407 1270 1170 100 114
0 0 0 0 0

SampleOutput
After 3 jumps the flea lands at (11, 9).
After 1 jumps the flea lands at (263, 111).
The flea cannot escape from black squares.
After 306 jumps the flea lands at (1576, 1629).
The flea cannot escape from black squares.
After 0 jumps the flea lands at (1270, 1170).