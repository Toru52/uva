12602 - Nice Licence Plates



#include <cstdio>  

int main()
{
	int  n, x, y;
	char buf[10];
	while (~scanf("%d", &n))
		while (n--) {
			scanf("%s", buf);
			x = (buf[0] - 'A') * 26 * 26 + (buf[1] - 'A') * 26 + buf[2] - 'A';
			y = (buf[4] - '0') * 1000 + (buf[5] - '0') * 100 + (buf[6] - '0') * 10 + buf[7] - '0';
			if (x - y <= 100 && x - y >= -100)
				printf("nice\n");
			else printf("not nice\n");
		}

	return 0;
}



#include<cstdio>
#include<algorithm>
int main()
{
	int n,sum1,sum2;
	char s[10];
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", &s);
		sum1 = (s[0] - 'A') * 26 * 26 + (s[1] - 'A') * 26 + (s[2] - 'A');
		sum2 = (s[4] - '0') * 1000 + (s[5] - '0') * 100 + (s[6] - '0') * 10 + (s[7] - '0');
		puts(abs(sum1 - sum2) <= 100 ? "nice" : "not nice");
	}
}



Alberta licence plates currently have a format of ABC-0123 
(three letters followed by four digits). We say that the licence 
plate is “nice” if the absolute difference between the value of 
the first part and the value of the second part is at most 100.
The value of the first part is calculated as the value of base-26 
number (where digits are in [A..Z]). For instance, 
if the first part is “ABC”, its value is 28 (0∗262+1∗261+2∗260). 
So, the plate “ABC-0123” is nice, because |28 − 123| ≤ 100.
Given the list of licence plate numbers, your program should 
determine if the plate is nice or not.



Input
First line of the input contains an integer N (1 ≤ N ≤ 100), 
the number of licence plate numbers. Then follow N lines, 
each containing a licence plate in the format ‘LLL-DDDD’.

Output
For each licence plate print on a line ‘nice’ or ‘not nice’ 
(without quotes) depending on the plate number being nice as 
described in the probem statement.



Sample Input
2
ABC-0123
AAA-9999

Sample Output
nice
not nice