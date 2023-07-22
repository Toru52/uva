10302 - Summation of Polynomials



http://bruce30262.pixnet.net/blog/post/88223717-%5Bc-c%2B%2B%5D-uva-10302-summation-of-polynomials
#include <stdio.h>
 
int main()
{
     long long int n,ans;
     while(~scanf("%lld",&n))
         printf("%lld\n",(n*n*(n+1)*(n+1)/4));
 
     return 0;
}



https://saicheems.wordpress.com/2013/11/08/uva-10302-summation-of-polynomials/
#include<cstdio>

int x;

long long poly(int x) {
	long long sum = 0;
	for (long long i = 1; i <= x; i++) {
		sum += i * i * i;
	}
	return sum;
}

int main() {
	while (scanf("%d", &x) == 1) printf("%lld\n", poly(x));
}



Input
Input  le contains several lines of input. 
Each line contain a single number which denotes the value of x.
Input is terminated by end of  le. 

Output
For each line of input produce one line of output which is the 
desired summation value.



SampleInput
1
2
3

SampleOutput
1
9
36
