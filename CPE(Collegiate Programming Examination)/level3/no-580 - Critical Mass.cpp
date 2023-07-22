no-580 - Critical Mass
http://blog.csdn.net/keshuai19940722/article/details/26625005




#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll solve() {
	ll dp[40]{1,1};
	for (int i = 2; i <= n; i++) 
		for (int j = 1; j <= min(3, i); j++)
			dp[i] += dp[i - j];
	ll ans = 0;
	for (int i = 0; i <= min(n, 2); i++)
		ans += dp[n - i];
	return (1LL << n) - ans;
}
int main() {
	while (scanf("%d", &n), n) 
		printf("%lld\n", solve());
	return 0;
}