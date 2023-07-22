572 - Oil Deposits



#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
int d[8][2] = { 1,1, 1,0, 1,-1, 0,-1, -1,-1, -1,0, -1,1, 0,1 };
int m, n;
vector<string>v;
bool used[105][105];
void dfs(int a, int b) {
	int x, y;
	for (int i = 0; i < 8; i++) {
		x = a + d[i][0], y = b + d[i][1];
		if (!used[x][y] && 0 <= x && 0 <= y&&x < m&&y < n) {
			used[x][y] = 1;
			if (v[x][y] == '@')
				dfs(x, y);
		}
	}
}
int main() {
	string s;
	while (scanf("%d %d", &m, &n), m + n) {
		int cnt = 0;
		v.clear();
		memset(used, 0, sizeof(used));
		for (int i = 0; i < m; i++)
			cin >> s, v.push_back(s);
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (!used[i][j] && v[i][j] == '@')
					used[i][j] = 1, cnt++, dfs(i, j);
		printf("%d\n", cnt);
	}
	return 0;
}





The GeoSurvComp geologic survey company is responsible for detecting 
underground oil deposits.
GeoSurvComp works with one large rectangular region of land at a time, 
and creates a grid that divides the land into numerous square plots. 
It then analyzes each plot separately, using sensing equipment to
determine whether or not the plot contains oil.
A plot containing oil is called a pocket. If two pockets are adjacent, 
then they are part of the same oil deposit. Oil deposits can be quite 
large and may contain numerous pockets. Your job is to determine 
how many different oil deposits are contained in a grid.



Input
The input file contains one or more grids. Each grid begins with a line
containing m and n, the number of rows and columns in the grid, 
separated by a single space. If m = 0 it signals the end of the input;
otherwise 1  m  100 and 1  n  100. 
Following this are m lines of n characters each (not counting 
the end-of-line characters). 
Each character corresponds to one plot, and is either ‘*’, 
representing the absence of oil, or ‘@’, representing an oil pocket.

Output
For each grid, output the number of distinct oil deposits. 
Two different pockets are part of the same oil deposit 
if they are adjacent horizontally, vertically, or diagonally. 
An oil deposit will not contain more than 100 pockets.



Sample Input
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0

Sample Output
0
1
2
2