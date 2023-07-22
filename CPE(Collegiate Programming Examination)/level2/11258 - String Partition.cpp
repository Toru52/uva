11258 - String Partition   
https://github.com/morris821028/UVa/blob/master/volume112/11258%20-%20String%20Partition.cpp#L4


#include <stdio.h>
#include <string.h>
const long long limit = 2147483647LL;
long long max(long long x, long long y) {
	return x > y ? x : y;
}
int main() {
	int t, i, j;
	char str[201];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int slen = strlen(str), i;
		long long DP[202] = {}, tmp = 0;
		for (i = 0; i < slen; i++) {
			if (str[i] == '0') {
				DP[i + 1] = max(DP[i + 1], DP[i]);
			}
			else {
				tmp = 0;
				for (j = i; j < slen; j++) {
					tmp = tmp * 10 + str[j] - '0';
					if (tmp > limit)
						break;
					//printf("tmp %lld     DP[%d]=%lld     DP[%d]=%lld\n",tmp,j+1, DP[j + 1],i, DP[i] + tmp);
					//printf("DP[%d]=%lld\n", slen, DP[slen]);
					DP[j + 1] = max(DP[j + 1], DP[i] + tmp);
				}
			}
		}
		printf("%lld\n", DP[slen]);
	}
	return 0;
}



#include <stdio.h>
#include <string.h>
#include<algorithm>

int main() {
	int t;
	char str[201];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", str);
		int slen = strlen(str);
		long long DP[202] = {}, tmp = 0;
		for (int i = 0; i < slen; i++) 
			if (str[i] == '0') //no add temp
				DP[i + 1] = std::max(DP[i + 1], DP[i]);
			else {
				tmp = 0;
				for (int j = i; j < slen; j++) {
					tmp = tmp * 10 + str[j] - '0';
					if (tmp > -1u>>1) 
						break;		
					DP[j + 1] = std::max(DP[j + 1], DP[i] + tmp);
				}
			}	
		printf("%lld\n", DP[slen]);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<algorithm>
int main() {
	int t;
	char str[202];
	scanf("%d", &t);
	while (t--) {
		long long tmp, dp[202] = {};
		scanf("%s", &str);
		int len = strlen(str);
		for (int i = 0; i<len; i++) 
			if (str[i]=='0')
				dp[i + 1] = std::max(dp[i + 1], dp[i]);
			else {
				tmp = 0;
				for (int j = i; j<len; j++) {
					tmp = tmp * 10 + str[j] - '0';
					if (tmp > (-1u >> 1))
						break;
					dp[j + 1] = std::max(dp[j + 1], dp[i] + tmp);
				}
			}
			printf("%lld\n", dp[len]);
	}
	return 0;
}
/*
explain 
max signed integer(INT_MAX(limits.h))
2147483647

if input integer larger than max signed integer,
then it be fool number.
This represent programmer no write this number,
In other words,There are any space in input number

->imput number inclese what exceed number
ex
21474836475  ->214748364 7 5
->40+(7+5)=52
2147483652

2147483648
->(4+8)+60=72
214748372



21474836408
2147483648

21474836001
2147483601

->if exceed limitnumber and have zero last number,
  to leave out zero number

  
  
21474836480
2-------->
1474836482

214748364999  2 14748364 9(999)
2------->
1474836510


214748364567
2------->
1------>
2147483712

*/

John was absurdly busy for preparing a programming contest 
recently. He wanted to create a ridicu-lously easy problem 
for the contest. His problem was not only easy, but also 
boring: Given a list of non-negative integers, 
what is the sum of them?
However, he made a very typical mistake when he wrote a 
program to generate the input data for his problem. 
He forgot to print out spaces to separate the list of integers. 
John quickly realized his mistake after looking at the 
generated input le because each line is simply a string of 
digits instead of a list of integers.
He then got a better idea to make his problem a little more 
interesting: There are many ways to split a string of digits 
into a list of non-zero-leading (0 itself is allowed) 32-bit 
signed integers. What is the maximum sum of the resultant 
integers if the string is split appropriately?



Input
The input begins with an integer N ( 500) which indicates 
the number of test cases followed. Each of the following test 
cases consists of a string of at most 200 digits.

Output
For each input, print out required answer in a single line.



Sample Input
6
1234554321
5432112345
000
121212121212
2147483648
11111111111111111111111111111111111111111111111111111

Sample Output
1234554321
543211239
0
2121212124
214748372
5555555666