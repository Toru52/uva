11364 - Parking



#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int main()
{
	int test, p, n;
	scanf("%d", &test);
	while (test--)
	{
		scanf("%d", &n);
		for (int i = 0; i<n; i++)
			scanf("%d", &a[i]);
		
		sort(a, a + n);
		for (int i = 0; i<n; i++)
			p = a[n - 1] - a[0];
		printf("%d\n", p * 2);
	}
}



#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int c, n, a[100] = {0};
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		printf("%d\n", (a[n - 1] - a[0]) * 2);
	}
}



When shopping on Long Street, Michael usually parks his 
car at some random location, and then walks to the 
stores he needs. Can you help Michael choose a place to
park which minimises the distance he needs to walk on 
his shopping round? Long Street is a straight line, 
where all positions are integer. You pay for parking in 
a specific slot, which is an integer position on Long 
Street. Michael does not want to pay for more than one 
parking though. He is very strong, and does not mind 
carrying all the bags around.



Input
The first line of input gives the number of test cases, 
1 ≤ t ≤ 100. There are two lines for each test
case. The first gives the number of stores Michael wants 
to visit, 1 ≤ n ≤ 20, and the second gives
their n integer positions on Long Street, 0 ≤ xi ≤ 99.

Output
Output for each test case a line with the minimal 
distance Michael must walk given optimal parking.



Sample Input
2
4
24 13 89 37
6
7 30 41 14 39 42

Sample Output
152
70