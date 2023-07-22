no 343 - What Base Is This?



#include<cstdio>

//计算字符数值   
int ValueChar(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	return ch - 'A' + 10;
}

//计算字符串数值   
int ValueStr(int base, char buf[])
{
	int value = 0;
	for (int i = 0; buf[i]; ++i) {
		value *= base;
		value += ValueChar(buf[i]);
	}
	return value;
}

int main()
{
	char str1[101], str2[101];
	while (~scanf("%s%s", str1, str2)) {
		//找到每个串的最小进制   
		int max1 = 1, max2 = 1;
		for (int i = 0; str1[i]; ++i)
			if (max1 < ValueChar(str1[i]))
				max1 = ValueChar(str1[i]);
		for (int i = 0; str2[i]; ++i)
			if (max2 < ValueChar(str2[i]))
				max2 = ValueChar(str2[i]);
		//查找不同的进制时相同的值   
		int flag = 0;
		for (int i = max1 + 1; i < 37; ++i)
			for (int j = max2 + 1; j < 37; ++j)
				if (!flag && ValueStr(i, str1) == ValueStr(j, str2)) {
					flag = 1;
					printf("%s (base %d) = %s (base %d)\n", str1, i, str2, j);
				}
		if (!flag)
			printf("%s is not equal to %s in any base 2..36\n", str1, str2);
	}
	return 0;
}



#include<cstdio>

int CH(char c) {
	if ('0' <= c&&c <= '9')
		return c - '0';
	return c - 'A'+10;
}

int base(int b, char buf[]) {
	int sum = 0;
	for (int i = 0; buf[i]; i++) {
		sum *= b;
		sum += CH(buf[i]);
	}
	return sum;
}

int main() {
	char str[101], str2[101];
	while (scanf("%s %s", str, str2) == 2) {
		int max = 1, max2 = 1,F=0;
		for (int i = 0; str[i]; i++)
			if (max < CH(str[i]))
				max = CH(str[i]);
		for (int i = 0; str2[i]; i++)
			if (max2 < CH(str2[i]))
				max2 = CH(str2[i]);
		for (int i = max + 1; i < 37; i++)
			for (int j = max2 + 1; j < 37; j++)
				if (!F&&base(i, str) == base(j, str2))
					F=1,printf("%s (base %d) = %s (base %d)\n", str, i, str2, j);
		if (!F)
			printf("%s is not equal to %s in any base 2..36\n", str, str2);
	}
}



In positional notation we know the position of a digit 
indicates the weight of that digit toward the
value of a number. For example, in the base 10 number 362 we 
know that 2 has the weight 100, 6 has the weight 101
, and 3 has the weight 102
, yielding the value 3 × 102 + 6 × 101 + 2 × 100
, or just
300 + 60 + 2. The same mechanism is used for numbers expressed 
in other bases. While most people assume the numbers they 
encounter everyday are expressed using base 10, we know that 
other bases are possible. In particular, the number 362 in 
base 9 or base 14 represents a totally different value than
362 in base 10. For this problem your program will presented 
with a sequence of pairs of integers. Let’s call the members 
of a pair X and Y . What your program is to do is determine 
the smallest base for X and the smallest base for Y (likely 
different from that for X) so that X and Y represent the same 
value. Consider, for example, the integers 12 and 5. Certainly 
these are not equal if base 10 is used for
each. But suppose 12 was a base 3 number and 5 was a base 6 
number? 12 base 3 = 1 × 3
1 + 2 × 3
0
,
or 5 base 10, and certainly 5 in any base is equal to 5 
base 10. So 12 and 5 can be equal, if you select
the right bases for each of them



Input
On each line of the input data there will be a pair of 
integers, X and Y , separated by one or more blanks;
leading and trailing blanks may also appear on each line, 
are are to be ignored. The bases associated
with X and Y will be between 1 and 36 (inclusive), and as 
noted above, need not be the same for X and
Y . In representing these numbers the digits 0 through 9 have 
their usual decimal interpretations. The uppercase alphabetic 
characters A through Z represent digits with values 10 through 
35, respectively.

Output
For each pair of integers in the input display a message 
similar to those shown in the examples shown below. 
Of course if the two integers cannot be equal regardless of 
the assumed base for each, then print an appropriate message; 
a suitable illustration is given in the examples.



Sample Input
12 5
10 A
12 34
123 456
1 2
10 2

Sample Output
12 (base 3) = 5 (base 6)         ->equal to 5   (1*3+2=5)
10 (base 10) = A (base 11)       ->equal to 1  (1)
12 (base 17) = 34 (base 5)       ->equal to 19  (1*17+2=3*5+4)
123 is not equal to 456 in any base 2..36
1 is not equal to 2 in any base 2..36
10 (base 2) = 2 (base 3)         ->equal to 2   (1*2=2)