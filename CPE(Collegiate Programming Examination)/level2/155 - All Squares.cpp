155 - All Squares
https://sites.google.com/site/pcshic/solutions/2013-xiao-qing-bei-yi-zu-can-kao-jie-da


#include <stdio.h>

int k, n, m, ans;
void dfs(int x, int y, int k) {
	if (k == 0)
		return;
	if (x - k <= n && x + k >= n && y - k <= m && y + k >= m)
		ans++,printf("size %d position(%d %d)\n",k,x, y);
	dfs(x + k, y + k, k / 2);
	dfs(x + k, y - k, k / 2);
	dfs(x - k, y + k, k / 2);
	dfs(x - k, y - k, k / 2);
}
int main() {
	while (scanf("%d %d %d", &k, &n, &m) == 3) {
		if (k == 0 && n == 0 && m == 0)
			break;
		ans = 0;
		dfs(1024, 1024, k);
		printf("%3d\n", ans);
	}
	return 0;
}



#include<stdio.h>
int a, b, k,cnt;
void dfs(int x, int y, int k)
{
	if (k == 0)
		return;
	if (x - k <= a&&a <= x + k&&y - k <= b&&b <= y + k)
		cnt++;
	dfs(x - k, y - k, k / 2);
	dfs(x + k, y - k, k / 2);
	dfs(x - k, y + k, k / 2);
	dfs(x + k, y + k, k / 2);
}
int main()
{
	while (scanf("%d %d %d", &k, &a, &b) == 3 &&a&&b&&k)
	{
		cnt = 0;
		dfs(1024, 1024, k);
		printf("%3d\n", cnt);
	}
}



#include <iostream>
#include <iomanip>
#include <cstdlib>      //for abs(int)
using namespace std;

int main () {
    int k, x, y, x1, y1, ns;
    while (cin >> k >> x >> y, k) {
        ns = 0;                                 //no of s(quare)--正方形數
        x1 = y1 = 1024;                         //中心點
        while (k) {
            if (abs(x-x1)<=k && abs(y-y1)<=k)   //在正方形內
                ns++;
            x1 +=  k * ((x >= x1) - (x < x1));   //(x1,y1) 移到最接近的角
            y1 +=  k * ((y >= y1) - (y < y1));
            k /= 2;                             //縮小正方形
        }
        cout << setw(3) << ns << endl;
    }
}



Points
The largest square is of size k 
->The largest square is positioned at the central
->Therefore the size k represent that 
  set the size initial square at the central
->



Geometrically, any square has a unique, well-defined centre 
point. On a grid this is only true if the sides of the square 
are an odd number of points long. Since any odd number can be 
written in the form 2k+1, we can characterise any such square 
by specifying k, that is we can say that a square whose sides 
are of length 2k+1 has size k. Now define a pattern of squares 
as follows.

The largest square is of size k (that is sides are of length 
2k+1) and is centred in a grid of size 1024 (that is the grid 
sides are of length 2049).
The smallest permissible square is of size 1 and the 
largest is of size 512, thus  tex2html_wrap_inline32 .
All squares of size k > 1 have a square of 
size k div 2 centred on each of their 4 corners. 
(Div implies integer division, thus 9 div 2 = 4).
The top left corner of the screen has coordinates (0,0), 
the bottom right has coordinates (2048, 2048).
Hence, given a value of k, we can draw a unique pattern of 
squares according to the above rules. Furthermore any point 
on the screen will be surrounded by zero or more squares. 
(If the point is on the border of a square, it is considered 
to be surrounded by that square). Thus if the size of the 
largest square is given as 15, then the following pattern 
would be produced.

picture25
Write a program that will read in a value of k and the 
coordinates of a point, and will determine how many squares 
surround the point.



Input and Output
Input will consist of a series of lines. Each line will 
consist of a value of k and the coordinates of a point. 
The file will be terminated by a line consisting of three 
zeroes (0 0 0).
Output will consist of a series of lines, one for each line of 
the input. Each line will consist of the number of squares 
containing the specified point, right justified in a field of 
width 3.



Sample input
500 113 941
0 0 0
Sample output
  5