10370－Above Average



#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int C, N;
  float score[1005], average, percent;
  while( scanf( "%d", &C ) != EOF ){
    for( int i = 1 ; i <= C ; i++ ){
      scanf( "%d", &N );
      average = 0.0;
      for( int j = 0 ; j < N ; j++ ){
        scanf( "%f", &score[j] );
        average += score[j];
      }
      average /= N;
      percent = 0.0;
      for( int j = 0 ; j < N ; j++ ){
        if( score[j] > average ) percent++;
      }
      percent /= N;
      percent *= 100;
      printf( "%.3f%%\n", percent );
    }
  }
  return 0;
}



#include<stdio.h>
int main()
{
	float g[10000];
	int C, N;
	scanf("%d", &C);
	while (C--)
	{
		float avg = 0, avg2 = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%f", &g[i]);
			avg += g[i];
		}
		avg /= N;
		for (int i = 0; i < N; i++)
			if (avg < g[i])
				avg2 += 100;
		printf("%2.3f%%\n", avg2 / N);
	}
}



It is said that 90% of frosh expect to be
above average in their class. You are to
provide a reality check.



Input
The first line of standard input contains
an integer C, the number of test cases.
C data sets follow. Each data set begins
with an integer, N, the number of people
in the class (1 ≤ N ≤ 1000). N integers
follow, separated by spaces or newlines,
each giving the final grade (an integer between
0 and 100) of a student in the class.

Output
For each case you are to output a line giving the percentage of 
students whose grade is above average,
rounded to 3 decimal places.



Sample Input
5
5 50 50 70 80 100
7 100 95 90 80 70 60 50
3 70 90 80
3 70 90 81
9 100 99 98 97 96 95 94 93 91

Sample Output
40.000%
57.143%
33.333%
66.667%
55.556%