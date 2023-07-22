12068 - Harmonic Mean
http://mypaper.pchome.com.tw/zerojudge/post/1322633054



#include<stdio.h>
long long gcd(long long x, long long y) {
	return y == 0 ? x : gcd(y, x%y);
}
int main() {
	int T, C = 0, N;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		long long A[10], m = 0, n = 0, tmp = 1;
		for (int i = 0; i < N; i++)
			scanf("%lld", &A[i]), tmp *= A[i];
		m = tmp*N;
		for (int i = 0; i < N; i++)
			n += tmp / A[i];
		tmp = gcd(m, n), m /= tmp, n /= tmp;
		printf("Case %d: %lld/%lld\n", ++C, m, n);
	}
	return 0;
}



#include<stdio.h>
typedef long long ll;
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a%b); }
int main() {
	int T, N;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		long long sum[15]{}, m, n=0, tmp = 1;
		for (int i = 0; i < N; i++)
			scanf("%d", &sum[i]), tmp *= sum[i];
		m = tmp*N;
		for (int i = 0; i < N; i++)
			n += tmp / sum[i];
		tmp = gcd(n, m), n /= tmp, m /= tmp;
		printf("Case %d: %lld/%lld\n", cas, m, n);
	}
	return 0;
}



/*
ex
H=4
4/((1/a)+(1/b)+(1/c)+(1/d))
->
m=a*b*c*d
n=((n/a)+(n/b)+(n/c)+(n/d))
(4*m)/n
tmp=gcd(m,n)
m/tmp,n/tmp


The harmonic mean (HN) of N numbers a1; a2; a3 : : : aN􀀀1; aN
is dened as below:
HN =
N
1
a1
+ 1
a2
+ 1
a3
+ : : : + 1
aN􀀀1
+ 1
aN
So the harmonic mean of four numbers a, b, c, d is dened
as
H4 =
4
1
a + 1
b + 1
c + 1
d
In this problem your job is very simple: given N (0 < N <
9) integers you will have to nd their harmonic mean.
Input
The rst line of the input le contains an integer S (0 < S < 501), 
which indicates how many sets of inputs are there. 
Each of the next S lines contains one set of input. 
The description of each set is given below:
Each set starts with an integer N (0 < N < 9), 
which indicates how many numbers are there in
this set. 
This number is followed by N integers a1; a2; a3 : : : aN􀀀1;
aN (0 < ai < 101).

Output
For each set of input produce one line of output. 
This line contains the serial of output followed by two
integers m and n separated by a front slash. 
These two numbers actually indicate that the harmonic
mean of the given four numbers is m n . 
You must ensure that gcd(m; n) = 1 or in other words m and n
must be relative prime. The value of m and n will t into a 64-bit 
signed integer.



Sample Input
2
4 1 2 3 4
4 2 2 3 1

Sample Output
Case 1: 48/25
Case 2: 12/7