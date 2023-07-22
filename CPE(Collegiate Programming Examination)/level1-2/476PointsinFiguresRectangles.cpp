476	Points in Figures: Rectangles



#include<cstdio>
#define N 10
struct Rec
{
	double x1, y1, x2, y2;
}rec[11];
int main()
{
	int count = 1;
	while (getchar() == 'r')
	{
		scanf("%lf%lf%lf%lf", &rec[count].x1, &rec[count].y1, &rec[count].x2, &rec[count].y2);
		count++;
		getchar();
	}

	bool in;
	int i = 0;
	double x, y;
	while (scanf("%lf%lf", &x, &y) && x != 9999.9&&y != 9999.9)
	{
		in = false;
		i++;
		for (int j = 1; j<count; j++)
			if (x > rec[j].x1&&x < rec[j].x2&&y<rec[j].y1&&y > rec[j].y2)
			{
				printf("Point %d is contained in figure %d\n", i, j);
				in = true;
			}

		if (!in)
			printf("Point %d is not contained in any figure\n", i);
	}
	return 0;
}



#include<cstdio>
struct REC
{
	double x1, y1, x2, y2;
}rec[11];
int main()
{
	int i = 1, max;
	while (getchar() != '*')
	{
		scanf("%lf %lf %lf %lf", &rec[i].x1, &rec[i].y1, &rec[i].x2, &rec[i].y2);
		getchar();
		i++;
	}
	max=i;
	i = 1;
	double x, y;
	while (scanf("%lf %lf", &x, &y)&& (x != 9999.9&&y != 9999.9))
	{
		bool flag = false;
		for (int j = 1; j <= max;j++)
			if (rec[j].x1 < x&&x < rec[j].x2&&rec[j].y2 < y&&y<rec[j].y1)
			{
				flag = true;
				printf("Point %d is contained in figure %d\n", i, j);
			}
		if (!flag)
			printf("Point %d is not contained in any figure\n", i);
		i++;
	}
}



Given a list of rectangles and a list of points in the x-y plane, 
determine for each point which figures (if any) contain the point.



Input
There will be n( tex2html_wrap_inline220 ) rectangles descriptions, 
one per line. The first character will designate the type of figure 
(``r'' for rectangle). This character will be followed by four real 
values designating the x-y coordinates of the upper left and lower 
right corners.The end of the list will be signalled by a line 
containing an asterisk in column one.The remaining lines will contain 
the x-y coordinates, one per line, of the points to be tested. 
The end of this list will be indicated by a point with coordinates 
9999.9 9999.9; these values should not be included in the output.
Points coinciding with a figure border are not considered inside.

Output
For each point to be tested, write a message of the form:
Point i is contained in figure j
for each figure that contains that point. If the point is not 
contained in any figure, write a message of the form:
Point i is not contained in any figure
Points and figures should be numbered in the order in which they 
appear in the input.



Sample Input

r 8.5 17.0 25.5 -8.5
r 0.0 10.3 5.5 0.0
r 2.5 12.5 12.5 2.5
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output

Point 1 is contained in figure 2
Point 2 is contained in figure 2
Point 2 is contained in figure 3
Point 3 is contained in figure 3
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 6 is not contained in any figure
