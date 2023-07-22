10298 - Power Strings 
http://theinfinitytutorial.blogspot.tw/2013/09/uva-10298-power-strings.html

KMP
http://capm-network.com/?tag=C%E8%A8%80%E8%AA%9E%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0-KMP%E6%B3%95




#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int power, len,ans;
	char s[1000005];

	while (scanf("%s", &s) ,s[0]!='.') {
		len = strlen(s);
		for (int i = 1; i <= len; i++) 
			if (len % i == 0) {
				power = len / i;
				ans = true;
				for (int j = 0; j < i; j++) 
					for (int k = j + i; k < len; k += i) {
						//printf("s[%d] = %c s[%d] = %c\n",j, s[j],k, s[k]);
						if (s[j] != s[k]) {
						//	printf("s[%d](%c)!=s[%d](%c)\n", j,s[j], k,s[k]);
							ans = false;
							break;
						}
					}
				if (ans)break;
			}
		printf("%d\n", power);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main() {
	int ans, pow, len;
	char s[1000005];
	while (scanf("%s", &s), s[0] != '.') {
		len = strlen(s);
		for (int i = 1; i <= len; i++) {
			if (len%i == 0) {
				pow = len / i;
				ans = true;
				for(int j=0;j<i;j++)
					for (int k = j + i; k < len; k += i) 
						if (s[j] != s[k]) {
							ans = false;
							break;
						}	
			}		
			if (ans)break;	
		}
		printf("%d\n", pow);
	}
	return 0;
}



Given two strings
a
and
b
we de ne
a

b
to be their concatenation. For
example, if
a
= `
abc
' and
b
= `
def
' then
a

b
= `
abcdef
'. If we think of
concatenation as multiplication, exponentiation by a non-negative 
integer is de ned in the normal way:
a
0
= `' (the empty string) and
a
(
n
+1)
=
a

(
a
n
).

Input
Each test case is a line of input representing
s
, a string of printable char-
acters. The length of
s
will be at least 1 and will not exceed 1 million
characters. A line containing a period follows the last test case

Output
For each
s
you should print the largest
n
such that
s
=
a
n
for some string
a
.



SampleInput
abcd
aaaa
ababab
.

SampleOutput
1
4
3