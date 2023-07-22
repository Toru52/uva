10071 - Back to High School Physics



#include<stdio.h>

int main()
{
	int v, t;
	while (scanf("%d%d", &v, &t) != EOF)
		printf("%d\n", 2 * v*t);
	return 0;
}



#include<stdio.h>
int main()
{   int a, b;
	while (~scanf("%d%d", &a, &b))
		printf("%d\n", 2 * a*b);
}



A particle has initial velocity and acceleration. 
If its velocity after certain time is v then what will its
displacement be in twice of that time?



Input
The input will contain two integers in each line. Each line 
makes one set of input. These two integers
denote the value of v (−100 ≤ v ≤ 100) and t (0 ≤ t ≤ 200) 
(t means at the time the particle gains that velocity)

Output
For each line of input print a single integer in one line 
denoting the displacement in double of that time.



Sample Input
0 0
5 12

Sample Output
0
120