846 - Steps 



#include <stdio.h>
#include <math.h>
int main() {
	int t, x, y, L;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &x, &y);
		L = y - x;
		int steps = 0, n = (int)sqrt(L);
		steps = n;
		L -= n*(n + 1) / 2;
		while (L > 0) {
			while (n*(n + 1) / 2 > L)
				n--;
			if (n*(n + 1) / 2 == L)
				L = 0, steps += n;
			else
				L -= n, steps++;
		}
		printf("%d\n", steps);
	}
	return 0;
}



#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int cas,x,y;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &x, &y);
		int L = y - x;
		int side = (int)sqrt(L);
		int steps = side;
		L -= (side*(side + 1) / 2);
		while (L) {
			while ((side*(side + 1) / 2) > L)
				side--;
			if ((side*(side + 1) / 2) == L)
				L = 0, steps += side;
			else
				L -= side, steps++;
		}
		printf("%d\n", steps);
	}
}


ex 1 10
root(10-1)->3
Thefore you understand we need to 3 steps to climb to top,
so steps=n;(from start to top of mountain)

last step (from top to end (9- (1+2+3)=3))



One steps through integer points of the straight line. 
The length of a step must be nonnegative and can be by 
one bigger than, equal to, or by one smaller than the 
length of the previous step. What is the minimum number 
of steps in order to get from x to y? The length of the 
first and the last step must be 1.

Input and Output
Input consists of a line containing n, the number of test 
cases. For each test case, a line follows with
two integers: 0 ≤ x ≤ y < 2
31. For each test case, print a line giving the minimum 
number of steps to get from x to y.



Sample Input
3
45 48
45 49
45 50

Sample Output
3
3
4