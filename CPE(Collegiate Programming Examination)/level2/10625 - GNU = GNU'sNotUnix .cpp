10625 - GNU = GNU'sNotUnix 
https://github.com/morris821028/UVa/blob/master/volume106/10625%20-%20GNU%20%3D%20GNU'sNotUnix.cpp



#include <stdio.h>
#include <map>
using namespace std;

int main() {
	int t, n, m;
	char c, s[1024];
	scanf("%d", &t);
	while (t--) {
		scanf("%d ", &n);
		map<int, int> g[128];
		while (n--) {
			scanf("%c->%s ", &c, s);
			for (int i = 0; s[i]; i++)
				g[c][s[i]]++;
		}
		scanf("%d", &m);
		while (m--) {
			scanf("%s %c %d", s, &c, &n);
			unsigned long long cnt[128] = {};
			for (int i = 0; s[i]; i++)
				cnt[s[i]]++;
			while (n--) {
				unsigned long long flag,tmp[128] = {};
				for (int i = 33; i <= 126; i++) {
					flag = 1;
					for (map<int, int>::iterator it = g[i].begin();
						it != g[i].end(); it++)
						tmp[it->first] += cnt[i] * it->second, flag = 0, printf("i %c tmp[%c]=%llu\n",i, it->first, tmp[it->first]);
					                    //sum count generate character 
					tmp[i] += cnt[i] * flag;
					if(tmp[i])
						printf("tmp[%c]=%llu\n\n", i, tmp[i]);
				}
			for (int i = 33; i <= 126; i++)
					cnt[i] = tmp[i];
			printf("%c %llu\n",c, cnt[c]);
			}
			printf("%llu\n", cnt[c]);
		}
	}
	return 0;
}



#include<stdio.h>
#include<map>
using namespace std;
int main() {
	int t, n, m;
	char c, s[1024];
	scanf("%d", &t);
	while (t--) {
		map<int, int>g[128];
		scanf("%d ", &n);
		while (n--) {
			scanf("%c->%s ", &c,s);
			for (int i = 0; s[i]; i++)
				g[c][s[i]]++;
		}
		scanf("%d", &m);
		while (m--) {
			unsigned long long cnt[128] = {};
			scanf("%s %c %d",s, &c, &n);
			for (int i = 0; s[i]; i++)
				cnt[s[i]]++;
			while (n--) {
				unsigned long long flag, tmp[128] = {};
				for (int i = 33; i <= 126; i++) {
					flag = 1;
					for (map<int, int>::iterator it = g[i].begin();
						it != g[i].end(); it++)
						tmp[it->first] += cnt[i] * it->second, flag = 0;
					tmp[i] += cnt[i] * flag;
				}
				for (int i = 33; i <= 126; i++)
					cnt[i] = tmp[i];
			}
			printf("%llu\n", cnt[c]);
		}
	}
	return 0;
}



/*
concept
2
3
G->GNU's
N->Not
U->Unix
2
GNU t 3 ->;
GNU N 3(step3)
->step0 GNU (initial_strings)
->(step3)GNU'sNotUnix'sNototUnixnix'sNotototUnixnixnix ->N=4
->4
1
A->BAcX
1
ABCcXA c 10000
->step0 ABCcXA (initial_strings )
->(step10000) ->c 20000

(extra ex)
c c 10000
->step0 c 
->1   (Since step0 strings no touch with initial character,
       So it can not to generate to increase)
	   
input ->apeeared number
output->generate count number
*/



Let us de ne GNU, the recursive acronym for
GNU's Not Unix with the following recursive rules:
1.
G {
>
GNU's
2.
N {
>
Not
3.
U {
>
Unix
In each step we apply all the rules simultaneously.
If a character in a string does not have a rule associated
with it (there will be at most one rule per character),
it remains in the string.
For example if we start with GNU, we get:
Step
String
0
GNU
1
GNU'sNotUnix
2
GNU'sNotUnix'sNototUnixnix
3
GNU'sNotUnix'sNototUnixnix'sNotototUnixnixnix
4
GNU'sNotUnix'sNototUnixnix'sNotototUnixnixnix'
sNototototUnixnixnixnix
. . .
. . .
As you can see, the strings are growing larger in every steps. 
And in certain cases the growth can be
quite fast. Fear not, for we're not interested in the entire 
string. We just want to know the frequency
of a particular character after a  nite number of steps.
Input
The  rst line of the input starts with an integer,
T
(1

T

10), the number of test cases. Then
T
test cases will follow. The  rst line of each test case will 
give you
R
, (1

R

10) the number of
rules. In each of the next
R
lines there will be one rule. The rules are written in the 
following format:
`
x
->
S
' (without the quotes). Here
x
is a single character and
S
is a sequence of characters. You can
assume that the ASCII value of the characters lie in the range 
33 to 126, that
S
will contain no more
than 100 characters. You can also assume that the symbols `
-
' and `
>
' won't appear in
S
. The rules
can be immediately recursive, recursive in a cycle or not 
recursive at all. After the rules, you'll  nd
an integer
Q
(1

Q

10), the number of queries to follow. Each of the
Q
queries will be presented
in the format \
initial
string x n
" in a single line, where
initial
string
is the string that you have in
step 0 (with length between 1 and 100),
x
is the character whose frequency you should count, and
n
(1

n

10000) is the number of times the rules should be applied. 
All characters in the initial string
will have ASCII values in the range 33 to 126.
Output
For each query, print the number of occurances of the particular 
character in the result string after
applying the rules
n
times, starting with the initial string.  
The output will always  t in a 64-bit
unsigned integer.



SampleInput
2
3
G->GNU's
N->Not
U->Unix
2
GNU t 3
GNU N 3
1
A->BAcX
1
ABCcXA c 10000

SampleOutput
6
4
20001