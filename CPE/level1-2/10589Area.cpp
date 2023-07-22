10589	Area



no1
#include <cstdio>

int main() {
	int N, A;
	double x, y;

	while (true) {
		scanf("%d %d", &N, &A);
		if (N == 0) 
			break;

		int cont = 0, R2 = A*A;

		for (int i = 0; i<N; ++i) {
			scanf("%lf %lf", &x, &y);
			bool valid = true;

			if ((x - 0)*(x - 0) + (y - 0)*(y - 0)>R2) 
				valid = false;
			if ((x - 0)*(x - 0) + (y - A)*(y - A)>R2) 
				valid = false;
			if ((x - A)*(x - A) + (y - 0)*(y - 0)>R2) 
				valid = false;
			if ((x - A)*(x - A) + (y - A)*(y - A)>R2) 
				valid = false;
			if (valid) 
				++cont;
		}
		printf("%.5f\n", (double)cont*(A*A) / N);
	}
	return 0;
}



no2
#include<stdio.h>

int main()
{
	int a,N;
	while (scanf("%d %d", &N, &a)&&N)
	{
		double x, y;
		int M = 0,R=a*a;
		
		for (int i = 0; i < N; i++)
		{
			scanf("%lf %lf", &x, &y);
			bool stripe = true;

			if ((x*x) + (y*y) > R)
				stripe = false;
			if (((x - a)*(x - a)) + (y*y) > R)
				stripe = false;
			if ((x*x) + ((y - a)*(y - a)) > R)
				stripe = false;
			if (((x - a)*(x - a)) + ((y - a)*(y - a)) > R)
				stripe = false;
			if (stripe)
				M++;
		}
			printf("%.5f\n", (double)M*a*a / N);
	}
}



Algorithm
http://www.geisya.or.jp/~mwm48961/kou3/circle1.htm
x^2+y^2=r^2           P(x,y)->P(0,0)
(x−a)^2+(y−b)^2=r^2   P(x,y)->P(a,b)



Measuring the area of a certain
shape is an important part of certain
geometric problems. When
the shape becomes complex it often
becomes very difficult to measure
the area of that geometric shape.
In some of these cases some randomized
algorithms helps us immensely
to find the area roughly.
In this problem we will find such an
area with randomized algorithm.
Look at the picture on the right.
ABCD is a square whose sides are
a. A circle is drawn (1/4 th of a
circle I should say) considering A
as its center. Its radius is a. Three
similar circles are drawn considering
B, C, D as centers. Using an
algorithm based on random numbers
(The random number generator may be biased) you will have to 
find the area of the striped region.
The idea is that you will be given N pairs of random 
coordinates within the rectangle. If M of them are within 
the striped region then the approximate area of the striped 
region A = M ∗ a ∗ a/N. You are to find the approximate 
area using this concept.



Input
The input file contains several sets of inputs. The 
description of each set is given below. The first line of 
each set contains two integers N (N can always be written 
in the form 10k where k is a non-negative integer less than 
6), a (100 > a ≥ 10). Each of the next N lines contains two 
floatingpoint numbers, which indicates the coordinate of a 
point. These floating-point numbers always have seven digits 
after the decimal point and the coordinates are always
within the rectangle. Points just on the boundaries of the 
striped region are considered within the striped region. 
Points just outside are considered out of the striped region 
and vice versa. Assume that the lower left corner of the 
rectangle is (0, 0) and top right corner is (a, a) as shown 
in the figure above. Input is terminated by a set 
whose N is zero.



Output
For each of input you should produce one line of output. 
This line should contain the area of the striped
region according to the formula specified above. 
Your answer must be exact and no floating-point errors
will be tolerated. That means precision of calculation must 
be infinite or precision error must be zero. Output numbers 
should always have five digits after the decimal point



Sample Input
1 10
5.0000000 5.0000000
0 0

Sample Output
100.00000