UVa 10323: Factorial! You must be kidding!!!
https://saicheems.wordpress.com/2014/05/06/uva-10323-factorial-you-must-be-kidding/



#include<stdio.h>
int main() {
	int n,lower,upper;
	long long a[20],f = 1;
	for (n = 1; f < 6227020800; n++) {
		f *= n;
		a[n] = f;
		if (f < 10000)
			lower = n;
	}
	upper = n;

	while (~scanf("%d", &n)) {
		if (n < 0)
			if (n & 1)puts("Overflow!");
			else puts("Underflow!");
		else
			if (n <= lower)puts("Underflow!");
			else if ( n>= upper)puts("Overflow!");
			else printf("%lld\n", a[n]);
	}
	return 0;
}


//test unsigned integer 
#include <iostream>
#include <string>
using namespace std;
int main()
{
	unsigned f=1;
	for (unsigned n = 1; n < 10; n++) {
		f *= n*-1;
		cout << f <<endl;
	}
	
	return  0;
}



Arif has bought a super computer from Bongobazar. Bongobazar is a 
place in Dhaka where second hand goods are found in plenty. 
So the super computer bought by him is also second hand and has
some bugs. One of the bugs is that the range of ***unsigned long 
integer of this computer for C/C++ compiler has changed. 
Now its new lower limit is 10000 and upper limit is 6227020800. 
Arif writes a program in C/C++ which determines the factorial of an 
integer. Factorial of an integer is de ned recursively as:

f actorial
(0)  =  1
f actorial
(
n
)  =
n

f actorial
(
n




Input
The input  le contains several lines of input. 
Each line contains a single integer
n
. No integer has more
than six digits. Input is terminated by end of  le.
Output
For each line of input you should output a single line. 
This line will contain a single integer
n
! if the
value of
n
!  ts within the unsigned long integer of Arif's computer. 
Otherwise the line will contain one
of the following two words
Overflow!
(When
n
!
>
6227020800)
Underflow!
(When
n
!
<
10000)



SampleInput
2
10
100

SampleOutput
Underflow!
3628800
Overflow!