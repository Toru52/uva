151 - Power Crisis



no1
#include<cstdio>

int main() {
	int N, m, turnoff;

	while (scanf("%d", &N) != EOF && N != 0) {
		for (m = 1; m < N-1; m++) {
			turnoff = 0;
			printf("m %d\n", m);
			for (int i = 1; i < N; i++)
				turnoff = (turnoff + m) % i,printf("turn off%d\n",turnoff);
			if (turnoff == 11)
				break;
		}
		printf("%d\n", m);
	}
	return 0;
}




no2
#include <stdio.h>
#include <string.h>

void init(int k[])
{
	int i;
	for (i = 1; i < 100; i++)
		k[i] = 0;
}

int main()
{
	int N, count, i, m;
	int k[100], t;

	while (scanf("%d", &N) == 1)
	{
		if (N == 0)
			break;
		for (i = 1; i < N; i++)
		{
			printf("i %d\n",i);
			init(k);
			int j = 1, count = 0;
			t = 1;
			for (; ; )
			{
				if (j > N)
					j -= N;
				if (k[j] == 0)
				{
					if (count == i)
					{
						k[j] = 1;
						printf("j %d\n", j);
						count = 0;
					}
					j++;
					count++;
					k[1] = 1;
				}
				else
					j++;
				if (k[13] == 1)
					break;
			}
			for (m = 1; m <= N; m++)
			{
				if (k[m] == 0)
				{
					t = 0;
					break;
				}
			}
			if (t == 1)
			{
				printf("%d\n", i);
				break;
			}
			puts("");
		}
	}
	return 0;
}



no3
#include<cstdio>
int main()
{
	int n;
	while (~scanf("%d", &n)&&n)
	{
		for (int m = 1; m < n-1; m++)
		{
			int turnoff = 0;
			for (int i = 1; i < n ; i++)
				turnoff = (turnoff + m) % i;
			if (turnoff == 11)
			{
				printf("%d\n", m);
				break;
			}
		}
	}
}



hints
原本最後的點13需減1變成12，再來因為編號從0開始編比較好算，
所以真正最後的點會變成11



During the power crisis in New Zealand this winter (caused by 
a shortage of rain and hence low levels in the hydro dams), 
a contingency scheme was developed to turn off the power to 
areas of the country in a systematic, totally fair, manner. 
The country was divided up into N regions (Auckland was region 
number 1, and Wellington number 13). A number, m, would be
picked `at random', and the power would first be turned off in 
region 1 (clearly the fairest starting point) and then in 
every m'th region after that, wrapping around to 1 after N, 
and ignoring regions already turned off. For example, 
if N = 17 and m = 5, power would be turned off to the regions 
in the order:1,6,11,16,5,12,2,9,17,10,4,15,14,3,8,13,7.
The problem is that it is clearly fairest to turn off 
Wellington last (after all, that is where the Electricity 
headquarters are), so for a given N, the `random' number m 
needs to be carefully chosen so that region 13 is the last 
region selected.
Write a program that will read in the number of regions and 
then determine the smallest number m that will ensure that 
Wellington (region 13) can function while the rest of the 
country is blacked out.



Input and Output
Input will consist of a series of lines, each line containing 
the number of regions (N) with  tex2html_wrap_inline42 . 
The file will be terminated by a line consisting of a single 0.
Output will consist of a series of lines, one for each line of 
the input. Each line will consist of the number m according to 
the above scheme.



Sample input
17
0

Sample output
7



m=5
1,6,11,16,5,12,2,9,17,10,4,15,14, 3, 8,13,7
  0, 1, 0,1, 1,0,5, 2, 7,2, 7, 0, 5,10, 0,5
  
1, 2, 3, 4, 5, 6,7, 8, 9,10,11,12,13,14,15,16,17
1, 0, 1, 1, 0, 5,2, 7, 2, 7, 0, 5,10, 0, 5
1, 6,11,16, 5,12,2, 9,17,10, 4,15,14, 3, 8,13, 7


m=7
0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
0,1,2,1,3,4,4,3,1,8, 4,11, 5,12, 4,11

1,2,3, 4,5, 6,7, 8, 9,10,11,12,13,14,15,16,17
1,7,8,15,6,14,7,17,11, 5, 3, 2, 4,10,16, 9,12,13