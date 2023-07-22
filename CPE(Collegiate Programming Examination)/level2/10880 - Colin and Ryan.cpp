10880 - Colin and Ryan
https://github.com/morris821028/UVa/blob/master/volume108/10880%20-%20Colin%20and%20Ryan.cpp



#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
	int cases; cin >> cases;
	for (int C, R, c = 1; cases--; ++c) {
		cin >> C >> R;
		set<int> res;
		int diff = C - R;
		cout << "Case #" << c << ":";
		if (diff == 0) {
			cout << " 0" << endl;
			continue;
		}
		for (int i = 1; i * i <= diff; ++i)
			if (diff % i == 0) {
				res.insert(diff / i);
				res.insert(i);
			}
		for (set<int>::iterator it = res.begin(); it != res.end(); it++)
			if (*it > R) cout << " " << *it;
		cout << endl;
	}
	return 0;
}



#include<iostream>
#include<set>
using namespace std;
int main() {
	int cas, C, R;
	scanf("%d", &cas);
	for (int c = 1; c <= cas; c++) {
		set<int>Q = {};
		scanf("%d %d", &C, &R);
		printf("Case #%d:", c);
		if (C == R) {
			puts(" 0");
			continue;
		}
		int dif = C - R;
		for (int i = 1; i*i <= dif; i++) 
			if (dif%i == 0) 
				Q.insert(dif/i), Q.insert(i);
		for (set<int>::iterator it = Q.begin(); it != Q.end(); ++it) 
			if (*it > R)
				printf(" %d", *it);
		puts("");
	}
	return 0;
}



Colin and Ryan had a party. They baked C cookies and invited G guests. 
Each guest ate Q cookies,and R cookies were left (R < Q).



Input
The rst line of input gives the number of cases, N. N test cases 
follow. Each one is a line containing
C and R (at most 2000000000).

Output
For each test case, output one line containing 
`Case #x:' followed by Q | the number of cookies each
guest ate. If there are multiple answers, print them in 
increasing order, separated by spaces. 
Do not print trailing spaces. Print a `0' in the case when R = C.



Sample Input
4
10 0
13 2
300 98
1000 997

Sample Output
Case #1: 1 2 5 10
Case #2: 11
Case #3: 101 202
Case #4: