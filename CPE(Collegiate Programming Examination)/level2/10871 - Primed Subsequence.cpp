10871 - Primed Subsequence
https://github.com/Sharknevercries/Online-Judge/blob/master/UVA/Volume%20CVIII/10871%20Primed%20Subsequence.cpp



#include<cstdio>
bool check(int s) {
	int limit = sqrt(s);
	for (int i = 2; i*i <= s; i++)
		if (s%i == 0)
			return false;
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, T[1001] = {}, M[1001];
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", M + i);
		for (int i = 1; i <= n; i++)
			T[i] = T[i - 1] + M[i], //printf("T[%d] %d\n", i, T[i]);

		bool found = false;
		for (int i = 2; i <= n && !found; i++)
			for (int j = 1; i + j - 1 <= n && !found; j++) {
				//printf("i %d j %d T[%d](%d)-T[%d](%d)=%d\n", i, j, i + j - 1, T[i + j - 1], j - 1, T[j - 1], T[i + j - 1] - T[j - 1]);				
				if (check(T[i + j - 1] - T[j - 1])) {
					printf("Shortest primed subsequence is length %d:", i);
					for (int k = 0; k < i; k++)
						printf(" %d", M[j + k]);
					puts("");
					found = true;
				}
			}
		if (!found)
			puts("This sequence is anti-primed.");
	}
	return 0;
}



#include<stdio.h>
int check(int s) {
	for (int i = 2; i*i <= s; i++)
		if (s%i == 0)
			return false;
	return true;
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int T[1005] = {}, seq[1005] = {}, flag = true;
		for (int i = 1; i <= n; i++)
			scanf("%d", &seq[i]), T[i] = T[i - 1] + seq[i];
		for(int i=2;i<=n&&flag;i++)
			for(int j=1;j+i-1<=n&&flag;j++)
				if (check(T[i + j - 1] - T[j - 1])) {
					printf("Shortest primed subsequence is length %d:", i);
					for (int k = 0; k < i; k++)
						printf(" %d", seq[j + k]);
					flag = false;
				}
		if (flag)
			printf("This sequence is anti-primed.");
		puts("");
	}
	return 0;
}



/*
concept about "T[i + j - 1] - T[j - 1]"

ex 5   3 5 6 3 8
2 1 35(8)-0=35(8)
2 2 356(14)-3=56(11)->Shortest primed subsequence
2 3 3563(17)-35(8)=63(9)
2 4 35638(25)-356(14)=38(11)


*/



Given a sequence of positive integers of length n, we dene a primed 
subsequence as a consecutive subsequence of length at least two that 
sums to a prime number greater than or equal to two.
For example, given the sequence:
3 5 6 3 8
There are two primed subsequences of 
length 2 (5 + 6 = 11 and 3 + 8 = 11), 
one primed subsequence
of length 3 (6 + 3 + 8 = 17), and one primed subsequence of 
length 4 (3 + 5 + 6 + 3 = 17).



Input
Input consists of a series of test cases. The rst line consists of 
an integer t (1 < t < 21), the number
of test cases. Each test case consists of one line. 
The line begins with the integer n, 0 < n < 10001,
followed by n non-negative numbers less than 10000 comprising the 
sequence. You should note that
80% of the test cases will have at most 1000 numbers in the sequence.

Output
For each sequence, print the `Shortest primed subsequence is length 
x:', where x is the length
of the shortest primed subsequence, followed by the shortest primed 
subsequence, separated by spaces.
If there are multiple such sequences, print the one that occurs rst. 
If there are no such sequences,
print `This sequence is anti-primed.'.



Sample Input
3
5 3 5 6 3 8
5 6 4 5 4 12
21 15 17 16 32 28 22 26 30 34 29 31 20 24 18 33 35 25 27 23 19 21

Sample Output
Shortest primed subsequence is length 2: 5 6
Shortest primed subsequence is length 3: 4 5 4
This sequence is anti-primed.