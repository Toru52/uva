uva 10090 - Marbles
http://xwk.iteye.com/blog/2130836

explain about 
"Extended Euclidean algorithm"
http://tubo28.me/algorithm/extgcd/
http://www.tbasic.org/reference/old/ExEuclid.html
https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
P937



#include <cstdio>
#include <cmath>
typedef long long ll;

// d->gcd  tool_gcd->a,b    
void gcd(ll a, ll b, ll& d, ll& x, ll& y) {
	if (!b) {
		d = a;
		x = 1;
		y = 0;
		//start from xi=1,yi=0;
	}
	else {
		gcd(b, a%b, d, y, x);
		y -= (a / b)*x;
	}
	//	printf("a %lld b %lld d %lld x %lld y %lld \n",a,b, d, x, y);

}

int main() {
	ll n, c1, t1, c2, t2;
	while (scanf("%lld", &n) == 1 && n) {
		scanf("%lld%lld%lld%lld", &c1, &t1, &c2, &t2);
		ll d, xi, yi, x, y;
		gcd(t1, t2, d, xi, yi);
		ll lower = ceil(-1.0 * n * xi / t2);
		ll up = floor(1.0 * n * yi / t1);
//printf("\nd %lld xi %lld yi %lld lower %lld up %lld\n", d, xi, yi, lower, up);

		if (lower > up || n % d) {
			printf("failed\n");
			continue;
		}

		if (c1 * t2 > c2 * t1) {
			x = xi * n / d + t2 / d * lower;
			y = yi * n / d - t1 / d * lower;
		}
		else {
			x = xi * n / d + t2 / d * up;
			y = yi * n / d - t1 / d * up;
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
}



#include<cstdio>
#include<cmath>
typedef long long ll;
void gcd(ll a, ll b, ll &d,ll &x,ll &y) {
	if (!b) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		gcd(b, a%b, d, y, x);
		y -= (a / b)*x;
	}
}

int main() {
	ll n,n1,n2,c1,c2,d,xi,yi,lower,up,x,y;
	while (scanf("%lld", &n) == 1 && n) {
		scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);
		gcd(n1, n2, d, xi, yi);
		lower = ceil(-1.0 * n*xi / n2);
		up = floor(1.0*n*yi / n1);

		if (lower > up || n%d) {
			printf("failed\n");
			continue;
		}
		if (c1*n2 > c2*n1) {
			x = xi*n / d + n2 / d*lower;
			y = yi*n / d - n1 / d*lower;
		}
		else{
			x = xi*n / d + n2 / d*up;
			y = yi*n / d - n1 / d*up;
		}
		printf("%lld %lld\n", x, y);
	}
	return 0;
}




I have some (say, n) marbles (small glass balls) and I am going 
to buy some boxes to store them. The boxes are of two types:
T ype 1: each box costs c1 Taka and can hold exactly n1 marbles
T ype 2: each box costs c2 Taka and can hold exactly n2 marbles
I want each of the used boxes to be filled to its capacity and 
also to minimize the total cost of buying them. Since I find it 
difficult for me to figure out how to distribute my marbles among 
the boxes, I seek your help. I want your program to be efficient 
also.



Input
The input file may contain multiple test cases. Each test case 
begins with a line containing the integer 
n (1 ≤ n ≤ 2, 000, 000, 000). 
The second line contains c1 and n1,and the third line contains c2 
and n2. Here, c1, c2, n1 and n2 are all positive integers having 
values smaller than 2,000,000,000. A test case containing a zero 
for n in the first line terminates the input.

Output
For each test case in the input print a line containing the 
minimum cost solution (two nonnegative integers m1 and m2, 
where mi = number of T ypei boxes required) if one exists, 
print ‘failed’ otherwise.
If a solution exists, you may assume that it is unique.



Sample Input
43
1 3
2 4
40
5 9
5 12
0

Sample Output
13 1
failed