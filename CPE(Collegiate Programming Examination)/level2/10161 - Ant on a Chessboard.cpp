10161 - Ant on a Chessboard
https://saicheems.wordpress.com/2013/11/29/uva-10161-ant-on-a-chessboard/



#include<cmath>
#include<cstdio>

int main() {
	int n, x, y;
	while (scanf("%d", &n)==1&&n) {
		int root = ceil(sqrt(n));
		int c = root * root - root + 1;
		x = y = root;

		if (root % 2 == 0) {
			if (n > c) 
				y -= n - c;
			else 
				x -= c - n;
		}
		else {
			if (n > c) 
				x -= n - c;
			else 
				y -= c - n;
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}



#include<cstdio>
#include<cmath>
int main() {
	int n;
	while (scanf("%d", &n) == 1 && n) {
		int root = ceil(sqrt(n));
		int c = root*root - root + 1;
		int x = root,y=root;

		if (root & 1)
			if (n > c)
				x -= n - c;
			else
				y -= c - n;
		else
			if (n > c)
				y -= n - c;
			else
				x -= c - n;
		printf("%d %d\n", x, y);
	}
}


One day, an ant called Alice came to an M*M chessboard. 
She wanted to go around all the grids. So she began to walk along 
the chessboard according to this way: (you can assume that her 
speed is one grid per second)
At the first second, Alice was standing at (1,1). 
Firstly she went up for a grid, then a grid to the right, 
a grid downward. After that, she went a grid to the right, 
then two grids upward, and then two grids to the leftin a word, 
the path was like a snake. For example, 
her first 25 seconds went like this:
( the numbers in the grids stands for the time when she went into 
  the grids)
  
  
  fig
  
  
  At the 8-th second , she was at (2,3), and at 20-th second, 
  she was at (5,4).
Your task is to decide where she was at a given time 
(you can assume that M is large enoug



Input
Input file will contain several lines, and each line contains a 
number N (1 ≤ N ≤ 2 ∗ 109), which stands for the time. 
The file will be ended with a line that contains a number ‘0’.

Output
For each input situation you should print a line with two 
numbers (x,y), the column and the row number, 
there must be only a space between them.



Sample Input
8
20
25
0

Sample Output
2 3
5 4
1 5





