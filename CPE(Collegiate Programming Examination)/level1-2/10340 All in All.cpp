10340	All in All



no1
#include <cstdio>
char s[100000], t[100000];

int main()
{
	while (scanf("%s%s", s, t) != EOF) {
		int i = 0, j = 0;
		for (; t[i]; i++) {
			if (t[i] == s[j]) j++;
		}
		if (!s[j]) 
			printf("Yes\n");
		else
			printf("No\n");
	}
}



no2
#include<stdio.h>
char a[100000], b[100000];
int main()
{
	while (~scanf("%s %s", &a, &b))
	{
		int s = 0;
		for (int i=0; b[i]; i++)
			if (b[i] == a[s])
				s++;
		if (a[s])
			puts("No");
		else
			puts("Yes");
	}
}



You have devised a new encryption technique which encodes a message 
by inserting between its characters randomly generated strings in a 
clever way. Because of pending patent issues we will not discuss in
detail how the strings are generated and inserted into the original 
message. To validate your method, however, it is necessary to write 
a program that checks if the message is really encoded in the final
string. Given two strings s and t, you have to decide whether s is a 
subsequence of t, i.e. if you can remove characters from t such that 
the concatenation of the remaining characters is s.



Input
The input contains several testcases. Each is specified by two 
strings s, t of alphanumeric ASCII characters separated by whitespace. 
Input is terminated by EOF.

Output
For each test case output, if s is a subsequence of t.



Sample Input
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter

Sample Output
Yes
No
Yes
No