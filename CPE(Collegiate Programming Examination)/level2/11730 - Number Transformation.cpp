11730 - Number Transformation
https://github.com/morris821028/UVa/blob/master/volume117/11730%20-%20Number%20Transformation.cpp
concept
http://kos74185foracm.blogspot.tw/2013/07/11730-number-transformation.html



#include <stdio.h>
#include <queue>
using namespace std;
int p[1005], pt;
void prime() {
	int mark[1005] = {};
	pt = 0;
	for (int i = 2; i < 1000; i++)
		if (mark[i] == 0) {
			for (int j = i + i; j < 1000; j += i)
				mark[j] = 1;
			p[pt++] = i;
		}
}
int main() {
	prime();
	int A, B, cas = 0;
	while (scanf("%d %d", &A, &B), A) {
		queue<int> Q;
		int dp[1005] = {}, used[1005] = {};
		Q.push(A);
		used[A] = 1;
		while (!Q.empty() && !used[B]) {
			A = Q.front(), Q.pop();
			for (int i = 0; i < pt && p[i] < A; i++)
				if (used[A + p[i]] == 0 && A%p[i] == 0)
					if (A + p[i] <= B) {
						printf("i %d A %d p[i] %d\n", i, A, p[i]);
						dp[A + p[i]] = dp[A] + 1, used[A + p[i]] = 1;
						Q.push(A + p[i]);
					}
		}
		printf("Case %d: ", ++cas);
		if (used[B])
			printf("%d\n", dp[B]);
		else
			puts("-1");
	}
	return 0;
}



#include<stdio.h>
#include<queue>
using namespace std;
int A,B,pt = 0, p[1005]{}, cas = 0;
void prime() {
	int mark[1005]{};
	for (int i = 2; i < 1000; i++) 
		if (!mark[i]) {
			for (int j = i + i; j < 1000; j += i)
				mark[j] = 1;
			p[pt++] = i;
		}
}
int main() {
	prime();
	while (scanf("%d %d", &A, &B), A) {
		queue<int>Q;
		int used[1005]{}, dp[1005]{};
		Q.push(A);
		used[A] = 1;
		while (!used[B] && !Q.empty()) {
			A = Q.front(), Q.pop();
			for(int i=0;i<pt&&p[i]<A;i++)
				if (!used[p[i] + A] && !(A%p[i])) 
					if (A + p[i] <= B) {
						dp[A + p[i]] = dp[A] + 1, used[A + p[i]]=1;
						Q.push(A + p[i]);
					}
		}
		printf("Case %d: ", ++cas);
		if (used[B])
			printf("%d\n", dp[B]);
		else
			puts("-1");
	}
	return 0;
}






You are given an integer number S. You can transform any integer 
number A to another integer number B by adding x to A. 
This x is an integer number which is a prime factor of A 
(Please note that 1 and A are not being considered as a factor of 
A). Now, your task is to nd the minimum number of 
transformations required to transform S to another integer number T.



Input
For each test case, there will be a line with two integers, 
S (1  S  100) & T (1  T  1000), as described above. 
The last test case will be followed by a line with two 0's 
denoting end of input. This case should not be processed.

Output
For every test case except the last one, print a line of the form 
`Case X: Y ' where X is the serial number of output (starting from
1). Y is the minimum number of transformations required to 
transform S to T. If it is not possible to make T from S with the 
given rules, Y shall be `-1'. Explanation of case 1:
You can make 12 from 6 in 2 steps in this way: 6 ! 9 ! 12.



Sample Input
6 12
6 13
0 0

Sample Output
Case 1: 2
Case 2: -1