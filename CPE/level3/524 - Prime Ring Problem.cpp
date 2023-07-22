524 - Prime Ring Problem
https://saicheems.wordpress.com/2013/08/09/uva-524-prime-ring-problem/



#include<stdio.h>
int cas = 0, n,C[20];
bool used[20];
bool P(int p) {
	for (int i = 2; i*i <= p; i++)
		if (p % i == 0) return false;
	return true;
}
void dfs(int m) {
	if (m == n - 1 && P(C[n - 1] + C[n])) {
		for (int i = 0; i < n; i++)
			printf(i == n - 1 ? "%d" : "%d ", C[i]);
		printf("\n");
		return;
	}
	for (int i = 2; i <= n; i++)
		if (!used[i] && P(C[m] + i)) {
			used[i] = true;
			C[m + 1] = i;
			dfs(m + 1);
			used[i] = false;
		}
}
int main() {
	while (scanf("%d", &n) == 1) {
		if (cas)
			printf("\n");
		//S        E
		C[0] = 1, C[n] = 1;
		printf("Case %d:\n", ++cas);
		dfs(0);
	}
	return 0;
}



#include<stdio.h>
int n, cas = 0, C[20]{ 1 };
bool used[20]{};
bool P(int p) {
	for (int i = 2; i*i <= p; i++)
		if (p%i == 0)
			return false;
	return true;
}
void dfs(int i) {
	if (i + 1 == n&&P(1 + C[i])) {
		for (int j = 0; j < n; j++)
			printf(j == 0 ? "%d" : " %d", C[j]);
		puts("");
		return;
	}
	for (int v = 2; v <= n; v++) 
		if (!used[v] && P(C[i] + v)) {
			used[v] = true;
			C[i + 1] = v;
			dfs(i + 1);
			used[v] = false;
		}
}
int main() {
	while (scanf("%d", &n) == 1) {
		if (cas)puts("");
		printf("Case %d:\n", ++cas);
		C[n] = 1;
		dfs(0);
	}
	return 0;
}


A ring is composed of n (even number) circles as shown in diagram.
Put natural numbers 1; 2; : : : ; n into each circle separately, 
and the sum of numbers in two adjacent circles should be a prime.
Note: the number of first circle should always be 1.



Input
n (0 < n  16)
Output
The output format is shown as sample below. Each row represents a 
series of circle numbers in the ring beginning from 1 clockwisely 
and anticlockwisely. The order of numbers must satisfy the above
requirements.
You are to write a program that completes above process.



Sample Input
68

Sample Output
Case 1:
1 4 3 2 5 6
1 6 5 2 3 4
Case 2:
1 2 3 8 5 6 7 4
1 2 5 8 3 4 7 6
1 4 7 6 5 8 3 2
1 6 7 4 3 8 5 2