10994 - Simple Addition
http://webcache.googleusercontent.com/search?q=cache:vMJNt0ILYTUJ:knightzone.org/%3Fp%3D1591+&cd=3&hl=en&ct=clnk&gl=tw

The sum of arithmetical progression
http://mathtrain.jp/sequencesum



#include<cstdio>

int main() {
	long long p, q;

	while (scanf("%lld%lld", &p, &q) && !(p < 0 && q < 0)) {
		long long sum = 0;
		while (p || q) {
			sum += (q % 10 + p % 10)*((q % 10) - (p % 10) + 1) / 2;
			//calculate digit 1
			//The sum of arithmetical progression
			//(1/2*n*(a+l)) ex p=5 q=9 -> (5*(5+9))/2=35
			printf("be p %lld q %lld sum %lld\n", p, q, sum);
			sum += (q / 10 - p / 10) * 45; //calculate digit 2
            //45=1+2+3+4+5+6+7+8+9
			if (p % 10 && (p / 10 || q / 10))
				p += 10;//(p=1 q=10 q-p=9)  !=  (p=11 q=20 q-p=9)
			p /= 10; q /= 10; //calculate next time when digit 2 or more number
			printf("af p %lld q %lld sum %lld\n", p, q, sum);
		}
		printf("%lld\n", sum);
	}
	return 0;
}



#include<stdio.h>
int main() {
	long long p, q, sum;
	while (scanf("%lld%lld", &p, &q) && !(p < 0 && q < 0)) {
		sum = 0;
		while (p || q) {
			sum += (p % 10 + q % 10)*(q % 10 - p % 10 + 1) / 2;
			sum += (q / 10 - p / 10) * 45;
			if (p % 10 && (p / 10 || q / 10))
				p += 10;
			p /= 10, q /= 10;
		}
		printf("%lld\n", sum);
	}
	return 0;
}



Lets dene a simple recursive function F(n), where
F(n) = p(x) =
8<
:
n%10; if (n%10) > 0
0; if n = 0
F(n=10); Otherwise
Lets dene another function S(p; q),
S(p; q) =
Σq
i=p
F(i)
In this problem you have to Calculate S(p; q) on given value of p and q.



Input
The input le contains several lines of inputs. 
Each line contains two non
negative integers p and q(p  q) separated by a single space. 
p and q will t in 32 bit signed integer. In put is terminated by a
line which contains two negative integers. 
This line should not be processed.

Output
For each set of input print a single line of the value of S(p; q).



Sample Input
1 10
10 20
30 40
-1 -1

Sample Output
46
48
52