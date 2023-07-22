477 - Points in Figures: Rectangles and Circles 



no1
#include <stdio.h>

struct figure {
	char type;	
	double x1;//left	
	double y1;//upper
	double x2;//right
	double y2;//lower
	double r;
};

int main() {
	char a;
	struct figure fig[10];
	int cnt = 0;
	while (scanf(" %c", &a) != EOF) {
		if (a == '*') break;
		else if (a == 'r')
			scanf("%lf%lf%lf%lf", &fig[cnt].x1, &fig[cnt].y1, &fig[cnt].x2, &fig[cnt].y2);
		else if (a == 'c')
			scanf("%lf%lf%lf", &fig[cnt].x1, &fig[cnt].y1, &fig[cnt].r);
		fig[cnt].type = a;
		cnt++;
	}

	double x, y;
	int point = 0;
	while (scanf("%lf%lf", &x, &y) != EOF) {
		if (x == 9999.9 && y == 9999.9) break;
		point++;
		int i = 0, flag = 0;
		for (i = 0; i<cnt; i++) {
			if (fig[i].type == 'r') {
				if (x>fig[i].x1 && x<fig[i].x2 && y<fig[i].y1 && y>fig[i].y2) {
					printf("Point %d is contained in figure %d\n", point, i + 1);
					flag = 1;
				}
			}
			else if (fig[i].type == 'c') {
				if (((x - fig[i].x1)*(x - fig[i].x1) + (y - fig[i].y1)*(y - fig[i].y1)) < fig[i].r*fig[i].r) {
					printf("Point %d is contained in figure %d\n", point, i + 1);
					flag = 1;
				}
			}
			else printf("error");
		}
		if (flag == 0) printf("Point %d is not contained in any figure\n", point);
	}
	return 0;
}



no2.
#include<stdio.h>
#include<string>

struct figure {
	int type;
	double x1, x2, y1, y2,r;
};

int main()
{
	char a;
	struct figure fig[11];
	int cnt=1;
	while (scanf(" %c",&a)!=EOF)
	{
		if (a == '*')
			break;
		else if (a == 'r')
			scanf("%lf%lf%lf%lf", &fig[cnt].x1, &fig[cnt].y1, &fig[cnt].x2, &fig[cnt].y2);
		else if (a == 'c')
			scanf("%lf %lf %lf", &fig[cnt].x1, &fig[cnt].y1, &fig[cnt].r);
		fig[cnt].type = a;
		cnt++;
	}
	double x, y;
	int point = 0;
	while (scanf("%lf %lf", &x, &y))
	{
		if (x == 9999.9&&y == 9999.9)
			break;
		point++;
		int flag = 0;
		for (int i = 0; i < cnt; i++)
		{
			
			if (fig[i].type == 'r') {
				if ((fig[i].x1<=x&&x<=fig[i].x2) && (fig[i].y1 >= y&&y >= fig[i].y2))
				{
					printf("Point %d is contained in figure %d\n", point, i);
					flag = 1;
				}
			}
			else if (fig[i].type == 'c') {
				if (((x - fig[i].x1)*(x - fig[i].x1)) + ((y - fig[i].y1)*(y - fig[i].y1)) < fig[i].r*fig[i].r)
				{
					printf("Point %d is contained in figure %d\n", point, i);
					flag = 1;
				}
			}
		}
		if (flag == 0)
			printf("Point %d is not contained in any figure\n", point);
	}
}



Given a list of figures (rectangles and circles) and a list of 
points in the x-y plane, determine for each point which figures 
(if any) contain the point.



Input
There will be n(≤ 10) figures descriptions, one per line. The 
first character will designate the type of figure 
(“r”, “c” for rectangle or circle, respectively). 
This character will be followed by values which describe that 
figure.
• For a rectangle, there will be four real values designating the 
x-y coordinates of the upper left and lower right corners.
• For a circle, there will be three real values, designating the 
x-y coordinates of the center and the radius.
The end of the list will be signalled by a line containing an 
asterisk in column one. The remaining lines will contain the 
x-y coordinates, one per line, of the points to be tested. 
The end of this list will be indicated by a point with 
coordinates 9999.9 9999.9; these values should not be included 
in the output. Points coinciding with a figure border 
are not considered inside.



Output
For each point to be tested, write a message of the form:
Point i is contained in figure j
for each figure that contains that point. If the point is not 
contained in any figure, write a message of the form:
Point i is not contained in any figure
Points and figures should be numbered
in the order in which they appear in the
input.
Note: See the picture on the right for a
diagram of these figures and data points.



Sample Input
r 8.5 17.0 25.5 -8.5
c 20.2 7.3 5.8
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output
Point 1 is contained in figure 3
Point 2 is contained in figure 3
Point 2 is contained in figure 5
Point 3 is contained in figure 5
Point 3 is contained in figure 6
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 5 is contained in figure 2
Point 6 is contained in figure 4