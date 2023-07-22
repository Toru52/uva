11231 - Black and white painting
http://blog.csdn.net/mobius_strip/article/details/50009023


#include <cstdio>  
  
int main()  
{  
    int n, m, c;  
    while (~scanf("%d%d%d",&n,&m,&c) && n+m+c)  
        printf("%d\n",((n-7+c)/2)*((m-6)/2) + ((n-6-c)/2)*((m-7)/2));  
          
    return 0;  
}  



#include <stdio.h>

int main() {
	int n, m, c;
	while (scanf("%d %d %d", &n, &m, &c) == 3) {
		if (n + m + c == 0)
			break;
		if (c == 0) 
			printf("%d\n", (n - 7)*(m - 7) / 2);
		else 
			printf("%d\n", ((n - 7)*(m - 7) + 1) / 2);
		
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, m, c;
	while (scanf("%d%d%d", &n, &m, &c), n) {
		if (c)
			printf("%d\n", ((n - 7)*(m - 7) + 1) / 2);
		else
			printf("%d\n", (n - 7)*(m - 7) / 2);
	}
	return 0;
}



/*
we should just paint black tile
since color is white,
so don't have to paint white color

3*3
right bottom is white
wbw
bwb
wbw   black is 4

->next paint from black,so plus 1 when even board 

right bottom is black
bwb
wbw
bwb   black is 5

2*2
right bottom is white
wb
bw   black is 2

->next paint from white 

right bottom is black
bw
wb  black is 2

->when even board,difference is one between white and black
since 8*8 board already painted
so start from 8 row column
*/


You are visiting the Centre Pompidou which contains a lot of modern 
paintings. In particular you notice one painting which consists 
solely of black and white squares, arranged in rows and columns 
like in a chess board (no two adjacent squares have the same colour). 
By the way, the artist did not use the tool of problem 
A to create the painting.
Since you are bored, you wonder how many 8  8 chess boards are 
embedded within this painting.
The bottom right corner of a chess board must always be white.



Input
The input contains several test cases. Each test case consists of 
one line with three integers n, m and c. (8  n;m  40000), 
where n is the number of rows of the painting, and m is the number 
of columns of the painting. c is always 0 or 1, 
where 0 indicates that the bottom right corner of the painting is
black, and 1 indicates that this corner is white.
The last test case is followed by a line containing three zeros.

Output
For each test case, print the number of chess boards embedded 
within the given painting.



Sample Input
8 8 0
8 8 1
9 9 1
40000 39999 0
0 0 0

Sample Output
0
1
2
799700028