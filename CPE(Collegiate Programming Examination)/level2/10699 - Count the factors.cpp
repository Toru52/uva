10699 - Count the factors
http://mypaper.pchome.com.tw/zerojudge/post/1322850789
concept
http://knightzone.org/?p=1314
http://maplewing.blogspot.tw/2011/01/uva10699count-factors.html



#include <stdio.h>
#include <math.h>
int main() {
	int n, i;
	while (scanf("%d", &n) == 1 && n) {
		printf("%d : ", n);
		int ans = 0;
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0)
				ans++;
			while (n%i == 0) {
				n /= i;
			}
		}
		if (n != 1)	ans++;
		printf("%d\n", ans);
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	int n;
	while (scanf("%d", &n), n) {
		int ans = 0;
		printf("%d : ", n);
		for (int i = 2; i <= sqrt(n); i++) {
			if (n%i == 0)
				ans++;
			while (n%i == 0)
				n /= i;
		}
		if (n != 1)ans++;
		printf("%d\n", ans);
	}
	return 0;
}



Write a program, that computes the number of different prime 
factors in a positive integer.

Input
The input tests will consist of a series of positive integers. 
Each number is on a line on its own. The
maximum value is 1000000. The end of the input is reached 
when the number `0' is met. The number
`0' shall not be considered as part of the test set.

Output
The program shall output each result on a line by its own, 
following the format given in the sample output.



Sample Input
289384
930887
692778
636916
747794
238336
885387
760493
516650
641422
0

Sample Output
289384 : 3
930887 : 2
692778 : 5
636916 : 4
747794 : 3
238336 : 3
885387 : 2
760493 : 2
516650 : 3
641422 : 3