11192	Group Reverse



#include <stdio.h>
#include <string.h>

int main() {
	int g;
	char str[101];
	while (scanf("%d", &g) == 1 && g) {
		scanf("%s", str);
		int len = strlen(str), p = len / g;
		for (int i = 0; i < len; i += p) {
			for (int j = i + p - 1; j >= i; j--)
				putchar(str[j]);
		}
		puts("");
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main()
{
	int g;
	char s[48];
	while (scanf("%d ", &g) == 1 && g)
	{
		scanf("%s", &s);
		int len = strlen(s), p = len / g;

		for (int i = 0; i < len; i += p)
			for (int j = i + p - 1; j >= i; j--)
				putchar(s[j]);
		puts("");
	}
}



Group reversing a string means reversing a string by 
groups. For example consider a string:
“TOBENUMBERONEWEMEETAGAINANDAGAINUNDERBLUEICPCSKY”
This string has length 48. We have divided into 8 groups 
of equal length and so the length of each
group is 6. Now we can reverse each of these eight 
groups to get a new string:
“UNEBOTNOREBMEEMEWENIAGATAGADNAEDNUNIIEULBRYKSCPC”
Given the string and number of groups in it, your 
program will have to group reverse it.



Input
The input file contains at most 101 lines of inputs. 
Each line contains at integer G (G < 10) which
denotes the number of groups followed by a string 
whose length is a multiple of G. The length of the
string is not greater than 100. The string contains 
only alpha numerals. Input is terminated by a line
containing a single zero.

Output
For each line of input produce one line of output which 
contains the group reversed string.



Sample Input
3 ABCEHSHSH
5 FA0ETASINAHGRI0NATWON0QA0NARI0
0

Sample Output
CBASHEHSH
ATE0AFGHANISTAN0IRAQ0NOW0IRAN0