11677 - Alarm Clock
https://github.com/Diusrex/UVA-Solutions/blob/master/11677%20Alarm%20Clock.cpp
https://sites.google.com/site/pcshic/solutions/100-1-zi-xun-she-qi-mo-kao-can-kao-jie-da


#include <cstdio>
using namespace std;
const int FULL_DAY = 60 * 24;

int main()
{
	int h1, m1, h2, m2;
	while (scanf("%d%d%d%d", &h1, &m1, &h2, &m2), h1 + m1 + h2 + m2)
	{
		int t1 = h1 * 60 + m1;
		int t2 = h2 * 60 + m2;

		if (t1 > t2)
			t2 += FULL_DAY;
		printf("%d\n", t2 - t1);
	}
}



#include <iostream>
using namespace std;
int main () {
    int h1, m1, h2, m2;
    while (cin >> h1 >> m1 >> h2 >> m2, h1 + m1 + h2 + m2) {
        cout << ((h2*60 + m2) - (h1*60 + m1) + 1440) % 1440 << endl;
    }
}



#include<iostream>
using namespace std;
int main() {
	int h1, m1, h2, m2;
	while (cin >> h1 >> m1 >> h2 >> m2, h1 + m1 + h2 + m2)
		cout << ((h2 * 60 + m2) - (h1 * 60 + m1) + (60 * 24)) % (24 * 60) << endl;
}

Daniela is a nurse in a large hospital, which causes her 
working shifts to constantly change.  
To make it worse, she has deep sleep, 
and a difficult time to wake up using alarm clocks.
Recently she got a digital clock as a gift, with several 
different options of alarm sounds, 
and she has hope that it might help solve her problem.  
But, lately, she's been very tired and want to enjoy every 
single moment of rest.  So she carries her new clock to 
every place she goes, and whenever she has some spare time, 
she tries to sleep, setting her alarm clock to the time 
when she needs to wake up.
But, with so much anxiety to sleep, she ends up with some 
difficulty to fall asleep and enjoy some rest.
A problem that has been tormenting her is to know 
how many minutes of sleep she would have if
she felt asleep immediately and woken up when the alarm 
clock ringed.  
But she is not very good with numbers, 
and asked you for help to write a program that, 
given the current time and the alarm time,
nd out the number of minutes she could sleep.



Input
The input contains several test cases. 
Each test case is described in one line, 
containing four integers

H1,M1,H2 and M2, with H1:M1 representing the current hour 
and minute, and H2:M2 representing the time (hour and minute)
when the alarm clock is set to ring 
The end of the input is indicated by a line containing 
only four zeros, separated by blank spaces.

Output
For each test case, your program must print one line, 
containing a single integer, indicating the number
of minutes Daniela has to sleep.



SampleInput
1 5 3 5
23 59 0 34
21 33 21 10
0 0 0 0

SampleOutput
120
35
1417