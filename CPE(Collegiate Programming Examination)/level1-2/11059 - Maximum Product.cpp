11059 - Maximum Product



#include<cstdio>

int main() {
	int N, casenum = 1;
	long long S[20], maxproduct, temp;

	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%lld", &S[i]);

		maxproduct = 0;
		for (int i = 0; i < N; i++) {
			temp = 1;
			for (int j = i; j < N; j++) {
				temp *= S[j];
				if (temp > maxproduct) 
					maxproduct = temp;
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", casenum++, maxproduct);
	}
}



#include<stdio.h>
int main()
{
	long long  num[21];
	int c=1,n;

	while (~scanf("%d", &n))
	{
		for (int i = 0; i < n; i++) 
			scanf("%lld", &num[i]);
		long long  max = 0;
		for (int i = 0; i < n; i++) {
		long long temp = 1;
			for (int j = i; j < n; j++)
			{
				temp *= num[j];
				if (max < temp)
					max = temp;		
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", c++, max);
	}
}