10908 - Largest Square



#include <iostream>
using namespace std;
int main()
{
	int t, m, n, q;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> q;
		char ch[102][102] = { '\0' };//初始
		for (int i = 0; i<m; i++)
			for (int j = 0; j<n; j++)
				cin >> ch[i][j];

		cout << m << " " << n << " " << q << endl;
		while (q--)
		{
			int r = 0, c = 0;
			cin >> r >> c;
			char center = ch[r][c];
			int ans = 1;
			for (int k = 3; k >= 0; k += 2)//邊長
				for (int i = 0; i<k; i++)//從中心左上角開始跑k*k個字元
					for (int j = 0; j<k; j++)
						if (ch[r - ((k - 1) / 2) + i][c - ((k - 1) / 2) + j] != center)
						{
							i = k;
							ans = k - 2; k = -3;
							break;
						}
			cout << ans << endl;
		}
	}
	return 0;
}




no2.
#include<iostream>
int main()
{
	int n,x,y,mx,my,cas;
	scanf("%d", &cas);

	for (int c = 0; c < cas; c++)
	{
		char ch[201][201] = {'\0'};
		scanf("%d%d%d", &mx, &my, &n);
		for (int i = 0; i < mx; i++)
			for (int j = 0; j < my; j++)
				std::cin >> ch[i][j];

		printf("%d %d %d\n", mx, my, n);

		for (int m = 0; m < n; m++)
		{
			int ans = 1;
			scanf("%d%d", &x, &y);
			for (int k = 3; k >= 0; k += 2)
				for (int i = 0; i < k; i++)
					for (int j = 0; j < k;j++)
						if (ch[x - ((k - 1) / 2) + i][y - ((k - 1) / 2) + j] != ch[x][y])
						{
							ans = k - 2, k = -3;
							break;
						}
			printf("%d\n", ans);
		}
	}
}


Given a rectangular grid of characters you have to find out the 
length of a side of the largest square such that all the 
characters of the square are same and the center [intersecting 
point of the two diagonals] of the square is at location (r, c).
The height and width of the grid is M and N respectively. 
Upper left corner and lower right corner of the grid will be 
denoted by (0, 0) and (M − 1, N − 1) respectively. Consider the 
grid of characters given below. Given the location (1, 2) the 
length of a side of the largest square is 3.

abbbaaaaaa
abbbaaaaaa
abbbaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaccaaaaaa
aaccaaaaaa



Input
The input starts with a line containing a single integer T (< 21). 
This is followed by T test cases. The first line of each of them will 
contain three integers M, N and Q (< 21) separated by a space where
M, N denotes the dimension of the grid. Next follows M lines each 
containing N characters. Finally, there will be Q lines each 
containing two integers r and c. The value of M and N will be at most 
100.

Output
For each test case in the input produce Q + 1 lines of output. In the 
first line print the value of M, N and Q in that order separated by 
single space. In the next Q lines, output the length of a side of 
the largest square in the corresponding grid for each (r, c) pair in 
the input.



Sample Input
1
7 10 4
abbbaaaaaa
abbbaaaaaa
abbbaaaaaa
aaaaaaaaaa
aaaaaaaaaa
aaccaaaaaa
aaccaaaaaa
1 2
2 4
4 6
5 2

Sample Output
7 10 4
3
1
5
1


