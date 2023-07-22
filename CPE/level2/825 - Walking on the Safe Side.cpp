825 - Walking on the Safe Side



#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int T, W, N;
	cin >> T;
	while (T--) {
		cin >> W >> N;
		// Initial
		bool Map[100][100] = { 0 };
		int dp[100][100] = { 0 };
		// Input
		cin.ignore();    // ignore '\n'
		string str;
		for (int i = 1, j; i <= W; ++i) {
			getline(cin, str);
			stringstream ss(str);
			ss >> j;    // ignore the first number
			while (ss >> j)
				Map[i][j] = true;
		}
		dp[1][1] = 1;
		for (int i = 1; i <= W; ++i) {
			for (int j = 1; j <= N; ++j) {
				if (Map[i][j]) continue;
				if (i > 1) dp[i][j] += dp[i - 1][j];
				if (j > 1) dp[i][j] += dp[i][j - 1];
			}
		}
		cout << dp[W][N] << endl;
		if (T) cout << endl;
	}
}



#include<iostream>
#include<sstream>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int cas,W,N;
	string str;

	cin >> cas;
	while (cas--) {
		int block[100][100] = {}, dp[100][100] = {};
		cin >> W >> N;
		cin.ignore();
		for (int i = 1, j; i <= W; i++) {
			getline(cin, str);
			stringstream ss(str);
			ss >> j;
			while (ss >> j)
				block[i][j] = 1;
		}
		dp[1][1] = 1;
		for (int i = 1; i <= W; i++)
			for (int j = 1; j <= N; j++) {
				if (block[i][j])
					continue;
				else {
					if (i > 1)dp[i][j] += dp[i - 1][j];
					if (j > 1)dp[i][j] += dp[i][j - 1];
				}
			}
		cout << dp[W][N] << endl;	
		if (cas)
			cout << endl;
	}
}



Square City is a very easy place for people to walk around. 
The two-way streets run North-South or
East-West dividing the city into regular blocks. 
Most street intersections are safe for pedestrians to
cross. In some of them, however, crossing is not safe and 
pedestrians are forced to use the available
underground passages. Such intersections are avoided by 
walkers. The entry to the city park is on the North-West 
corner of town, whereas the railway station is on the 
South-East corner. Suppose you want to go from the park 
to the railway station, and do not want to walk more than
the required number of blocks. You also want to make your 
way avoiding the underground passages, that would 
introduce extra delay. Your task is to determine the 
number of different paths that you can follow from the 
park to the station, satisfying both requirements.
The example in the picture illustrates a city with 4 E-W 
streets and 5 N-S streets. Three intersections
are marked as unsafe. The path from the park to the 
station is 3 + 4 = 7 blocks long and there are 4
such paths that avoid the underground passages.



Input
The input begins with a single positive integer on a line 
by itself indicating the number of the cases following, 
each of them as described below. This line is followed by 
a blank line, and there is also a blank line between two 
consecutive inputs. The first line of the input contains 
the number of East-West streets W and the number of 
NorthSouth streets N. Each one of the following W lines 
starts with the number of an East-West street,
followed by zero or more numbers of the North-South 
crossings which are unsafe. Streets are numbered from 1.

Output
For each test case, the output must follow the 
description below. The outputs of two
consecutive cases will be separated by a blank line.
The number of different minimal paths from the park to 
the station avoiding underground passages.



Sample Input
1
4 5
1
2 2
3 3 5
4

Sample Output
4