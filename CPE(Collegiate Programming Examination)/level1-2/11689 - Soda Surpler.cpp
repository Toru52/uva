11689 - Soda Surpler



#include <iostream>
#include <stdio.h>
#include<math.h>
using namespace std;

int main()
{
	float c, e, f, n;
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%f%f%f", &e, &f, &c);
		n = ((e + f) / (c - 1)) - 1;
		if (n <= 0)
			cout << 0 << endl;
		else 
			cout << ceil(n) << endl;
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main()
{
	int cas;
	float e, f, c, n;

	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%f %f %f", &e, &f, &c);
		n = ((e + f) / (c - 1)) - 1;

		if (n <= 0)
			puts("0");
		else
			printf("%.f\n", ceil(n));
	}
}



Tim is an absolutely obsessive soda drinker,he simply cannot get 
enough. Most annoyingly though, he almost never has any money,
so his only obvious legal way to obtain more soda is to take the 
money he gets when he recycles empty soda bottles to buy new ones.
In addition to the empty bottles resulting from his own consumption 
he sometimes find empty bottles in the street. One day he was extra 
thirsty, so he actually drank sodas until he couldn’t afford a new 
one.



Input
The first line of the input file contains an integer N (N < 15) 
which denotes the total number of test
cases. The description of each test case is given below:
Three non-negative integers e, f, c, where e < 1000 equals the 
number of empty soda bottles in Tim’s possession at the start of 
the day, f < 1000 the number of empty soda bottles found during the
day, and 1 < c < 2000 the number of empty bottles required to buy 
a new soda.

Output
For each test case print how many sodas did Tim drink on his extra 
thirsty day? Look at the sample output for details.



Sample Input
2
9 0 3
5 5 2

Sample Output
4
9