10209 - Is This Integration ?



no1.
#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
	double a;
	while (scanf("%lf", &a) != EOF)
	{
		double x, y, z;
		z = a*a - a*a*PI / 4;
		z -= a*a*PI / 4 - a*a*PI / 6 - (a*a*PI / 6 - a*a*sqrt(3.0) / 4);
		y = a*a - a*a*PI / 4 - 2 * z;
		x = a*a - 4 * y - 4 * z;
		printf("%.3lf %.3lf %.3lf\n", x, 4 * y, 4 * z);
	}
	return 0;
}



no2
#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
	double a,x,y,z;
	while (~scanf("%lf", &a))
	{
		z = a*a - a*a*PI / 4;
		z -= a*a*PI / 12 - (a*a*PI / 6 - a*a*sqrt(3) / 4);
		y = a*a-a*a*PI / 4 - z * 2;
		x = a*a - z * 4 - y * 4;
		printf("%.3lf %.3lf %.3lf\n", x, y*4, z*4);
	}
}


Algorithm
http://www.tokumath.com/situmon/kyuseki1.html#




In the image below you can see a square
ABCD, where AB = BC = CD = DA =
a. Four arcs are drawn taking the four
vertexes A, B, C, D as centers and a as
the radius. The arc that is drawn taking
A as center, starts at neighboring vertex
B and ends at neighboring vertex D.
All other arcs are drawn in a similar fashion.
Regions of three different shapes are
created in this fashion. You will have to
determine the total area if these different
shaped regions.



Input
The input file contains a floating-point
number a (0 ≤ a ≤ 10000) in each line
which indicates the length of one side of
the square. Input is terminated by end of
file

Output
For each line of input, output in a single line the total area of the 
three types of region (filled with
different patterns in the image above).
These three numbers will of course be floating point numbers with 
three digits after the decimal point. First number will denote the 
area of the striped region, the second number will denote the total
area of the dotted regions and the third number will denote the area 
of the rest of the regions.



Sample Input
0.1
0.2
0.3

Sample Output
0.003 0.005 0.002
0.013 0.020 0.007
0.028 0.046 0.016