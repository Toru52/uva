10221 - Satellites



no1.
#include<cstdio>
#include<cstring>
#include<math.h>
#define pi 2*acos(0.0)

int main() {
	double s, a;
	char str[5];
	while (scanf("%lf%lf%s", &s, &a, str) == 3) {
		s += 6440;
		if (a > 180)
			a = 360 - a;
		if (!strcmp(str, "min"))
			a = a / 60.0;
		a = (pi * a) / 180.0;
		printf("%0.6lf %0.6lf\n", s * a, 2 * s * sin(a / 2.0));
	}
	return 0;
}



no2.
#include<cstring>
#include<cstdio>
#include<math.h>
#define pi 2*acos(0.0)

int main()
{
	double s, a;
	char str[4];
	while (scanf("%lf%lf%s", &s, &a, str) == 3)
	{
		s += 6440;
		if (180 < a)
			a =360-a;
		if (!strcmp("min", str))
			a =a/ 60.0;
		a = (a*pi) / 180.0;
		printf("%0.6lf %0.6lf\n", a*s, s * 2 * sin(a / 2.0));
	}
	return 0;
}



//pi->   #define pi 2*acos(0.0)
//http://www004.upp.so-net.ne.jp/s_honma/circle/huygens.htm
//chord->2r*sin(θ/2)      arc->r*θ   'min'->minutes convert to second(s)->a/60
//http://www.peko-step.com/tool/tfrad.html
//angle=radian*180/pi   ->radian=angle*pi/180



The radius of earth is 6440 Kilometer. There are many Satellites
and Asteroids moving around the earth. If two Satellites
create an angle with the center of earth, can you find out
the distance between them? By distance we mean both the
arc and chord distances. Both satellites are on the same orbit
(However, please consider that they are revolving on a circular
path rather than an elliptical path).



Input
The input file will contain one or more test cases.
Each test case consists of one line containing two-integer
s and a, and a string ‘min’ or ‘deg’. Here s is the distance of
the satellite from the surface of the earth and a is the angle
that the satellites make with the center of earth. It may be in 
minutes (′) or in degrees (◦). Remember that the same line will 
never contain minute and degree at a time.

Output
For each test case, print one line containing the required 
distances i.e. both arc distance and chord distance respectively 
between two satellites in Kilometer. The distance will be a 
floating-point value with six digits after decimal point.



Sample Input
500 30 deg
700 60 min
200 45 deg

Sample Output
3633.775503 3592.408346
124.616509 124.614927
5215.043805 5082.035982