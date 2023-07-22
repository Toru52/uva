11233 - Deli Deli
http://www.voidcn.com/blog/u012866104/article/p-3800799.html



#include<cstdio>
#include<cstring>
#include<algorithm>
const int inf = -1u >> 1;

int main()
{
	int t;
	char s[210];
	long long dp[210];
	
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s + 1);
		dp[1] = s[1] - '0';
		int len = strlen(s + 1);
		for (int i = 2; i <= len; i++) {
			long long sum = s[i] - '0', mul = 1;
			dp[i] = dp[i - 1] + sum;
			for (int j = i - 1; j >= 1; j--) {
				mul *= 10;
				if (s[j] == '0')
					continue;
				sum += mul*(s[j] - '0');
				if (sum>inf) 
					break;
				dp[i] = std::max(dp[i], dp[j - 1] + sum);
			}
		}
		printf("%lld\n", dp[len]);
	}
	return 0;
}