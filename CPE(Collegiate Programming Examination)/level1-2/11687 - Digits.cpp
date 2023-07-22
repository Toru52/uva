11687 - Digits



#include <cstdio>
#include <cstring>

int main(void) {
	char c;
	unsigned int cnt;
	bool mark;

	while ((c = getc(stdin)) != 'E') {
		cnt = mark = 1;
		if (c == '1')
			mark = 0;
		while ((c = getc(stdin)) != '\n')
			cnt++;
		if (cnt == 1)
			printf("%d\n", cnt + mark);
		else if (cnt < 10)
			printf("%d\n", 3);
		else
			printf("%d\n", 4);
	}
	return 0;
}



#include<cstdio>

int main()
{
	char c;
	unsigned int cnt;
	bool mark;
	while ((c = getc(stdin)) != 'E')
	{
		mark = cnt = 1;
		if (c == '1')
			mark = 0;
		while ((c = getc(stdin)) != '\n')
			cnt++;
		if (cnt == 1)
			printf("%d\n", mark + cnt);
		else if (cnt < 10)
			puts("3");
		else
			puts("4");
	}
}



A googol written out in decimal has 101 digits. A googolplex has one
plus a googol digits. That’s a lot of digits! Given any number x0, 
define a sequence using the following recurrence:
xi+1 = the number of digits in the decimal representation of xi Your 
task is to determine the smallest positive i such that xi = xi−1.



Input
Input consists of several lines. Each line contains a value of x0. 
Every value of x0 is non-negative and has no more than one million digits.
The last line of input contains the word ‘END’.

Output
For each value of x0 given in the input, output one line containing the 
smallest positive i such that xi = xi−1.



Sample Input
42
END

Sample Output
3