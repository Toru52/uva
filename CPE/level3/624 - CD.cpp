624 - CD 
http://scj-code.blogspot.tw/2016/09/uva-624-cd.html



#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
int w[22], dp[22][100005];
int main(){
	int n,t;
	while (cin >> t >> n){
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; ++i)
			cin >> w[i];
		//knapsack algorithm
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= t; ++j)
				if (j < w[i])
					dp[i][j] = dp[i - 1][j];
				else 
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + w[i]);
		stack<int> st;
		//select num that just updated from n
		//updated num at i represent must use w[i] element
		for (int x = n, y = t; x > 0; --x)	
			if (dp[x][y] != dp[x - 1][y])
				st.push(w[x]), y -= w[x];
		while (st.size())
			cout << st.top() << ' ', st.pop();
		cout << "sum:" << dp[n][t] << endl;
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
using namespace std;
int w[22], dp[22][100005];
int main() {
	int t, n;
	while (scanf("%d %d", &t, &n) == 2) {
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= t; j++)
				if (j < w[i])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = max(dp[i - 1][j], w[i] + dp[i-1][j - w[i]]);
		stack<int>st;
		for (int i = n, j = t; i > 0; i--)
			if (dp[i][j] != dp[i - 1][j])
				st.push(w[i]), j -= w[i];
		while (st.size())
			printf("%d ", st.top()), st.pop();
		printf("sum:%d\n", dp[n][t]);
	}
	return 0;
}




You have a long drive by car ahead. You have a tape recorder,
but unfortunately your best music is on CDs. 
You need to have it on tapes so the problem to solve is: 
you have a tape N minutes long. 
How to choose tracks from CD to get most out of tape space and have 
as short unused space as possible.
Assumptions:
• number of tracks on the CD does not exceed 20
• no track is longer than N minutes
• tracks do not repeat
• length of each track is expressed as an integer number
• N is also integer
Program should find the set of tracks which fills the tape best and 
print it in the same sequence as the tracks are stored on the CD



Input
Any number of lines. Each one contains value N, (after space) 
number of tracks and durations of the tracks. 
For example from first line in sample data: N = 5, 
number of tracks=3, first track lasts for 1
minute, second one 3 minutes, next one 4 minutes

Output
Set of tracks (and durations) which are the correct solutions and 
string ‘sum:’ and sum of duration times.



Sample Input
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
Sample Output
1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45