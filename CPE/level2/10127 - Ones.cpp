10127 - Ones
https://sites.google.com/site/pcshic/solutions/2014-zi-xun-neng-li-jing-sai-can-kao-jie-da
http://knightzone.org/?p=1718


#include <iostream>
using namespace std;

int main () {
    int n, m, c;
    while (cin >> n) {
        m = 1;   //since smallest number is 1,you can set 1 initially.
        for (c=1; m%n; c++)   //stop when m%n=0 //c(ount)--計算幾位數
            m = (m * 10 + 1) % n;               //m(ultiple)--倍數
        cout << c << endl;
    }
}


/*
*test code
#include<iostream>
using namespace std;
int main() {
	long long  n=7,sum = 0,ones=1;
	for (long long i = 1; i <= n; i++) {
		sum += ones;
		ones *= 10;
		cout << sum << " " << sum%n << endl;
	}
}
base
x-1 sigma i=0 (10^i)

11=41                   11/7=1,,,4
111=61                 111/7=75,,,6
1111=51                
11111=21
111111=1
*/



#include<iostream>
using namespace std;
int main() {
	int n, c=1;
	while (cin >> n) {
		int c = 1;
		for (int m = 1; m%n; c++)
			m = (m * 10 + 1) % n;
		cout << c << endl;
	}
	return 0;
}

Given any integer 0 ≤ n ≤ 10000 not divisible
by *2* or *5*, some multiple of n is a number which
in decimal notation is a sequence of 1’s. How
many digits are in the smallest such a multiple
of n?



Input
A file of integers at one integer per line.

Output
Each output line gives the smallest integer x > 0
such that p =
∑x−1
i=0 1×10i = a×b,
***1+10+,,,ix
 where a is the
corresponding input integer, and b is an integer
greater than zero.



Sample Input
3
7
9901

Sample Output
3
6
12