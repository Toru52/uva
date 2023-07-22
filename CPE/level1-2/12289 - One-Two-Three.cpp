12289 - One-Two-Three



#include<stdio.h>
#include<string.h>

int main() {
	int T;
	char s[6];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		if (strlen(s) == 5)    
			puts("3");
		else {
			int t = 0;
			if (s[0] == 'o') t++;
			if (s[1] == 'n') t++;
			if (s[2] == 'e') t++;
			puts(t >= 2 ? "1" : "2");
		}
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char s[12];
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", &s);
		if (strlen(s) == 5)
			puts("3");
		else {
			int c = 0;
			if (s[0] == 'o')c++;
			if (s[1] == 'n')c++;
			if (s[2] == 'e')c++;
			puts(c >= 2 ? "1" : "2");
		}
	}
}



Your little brother has just learnt to write one, two and three, 
in English. He has written a lot of those words in a paper, 
your task is to recognize them. Note that your little brother is 
only a child, so he may make small mistakes: for each word, there 
might be at most one wrong letter. The word length is always 
correct. It is guaranteed that each letter he wrote is in 
lower-case, and each word he wrote has a unique interpretation.



Input
The first line contains the number of words that your little 
brother has written. Each of the following lines contains a 
single word with all letters in lower-case. The words satisfy 
the constraints above: at most one letter might be wrong, 
but the word length is always correct. 
There will be at most 10 words in the input.

Output
For each test case, print the numerical value of the word.



Sample Input
3
owe
too
theee

Sample Output
1
2
3