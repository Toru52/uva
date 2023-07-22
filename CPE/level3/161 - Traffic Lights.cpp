161 - Traffic Lights 
https://github.com/morris821028/UVa/blob/master/volume001/161%20-%20Traffic%20Lights.cpp



#include <cstdio>
int main() {
	while (1) {
		int A[105]{}, n = 0, time[105] {};
		//the cycle time of a single signal
		//Cycle times will not be less than 10 seconds,
        //nor more than 90 seconds.
		while (scanf("%d", &A[n]),A[n]) 
			n++;
		if (A[0] == 0)
			break;
		int s = 18001;
		//Time is measured from the instant->select shortest time in a event
		for (int i = 0; i < n; i++) 
			if (A[i] < s)
				s = A[i];
		for (; s <= 18000; s++) {
			int yes = 1;
			for (int i = 0; i < n; i++) {
				//s=cycle time(except initial time)
				//time[i] + A[i] - 5 =cycle time + green(A[i]) time
				//time[i] + A[i] - 5 <= s  ->  red or oreange
				//time[i] + A[i] - 5 > s   ->  green
				while (time[i] + A[i] - 5 <= s) 
					time[i] += 2 * A[i];
				if (!(time[i] <= s && s < time[i] + A[i] - 5)) {
					s = time[i] - 1;
					yes = 0;
					break;
				}
			}
			if (yes)
				break;
		}
		if (s > 18000)
			puts("Signals fail to synchronise in 5 hours");
		else
			printf("%02d:%02d:%02d\n", s / 3600, s % 3600 / 60, s % 60);
	}
	return 0;
}




#include<stdio.h>
int main() {
	while (1) {
		int n = 0, s = 18001, A[105], time[105]{};
		while (scanf("%d", &A[n]), A[n])
			n++;
		if (A[0] == 0)
			break;
		for (int i = 0; i < n; i++)
			if (A[i] < s)
				s = A[i];
		for (; s <= 18000; s++) {
			int flag = 1;
			for (int i = 0; i < n; i++) {
				while (time[i] + A[i] - 5 <= s)
					time[i] += A[i] * 2;
				if (time[i] > s || time[i] + A[i] - 5 <= s) {
					s = time[i] - 1;
					flag = 0;
					break;
				}
			}
			if (flag)break;
		}
		if (s > 18000)puts("Signals fail to synchronise in 5 hours");
		else printf("%02d:%02d:%02d\n", s / 3600, s%3600 /60, s % 60);
	}
	return 0;
}



/*
concept
g->o->r (cycle)
-
#take notice
initial portion while they are all still green is excluded from the reckoning.


ex 25 35 0 ->150
signal(25)
g(0-20) 0(20-25) r(25-50) g(50-70) o(70-75) r(75-100) g(100-120) o(120-125) r(125-150) g(150-)
signal(35)
g(0-30)      0(30-35)     r(35-70) g(70-100)       o(100-105)      r(105-140)      g(140-)

->170(cicle time(single(35))(140) +green time(30) )   >   150(cicle time(single(25)))
->150 is green simultaneously at signal(25) and signal(35)
*/



One way of achieving a smooth and economical drive to work is to ‘catch’ 
every traffic light, that is have every signal change to green as you 
approach it. One day you notice as you come over the brow of a hill that 
every traffic light you can see has just changed to green and that 
therefore your chances of catching every signal is slight. 
As you wait at a red light you begin to wonder how long it will be before
all the lights again show green, not necessarily all turn green, 
merely all show green simultaneously, even if it is only for a second.
Write a program that will determine whether this event occurs within a 
reasonable time. Time is measured from the instant when they all turned 
green simultaneously, although the initial portion while they are all 
still green is excluded from the reckoning.



Input
Input will consist of a series of scenarios. Data for each scenario will 
consist of a series of integers representing the cycle times of the 
traffic lights, possibly spread over many lines, with no line being
longer than 100 characters. Each number represents the cycle time of a 
single signal. The cycle time is the time that traffic may move in one 
direction; note that the last 5 seconds of a green cycle is actually orange.
Thus the number 25 means a signal that (for a particular direction) will 
spend 20 seconds green,5 seconds orange and 25 seconds red. 
Cycle times will not be less than 10 seconds, nor more than 90 seconds. 
There will always be at least two signals in a scenario and never more than 
100. Each scenario will be terminated by a zero (0).
The file will be terminated by a line consisting of three zeroes (0 0 0).

Output
Output will consist of a series of lines, one for each scenario in the 
input. Each line will consist of the time in hours, 
minutes and seconds that it takes for all the signals to show green again 
after at least one of them changes to orange. 
Follow the format shown in the examples. 
Time is measured from the instant they all turn green simultaneously. 
If it takes more than five hours before they all show green
simultaneously, the message ‘Signals fail to synchronise in 5 hours’ 
should be written instead.



Sample Input
19 20 0
30
25 35 0
0 0 0

Sample Output
00:00:40
00:05:00