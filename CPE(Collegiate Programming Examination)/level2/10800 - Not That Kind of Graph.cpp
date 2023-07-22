10800 - Not That Kind of Graph
http://blog.csdn.net/mobius_strip/article/details/48715375



#include <cstdio>  
int main()
{
	int n;
	while (~scanf("%d", &n))
		for (int k = 1; k <= n; ++k) {
			char buf[55] = {}, maps[105][55] = {}; 
			scanf("%s", buf);
//绘制底板
			int max = 50, min = 52, now = 51, len = 0;
			for (int i = 0; buf[i]; ++i) {
			//	x:i y:now
				if (buf[i] == 'F') maps[--now][i + 2] = '\\';
				if (min > now) min = now;
				if (buf[i] == 'C') maps[now][i + 2] = '_';
				if (max < now) max = now;
				if (buf[i] == 'R') maps[now++][i + 2] = '/';
				len = i + 3;
			}//绘制坐标轴 
			maps[min - 1][0] = '+';
			for (int i = 1; i <= len; ++i)
				maps[min - 1][i] = '-';  
			//填充底板  
			for (int i = min; i <= max; ++i) {
				maps[i][0] = '|';
				int move = len;
				while (!maps[i][move]) --move;
				while (--move > 0)
					if (!maps[i][move])
						maps[i][move] = ' ';
			}//打印输出
			printf("Case #%d:\n", k);
			for (int i = max; i >= min - 1; --i)
				puts(maps[i]);
			puts("");
		}
	return 0;
}



#include<cstdio>
int main() {
	int n;
	while (~scanf("%d", &n)) {
		for (int cas = 1; cas <= n; ++cas) {
			char str[55] = {}, map[105][55] = {};
			scanf("%s", str);
			int now = 50, max = 49, min = 51, len = 0;
			for (int i = 0; str[i]; i++) {
				if (str[i] == 'F')map[--now][i + 2] = '\\';
				if (min > now)min = now;
				if (str[i] == 'C')map[now][i + 2] = '_';
				if (max < now)max = now;	
				if (str[i] == 'R')map[now++][i + 2] = '/';						
				len = i + 3;
			}
			map[min - 1][0] = '+';
			for (int i = 1; i <= len; ++i)
				map[min - 1][i] = '-';
			for (int i = min; i <= max; ++i) {
				map[i][0] = '|';
				int move = len;
				while (!map[i][move])--move;
				while (--move > 0)
					if (!map[i][move])
						map[i][move] = ' ';
			}
			printf("Case #%d:\n", cas);
			for (int i = max; i >= min - 1; --i)
				puts(map[i]);
			puts("");
		}
	}
	return 0;
}



Your task is to graph the price of a stock over time. 
In one unit of time, the stock can either Rise,
Fall or stay Constant. 
The stock's price will be given to you as a string of R's, F's and C's.
You need to graph it using the characters '/' (slash), '\' (backslash) 
and '_' (underscore).



Input
The rst line of input gives the number of cases, N. N test cases 
follow. Each one contains a string of
at least 1 and at most 50 upper case characters (R, F or C).

Output
For each test case, output the line `Case #x:', where x is the number 
of the test case. Then print the graph, as shown in the sample output, 
including the x- and y-axes. The x-axis should be one character
longer than the graph, and there should be one space between the 
y-axis and the start of the graph.
There should be no trailing spaces on any line. 
Do not print unnecessary lines. The x-axis should
always appear directly below the graph. Finally, 
print an empty line after each test case.



Sample Input
1
RCRFCRFFCCRRC

Sample Output
Case #1:
| _
| _/\_/\ /
| / \__/
+---------------