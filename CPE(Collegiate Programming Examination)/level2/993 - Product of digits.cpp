993 - Product of digits



#include <stdio.h>

int main() {
	int i, T, n;
	while (scanf("%d", &T) == 1) {
		while (T--) {
			scanf("%d", &n);
			if (n < 10) { printf("%d\n", n);    continue; }
			int num[10] = { 0 };
			for (i = 9; i >= 2; i--)
				if (n%i == 0) {
					n /= i;
					num[i]++;
				}
			if (n != 1)    printf("-1\n");
			else {
				for (i = 2; i <= 9; i++)
					while (num[i]--)
						printf("%d", i);
				puts("");
			}
		}
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n,cas;
	scanf("%d", &cas);
	while (cas--) {
		int num[10] = {};
		scanf("%d",&n);
		if (n < 10) {
			printf("%d\n",n);
			continue;
		}
		for(int i=9;i>=2;i--)
			if (n%i == 0) {
				num[i]++;
				n /= i;
			}
		if (n != 1)
			printf("-1");
		else
			for (int i = 2; i <= 9; i++)
				if(num[i])
					printf("%d", i);
		puts("");
	}
}



For a given non-negative integer number N, find the minimal natural
Q such that the product of all digits of Q is equal N.



Input
The first line of input contains one positive integer number, which 
is the number of data sets. Each subsequent line contains one data 
set which consists of one non-negative integer number N (0 ≤ N ≤109).

Output
For each data set, write one line containing the corresponding 
natural number Q or ‘-1’ if Q does not exist.



Sample Input
3
1
10
123456789

Sample Output
1
25
-1