20.10812	Beat the Spread!


no1.
#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		int s, d;
		int ans1, ans2;

		scanf("%d %d", &s, &d);
		ans1 = (s + d) / 2;
		ans2 = (s - d) / 2;

		if ((s + d) % 2 != 0 || ans2<0)
		{
			puts("impossible");
		}
		else
			printf("%d %d\n", ans1, ans2);
	}
}



no2.
#include<cstdio>

int main()
{
	int cas,sum,dif,a,b;

	while (scanf("%d", &cas) != EOF)
	{
		for (int i = 0; i < cas; i++)
		{
			scanf("%d%d", &sum, &dif);

			a = (sum + dif) / 2;
			b = (sum - dif) / 2;

			if (sum>=dif&&(a+b)==sum)
				printf("%d %d\n", a, b);
			else
				puts("impossible");
		}
	}
}





Superbowl Sunday is nearly here. In order to pass the time waiting
for the half-time commercials and wardrobe malfunctions, the local
hackers have organized a betting pool on the game. Members place
their bets on the sum of the two final scores, or on the absolute
difference between the two scores.
Given the winning numbers for each type of bet, can you deduce
the final scores?



Input
The first line of input contains n, the number of test cases. 
n lines follow, each representing a test case. Each test case gives 
s and d,non-negative integers representing the sum and (absolute) 
difference between the two final scores.



Output
For each test case, output a line giving the two final scores, 
largest first. If there are no such scores,output a line 
containing “impossible”. Recall that football scores are always 
non-negative integers.



Sample Input
2
40 20
20 40

Sample Output
30 10
impossible



