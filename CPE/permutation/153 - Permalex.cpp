153 - Permalex
http://mypaper.pchome.com.tw/zerojudge/post/1323074550



#include <stdio.h>
#include <string.h>
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int main() {
	char s[50];
	while (scanf("%s", s),s[0]!='#') {
		int cnt[26] = {}, len = strlen(s);
		for (int i = 0; s[i]; i++) 
			cnt[s[i] - 'a']++;
		
		long long ans = 0;
		for (int i = 0; s[i]; i++) {
			for (int j = 0; j < s[i] - 'a'; j++) {
				if (cnt[j] == 0) 
					continue;
				cnt[j]--;
				int set[50] = {};
				for (int k = 2; k < len - i; k++)
					set[k] = k;
				for (int k = 0; k < 26; k++) {
					for (int l = 2; l <= cnt[k]; l++) {
						int tmp = l;
						for (int a = 2; a < len - i; a++) {
							int g = gcd(tmp, set[a]);
							tmp /= g;
							set[a] /= g;
						}
					}
				}
				long long tmp = 1;
				for (int k = 2; k < len - i; k++)
					tmp *= set[k];
				ans += tmp;
				cnt[j]++;
			}
			cnt[s[i] - 'a']--;
		}
		printf("%10lld\n", ans + 1);
	}
	return 0;
}



Given a string of characters, we can permute the individual 
characters to make new strings. 
If we can impose an ordering on the characters 
(say alphabetic sequence), then the strings themselves can
be ordered and any given permutation can be given a unique 
number designating its position in that ordering. 
For example the string ‘acab’ gives rise to the following 12 
distinct permutations:
aabc 1 acab 5 bcaa 9
aacb 2 acba 6 caab 10
abac 3 baac 7 caba 11
abca 4 baca 8 cbaa 12
Thus the string ‘acab’ can be characterised in this sequence as 5.
Write a program that will read in a string and determine its 
position in the ordered sequence of permutations of its 
constituent characters. Note that numbers of permutations can 
get very large;
however we guarantee that no string will be given whose position 
is more than 231􀀀1 = 2; 147; 483; 647.



Input
Input will consist of a series of lines, each line containing 
one string. Each string will consist of up to
30 lower case letters, not necessarily distinct. 
The file will be terminated by a line consisting of a single ‘#’.

Output
Output will consist of a series of lines, one for each line of 
the input. Each line will consist of the
position of the string in its sequence, 
right justified in a field of width 10.



Sample Input
bacaa
abc
cba
#

Sample Output
15
16