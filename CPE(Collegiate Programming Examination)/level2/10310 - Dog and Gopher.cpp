10310 - Dog and Gopher
https://github.com/Sharknevercries/Online-Judge/blob/master/UVA/Volume%20CIII/10310%20Dog%20and%20Gopher.cpp



#include<stdio.h>
#include<math.h>
int main() {
	int n;
	double gopher_x, gopher_y, dog_x, dog_y;
	while (scanf("%d%lf%lf%lf%lf", 
		&n, &gopher_x, &gopher_y, &dog_x, &dog_y) == 5) {
		bool escape = false;
		double x, y, tx, ty;
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &x, &y);
			if (!escape&&
				sqrt((gopher_x - x)*(gopher_x - x) + (gopher_y - y)*(gopher_y - y)) * 2 
				<= sqrt((dog_x - x)*(dog_x - x) + (dog_y - y)*(dog_y - y))) {
				escape = true;
				tx = x;
				ty = y;
			}
		}
		if (escape)
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", tx, ty);
		else
			puts("The gopher cannot escape.");

	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	int n;
	double gx, gy, dx, dy,fx,fy,hx,hy;
	while (scanf("%d %lf %lf %lf %lf", &n, &gx, &gy, &dx, &dy) == 5) {
		int escape = false;
		for (int i = 0; i < n;i++) {
			scanf("%lf%lf", &hx, &hy);
			if (!escape&&sqrt((gx - hx)*(gx-hx) + (gy - hy)*(gy-hy))*2 
				<= sqrt((dx - hx)*(dx-hx) + (dy - hy) *(dy-hy))) {
				escape = true;
				fx = hx,fy = hy;
			}
		}
		if (escape)
			printf("The gopher can escape through the hole at (%.3f,%.3f).\n", fx, fy);
		else
			puts("The gopher cannot escape.");
	}
	return 0;
}



A large  eld has a gopher and a dog. The dog wants to eat the gopher, 
while the gopher wants to run to safety through one of several gopher 
holes dug in the surface of the  eld. Neither the dog nor the gopher 
is a math major; however, neither is entirely stupid. The gopher
decides on a particular gopher hole and heads for that hole in a 
straight line at a  xed speed. The dog, which is very good at reading 
body language, anticipates which hole the gopher has chosen, 
and heads at double the speed of the gopher to the hole, 
where it intends to gobble up the gopher. If the dog reaches the hole 
rst, the gopher gets gobbled; otherwise, the gopher escapes.
You have to select a hole for the gopher through which it can escape, 
if such a hole exists.



Input
The input  le contains several sets of input. The  rst line of each 
set contains one integer and four oating point numbers. 
The integer n denotes how many holes are in the set and the four  
oating point numbers denote the (x;y) coordinates of the gopher 
followed by the (x;y) coordinates of the dog. Subsequent n lines of 
input each contain two  oating point numbers: the (x;y) coordinates 
of a gopher hole. All distances are in meters; to the nearest mm. 
Input is terminated by end of  le. There is a blank line between two 
consecutive sets.

Output
Your should output a single line for each set of input.  
For each set, if the gopher can escape the output line should read `
The gopher can escape through the hole at (x;y).' identifying the
appropriate hole to the nearest mm.  
Otherwise the output line should read `The gopher cannot escape.
' If the gopher may escape through more than one hole, 
report the one that appears  rst in the input. There are not more 
than 1000 gopher holes in a set of input and all coordinates are 
between
-10000 and +10000.



SampleInput
1 1.000 1.000 2.000 2.000
1.500 1.500
2 2.000 2.000 1.000 1.000
1.500 1.500
2.500 2.500

SampleOutput
The gopher cannot escape.
The gopher can escape through the hole at (2.500,2.500).