10107 - What is the Median?



no1
#include<cstdio>
#include<algorithm>

int main()
{
	long long a[10005], n, i = 0, ans;
	while (scanf("%lld", &n) == 1)
	{
		a[i] = n;
		std::sort(a, a + i + 1);
		if (i % 2 == 0)
			printf("%lld\n", a[i / 2]);
		else
		{
			ans = a[i / 2] + a[(i / 2) + 1];
			printf("%lld\n", ans / 2);
		}
		i++;
	}
}



no2
#include<cstdio>
#include<algorithm>
int main()
{
	long long a[10001], n, i = 0;
	while (scanf("%lld",&n)==1)
	{
		a[i] = n;
		std::sort(a, a + i + 1);
		if (i % 2 == 0)
			printf("%lld\n", a[i / 2]);
		else
			printf("%lld\n", (a[i / 2] + a[(i / 2) + 1]) / 2);
		i++;
	}
}


Median plays an important role in the world of statistics. 
By definition, it is a value which divides an array into 
two equal parts. In this problem you are to determine the 
current median of some long integers. Suppose, we have five 
numbers {1,3,6,2,7}. In this case, 3 is the median as it 
has exactly two numbers on its each side. 
{1,2} and {6,7}. If there are even number of values like 
{1,3,6,2,7,8}, only
one value cannot split this array into equal two parts, 
so we consider the average of the middle values
{3,6}. Thus, the median will be (3+6)/2 = 4.5. 
In this problem, you have to print only the integer
part, not the fractional. As a result, according to this 
problem, the median will be 4 !



Input
The input file consists of series of integers X (0 ≤ X < 2
31) and total number of integers N is less than
10000. The numbers may have leading or trailing spaces.

Output
For each input print the current value of the median.



Sample Input
1
3
4
60
70
50
2

Sample Output
1
2
3
3
4
27
4