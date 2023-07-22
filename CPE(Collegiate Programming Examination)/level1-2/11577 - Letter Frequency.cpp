11577 - Letter Frequency



#include <stdio.h>

int main() {
	int t;
	char str[999];
	scanf("%d", &t);
	getchar();
	while (t--) {
		fgets(str,999,stdin);
		int cnt[26] = {}, i;
		for (i = 0; str[i]; i++) {
			if (str[i] >= 'a' && str[i] <= 'z')
				cnt[str[i] - 'a']++;
			if (str[i] >= 'A' && str[i] <= 'Z')
				cnt[str[i] - 'A']++;
		}
		int max = 0;
		for (i = 0; i < 26; i++)
			max = max > cnt[i] ? max : cnt[i];
		for (i = 0; i < 26; i++)
			if (cnt[i] == max)
				printf("%c", i + 'a');
		puts("");
	}
	return 0;
}



#include<iostream>
int main()
{
	char str[999];
	int n;
	scanf("%d", &n);
	getchar();
	while (n--)
	{
		int cnt[26] = {};
		fgets(str, 999, stdin);
		for (int i = 0; str[i]; i++)
		{
			if ('a' <= str[i] && str[i] <= 'z')
				cnt[str[i] - 'a']++;
			if ('A' <= str[i] && str[i] <= 'Z')
				cnt[str[i] - 'A']++;
		}
		int max = 0;
		for (int i = 0; i < 26; i++)
			max = max > cnt[i] ? max : cnt[i];
		for (int i = 0; i < 26; i++)
			if (max == cnt[i])
				printf("%c", i + 'a');
		puts("");
	}
}



In this problem we are interested in the frequency of 
letters in a given line of text. Specifi-cally, 
we want to know the most frequently occurring letter(s) 
in the text, ignoring case (to be clear, “letters” 
refers precisely to the 26 letters of the alphabet).



Input
Input begins with the number of test cases on its own 
line. Each test case consists of a single line of
text. The line may contain non-letter characters, but is 
guaranteed to contain at least one letter and
less than 200 characters in total.

Output
For each test case, output a line containing the most 
frequently occurring letter(s) from the text in
lowercase (if there are ties, output all such letters 
in alphabetical order).



Sample Input
1
Computers account for only 5% of the country’s 
commercial electricity consumption.

Sample Output
co