10573 - Geometry Paradox.cpp
http://mypaper.pchome.com.tw/zerojudge/post/1323852157



#include <stdio.h>
#include <math.h>
const double pi = acos(-1);
int main() {
	int t, a, b;
	char cmd[50];
	scanf("%d ", &t);
	while (t--) {
		fgets(cmd, sizeof(cmd), stdin);
		if (sscanf(cmd, "%d %d", &a, &b)==2) 
			printf("%.4lf\n", 2 * a*b*pi);
		else 
			sscanf(cmd, "%d", &a),printf("%.4lf\n", a*a*pi / 8);
	}
	return 0;
}



In the picture below you can see two small circles
touching each other. The larger circle touches
both of them. The length of the common tan-
gent inscribed inside the larger circle is t and
the radiuses of the two smaller circles are
r
1
and
r
2
. The centers of the three circles are collinear.
You will be given the value of
r
1
and
r
2
or the
value of
t
. You will have to  nd the area that is
within the larger circle but out of the two smaller
circles (marked gray in the picture). If the given
data is not enough to  nd the gray area, print
the line `
Impossible.
' in a single line
Input
First line of the input  le contains an integer
N
(
N

100) which denotes how many sets of in-
puts are there. Each of the next
N
lines contain
a set of input.
Each set either contains one or two integer.
If it contains one integer then it is the value of
t
, otherwise the two values are the values of
r
1
and
r
2
.
All these integers are less than 100
Output
For each line of input produce one line of output. 
This line contains the area of the gray part if the given
information is enough to  nd the area of the gray part. 
Otherwise it contains the line `
Impossible
'.
The area should have four digits after the decimal point. 
Assume that

= 2

cos
