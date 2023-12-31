 623 500! 
 http://mypaper.pchome.com.tw/zerojudge/post/1322833693
 
 
 
#include<stdio.h>
int A[1001][2600]{ 1 };
int main() {
	int i, j, n, last = 0;
	for (i = 1; i <= 1000; i++) {
		//n!
		for (j = 0; j <= last; j++)
			A[i][j] = A[i - 1][j] * i;
		//partition (ketawake)
		for (j = 0; j <= last; j++) {
			A[i][j + 1] += A[i][j] / 10;
			A[i][j] %= 10;
		}
		//if pull-back to new digit,
		//make new digit by add 'j'
		while (A[i][j] != 0) {
			A[i][j + 1] += A[i][j] / 10;
			A[i][j] %= 10;
			j++;
		}
		last = j;
	}
	while (scanf("%d", &n) == 1) {
		i = 2599;
		while (!A[n][i])i--;
		printf("%d!\n", n);
		for (; i >= 0; i--)
			printf("%d", A[n][i]);
		puts("");
	}
	return 0;
}
 
 
 
 In these days you can more and more often happen to see programs which 
perform some useful calculations being executed rather then trivial 
screen savers. Some of them check the system message queue and in case 
of finding it empty (for examples somebody is editing a file and stays 
idle for some time) execute its own algorithm.
As an examples we can give programs which calculate primary numbers.
One can also imagine a program which calculates a factorial of given 
numbers. In this case it is not the time complexity of order O(n) which 
makes troubles, but the memory requirements. Considering the fact that 
500! gives 1135-digit number. No standard, neither integer nor floating,
data type is applicable here.
Your task is to write a programs which calculates a factorial of a 
given number.



Input
Any number of lines, each containing value n for which you should 
provide value of n!

Output
2 lines for each input case. First should contain value n followed by 
character ‘!’. The second should contain calculated value n!.
Assumptions:
• Value of a number n which factorial should be calculated of does not 
  exceed 1000 (although 500! is the name of the problem, 
  500 is a small limit).
• Mind that visually big number of case 4 is broken after 80 characters,
  but this is not the case in the real output file.
  
  

Sample Input
10
30
50
100

Sample Output
10!
3628800
30!
265252859812191058636308480000000
50!
30414093201713378043612608166064768844377641568960512000000000000
100!
93326215443944152681699238856266700490715968264381621468592963895217599993229915
608941463976156518286253697920827223758251185210916864000000000000000000000000