10010 - Where's Waldorf?
https://saicheems.wordpress.com/2014/01/05/uva-10010-wheres-waldorf/



#include<cstdio>
#include<cstring>

using namespace std;

int t, n, m, k, len, r, c;
char grid[100][100], word[100];

int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool despite_case(char c, char d) {
	if (c == d) return true;
	if (c >= 'A' && c <= 'Z' && c == (d + 'A' - 'a'))
		return true;
	if (c >= 'a' && c <= 'z' && d == (c + 'A' - 'a'))
		return true;
	return false;
}

bool search(int r, int c) {
	for (int i = 0; i < 8; i++) {
		int rt = r, ct = c, k;
		for (k = 0; k < len; k++) {
			if (rt >= n || rt < 0 || ct >= m || ct < 0) break;
			if (!despite_case(grid[rt][ct], word[k])) break;
			rt += x[i], ct += y[i];
			//printf("rt %d ct %d\n", rt, ct);
		}
		if (k == len) return true;
	}
	return false;
}

void init() {
	for (r = 0; r < n; r++)
		for (c = 0; c < m; c++) {
			if (search(r, c))
				return;
		}
}

int main() {
	scanf("%d", &t);
	for (int u = 0; u < t; u++) {
		if (u != 0) printf("\n");

		scanf("%d %d\n", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", grid[i]);
		scanf("%d\n", &k);
		for (int i = 0; i < k; i++) {
			scanf("%s", word);
			len = strlen(word);

			init();
			printf("%d %d\n", r + 1, c + 1);
		}
	}
}



#include<cstdio>
#include<cstring>
int x[] = {-1,-1,-1,0,1,1,1,0};
int y[] = {-1,0,1,1,1,0,-1,-1};
int cas,n,m,N,len,r,c,k;
char grid[100][100], word[100];
bool search(int r, int c) {
	for (int i = 0; i < 8; i++) {
		int rr = r, cc = c;		
		for (k = 0; k < len; k++) {		
			if (cc < 0 || rr < 0 || n <= rr || m <= cc)
				break;
			if (grid[rr][cc] != word[k] &&
				grid[rr][cc] != (word[k] + ('A' - 'a')) &&
				word[k] != (grid[rr][cc] + ('A' - 'a')))
				break;
			rr += x[i];cc += y[i];		
		}
		if (k == len)
				return true;
	}
	return false;
}
void init() {
	for (r = 0; r < n; r++)
		for (c = 0; c < m; c++)
			if (search(r, c)) 
				return;		
}
int main() {
	scanf("%d", &cas);
	for (int i = 0; i < cas; i++) {
		if (i)
			puts("");
		scanf("%d %d\n", &n, &m);
		for (int j = 0; j < n; j++)
			scanf("%s", &grid[j]);
		scanf("%d\n", &N);
		for (int j = 0; j < N; j++) {
			scanf("%s", &word);
			len = strlen(word);
			init();
			printf("%d %d\n", r+1, c+1);
		}
	}
	return 0;
}



Given a m by n grid of letters, (1 ≤ m, n ≤ 50), and a list
of words, find the location in the grid at which the word 
can be found. A word matches a straight, uninterrupted line 
of letters in the grid. A word can match the letters in the 
grid regardless of case (i.e. upper and lower case letters 
are to be treated as the same). The matching can be done in
any of the eight directions either horizontally, vertically
or diagonally through the grid.



Input
The input begins with a single positive integer on a line 
by itself indicating the number of the cases following, 
each of them as described below. This line is followed by 
a blank line, and there is also a blank line between two 
consecutive inputs. The input begins with a pair of 
integers, m followed by n, 1 ≤ m, n ≤ 50 in decimal 
notation on a single line. The next m lines contain n 
letters each; this is the grid of letters in which the 
words of the list must be found. The letters in the grid 
may be in upper or lower case. Following the grid of 
letters, another integer k appears on a line by itself 
(1 ≤ k ≤ 20). The next k lines of input contain the list 
of words to search for, one word per line. These words may 
contain upper and lower case letters only (no spaces, 
hyphens or other non-alphabetic characters).

Output
For each test case, the output must follow the description 
below. The outputs of two consecutive cases will be 
separated by a blank line. For each word in the word list, 
a pair of integers representing the location of the 
corresponding word in the grid must be output. 
The integers must be separated by a single space. 
The first integer is the line in the grid where the first 
letter of the given word can be found (1 represents the 
topmost line in the grid, and m represents the bottommost 
line). The second integer is the column in the grid where 
the first letter of the given word can be found 
(1 represents the leftmost column in the grid, and n 
represents the rightmost column in the grid). 
If a word can be found more than once in the grid, then 
the location which is output should correspond to the 
uppermost occurence of the word (i.e. the occurence which 
places the first letter of the word closest to the top of 
the grid). If two or more words are uppermost, the output 
should correspond to the leftmost of these occurences. 
All words can be found at least once in the grid.



Sample Input
1
8 11
abcDEFGhigg
hEbkWalDork
FtyAwaldORm
FtsimrLqsrc
byoArBeDeyv
Klcbqwikomk
strEBGadhrb
yUiqlxcnBjf
4
Waldorf
Bambi
Betty
Dagbert

Sample Output
2 5
2 3
1 2
7 8


