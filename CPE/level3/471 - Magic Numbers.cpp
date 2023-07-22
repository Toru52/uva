471 - Magic Numbers
http://mypaper.pchome.com.tw/zerojudge/post/1322741462



#include <stdio.h>
const long long limit = 9876543210LL;
int Check(long long n) {
	char digit[10] = { 0 }, s[11], i = 0;
	sprintf(s, "%lld", n);
	while (s[i]) {
		digit[s[i] - '0']++;
		if (digit[s[i] - '0'] == 2)
			return 0;
		i++;
	}
	return 1;
}
int main() {
	int T;
	long long n, m, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		for (i = 1; n*i <= limit; i++) {
			m = n*i;
			if (Check(i) && Check(m))
				printf("%lld / %lld = %lld\n", m, i, n);
		}
		if (T)	puts("");
	}
	return 0;
}



#include<stdio.h>
int check(long long n) {
	char digit[10]{}, s[11]{}, i=0;
	sprintf(s, "%lld", n);
	while (s[i]) {
		digit[s[i] - '0']++;
		if (digit[s[i] - '0'] == 2)
			return 0;
		i++;
	}
	return 1;
}
int main() {
	int t;
	long long i, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		for (i = 1; n*i <= 9876543210LL; i++)
			if (check(n*i) && check(i))
				printf("%lld / %lld = %lld\n", i*n, i, n);
		if (t)puts("");
	}
	return 0;
}



/*
ex
1234567890 / 1 = 1234567890
2469135780 / 2 = 1234567890
3703703670 / 3 = 1234567890->X since no number 1,2,4,5,8,9
4938271560 / 4 = 1234567890
6172839450 / 5 = 1234567890
8641975230 / 7 = 1234567890
9876543120 / 8 = 1234567890
*/
Write a program that finds and displays all pairs of 
integers s1 and s2 such that:
1. neither s1 nor s2 have any digits repeated; and
2. s1/s2 = N, where N is a given integer;



Input
The input file consist a integer at the beginning 
indicating the number of test case followed by a blank
line. Each test case consists of one line of input 
containing N. Two input are separated by a blank line.

Output
For each input the output consists of a sequence of zero 
or more lines each containing ￿ ‘s1 / s2 = N’,
where s1, s2 and N￿ are the integers described 
above. When there are two or more solutions, sort them
by increasing numerator values.
Two consecutive output set will separated by a blank line.



Sample Input
1
1234567890

Sample Output
1234567890 / 1 = 1234567890
2469135780 / 2 = 1234567890
4938271560 / 4 = 1234567890
6172839450 / 5 = 1234567890
8641975230 / 7 = 1234567890
9876543120 / 8 = 1234567890