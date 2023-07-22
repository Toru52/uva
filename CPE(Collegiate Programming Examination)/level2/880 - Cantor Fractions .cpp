880 - Cantor Fractions 



#include <stdio.h>
#include <math.h>
int main() {
    long long n;
    while(scanf("%lld", &n) == 1) {
		//n->The number of dot
        long long i = sqrt(2*n)-1, sum = i*(i+1)/2;
		// i = sqrt(2*n)-1 ->difference sequence
		// http://sanzyutsuman.xsrv.jp/Pages/kouza73.html
        for(i++; ; i++) {
            if(sum+i >= n) {
                printf("%lld/%lld\n", i-n+sum+1, n-sum);
                break;
            }
            sum += i;
        }
    }
    return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	long long n;
	while (~scanf("%lld", &n)) {
		long long i = sqrt(n * 2) - 1, sum = i*(i + 1)/2;
		for (i++;; i++) {
			if (sum + i >= n) {
				printf("%lld/%lld\n", i - n + sum + 1, n - sum);
				break;
			}
			sum+=i;
		}
	}
}



In the late XIXth century the German mathematician George
Cantor argued that the set of positive fractions Q+ is 
equipotent to the set of positive integers N, meaning 
that they are both infinite, but of the same class. 
To justify this, he exhibited a mapping from N to Q+ that 
is onto. This mapping is just traversal of the N × N 
plane that covers all the pairs: 
The first fractions in the Cantor mapping are:
1
1
,
2
1
,
1
2
,
3
1
,
2
2
,
1
3
, . . .
Write a program that finds the i-th Cantor fraction 
following the mapping outlined above.



Input
The inputs consists of several lines with a positive 
integer number i each one.

Output
The output consists of a line per input case, that 
contains the i-th fraction, with numerator and
denominator separed by a slash ‘/’. The fraction should 
not be in the most simple form.



Sample Input
6

Sample Output
1/3