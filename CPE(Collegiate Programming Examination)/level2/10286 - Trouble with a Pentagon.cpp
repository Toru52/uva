10286 - Trouble with a Pentagon
explain concept
http://www.it610.com/article/1907571.htm
cc.chu.edu.tw
http://blog.csdn.net/mobius_strip/article/details/39931435

http://slideshowjp.com/doc/125752/%E6%AD%A3%E4%BA%94%E8%A7%92%E5%BD%A2%E3%81%AB%E5%86%85%E6%8E%A5%E3%81%99%E3%82%8B%E6%AD%A3%E6%96%B9%E5%BD%A2---tcp-ip



#include<iostream>
#include<cmath>
#define PI acos(-1)

using namespace std;

int main() {
	double l, x, conv = sin(72 * PI / 180) / sin(63 * PI / 180);
	while (cin >> l) {
		x = conv*l;
		printf("%.10f\n", x);
	}
}



#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  

using namespace std;

int main()
{
	double A = acos(-1.0) / 2.5, B = acos(-1.0) / 5.0;
	double p = 2.0*sin(B)*cos(B)*cos(A) - 2.0*cos(B)*cos(B)*sin(A);
	double q = sin(B) - cos(B) + 2.0*cos(B)*cos(A) - 2.0*cos(B)*sin(A);
	double n;

	while (~scanf("%lf", &n))
		printf("%.10lf\n", n*sqrt(2.0)*p / q);

	return 0;
}

