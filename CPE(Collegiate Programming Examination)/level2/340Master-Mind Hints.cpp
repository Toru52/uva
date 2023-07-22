340	Master-Mind Hints



#include <cstdio>

int main() {
	int n, a, b, tmp1, tmp2, game = 0, s[1000], g[1000];

	while (~scanf("%d", &n) && n) {	
		for (int i = 0; i < n; ++i)
			scanf("%d", &s[i]);
		printf("Game %d:\n", ++game);

		while (true) {
			tmp1 = tmp2 = b = a = 0;
			for (int i = 0; i < n; ++i) {
				scanf("%d", &g[i]);
				if (s[i] == g[i]) 
					++a;
			}
			if (!g[0]) 
				break;
			for (int i = 1; i < 10; ++i) {
				for (int j = 0; j < n; ++j) {
					if (s[j] == i) 
						++tmp1;
					if (g[j] == i)
						++tmp2;
				}
				if (tmp1 && tmp2) 
					b = b + (tmp1 < tmp2 ? tmp1 : tmp2);
				tmp1 = tmp2 = 0;
			}
			printf("    (%d,%d)\n", a, b - a);
		}
	}
	return 0;
}



#include<cstdio>
int main()
{
	int n, game=0,F[1000], S[1000];
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &F[i]);
		printf("Game %d:\n", ++game);

		while (1) {
			int f = 0, s = 0, cnt1 = 0, cnt2 = 0;
			for (int i = 0; i < n; i++) {
				scanf("%d", &S[i]);
				if (S[i] == F[i])
					f++;
			}
			if (!S[0])
				break;
			for (int i = 1; i < 10; i++) {
				for (int j = 0; j < n; j++) {
					if (i == F[j])
						cnt1++;
					if (i == S[j])
						cnt2++;
				}
				if (cnt1&&cnt2)
					s += cnt1 < cnt2 ? cnt1 : cnt2;
				cnt1 = cnt2 = 0;
			}
			printf("    (%d,%d)\n", f, s - f);
		}
	}
}



MasterMind is a game for two players. One of them, Designer, selects a 
secret code. The other, Breaker,tries to break it. A code is no more 
than a row of colored dots. At the beginning of a game, the players
agree upon the length N that a code must have and upon the colors that 
may occur in a code.In order to break the code, Breaker makes a number
of guesses, each guess itself being a code. After each guess 
Designer gives a hint, stating to what extent the guess matches his 
secret code. In this problem you will be given a secret code s1 . . . 
sn and a guess g1 . . . gn, and are to determine the hint. 
A hint consists of a pair of numbers determined as follows.
A match is a pair (i, j), 1 ≤ i ≤ n and 1 ≤ j ≤ n, such that si = gj . 
Match (i, j) is called strong when i = j, and is called weak otherwise.
 Two matches (i, j) and (p, q) are called independent when
i = p if and only if j = q. A set of matches is called independent 
when all of its members are pairwise independent.
Designer chooses an independent set M of matches for which the total 
number of matches and the number of strong matches are both maximal. 
The hint then consists of the number of strong followed by the number 
of weak matches in M. Note that these numbers are uniquely determined 
by the secret code and the guess. If the hint turns out to be (n, 0), 
then the guess is identical to the secret code.



Input
The input will consist of data for a number of games. The input for 
each game begins with an integer specifying N (the length of the code).
 Following these will be the secret code, represented as N integers,
which we will limit to the range 1 to 9. There will then follow an 
arbitrary number of guesses, each also represented as N integers, 
each in the range 1 to 9. Following the last guess in each game will 
be N zeroes; these zeroes are not to be considered as a guess.
Following the data for the first game will appear data for the second 
game (if any) beginning with a new value for N. The last game in the 
input will be followed by a single ‘0’ (when a value for N would
normally be specified). The maximum value for N will be 1000.

Output
The output for each game should list the hints that would be generated 
for each guess, in order, one hint per line. Each hint should be 
represented as a pair of integers enclosed in parentheses and separated
by a comma. The entire list of hints for each game should be prefixed 
by a heading indicating the game number;games are numbered sequentially
 starting with 1. Look at the samples below for the exact format.



Sample Input
4
1 3 5 5
1 1 2 3
4 3 3 5
6 5 5 1
6 1 3 5
1 3 5 5
0 0 0 0
10
1 2 2 2 4 5 6 6 6 9
1 2 3 4 5 6 7 8 9 1
1 1 2 2 3 3 4 4 5 5
1 2 1 3 1 5 1 6 1 9
1 2 2 5 5 5 6 6 6 7
0 0 0 0 0 0 0 0 0 0
0
Sample Output
Game 1:
(1,1)
(2,0)
(1,2)
(1,2)
(4,0)
Game 2:
(2,4)
(3,2)
(5,0)
(7,0)