11296 - Counting Solutions to an Integral Equation



#include <cstdio>
int main() {
	int n;
	while (scanf("%d", &n) ==1) {
		long long ans = 0;
		for (int i = 0; i + i <= n; ++i) 
			ans = ans + i + 1;	
		printf("%lld\n", ans);
	}
	return 0;
}



/*
concept
ex
1,2,3,4,5,6, 7, 8, 9, 10,,,
->
1,3,3,6,6,10,10,15,15,21,,,

solution number made of sequense.
*/

Given, n, count the number of solutions to the 
equation x + 2y + 2z = n, where x; y; z; n are non
negative integers.



Input
There is at most 1500 inputs. Each input is n (n < 1000001) 
on a single line.

Output
For each input, output the number of solutions on a 
single line.



Sample Input
2
3

Sample Output
3
3