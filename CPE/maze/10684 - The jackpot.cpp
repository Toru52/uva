10684 - The jackpot
https://prosenc.blogspot.tw/2016/03/uva-10684-jackpot-problem-solution.html



#include<iostream>
using namespace std;

int main() {
	int n,a;
	while (cin >> n && n) {
		int sum = 0,mx =-9999;
		for (int i = 0; i < n; i++) {
			cin >> a;
			sum += a;
			if (sum > mx)mx = sum;
			if (sum < 0)sum = 0;
		}
		(mx > 0) ? 
			cout << "The maximum winning streak is " << mx << "." << endl 
			: cout << "Losing streak." << endl;
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, a;
	while (scanf("%d", &n), n) {
		int sum = 0, mx = -9999;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a);
			sum += a;
			if (sum > mx)mx = sum;
			if (sum < 0)sum = 0;
		}
		if (mx > 0)printf("The maximum winning streak is %d.\n", mx);
		else puts("Losing streak.");
	}
	return 0;
}



As Manuel wants to get rich fast and without too much work, 
he decided to make a career in gambling.
Initially, he plans to study the gains and losses of players, 
so that, he can identify patterns of consecutive
wins and elaborate a win-win strategy. But Manuel, as smart as he thinks
he is, does not know how to program computers. 
So he hired you to write programs that will assist him in elaborating 
his strategy.
Your rst task is to write a program that identies the maximum 
possible gain out of a sequence of bets.
A bet is an amount of money and is either winning 
(and this is recorded as a positive value), or
losing (and this is recorded as a negative value



Input
The input set consists of a positive number N  10000 , 
that gives the length of the sequence, followed
by N integers. Each bet is an integer greater than 0 and less than 1000.
The input is terminated with N = 0.

Output
For each given input set, the output will echo a line with the 
corresponding solution. If the sequence
shows no possibility to win money, then the output is the message 
`Losing streak.'



Sample Input
5
12 -4
-10 4
9
3
-2 -1 -2
0

Sample Output
The maximum winning streak is 13.
Losing streak.