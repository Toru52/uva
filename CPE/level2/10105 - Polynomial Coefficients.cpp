10105 - Polynomial Coefficients
http://knightzone.org/?p=1730
https://github.com/morris821028/UVa/blob/master/volume101/10105%20-%20Polynomial%20Coefficients.cpp

about
coefficient of polynomial theorem
http://www.geisya.or.jp/~mwm48961/kou3/binomial1.htm




#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int n, k, power;
  long long answer;
  while( scanf( "%d%d", &n, &k ) != EOF ){
    answer = 1;
    for( int i = n ; i >= 1 ; i-- ) answer *= i;
    for( int i = 0 ; i < k ; i++ ){
      scanf( "%d", &power );
      for( int j = power ; j >= 1 ; j-- ) answer /= j;
    }
    printf( "%lld\n", answer );
  }
  return 0;
}



#include <stdio.h>

int main() {
	int n, k;
	int f[15] = {1};

	for (n = 1; n < 15; n++)
		f[n] = f[n - 1] * n;   //permutation
	while (scanf("%d %d", &n, &k) == 2) {
		int ans = f[n];
		while (k--) {
			scanf("%d", &n);
			ans /= f[n];
		}
		printf("%d\n", ans);
	}
	return 0;
}



#include<stdio.h>

int main() {
	int n, k,i;
	int f[15] = { 1 };

	for (int i = 1; i < 14; i++)
		f[i] =f[i-1]* i;
	while (scanf("%d %d", &n, &k) == 2) {
		int ans = f[n];
		while (k--) {
			scanf("%d", &i);
			ans/= f[i];
		}
		printf("%d\n", ans);
	}
}


The problem is to calculate the coefficients in expansion of
 polynomial (x1 + x2 + . . . + xk) n.
 
 
 
Input
The input will consist of a set of pairs of lines. The first line 
of the pair consists of two integers n and
k separated with space (0 < K, N < 13). This integers define the 
power of the polynomial and the amount of the variables. 
The second line in each pair consists of k non-negative integers 
n1, . . . , nk, where n1 + . . . + nk = n.

Output
For each input pair of lines the output line should consist one 
integer, the coefficient by the monomial

x
n1
1 x
n2
2
. . . x
nk
k
in expansion of the polynomial (x1 + x2 + . . . + xk)
n.



Sample Input
2 2
1 1
2 12
1 0 0 0 0 0 0 0 0 0 1 0

Sample Output
2
2