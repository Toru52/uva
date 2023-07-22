10174 - Couple-Bachelor-Spinster Numbers.cpp
https://gist.github.com/mob5566/169f30a7a2338f9fde25



#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

// definitions
#define FOR(i,a,b) for( int i=(a),_n=(b); i<=_n; ++i )
#define clr(x,v) memset( x, v, sizeof(x) )

typedef long long ll;

// declarations
char buf[1000];

// functions


// main function
int main(void)
{
	ll a, b;
	ll x, y;
	int cnt;

	// input
	while (fgets(buf,sizeof(buf),stdin)) {

		if (sscanf(buf, "%lld%lld", &a, &b) == 2) {
			/*
			If there are two numbers n1 and n2 in the input 
			then print ***how many bachelor numbers ***
			are in the interval [n1, n2].
			 Note that 0 ≤ n1 ≤ n2 and (n2−n1) */
			if ((a & 1LL)) ++a;

			cnt = 0;
			for (ll i = a; i <= b; i += 2) {
				if ((i % 4LL)) ++cnt;   
				//The LL makes the integer literal of 
				//type long long.
			}

			printf("%d\n", cnt);
		}
		else {
			if ((a & 1LL) || (a % 4LL) == 0) {
				b = a;
				if (a < 0LL) a = -a;

				if ((a & 1LL)) x = (a + 1LL) / 2LL, y = (a - 1LL) / 2LL;
				else x = (a / 4LL) + 1LL, y = (a / 4LL) - 1LL;

				if (b < 0LL) swap(x, y);
				printf("%lld %lld\n", x, y);
			}
			else puts("Bachelor Number.");
		}
	}

	return 0;
}



#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

int main() {
	ll a, b, x, y;
	char buf[1000];
	while (fgets(buf, sizeof(buf), stdin)) {
		if (sscanf(buf, "%lld%lld", &a, &b) == 2) {
			if (a & 1)
				a++;
			int cnt = 0;
			for (ll i = a; i <= b; i += 2)
				if (i % 4)
					cnt++;
			printf("%d\n", cnt);
		}
		else {
			if ((a & 1) || (a % 4) == 0) {
				b = a;
				if (a < 0)
					a = -a;
				if (a & 1)
					x = (a + 1) / 2, y = (a - 1) / 2;
				else
					x = (a / 4) + 1, y = (a / 4) - 1;
				if (b < 0)
					swap(x,y);
				printf("%lld %lld\n", x, y);
			}
			else
				puts("Bachelor Number.");
		}
	}
	return 0;
}



Can any number be expressed as a subtraction of two squares? 
The numbers, which can be expressed in such a way, 
are called square-couple numbers. Your job is to find out
a) If a number is square couple number.
b) If the number is square couple then find that format.
c) Find out how many square couple numbers are there within a 
   certain range (including the terminal numbers). 
   
   
   
Input
Each set of input is given in a single line. 
Each input set may contain one or two signed 32 bit integer
numbers. Input is terminated by end of file.

Output
If there is only a single number N on a single line then print 
two non-negative integer numbers a and b, such that a
2 − b
2 = N. 
If the number cannot be expressed in such a format then print 
the line ‘Bachelor Number.’ on a single line if it is even or 
else print ’Spinster Number.’ on a single line if it
is odd. Note that −2
31 ≤ N < 2
31
.
If there are two numbers n1 and n2 in the input then print 
how many bachelor numbers are in the
interval [n1, n2]. 
Note that 0 ≤ n1 ≤ n2 and (n2−n1) ≤ 1, 000, 000.



ex
12
a^2-b^2
4^2-2^2=12


Sample Input
6
12
3

Sample Output
Bachelor Number.
4 2
2 1
