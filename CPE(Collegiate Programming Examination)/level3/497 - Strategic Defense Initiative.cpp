497 - Strategic Defense Initiative
https://github.com/ajahuang/UVa/blob/master/UVa%20497%20-%20Strategic%20Defense%20Initiative.cpp

Longest Increasing Subsequence
http://judge.u-aizu.ac.jp/onlinejudge/commentary.jsp?id=DPL_1_D
http://www.geeksforgeeks.org/longest-increasing-subsequence/



#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
int main(){
	int t,missle;
	scanf("%d  ", &t);
	while (t--){
		vector<int> M;
		string s;
		while (getline(cin, s) && s != "")	{
			stringstream ss(s);
			ss >> missle;
			M.push_back(missle);
		}
		//all 1 in LIS like a memset 
		//  LIS[v.size]{1(0~v.size())}
		//  LIS->rank number
		vector<int> LIS(M.size(), 1),path(M.size(), -1);
		LIS[0] = 1;
		for (int  i = 1; i < M.size(); ++i)
			for (int j = 0; j < i; ++j){
				//smaller  order
				int l = M[j] < M[i] ? LIS[j] + 1 : 0;
				if (l > LIS[i]) //path make graph(i->j)
					                   //  type change(int)
					LIS[i] = l,  path[i] = static_cast<int>(j);
			}
	//  distance between begin and end
		int i = static_cast<int>(distance
		(LIS.begin(),max_element(LIS.begin(), LIS.end())));
		vector<int> print(1, M[i]);
		while (path[i] != -1)
			//v2.begin()=previous num
			//insert(position,number)->v2[v[j]]=v[i]
			i = path[i],   print.insert(print.begin(), M[i]);
		cout << "Max hits: " << print.size() << endl;
		copy(print.begin(), print.end(), ostream_iterator<int>(cout, "\n"));
		if (t)
			cout << endl;
	}
	return 0;
}



#include<iostream>
#include<iterator>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	int t, num;
	scanf("%d  ", &t);
	while (t--) {
		string s;
		vector<int>v;
		while (getline(cin, s), s != "") {
			stringstream ss(s);
			ss >> num; v.push_back(num);
		}
		vector<int>LIS(v.size(), 1), node(v.size(), -1);
		for(int i=1;i<v.size();i++)
			for (int j = 0; j < i; j++) {
				int k = v[j] < v[i] ? LIS[j]+1 : 0;
				if (LIS[i] < k)
					LIS[i] = k, node[i] = j;
			}
		int i = distance(LIS.begin(),
			             max_element(LIS.begin(), LIS.end()));
		vector<int>v2(1, v[i]);
		while (node[i] != -1)
			i = node[i], v2.insert(v2.begin(), v[i]);
		cout << "Max hits: " << v2.size() << endl;
		copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, "\n"));
		if (t)
			puts("");
	}
	return 0;
}



“Commander! Commander! Please wake up commander!”
“... mmmph. What time is it?”
“4:07 am, Commander. The following message just arrived on the emergency zeta 
priority classified scrambler, marked your eyes only.”
You grudgingly take the letter, rub the sleep from your eyes, 
fleetingly wish that the ’Backer closed at an earlier hour, and start to read.
``Dear StarWars SDI Commander, Bad news, buddy. 
Crazy Boris had a bit too much vodka last night
and when he woke up this morning, instead of the snooze button
on his alarm clock, he ... well, let me put it this way: we've got
tons of nuclear missles flying this way. Unfortunately, all that
we have is a chart of the altitudes at which the missles are
flying, arranged by the order of arrivals. Go for it, buddy.
Good luck. Secretary of Defense
P.S. Hilly and Bill say hi.''
To make things worse, you remeber that SDI has a fatal flaw due to the budget 
cuts. When SDI sends out missles to intercept the targets, every missle has 
to fly higher than the previous one. In other words, once you hit a target, 
the next target can only be among the ones that are flying at higher
altitudes than the one you just hit.
For example, if the missles are flying toward you at heights of 1, 6, 2, 3, 
and 5 (arriving in that order), you can try to intercept the first two, 
but then you won’t be able to get the ones flying at 2, 3, 5 
because they are lower than 6. Your job is to hit as many targets as possible. So you have to quickly
write a program to find the best sequence of targets that the flawed SDI 
program is going to destroy.
Russian war tactics are fairly strange; their generals are stickers for 
mathematical precision. 
Their missles will always be fired in a sequence such that there will only be 
one solution to the problem posed above.



Input
The input begins with a single positive integer on a line by itself indicating 
the number of the cases following, each of them as described below. 
This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
The input to your program will consist of a sequence of integer altitudes, 
each on a separate line.

Output
For each test case, the output must follow the description below. 
The outputs of two consecutive cases will be separated by a blank line.
Output from your program should contain the total number of targets you can 
hit, followed by the altitudes of those targets, one per line, 
in the order of their arrivals.



Sample Input
1

1
6
2
3
5

Sample Output
Max hits: 4
1 [0]
2 [2] 
3 [3]
5 [4]

