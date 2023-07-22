478 - Points in Figures: Rectangles, Circles, Triangles



#include <stdio.h>
#define eps 0
typedef struct {
	double x, y;
} Point;
typedef struct {
	Point a, b, c;
	double r;
	int sh;
} Shape;
Shape D[1000];
double cross(Point &o, Point &a, Point &b) {
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
int inShape(Point &a, Point &b, Point &c, Point &t) {
	if (cross(a, b, t)*cross(a, c, t) > eps) {   // a is main
		return 0;
	}
	if (cross(b, a, t)*cross(b, c, t) > eps) {   // b is main
		return 0;
	}
	if (cross(c, a, t)*cross(c, b, t) > eps) {   // c is main
		return 0;
	}
	return 1;
}
int main() {
	int n = 0, i;
	char s[1000];
	while (scanf("%s", s)) {
		if (s[0] == '*')
			break;
		if (s[0] == 'r') {
			scanf("%lf %lf %lf %lf %lf", &D[n].a.x, &D[n].a.y, &D[n].b.x, &D[n].b.y);
			D[n].sh = 1;
		}
		else if (s[0] == 'c') {
			scanf("%lf %lf %lf", &D[n].a.x, &D[n].a.y, &D[n].r);
			D[n].sh = 2;
		}
		else {
			scanf("%lf %lf %lf %lf %lf %lf", &D[n].a.x, &D[n].a.y, &D[n].b.x, &D[n].b.y, &D[n].c.x, &D[n].c.y);
			D[n].sh = 3;
		}
		n++;
	}
	int test = 0;
	double x, y;
	while (scanf("%lf %lf", &x, &y) == 2) {
		if (x == 9999.9 && y == 9999.9)
			break;
		test++;
		int flag = 0;
		for (i = 0; i < n; i++) {
			if (D[i].sh == 1) {
				if (D[i].a.x < x && x < D[i].b.x && D[i].a.y > y && y > D[i].b.y) {
					printf("Point %d is contained in figure %d\n", test, i + 1);
					flag = 1;
				}
			}
			else if (D[i].sh == 2) {
				if ((D[i].a.x - x)*(D[i].a.x - x) + (D[i].a.y - y)*(D[i].a.y - y) < D[i].r*D[i].r) {
					printf("Point %d is contained in figure %d\n", test, i + 1);
					flag = 1;
				}
			}
			else {
				Point t;
				t.x = x, t.y = y;
				if (inShape(D[i].a, D[i].b, D[i].c, t)) {
					printf("Point %d is contained in figure %d\n", test, i + 1);
					flag = 1;
				}
			}
		}
		if (!flag)
			printf("Point %d is not contained in any figure\n", test);
	}
	return 0;
}



#include<stdio.h>

typedef struct {
	double x, y;
}P;
typedef struct {
	P a, b, c;
	double r;
	int who;
}S;

S D[1000];

double order(P &o, P &a, P&b) {
	return ((a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x));
}
int IN(P &a, P &b, P &c, P &t) {
	if (order(a, b, t)*order(a, c, t) > 0)
		return 0;
	if (order(b,a, t)*order(b, c, t) > 0)
		return 0;
	if (order(c,b, t)*order(c,a, t) > 0)
		return 0;
	return 1;
}

int main() {
	char s[1000];
	int n = 0;
	while (scanf("%s", s)) {
		if (s[0] == '*')
			break;
		if (s[0] == 'r') {
			scanf("%lf %lf %lf %lf",&D[n].a.x,&D[n].a.y,
				                        &D[n].b.x,&D[n].b.y);
			D[n].who = 1;
		}
		else if (s[0] == 'c') {
			scanf("%lf %lf %lf", &D[n].a.x, &D[n].a.y, &D[n].r);
			D[n].who = 2;
		}
		else if (s[0] == 't') {
			scanf("%lf %lf %lf %lf %lf %lf", &D[n].a.x,
				&D[n].a.y, &D[n].b.x, &D[n].b.y, &D[n].c.x, &D[n].c.y);
			D[n].who = 3;
		}
		n++;
	}
	double x, y;
	int fig = 0;
	while (scanf("%lf %lf", &x, &y) == 2) {
		int F = 0;
		fig++;
		if (x == 9999, 9 && y == 9999.9)
			break;
		for (int i = 0; i < n; i++) {
			if (D[i].who == 1) {
				if (D[i].a.x<x&&x<D[i].b.x&&D[i].a.y>y&&y>D[i].b.y) {
					printf("Point %d is contained in figure %d\n", fig, i + 1);
					F = 1;
				}
			}
			else if (D[i].who == 2) {
				if ((D[i].a.x - x)*(D[i].a.x - x) + (D[i].a.y - y)*(D[i].a.y - y) < D[i].r * D[i].r) {
					printf("Point %d is contained in figure %d\n", fig, i + 1);
					F = 1;
				}
			}
			else if (D[i].who == 3) {
				P t;
				t.x = x, t.y = y;
				if (IN(D[i].a, D[i].b, D[i].c, t)) {
					printf("Point %d is contained in figure %d\n", fig, i + 1);
					F = 1;
				}
			}
		}
		if (!F)
			printf("Point %d is not contained in any figure\n", fig);
	}
}


Explain about "typedef"
http://www.ced.is.utsunomiya-u.ac.jp/lecture/2009/prog/p2/kadai2/typedef.php

"typedef" can to add the name at the last position after define a struct

ex
struct employee {
    char name[12];
    double hours;
    int wage;
};

typedef struct employee {  
  char name[12];
 double hours;
 int wage;
} EMPLOYEE;



IMAGE
"rectangle"
*ax



            *bx



			
			
The determine that a point at in the triangle or not.
http://ftvoid.com/blog/post/339




Given a list of figures (rectangles, circles, and triangles) and a 
list of points in the x-y plane, determine
for each point which figures (if any) contain the point.



Input
There will be n( 10) figures descriptions, one per line. The first 
character will designate the type of
figure (“r”, “c”, “t” for rectangle, circle, or triangle, respectively).
 This character will be followed by values which describe that figure.
• For a rectangle, there will be four real values designating 
  the x-y coordinates of the upper left and lower right corners.
• For a circle, there will be three real values, designating the 
  x-y coordinates of the center and the radius.
• For a triangle, there will be six real values designating the x-y 
  coordinates of the vertices.
The end of the list will be signalled by a line containing an asterisk 
in column one. The remaining lines will contain the x-y coordinates, 
one per line, of the points to be tested. The end of this list will be 
indicated by a point with coordinates 9999.9 9999.9; 
these values should not be included in the output.
Points coinciding with a figure border are not considered inside.

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
t -1.0 -1.0 10.1 2.2 .4 1.4
r 0.0 10.3 5.5 0.0
c -5.0 -5.0 3.7
t 20.3 9.8 10.0 -3.2 17.5 -7.7
r 2.5 12.5 12.5 2.5
c 5.0 15.0 7.2
t -10.0 -10.0 10.0 25.0 30.0 -10.0
*
2.0 2.0
4.7 5.3
6.9 11.2
20.0 20.0
17.6 3.2
-5.2 -7.8
9999.9 9999.9

Sample Output
Point 1 is contained in figure 4
Point 1 is contained in figure 9
Point 2 is contained in figure 4
Point 2 is contained in figure 7
Point 2 is contained in figure 9
Point 3 is contained in figure 7
Point 3 is contained in figure 8
Point 3 is contained in figure 9
Point 4 is not contained in any figure
Point 5 is contained in figure 1
Point 5 is contained in figure 2
Point 5 is contained in figure 6
Point 5 is contained in figure 9
Point 6 is contained in figure 5
Point 6 is contained in figure 9