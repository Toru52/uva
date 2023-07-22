 fractions
 
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
