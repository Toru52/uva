11464 - Even Parity
http://www.cnblogs.com/dwtfukgv/p/5555339.html

what is even parity
https://www.youtube.com/watch?v=RfTGvpY2Z5Y

#include <cstdio>
#include <cstring>
#include <algorithm>
int  n,a[20][20],INF=-1u>>1;

int solve(int s) {
	int  b[20][20]{};
　　　//n=3 -> i = 0,1,2  (1<<i)1,2,4
	for (int i = 0; i < n; ++i) {
		//determine s is which even parity
		if (s & (1 << i))
			b[0][i] = 1;
		else if(1 == a[0][i])  
			return INF;//是1，本应该是0的，不能修改，结束
	}   
	for (int r = 0; r < n - 1; ++r)
		for (int c = 0; c < n; ++c) {
			int sum = 0;
			if (r > 0)
				sum += b[r - 1][c];//计算上左右						   //            if(r < n-1)  sum += b[r+1][c];
			if (c > 0)
				sum += b[r][c - 1];
			if (c < n - 1) 
				sum += b[r][c + 1];
			b[r + 1][c] = sum % 2;//确定下一行元素
			if (a[r + 1][c] && !b[r + 1][c]) 
				return INF;//同上，不能改
		}
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (a[i][j] != b[i][j]) 
				++cnt;//计算个数
	return cnt;
}
int main() {
	int t;
	scanf("%d",&t);
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				scanf("%d", &a[i][j]);
		int ans = INF;   //(1<<n)->2^n->even parity number =2^n
		for (int i = 0; i < (1 << n); ++i)//二进制法枚举
			ans = std::min(ans, solve(i));
		printf("Case %d: %d\n", cas, ans == INF ? -1 : ans);
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
int a[20][20], n, inf = -1u >> 1;
int parity(int I) {
	int b[20][20]{}, cnt = 0;
	for (int j = 0; j < n; j++)
		if (I&(1 << j))
			b[0][j] = 1;
		else if (a[0][j] == 1)
			return inf;
	for(int r=0;r<n-1;r++)
		for (int c = 0; c < n; c++) {
			int sum = 0;
			if (r > 0)
				sum += b[r - 1][c];
			if (c > 0)
				sum += b[r][c - 1];
			if (c < n - 1)
				sum += b[r][c + 1];
			b[r + 1][c] = sum % 2;
			if (!b[r + 1][c] && a[r + 1][c])
				return inf;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != b[i][j])
				cnt++;
	return cnt;
}
int main() {
	int t,cas=0;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		int ans = inf;
		for (int i = 0; i < (1 << n); i++)
			ans = std::min(parity(i), ans);
		printf("Case %d: %d\n", ++cas, (ans == inf) ? -1: ans);
	}
	return 0;
}



/*
pattern is limited 
ex n=3
0
0 0 0 
0 0 0
0 0 0

1
1 0 0  0 2 0
0 1 0  2 0 2 
0 0 1  0 2 0 

1 0 0
add left one
0 1 0
add left one
0 0 1
(1,2,4)

2
0 1 0  2 0 2
1 0 1  0 4 0 
0 1 0  2 0 2 
(2,5,10(2))
0 1 0
add right one , ,add left one
1 0 1
,,add left one

3
1 1 0  2 2 2
1 1 1  2 4 2
0 1 1  2 2 2
(3,7,(14)6)
1 1 0
add right one,add left one one,add left one
4
0 0 1  0 2 0
0 1 0  2 0 2
1 0 0  0 2 0

5
1 0 1  0 2 0
0 0 0  2 0 2
1 0 1  0 2 0

6
0 1 1  2 2 2
1 1 1  2 4 2
1 1 0  2 2 2

7
1 1 1  2 2 2
1 0 1  2 4 2
1 1 1  2 2 2

->all number are even after transfer number
->row 1 was made by 2base bit (s=1->100,s=2->010,,,) 
n=2
0
0 0
0 0,,,

1
1 0  0 2
0 1  2 0

2
0 1  2 0
1 0  0 2

3
1 1  2 2
1 1  2 2

ex
3
0 0 0
0 0 1
0 0 0
->2367
->middle left is duplicated


if (s & (1 << i))
	b[0][i] = 1;
n=3

s=1
100
s=2
010
s=3
110
,,,
->2 base bit 



for (int j = 0; j < n; ++j) 
		if (I & (1 << j))
			b[0][j] = 1;
		else if(1 == a[0][j])  
			return INF;//是1，本应该是0的，不能修改，结束
n=3
100 ->even parity=1,3,5,7
010 ->even parity= 2,3,6,7



else if(1 == a[0][i])  
	return INF;//是1，本应该是0的，不能修改，结束
and

if (a[r + 1][c] && !b[r + 1][c]) 
				return INF;//同上，不能改
->a matrix must not bigger than even parity
  (in other words, a bigger denote no even parity) 

*/


We have a grid of size N  N. Each cell of the grid initially 
contains a zero(0) or a one(1). The parity of a cell is the number of 
1s surrounding that cell. A cell is surrounded by at most 4 cells 
(top, bottom,left, right).Suppose we have a grid of size 4  4:
1 0 1 0 1 3 1 2
1 1 1 1 2 3 2 1
0 1 0 0 2 1 2 1
0 0 0 0 0 1 0 0
For this problem, you have to change some of the 0s to 1s so that the 
parity of every cell becomes
even. We are interested in the minimum number of transformations of 
0 to 1 that is needed to achieve the desired requirement.



Input
The rst line of input is an integer T (T < 30) that indicates the 
number of test cases. Each case starts with a positive integer N 
(1  N  15). Each of the next N lines contain N integers (0/1) 
each. The integers are separated by a single space character.

Output
For each case, output the case number followed by the minimum number 
of transformations required. If it's impossible to achieve the desired 
result, then output `-1' instead.



Sample Input
3
3
0 0 0
0 0 0
0 0 0
3
0 0 0
1 0 0
0 0 0
3
1 1 1
1 1 1
0 0 0

Sample Output
Case 1: 0
Case 2: 3
Case 3: -1