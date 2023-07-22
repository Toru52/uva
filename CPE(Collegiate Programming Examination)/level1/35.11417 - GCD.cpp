11417 - GCD



no1.
#include <cstdio>

int GCD(int i, int j) {
	while ((i %= j) && (j %= i));
	return i + j;
}

int main() {
	int N, G;
	while (scanf("%d", &N) != EOF && N != 0) {
		G = 0;
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++)
			{
				G += GCD(i, j);
			}
		}
		printf("%d\n", G);
	}
	return 0;
}



no2.
#include<cstdio>

int GCD(int a, int b) { return (a%b) ? GCD(b, a%b) : b; }

int main()
{
	int N;
	while (~scanf("%d", &N) && N != 0)
	{
		int G = 0;
		for (int i = 1; i < N; i++)
			for (int j = i + 1; j <= N; j++)
				G += GCD(i, j);
		printf("%d\n", G);		
	}
}



