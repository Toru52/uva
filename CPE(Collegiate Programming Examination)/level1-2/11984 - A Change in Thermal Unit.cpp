11984 - A Change in Thermal Unit



#include<iostream>
#include<cstdio>
using namespace std;

int main(){
  int T;
  float C, d, F;
  while( scanf( "%d", &T ) != EOF ){
    for( int i = 1 ; i <= T ; i++ ){
      scanf( "%f%f", &C, &d );
      F = (9*C)/5 + 32;
      F += d;
      C = (F-32)*5/9;
      printf( "Case %d: %.2f\n", i, C );
    }
  }
  return 0;
}



#include<iostream>

int main()
{
	int n;
	float C, d, F;
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
	{
		scanf("%f %f", &C, &d);
		F = (9 * C) / 5 + 32;
		F += d;
		C = (F - 32)*5 / 9;
		printf("Case %d: %.2f\n", i, C);
	}
}


Measuring temperature and temperature differences are common task 
in many research and applications. Unfortunately, there exists 
more than one unit of measuring temperatures. This introduces a
lot of confusion at times. Two popular units of measurements are 
Celsius(C) and Fahrenheit (F). The
conversion of F from C is given by the formula:
F =
9
5
C + 32
In this problem, you will be given an initial temperature in C 
and an increase in temperature in F.
You would have to calculate the new temperature in C.



Input
Input starts with an integer T (≤ 100), denoting the number of 
test cases. Each case contains a line with two integers C and d 
(0 ≤ C, d ≤ 100), where C represents the initial temperature in 
Celsius and d represents the increase in temperature in Fahrenheit.

Output
For each case, print the case number and the new temperature in 
Celsius after rounding it to two digits after the decimal point.



Sample Input
2
100 0
0 100

Sample Output
Case 1: 100.00
Case 2: 55.56