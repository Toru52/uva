11661 - Burger Time?



no1
#include<stdio.h>
#include<math.h>

int main()
{
	int L;
	while (scanf("%d", &L) != EOF && L != 0)
	{
		getchar();
		char road[2000005] = { 0 };
		fgets(road,sizeof(road),stdin);
		int i, j,Z=0,D=-1,R=-1, min = 2147483647;

		for (i = 0; i < L && !Z; i++)
		{
			if (road[i] == 'D')
				D = i;
			if (road[i] == 'R')
				R = i;
			if (road[i] == 'Z')
				Z = 1;
			if (D >= 0 && R >= 0)
				min = (abs(D - R) < min) ? abs(D - R) : min;
		}
		if (Z)
			printf("0\n");
		else
			printf("%d\n", min);
	}
	return 0;
}



no2
#include<iostream>
#include<algorithm>
int main()
{
	int len;
	while (~scanf("%d", &len) && len)
	{
		getchar();
		char dis[2000001];
		int R = -1, D = -1, Z = 0,min=999999999;
		fgets(dis, len + 1, stdin);
		for (int i = 0; i < len; i++)
		{
			if (dis[i] == 'R')
				R = i;
			if (dis[i] == 'D')
				D = i;
			if (dis[i] == 'Z')
				Z = 1;
			if (R >= 0 && D >= 0)
				min = min < abs(R - D) ? min : abs(R - D);
		}
		if (Z)
			puts("0");
		else
			printf("%d\n", min);

	}
}



Everybody knows that along the more important highways there are 
countless fast food restaurants.One can find easily hamburgers, 
hot dogs, pizzas, sandwiches ... food everywhere. Many times the problem 
isn’t to find a restaurant but a drugstore. After a big lunch with fast 
food it’s normal that we need a drugstore because our stomach begins to 
feel pain. Given the locations of the restaurants and drugstores on a 
highway, you want to determine the minimum distance between a restaurant 
and a drugstore.



Input
The first line of each test case gives an integer L (1 ≤ L ≤ 2000000) 
indicating the length of the highway.
The second line of each test case contains a string S of length L, 
showing the positions of the restaurants and drugstores along the 
highway in the following manner:
• The character ‘R’ represents a place with a restaurant.
• The character ‘D’ represents a place with a drugstore.
• The character ‘Z’ represents a place with a restaurant and a drugstore.
• The character ‘.’ represents an empty place.
You can suppose that every test case has at least one restaurant and at 
least one drugstore. The end of the input is indicated when L = 0.

Output
For each case in the input, print one line with the minimum distance 
between a restaurant and a drugstore.



Sample Input
2
RD
5
..Z..
10
.R......D.
10
.R..Z...D.
10
...D..R...
25
..D...R.RR...DD...D.R...R
0

Sample Output
1
0
7
0
3
2