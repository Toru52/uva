424 - Integer Inquiry
https://github.com/morris821028/UVa/blob/master/volume004/424%20-%20Integer%20Inquiry.cpp



#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int Sum[201]{}, i;
	
	//convert order
	//ex 12345->54321
	while (getline(cin,s),s!="0") 
		for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--)
			Sum[i] += s[j] - '0';
	for (i = 0; i < 200; i++)
		if (Sum[i] >= 10) 
			Sum[i + 1] += Sum[i] / 10,Sum[i] %= 10;
	i = 200;
	//search sum max digit
	while (Sum[i] == 0 && i >= 0)	
		i--;
	if (i == -1)	
		printf("0");
	for (; i >= 0; i--) 
		printf("%d", Sum[i]);
	puts("");
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	int sum[201]{};
	while (getline(cin, s), s != "0") 
		for (int i = 0, j = s.length()-1; i < s.length(); i++, j--)
			sum[i] += s[j] - '0';
		for (int i = 0; i <= 200; i++)
			if (sum[i] >= 10)
				sum[i + 1] += sum[i] / 10, sum[i] %= 10;
		int i = 200;
		while (!sum[i] && i >= 0)
			i--;
		for (; i >=0; i--)
			printf("%d", sum[i]);
		puts("");
	return 0;
}



One of the first users of BIT’s new supercomputer was Chip Diller. 
He extended his exploration of powers of 3 to go from 0 to 333 and 
he explored taking various sums of those numbers.
“This supercomputer is great,” remarked Chip. 
“I only wish Timothy were here to see these results.”
(Chip moved to a new apartment, once one became available on the 
third floor of the Lemon Sky apartments on Third Street.)



Input
The input will consist of at most 100 lines of text, each of which 
contains a single VeryLongInteger.
Each VeryLongInteger will be 100 or fewer characters in length, 
and will only contain digits (no VeryLongInteger will be negative).
The final input line will contain a single zero on a line by itself.

Output
Your program should output the sum of the VeryLongIntegers given in 
the input.



Sample Input
123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0

Sample Output
370370367037037036703703703670





