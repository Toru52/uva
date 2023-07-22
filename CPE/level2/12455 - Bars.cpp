12455 - Bars
http://mypaper.pchome.com.tw/zerojudge/post/1323237875



#include <stdio.h>

int main() {
	int t, w, n, i, j, p;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &w, &n);
		int dp[1005] = {};
		dp[0] = 1;
		for (i = 0; i < n; i++) {
			scanf("%d", &p);
			for (j = w - p; j >= 0; j--) {
				if (dp[j] && !dp[j + p])
					dp[j + p] = 1;
			}
		}
		if (dp[w])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}



#include <stdio.h>

int main() {
	int t, w, n, p;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &w, &n);
		int dp[1005] = {1};
		for (int i = 0; i < n; i++) {
			scanf("%d", &p);
			for (int j = w - p; j >= 0; j--) 
				if (dp[j] && !dp[j + p])
					dp[j + p] = 1;	
		}
		if (dp[w])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int t, w, n, p;
	scanf("%d", &t);
	while (t--) {
		int dp[1005] = { 1 };
		scanf("%d %d", &w, &n);
		for (int i = 0; i < n; i++) {	
			scanf("%d", &p);
			for (int j = w - p; j >= 0; j--)
				if (dp[j] && !dp[j + p])
					dp[j + p] = 1;
		}
		if (dp[w])puts("YES");
		else puts("NO");
	}
	return 0;
}



/*
memo
we want to  obtain another one being exactly a given length long.
n= length of the bar we want to obtain.
p= number of bars we have.
p numbers= the length of the p bars.

cncept dp->combination
ex 25
10 12 5 7 ->12+5+7=24!=25 No
10 12 5 8 ->12+5+8=25==25 Yes
*/

Some things grow if you put them together.
We have some metallic bars, theirs length known, and, if necessary, 
we want to solder some of them in order to obtain another one being 
exactly a given length long. No bar can be cut up. Is it possible?



Input
The rst line of the input contains an integer,t, 0  t  50, 
indicating the number of test cases. For each test case, three lines 
appear, the rst one contains a number n, 0  n  1000, 
representing the length of the bar we want to obtain. 
The second line contains a number p, 1  p  20, 
representing the number of bars we have. 
The third line of each test case contains p numbers, 
representing the length of the p bars.

Output
For each test case the output should contain a single line, 
consists of the string `YES' or the string `NO',
depending on whether solution is possible or not.



Sample Input
4
25
4
10 12 5 7
925
10
45 15 120 500 235 58 6 12 175 70
120
5
25 25 25 25 25
0
2
13 567

Sample Output
NO
YES
NO
YES