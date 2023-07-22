10110 - Light, more light
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/10110%20-%20Light%2C%20more%20light.cpp



#include<cstdio>
#include<cmath>

int main() {
	unsigned int n, x;

	while (scanf("%u", &n),n) {
		x = sqrt(n);

		if (n == x*x) 
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
int main() {
	unsigned int n, i;
	while (scanf("%ud", &n), n) {
		i = sqrt(n);
		(i*i == n) ? puts("yes") : puts("no");
	}
	return 0;
}

/*
ex 4
off,off,off,off
i=2 4times can walk 2th

on,on,off,off
on,on,on,on
on,off,off,on
off,off,off,on
->yes

9
i=3 9times can walk 3th
of,of,of,of,of,of,of,of,of
on,on,on,of,of,of,of,of,of
on,on,on,on,on,on,of,of,of

on,on,on,on,on,on,on,on,on
on,on,on,on,on,of,of,of,on
on,on,of,of,of,of,of,of,on

of,of,of,of,of,of,of,of,on
on,on,on,of,of,of,of,of,on
on,on,on,on,on,on,of,of,on
->yes
*/

There is man named "mabu" for switching on-off light in our 
University. He switches on-off the lights in a corridor. 
Every bulb has its own toggle switch. That is, 
if it is pressed then the bulb turns on.
Another press will turn it off. To save power consumption 
(or may be he is mad or something else)
he does a peculiar thing. If in a corridor there is n bulbs, 
he walks along the corridor back and forth n times and in i-th walk 
he toggles only the switches whose serial is divisable by i. 
He does not press any switch when coming back to his initial position.
 A i-th walk is dened as going down the corridor
(while doing the peculiar thing) and coming back again. 
Now you have to determine what is the nal
condition of the last bulb. Is it on or off?



Input
The input will be an integer indicating the n'th bulb in a corridor.
 Which is less then or equals 232 􀀀1.
A zero indicates the end of input. You should not process this 
input.

Output
Output `yes' if the light is on otherwise `no', in a single line.



Sample Input
3
6241
8191
0

Sample Output
no
yes
no