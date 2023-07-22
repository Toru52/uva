10550 - Combination Lock



no1
#include<cstdio>

int main() {
	int num[4], angle;
	while (scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3]) != EOF) {
		if (!num[0] && !num[1] && !num[2] && !num[3])
			break;
		angle = 1080;
		angle += ((num[0] - num[1]) + 40) % 40 * 9;
		angle += ((num[2] - num[1]) + 40) % 40 * 9;
		angle += ((num[2] - num[3]) + 40) % 40 * 9;
		printf("%d\n", angle);
	}
}



no2
#include<cstdio>
int main()
{
	int p, f, s, t;
	while (scanf("%d %d %d %d", &p, &f, &s, &t) && p || f || s || t)
	{
		int a = 1080;
		a += (p - f + 40) % 40 * 9;
		a += (s-f + 40) % 40 * 9;
		a += (s - t + 40) % 40 * 9;
		printf("%d\n", a);
	}
}



Now that you’re back to school for another term, you need to
remember how to work the combination lock on your locker.
A common design is that of the Master Brand, shown at right.
The lock has a dial with 40 calibration marks numbered 0 to
39. A combination consists of 3 of these numbers; 
for example:15-25-8. To open the lock, 
the following steps are taken:
• turn the dial clockwise 2 full turns
• stop at the first number of the combination
• turn the dial counter-clockwise 1 full turn
• continue turning counter-clockwise until the 2nd number
is reached
• turn the dial clockwise again until the 3rd number is
reached
• pull the shank and the lock will open.
Given the initial position of the dial and the combination 
for the lock, how many degrees is the dial rotated in total 
(clockwise plus counter-clockwise) in opening the lock?



Input
Input consists of several test cases. For each case there 
is a line of input containing 4 numbers between
0 and 39. The first number is the position of the dial.
The next three numbers are the combination.
Consecutive numbers in the combination will be distinct. 
A line containing ‘0 0 0 0’ follows the last case.

Output
For each case, print a line with a single integer: the 
number of degrees that the dial must be turned to
open the lock



Sample Input
0 30 0 30
5 35 5 35
0 20 0 20
7 27 7 27
0 10 0 10
9 19 9 19
0 0 0 0

Sample Output
1350
1350
1620
1620
1890
1890