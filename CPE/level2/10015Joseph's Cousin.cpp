10015	Joseph's Cousin



#include <stdio.h>

int Pt = 1, P[5500];
void sieve() {
	char mark[50000] = {};
	int i, j;
	for (i = 2; i < 50000; i++) {
		if (!mark[i]) {
			P[Pt++] = i;
			for (j = 2 * i; j < 50000; j += i)
				mark[j] = 1;
		}
	}
}
int main() {
	sieve();
	int n, i, j, st[8193];
	while (scanf("%d", &n) == 1 && n) {
		int M;
		for (M = 1; M < n + 1; M <<= 1);
		for (i = 2 * M - 1; i > 0; i--) {
			if (i >= M)
				st[i] = 1;
			else
				st[i] = st[i << 1] + st[i << 1 | 1];
			//i=i*2+(i*2+1(or));
		}
		int m, last, prev = 0, s;
		for (i = 1; i <= n; i++) {
			m = (P[i] + prev) % (n - i + 1);
			if (m == 0)
				m = n - i + 1;
			prev = m - 1;
			for (s = 1; s < M;) {
				if (st[s << 1] < m)
					m -= st[s << 1], s = s << 1 | 1;
				else
					s = s << 1;
			}
			last = s - M + 1;
			while (s) {
				st[s] --;
				s >>= 1;
			}
		}
		printf("%d\n", last);
	}
	return 0;
}



#include<stdio.h>
int P[5500];
void prime() {
	char mark[50000] = {};
	int cnt = 1;
	for (int i = 2; i < 50000; i++) {
		if (!mark[i]) {
			P[cnt++] = i;
			for (int j = 2 * i; j < 50000; j += i)
				mark[j] = 1;
		}
	}
}

int main() {
	int n,M,st[8200];
	prime();
	while (scanf("%d", &n) == 1 && n) {
		for (M = 1; M <= n; M <<= 1);
		for (int i = M * 2-1; i > 0; i--) 
			if (M <= i)
				st[i] = 1;
			else
				st[i] = st[i << 1]+ st[i << 1 | 1];
		int m, s,last,prev = 0 ;
		for (int i = 1; i <= n; i++) {
			m = (P[i] + prev) % (n - i + 1);
			if (m == 0)
				m = (n - i + 1);
			prev = m - 1;
			for (s = 1; s < M;)
				if (st[s << 1]<m)
					m -=st[s<<1] , s = s << 1 | 1;
				else
					s <<= 1;
			last = s - M + 1;
			while (s) {
				st[s]--;
				s >>= 1;
			}
		}
		printf("%d\n", last);
	}
}




prime number
2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47



The Josephs problem is notoriously known. For those who are not 
familiar with the problem, among n people numbered 1, 2, . . . , n, 
standing in circle every mth is going to be executed and only the life 
of the last remaining person will be saved. Joseph was smart enough to 
choose the position of the last remaining person, thus saving his life 
to give the message about the incident. Although many good programmers 
have been saved since Joseph spread out this information,
Josephs Cousin introduced a new variant of the malignant game. 
This insane character is known for its barbarian ideas and wishes to 
clean up the world from silly programmers. We had to infiltrate
some the agents of the ACM in order to know the process in this new 
mortal game. In order to save yourself from this evil practice, 
you must develop a tool capable of predicting which person will be 
saved. The Destructive Process The persons are eliminated in a very 
peculiar order; m is a dynamical variable, which each time
takes a different value corresponding to the prime numbers succession 
(2,3,5,7,...). So in order to kill the i-th person, Josephs cousin 
counts up to the i-th prime.



Input
It consists of separate lines containing n [1..3501], and finishes 
with a ‘0’.

Output
The output will consist in separate lines containing the position of 
the person which life will be saved.



Sample Input
6
0

Sample Output
4