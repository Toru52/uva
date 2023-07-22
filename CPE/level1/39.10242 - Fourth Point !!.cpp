10242 - Fourth Point !!


no1.
#include <stdio.h>

int main() {
	double x1, y1, x2, y2, x3, y3, x4, y4;
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf",
		&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8) {
		if (x1 == x3 && y1 == y3)
			printf("%.3lf %.3lf\n", (x2 + x4) - x1, (y2 + y4) - y1);
		else if (x1 == x4 && y1 == y4)
			printf("%.3lf %.3lf\n", (x2 + x3) - x1, (y2 + y3) - y1);
		else if (x2 == x3 && y2 == y3)
			printf("%.3lf %.3lf\n", (x1 + x4) - x2, (y1 + y4) - y2);
		else
			printf("%.3lf %.3lf\n", (x1 + x3) - x2, (y1 + y3) - y2);
	}
	return 0;
}



no2.
#include<stdio.h>

int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8)
	{
		if (x1 == x3&&y1 == y3)
			printf("%.3lf %.3lf\n",(x2+x4)-x1,(y2+y4)-y1);
		else if (x1 == x4&&y1 == y4)
			printf("%.3lf %.3lf\n", (x2 + x3) - x1, (y2 + y3) - y1);
		else if (x2 == x3&&y2 == y3)
			printf("%.3lf %.3lf\n", (x1 + x4) - x2, (y1 + y4) - y2);
		else
			printf("%.3lf %.3lf\n", (x1 + x3) - x2, (y1 + y3) - y2);
	}
}




Given are the (x, y) coordinates of the endpoints of two adjacent 
sides of a parallelogram. Find the (x, y) coordinates of the 
fourth point.



Input
Each line of input contains eight floating point numbers: 
the (x, y) coordinates of one of the endpoints of the first side 
followed by the (x, y) coordinates of the other endpoint of the 
first side, followed by the(x, y) coordinates of one of the 
endpoints of the second side followed by the (x, y) coordinates 
of the other endpoint of the second side. All coordinates are in 
meters, to the nearest mm. All coordinates are between −10000 
and +10000. Input is terminated by end of file.

Output
For each line of input, print the (x, y) coordinates of the 
fourth point of the parallelogram in meters,
to the nearest mm, separated by a single space.



Sample Input
0.000 0.000 0.000 1.000 0.000 1.000 1.000 1.000
1.000 0.000 3.500 3.500 3.500 3.500 0.000 1.000
1.866 0.000 3.127 3.543 3.127 3.543 1.412 3.145

Sample Output
1.000 0.000
-2.500 -2.500
0.151 -0.398