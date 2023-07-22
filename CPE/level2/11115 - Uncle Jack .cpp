11115 - Uncle Jack 
https://github.com/morris821028/UVa/blob/master/volume111/11115%20-%20Uncle%20Jack.cpp



#include <stdio.h>

int main() {
	int x, y,i,j;
	while (scanf("%d %d", &x, &y),x) {
		int m[50][50] = { 1 };

		for (i = 1; i <= y; i++) {
			for (j = 0; j < 50; j++)
				m[i][j] = m[i - 1][j] * x;
			for (j = 0; j < 50; j++)
				if (m[i][j] >= 10) {
					m[i][j + 1] += m[i][j] / 10;
					m[i][j] %= 10;
				}
		}
		i = 49;
		while (m[y][i] == 0) i--;
		while (i >= 0)
			putchar(m[y][i] + '0'), i--;
		puts("");
	}
	return 0;
}



#include <stdio.h>

int main() {
	int N, D,i,j;
	while (scanf("%d %d", &N, &D),N) {
		int m[50][50] = { 1 };

		for (i = 1; i <= D; i++) {
			for (j = 0; j < 50; j++)
				m[i][j] = m[i - 1][j] * N;
			for (j = 0; j < 50; j++)
				if (m[i][j] >= 10) {
					m[i][j + 1] += m[i][j] / 10;
					m[i][j] %= 10;
				}
		}
		i = 49;
		while (m[D][i] == 0) i--;
		while (i >= 0)
			putchar(m[D][i] + '0'), i--;
		puts("");
	}
	return 0;
}



Dear Uncle Jack is willing to give away some of his collectable 
CDs to his nephews. Among the titles you can nd very rare 
albums of Hard Rock, Classical Music, Reggae and much more; 
each title is considered to be unique. Last week he was listening 
to one of his favorite songs, Nobody's fool, and realized that it
would be prudent to be aware of the many ways he can give away
the CDs among some of his nephews.
So far he has not made up his mind about the total amount of CDs 
and the number of nephews.
Indeed, a given nephew may receive no CDs at all.
Please help dear Uncle Jack, given the total number of CDs and 
the number of nephews, to calculate the number of different ways 
to distribute the CDs among the nephews.



Input
The input consists of several test cases. Each test case is given 
in a single line of the input by, space separated, 
integers N (1  N  10) and D (0  D  25), 
corresponding to the number of nephews and the number of CDs 
respectively. The end of the test cases is indicated with 
N = D = 0.

Output
The output consists of several lines, one per test case, 
following the order given by the input. Each line has the number 
of all possible ways to distribute D CDs among N  nephews.



Sample Input
1 20
3 10
0 0

Sample Output
1
59049