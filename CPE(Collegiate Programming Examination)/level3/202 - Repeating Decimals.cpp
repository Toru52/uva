202 - Repeating Decimals
http://mypaper.pchome.com.tw/zerojudge/post/1322632247



#include<stdio.h>
int main() {
	int i, j,n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		char s[3001], *str = s + 1;
		int mark[3001]{};
		printf("%d/%d = %d.", n, m, n / m);
		n %= m;
		mark[n] = 1;
		n *= 10;
		for (i = 2; ; i++) {
			*str = n / m + '0', str++;
			if (mark[n%m])	break;
			mark[n%m] = i;
			n %= m;
			n = n * 10;
		}
		int st = mark[n%m], ed = i;
		for (j = 1; j < ed && j <= 50; j++) {
			if (j == st)	
				printf("(");
			printf("%c", s[j]);
		}
		if (j < ed)	
			printf("...");
		printf(")\n");
		printf("   %d = number of digits in repeating cycle\n\n", ed - st);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) == 2) {
		int i=2, used[3001]{};
		char s[3001]{}, *str = s + 1;
		printf("%d/%d = %d.", n, m, n / m);
		used[n%m] = 1;
		while (1) {
			n %= m, n *= 10;
			*str = n / m + '0', str++;
			if (used[n%m]) break;
			used[n%m] = i;
			i++;
		}
		int S = used[n%m], E = i;
		for (i = 1; i < E&&i <= 50; i++) {
			if (i == S)
				printf("(");
			printf("%c", s[i]);
		}
		if (i < E)
			printf("...");
		puts(")");
		printf("   %d = number of digits in repeating cycle\n\n", E - S);
	}
	return 0;
}



The decimal expansion of the fraction 1/33 is 0:03, where the 03 is used 
to indicate that the cycle 03 repeats indenitely with no intervening 
digits. In fact, the decimal expansion of every rational number
(fraction) has a repeating cycle as opposed to decimal expansions of 
irrational numbers, which have no such repeating cycles.
Examples of decimal expansions of rational numbers and their repeating 
cycles are shown below.
Here, we use parentheses to enclose the repeating cycle rather than place 
a bar over the cycle. 
fraction decimal expansion repeating cycle cycle length
1/6 0.1(6) 6 1
5/7 0.(714285) 714285 6
1/250 0.004(0) 0 1
300/31 9.(677419354838709) 677419354838709 15
655/990 0.6(61) 61 2
Write a program that reads numerators and denominators of fractions and 
determines their repeating cycles.
For the purposes of this problem, dene a repeating cycle of a fraction 
to be the rst minimal length string of digits to the right of the 
decimal that repeats indenitely with no intervening digits. 
Thus for example, the repeating cycle of the fraction 1/250 is 0, 
which begins at position 4 
(as opposed to 0 which begins at positions 1 or 2 and as opposed to 00 
which begins at positions 1 or 4).



Input
Each line of the input le consists of an integer numerator, 
which is nonnegative, followed by an integer denominator, 
which is positive. None of the input integers exceeds 3000. 
End-of-le indicates the end of input.

Output
For each line of input, print the fraction, its decimal expansion through 
the rst occurrence of the cycle to the right of the decimal or 50 
decimal places (whichever comes rst), and the length of the entire
repeating cycle.
In writing the decimal expansion, enclose the repeating cycle in 
parentheses when possible. If the entire repeating cycle does not occur 
within the rst 50 places, place a left parenthesis where the cycle
begins | it will begin within the rst 50 places | and place `...)' 
after the 50th digit.



Sample Input
76 25
5 43
1 397

Sample Output
76/25 = 3.04(0)
1 = number of digits in repeating cycle
5/43 = 0.(116279069767441860465)
21 = number of digits in repeating cycle
1/397 = 0.(00251889168765743073047858942065491183879093198992...)
99 = number of digits in repeating cycle