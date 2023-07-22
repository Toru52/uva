834 - Continued Fractions



#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b)) { // 43,19
		printf("[%d;", a / b);    // [2;
		a %= b;                // 5,19
		while (a != 1) {
			printf("%d,", b / a); // [2;3, / [2;3,1,
			b %= a;            // 5,4 / 4,1
			swap(a, b);        // 4,5 / 1,4
		}
		printf("%d]\n", b);     // [2;3,4,1]
	}
	return 0;
}



#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	while (~scanf("%d %d", &a, &b)) {
		printf("[%d;",a / b);
		a %= b;

		while (a != 1) {
			printf("%d,", b / a);
			b %= a;
			swap(a, b);
		}
		printf("%d]\n", b);
	}
}



Let b0, b1, b2, . . . , bn be integers with bk > 0 for 
k > 0. The continued fraction of order n with coeficients
b1, b2, . . . , bn and the initial term b0 is defined by 
the following expression
b0 +
1
b1 +
1
b
2+...+ 1
bn
which can be abbreviated as [b0; b1, . . . , bn].
An example of a continued fraction of order n = 3 is 
[2; 3, 1, 4]. This is equivalent to
1 +
1
3 + 1
1+ 1
4
=
43
19
Write a program that determines the expansion of a given 
rational number as a continued fraction.
To ensure uniqueness, make bn > 1.



Input
The input consists of an undetermined number of rational 
numbers. Each rational number is defined
by two integers, numerator and denominator.

Output
For each rational number given in the input, you should 
output the corresponding continued fraction.



Sample Input
43 19
1 2

Sample Output
[2;3,1,4]
[0;2]



