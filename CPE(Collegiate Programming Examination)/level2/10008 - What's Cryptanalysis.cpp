10008 - What's Cryptanalysis?



#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;

int main() {
	int tc;
	char c;
	int freq[26] = {};
	priority_queue<pair<int, int> > pq;

	scanf("%d", &tc);
	while (scanf("%c", &c) != EOF) {
		if (!isalpha(c))
			continue;
		freq[toupper(c) - 'A']++;
	}

	for (int i = 0; i < 26; i++) 
		if (freq[i] > 0)
			pq.push(make_pair(freq[i], -(i + 'A')));

	while (!pq.empty()) {
		printf("%c %d\n", -pq.top().second, pq.top().first);
		pq.pop();
	}
	return 0;
}



#include<cstdio>
#include<cctype>
#include<queue>
using namespace std;
int main() {
	int n, freq[26] = {};
	priority_queue<pair<int, int>>pq;
	char c;
	scanf("%d", &n);
	while (~scanf("%c",&c)) {
		if (!isalpha(c))
			 continue;
		freq[toupper(c) - 'A']++;
	}
	for (int i = 0; i < 26; i++)
		if (freq[i])
			pq.push(make_pair(freq[i], -(i + 'A')));
	while (!pq.empty()) {
		printf("%c %d\n", -pq.top().second, pq.top().first);
		pq.pop();
	}
}



Cryptanalysis is the process of breaking someone else’s 
cryptographic writing. This sometimes involves
some kind of statistical analysis of a passage of 
(encrypted) text. Your task is to write a program which
performs a simple analysis of a given text.



Input
The first line of input contains a single positive decimal 
integer n. This is the number of lines which follow in the 
input. The next n lines will contain zero or more 
characters (possibly including whitespace).
This is the text which must be analyzed.

Output
Each line of output contains a single uppercase letter, 
followed by a single space, then followed by a positive 
decimal integer. The integer indicates how many times the 
corresponding letter appears in the input text. Upper and 
lower case letters in the input are to be considered the 
same. No other characters must be counted. The output must 
be sorted in descending count order; that is, the most
frequent letter is on the first output line, and the last 
line of output indicates the least frequent letter.
If two letters have the same frequency, then the letter 
which comes first in the alphabet must appear first in the 
output. If a letter does not appear in the text, then that 
letter must not appear in the output.



Sample Input
3
This is a test.
Count me 1 2 3 4 5.
Wow!!!! Is this question easy?

Sample Output
S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1