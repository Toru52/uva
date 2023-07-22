12694 - Meeting Room Arrangement   
https://github.com/morris821028/UVa/blob/master/volume126/12694%20-%20Meeting%20Room%20Arrangement.cpp



#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int t, L, R;
	scanf("%d", &t);
	while (t--) {
		vector< pair<int, int> > M;
		while (scanf("%d %d", &L, &R) == 2 && L + R) 
			M.push_back(make_pair(R, L));
		sort(M.begin(), M.end());
		int ret = 0;
		L = 0;
		for (int i = 0; i < M.size(); i++) {
			if (L <= M[i].second) {
				L = M[i].first;
				ret++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int t, F, T;
	scanf("%d", &t);
	while(t--){
		vector<pair<int, int>>E;
		while (scanf("%d %d", &F, &T), F + T)
			E.push_back(make_pair(T, F));
		sort(E.begin(), E.end());
		int cnt = 0;
		F = 0;
		for (int i = 0; i < E.size(); i++)
			if (F <= E[i].second)
				F = E[i].first, cnt++;
		printf("%d\n", cnt);
		}
	return 0;
}

Faculty of Engineering of PSU has a large meeting room for faculty 
sta to organize events and meetings.
The use of the meeting room must be reserved in advance. 
Since the meeting room is available in 10 hours per day and there may 
be several events that want to use the meeting room, 
the best usage policy is to maximize the number of events in day.
Suppose that the meeting room is available from time 0 to 10 
(10 hours). Given the list of start time and nish time of each 
candidate event, you are to write a program to select the events 
that t in the meeting room (i.e. their times do not overlap) 
and give the maximum number of events in a day.



Input
The rst line is a positive integer n (1  n  100) which 
determines the number of days (test cases).
Each test case consists of the time of the candidate events 
(less than 20 events). Each event time includes 2 integers which are 
start time(s) and nish time(f), 0  s  9, 1  f  10 
and s < f. The line containing `0 0' indicates the end of each test 
case. Note that an event must use at least 1 hour.

Output
For each test case, print out the maximum number of events that 
can be arranged in the meeting room.



Sample Input
3
0 6
5 7
8 9
5 9
1 2
3 4
0 5
0 0
6 10
5 6
0 3
0 5
3 5
4 5
0 0
1 5
3 9
0 0

Sample Output
4
4
1