275	Expanding Fractions



#include<cstdio>

int main()
{
	int n, m,save[1001],first[1001];

	while (~scanf("%d%d", &n, &m) && n + m) {
		int count=0,used[1001] = {};

		while (!used[n] && n) {
			used[n] = 1;
			save[count] = 10 * n / m;
			first[n] = count++;
			n = 10 * n%m;
		}
		printf(".");
		for (int i = 0; i < count; ++i) {
			if (i % 50 == 49) 
				printf("\n");
			printf("%d", save[i]);
		}
		if (!n)
			printf("\nThis expansion terminates.\n\n");
		else
			printf("\nThe last %d digits repeat forever.\n\n", count - first[n]);
	}
	return 0;
}



#include<cstdio>

int main()
{
	int n, m;
	while (~scanf("%d %d", &n, &m) && n + m)
	{
		int count = 0, first[1001], save[1001], used[1001] = {};
		while (!used[n] && n)
		{
			used[n] = 1;
			save[count] = n * 10 / m;
			first[n] = count++;
			n = n * 10 % m;
		}
		printf(".");
		for (int i = 0; i < count; i++) {
			if (i % 50 == 49)
				puts("");
			printf("%d", save[i]);
		}
		if (!n)
			puts("\nThis expansion terminates.\n");
		else
			printf("\nThe last %d digits repeat forever.\n\n", count - first[n]);
	}
}



point 
while (!used[n] && n)
while condition to continue ->n>0 used[n]=0

if n==0 represent This expansion terminates
if used[n]>0 represent some number repeat forever



In this problem you are to print the decimal expansion of a 
quotient of two integers. As you well know,the decimal 
expansions of many integer quotients result in decimal 
expansions with repeating sequences of digits. 
You must identify these. You will print the decimal expansion of 
the integer quotient given,stopping just as the expansion 
terminates or just as the repeating pattern is to repeat 
itself for the first time. If there is a repeating pattern, 
you will say how many of the digits are in the repeating pattern.



Input
There will be multiple input instances, each instance consists 
of two positive integers on a line. The first integer represents 
the numerator of the fraction and the second represents the 
denominator. In this problem, the numerator will always be less 
than the denominator and the denominator will be less than 1000. 
Input terminates when numerator and denominator are both zero.

Output
For each input instance, the output should consist of the 
decimal expansion of the fraction, starting with the decimal 
point. If the expansion terminates, you should print the 
complete decimal expansion. If the expansion is infinite, 
you should print the decimal expansion up to, but not including 
the digit where the repeated pattern first repeats itself.
For instance, 4/11 = .3636363636..., should be printed as .36. 
(Note that the shortest repeating pattern should be found. 
In the above example, 3636 and 363636, among others, are 
repeating patterns, but the shortest repeating pattern is 36.)
Since some of these expansions may be quite long, multiple line 
expansions should each contain exactly 50 characters on each 
line (except the last line, which, of course, may be shorter) — 
that includes the beginning decimal point.
On the line immediately following the last line of the decimal 
expansion there should be a line saying either ‘This expansion 
terminates.’, or ‘The last n digits repeat forever.’, 
where n is the number of digits in the repeating pattern.
Output for each input instance (including the last input 
instance) should be followed by a blank line.
Helpful hint: The number of digits before the pattern is repeated will never be more than the value
of the denominator.
Sample Input
3 7
345 800
112 990
53 122
0 0
Sample Output
.428571
The last 6 digits repeat forever.
.43125
This expansion terminates.
.113
The last 2 digits repeat forever.
.4344262295081967213114754098360655737704918032786
885245901639
The last 60 digits repeat forever.