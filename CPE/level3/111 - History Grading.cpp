111 - History Grading
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/I/111%20-%20History%20Grading.cpp

Longest Common Subsequence （ LCS ）
http://www.csie.ntnu.edu.tw/~u91029/LongestCommonSubsequence.html
http://d.hatena.ne.jp/naoya/20090328/1238251033



#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, c[20], r[20], lcs[21][21], x;

	scanf("%d\n", &n);
	for (int i = 0; i<n; i++)
		scanf("%d", &x), c[x - 1] = i;

	while (scanf("%d", &x) == 1) {
		r[x - 1] = 0;
		for (int i = 1; i<n; i++)
			scanf("%d", &x), r[x - 1] = i;

		for (int i = n; i >= 0; i--)
			for (int j = n; j >= 0; j--) {
				if (i == n || j == n) {
					lcs[i][j] = 0;
					continue;
				}
				if (c[i] == r[j]) lcs[i][j] = 1 + lcs[i + 1][j + 1];
				else lcs[i][j] = max(lcs[i][j + 1], lcs[i + 1][j]);
				//i(correct),j(choice)->num   c(correct),r(choice)->rank
				//printf("i %d j %d c %d r %d lcs %d\n", i+1, j+1,c[i]+1,r[j]+1, lcs[i][j]);
			}

		printf("%d\n", lcs[0][0]);
	}
	return 0;
}



#include<cstdio>
#include<algorithm>
int main() {
	int n, x, r[21], c[21], lcs[21][21];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x), c[x - 1] = i;
	while (scanf("%d", &x) == 1) {
		r[x - 1] = 0;
		for (int i = 1; i < n; i++)
			scanf("%d", &x), r[x - 1] = i;
		for(int i=n;i>=0;i--)
			for (int j = n; j >= 0; j--) {
				if (i == n || j == n) {
					lcs[i][j] = 0;
					continue;
				}
				if (c[i] == r[j])lcs[i][j] = 1 + lcs[i + 1][j + 1];
				else
					lcs[i][j] = std::max(lcs[i + 1][j], lcs[i][j + 1]);
			}
		printf("%d\n", lcs[0][0]);
	}
	return 0;
}



/*
ex
1 2 3 4
1 3 2 4
first 
1 4 ->2
second
1 2 4
1 3 4 ->max 3


correct order
4 2 3 1

student choice order
1 3 2 4
first->0
second->1

3 2 1 4
first->1(2)
second
3 2
1 4 ->max 2

2 3 4 1
first->1(1)
second
2 3 1 ->max 3



1 2 3 4
1 3 2 4
->
start from left bottom to left upper
3 2 2 1
2 2 2 1
2 2 1 1
1 1 1 1



4 2 3 1
2 3 4 1 
->
3 2 2 1
2 2 2 1
1 1 1 1
1 1 0 0



4 2 3 1
3 2 1 4
->
2 2 1 1
2 2 1 0
2 1 1 0
1 1 1 0

*/
Many problems in Computer Science involve maximizing some measure 
according to constraints. Consider a history exam in which students 
are asked to put several historical events into chronological
order. Students who order all the events correctly will receive full 
credit, but how should partial credit be awarded to students who 
incorrectly rank one or more of the historical events?
Some possibilities for partial credit include:
1. 1 point for each event whose rank matches its correct rank
2. 1 point for each event in the longest (not necessarily contiguous) 
sequence of events which are in the correct order relative to each 
other.
For example, if four events are correctly ordered 1 2 3 4 then the 
order 1 3 2 4 would receive a score of 2 using the first method 
(events 1 and 4 are correctly ranked) and a score of 3 using the 
second method (event sequences 1 2 4 and 1 3 4 are both in the 
correct order relative to each other).
In this problem you are asked to write a program to score such 
questions using the second method.
Given the correct chronological order of n events 1; 2; : : : ; n as 
c1; c2; : : : cn where 1  ci  n denotes
the ranking of event i in the correct chronological order and a 
sequence of student responses r1; r2; : : : ; rn
where 1  ri  n denotes the chronological rank given by the 
student to event i; determine the length
of the longest (not necessarily contiguous) sequence of events in 
the student responses that are in the
correct chronological order relative to each other.



Input
The input file contains one or more test cases, each of them as 
described below.
The first line of the input will consist of one integer n indicating 
the number of events with 2  n  20. 
The second line will contain n integers, 
indicating the correct chronological order of n events.
The remaining lines will each consist of n integers with each line 
representing a student’s chronological ordering of the n events. 
All lines will contain n numbers in the range [1 : : : n], 
with each number appearing exactly once per line, 
and with each number separated from other numbers on the same line
by one or more spaces.

Output
For each test case, the output must follow the description below
For each student ranking of events your program should print the 
score for that ranking. 
There should be one line of output for each student ranking.
Warning: Read carefully the description and consider the difference 
between ’ordering’ and ’ranking’.



Sample Input
4
4 2 3 1
1 3 2 4
3 2 1 4
2 3 4 1
10
3 1 2 4 9 5 10 6 8 7
1 2 3 4 5 6 7 8 9 10
4 7 2 3 10 6 9 1 5 8
3 1 2 4 9 5 10 6 8 7
2 10 1 3 8 4 9 5 7 6

Sample Output
1
2
3
6
5
10
9