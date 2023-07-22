12004 - Bubble Sort  
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/12004%20-%20Bubble%20Sort.cpp

concept about n time
http://www.ics.kagoshima-u.ac.jp/~fuchida/edu/algorithm/sort-algorithm/bubble-sort.html

#include <stdio.h>
int main() {
	int T, n;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d", &n);
		long long ans = (long long)n * (n - 1);
		printf("Case %d: ", tc);
		if (ans % 4 == 0) printf("%lld\n", ans / 4);
		else printf("%lld/2\n", ans / 2);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int T, n;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &n);
		long long time = (long long)n*(n - 1);
		printf("Case %d: ", i);
		if (time % 4 == 0)printf("%lld\n", time / 4);
		else printf("%lld/2\n", time / 2);
	}return 0;
}




/*
4,5,8,9,12,13,16,17,
concept
require each time some random integers (from 1 to n)
*/

Check the following code which counts the number of swaps of bubble sort.
int findSwaps( int n, int a[] )
{
int count = 0, i, j, temp, b[100000];
for( i = 0; i < n; i++ ) {
b[i] = a[i];
}
for( i = 0; i < n; i++ ) {
for( j = 0; j < n - 1; j++ ) {
if( b[j] > b[j+1] ) {
temp = b[j];
b[j] = b[j+1];
b[j+1] = temp;
count++;
}
}
}
return count;
}
You have to nd the average value of 'count' in the given code 
if we run ndSwaps() innitely many times using constant 'n' and each 
time some random integers (from 1 to n) are given in array
a[]. You can assume that the input integers in array a[] are distinct.



Input
Input starts with an integer T ( 1000), 
denoting the number of test cases. Each test case contains an
integer n (1  n  105) in a single line.

Output
For each case, print the case number and the desired result. 
If the result is an integer, print it. Otherwise
print it in `p=q' form, where p and q are relative prime.



Sample Input
2
1
2

Sample Output
Case 1: 0
Case 2: 1/2