No.1
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main() {
	int cas;
	int re, s[505];
	int house, d;

	while (scanf("%d", &cas) != EOF) {
		for (int i = 0; i < cas; i++) {
			scanf("%d", &re);
			for (int j = 0; j < re; j++)
				scanf("%d", &s[j]);
			sort(s, s + re);

			d = 0;
			house = s[re / 2];
			for (int j = 0; j < re; j++)
				d += abs(house - s[j]);
			printf("%d\n", d);
		}
	}
	return 0;
}


No.2
#include<cstdio>
#include<algorithm>
int main()
{
	int n,le;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &le);
		int min=99999,dis[99999] = {};
		for (int i = 0; i < le; i++)
			scanf("%d", &dis[i]);
		for (int i = 0; i < le; i++) {
			int sum = 0;
			for (int j = 0; j < le; j++)
				sum += abs(dis[i] - dis[j]);
			if (sum < min)
				min = sum;
		}
		printf("%d\n", min);
	}
}



UVA 10041: Vito’s family

Process
You can solve this problem by first sorting 
the street number array and calculating the 
sum of the distances of the median element 
to all other elements. This will always provide 
the optimal value.

input
4
2 2 4 
3 2 4 6
3 29999 29999 29999
6 2 0 8 9 1 4

output
2
4
0
18
