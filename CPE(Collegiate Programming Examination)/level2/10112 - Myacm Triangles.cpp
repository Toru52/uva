10112 - Myacm Triangles
http://blog.tobygameac.com/2013/08/uva-10112-myacm-triangles.html



#include <iostream>  
using namespace std;

typedef struct pnode
{
	char name;
	int  x, y;
}point;
point P[20];

int Area(point a, point b, point c)
{
	return abs((b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y));
}

int main()
{
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i)
			cin >> P[i].name >> P[i].x >> P[i].y;

		int Max = 0, a = 0, b = 1, c = 2;
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				for (int k = j + 1; k < n; ++k) {
					int flag = 1;
					int temp, area = Area(P[i], P[j], P[k]);
					for (int p = 0; p < n; ++p) {
						if (p == i || p == j || p == k)
							continue;
						temp = Area(P[p], P[j], P[k]);
						temp += Area(P[i], P[p], P[k]);
						temp += Area(P[i], P[j], P[p]);
						if (temp == area) {
							flag = 0;
							break;
						}
					}
					if (flag && Max < area) {
						a = i; b = j; c = k;
						Max = area;
					}
				}

		printf("%c%c%c\n", P[a].name, P[b].name, P[c].name);
	}
	return 0;
}



#include<iostream>
using namespace std;
typedef struct pnode { char name; int x, y; }point;

int AREA(point a,point b,point c){
	return abs((c.y - a.y)*(b.x - a.x) - (b.y - a.y)*(c.x - a.x));
}
int main() {
	point P[16];
	int n;
	while (cin >> n&&n) {
		for (int i = 0; i < n; i++)
			cin >> P[i].name >> P[i].x >> P[i].y;
		int max = 0, a = 0, b = 1, c = 2,area,temp;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for (int k = j + 1; k < n; k++) {
					int flag = 1;
					area = AREA(P[i], P[j], P[k]);
					for (int p = 0; p < n; p++) {
						if (p == i || p == j || p == k)
							continue;
						temp = AREA(P[p], P[j], P[k]);
						temp += AREA(P[i], P[p], P[k]);
						temp += AREA(P[i], P[j], P[p]);
						if (area == temp) {
						   flag = 0;
				    	   break;
						}
					}
					if (flag&&max < area) {
						max = area;
						a = i, b = j, c = k;
					}
				}
		printf("%c%c%c\n", P[a].name, P[b].name, P[c].name);
	}
	return 0;
}



There has been considerable archeological work on the ancient
Myacm culture. Many artifacts have been found in what
have been called power fields: a fairly small area, less than
100 meters square where there are from four to fifteen tall
monuments with crystals on top. Such an area is mapped out
above. Most of the artifacts discovered have come from inside
a triangular area between just three of the monuments, now
called the power triangle. After considerable analysis 
archeologists agree how this triangle is selected from all the 
triangles with three monuments as vertices: it is the triangle 
with the largest possible area that does not contain any other 
monuments inside the triangle or on an edge of the triangle. 
Each field contains only one such triangle.
Archeological teams are continuing to find more power fields. 
They would like to automate the task of locating the power 
triangles in power fields. Write a program that takes the 
positions of the monuments in any number of power fields as 
input and determines the power triangle for each power field.
A useful formula: the area of a triangle with vertices 
(x1, y1), (x2, y2), and (x3, y3) is the absolute value of
0.5 × [(y3 − y1)(x2 − x1) − (y2 − y1)(x3 − x1)].



Input
For each power field there are several lines of data. The first 
line is the number of monuments: at least 4, and at most 15. 
For each monument there is a data line that starts with a one 
character label for the monument and is followed by the 
coordinates of the monument, which are nonnegative integers 
less than 100. The first label is A, and the next is B, 
and so on.
There is at least one such power field described. 
The end of input is indicated by a 0 for the number
of monuments. The first sample data below corresponds to the 
diagram in the problem.

Output
For each power field there is one line of output. 
It contains the three labels of the vertices of the power
triangle, listed in increasing alphabetical order, with no 
spaces.



Sample Input
6
A 1 0
B 4 0
C 0 3
D 1 3
E 4 4
F 0 6
4
A 0 0
B 1 0
C 99 0
D 99 99
0

Sample Output
BEF
BCD