10038 - Jolly Jumpers

no1.
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int N;
	while (scanf("%d", &N) != EOF) {
		int s[3001], check[3001] = { 0 };
		bool ok = 1;

		scanf("%d", &s[0]);
		for (int i = 1; i<N; i++) {
			scanf("%d", &s[i]);
			int temp = abs(s[i] - s[i - 1]);
			if (temp <= 3000) check[temp]++;
		}

		for (int i = 1; i<N; i++)
			if (check[i] == 0) { ok = 0; break; }

		if (ok) printf("Jolly\n");
		else printf("Not jolly\n");
	}
	return 0;
}

no2.
#include<cstdio>
#include<algorithm>
#include<string.h>

int main()
{
	int dif[3001], check[3001] = {0};
	int n;

	while (scanf("%d", &n) != EOF)
	{
		memset(check, 0, sizeof(check));
		scanf("%d", &dif[0]);
		for (int i = 1; i < n; i++)
		{
			scanf("%d",&dif[i]);
			int temp = abs(dif[i] - dif[i - 1]);
			check[temp]++;
		}
		int cnt = 1;
		for (int i = 1; i < n; i++)
			if (check[i])
				cnt++;

		if (cnt==n)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}



A sequence of n > 0 integers is called a jolly jumper if the absolute 
values of the difference between successive elements take on all the 
values 1 through n − 1. For instance,
1 4 2 3
is a jolly jumper, because the absolutes differences are 3, 2, and 1 
respectively. The definition implies that any sequence of a single 
integer is a jolly jumper. You are to write a program to determine 
whether or not each of a number of sequences is a jolly jumper.



Input
Each line of input contains an integer n ≤ 3000 followed by n 
integers representing the sequence.

Output
For each line of input, generate a line of output saying 
‘Jolly’ or ‘Not jolly’.



Sample Input
4 1 4 2 3
5 1 4 2 -1 6

2 1 2 
4 1 4 3 1
4 1 4 2 3
5 1 4 2 -1 6
2 1 3
1 1
1 10
5 4 1 4 3 1
11 1 2 4 7 11 16 22 29 37 46 56  
3 2 1 3

Sample Output
Jolly
Not jolly

Jolly
Jolly
Jolly
Not jolly
Not jolly
Jolly
Jolly
Not jolly
Jolly
Jolly
