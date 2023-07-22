11384 - Help is needed for Dexter
http://naivered.github.io/2016/06/04/Problem_Solving/UVa/UVa-11384-Help-is-needed-for-Dexter/



#include<stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int ans = 0;
		for (int i = 1; i <= n; i <<= 1, ans++);
		printf("%d\n", ans);
	}
	return 0;
}



/*
concept
subtract=2 n=3
123
013
002
0
or
123
121
110
0

subtract=3 n=4
1234
0034
0004
0001
0
subtract=2 n=4
1234
0134
0024
0004
0002
0000

subtract=3 n=5
12345
00345
00045
00015
00003
0

subtract=3 n=6 L=3
123456
003456
000456
000156
000036
000006
000003
0

subtract=L ?

solutions made of sequence(bit number)
ex
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16
1,2,2,3,3,3,3,4,4,4, 4, 4, 4 ,4, 4, 5
*/


Dexter is tired of Dee Dee. So he decided to keep Dee Dee busy 
in a game. The game he planned for her is quite easy to play 
but not easy to win at least not for Dee Dee. 
But Dexter does not have time
to spend on this silly task, so he wants your help.
There will be a button, when it will be pushed a random number 
N will be chosen by computer.
Then on screen there will be numbers from 1 to N. 
Dee Dee can choose any number of numbers from
the numbers on the screen, and then she will command computer 
to subtract a positive number chosen by her 
(not necessarily on screen) from the selected numbers. 
Her objective will be to make all the numbers 0.
For example if N = 3, then on screen there will be 3 numbers 
on screen: 1, 2, 3. Say she now selects 1 and 2. 
Commands to subtract 1, then the numbers on the screen will 
be: 0, 1, 3. Then she selects 1 and 3 and commands to subtract 
1. Now the numbers are 0, 0, 2. Now she subtracts 2 from 2 
and all the numbers become 0.
Dexter is not so dumb to understand that this can be done very 
easily, so to make a twist he will give a limit L for each N 
and surely L will be as minimum as possible so that it is 
still possible to win within L moves. But Dexter does not 
have time to think how to determine L for each N, so he asks
you to write a code which will take N as input and give L as 
output.



Input
Input consists of several lines each with N such that 1 
 N  1; 000; 000; 000. Input will be terminated
by end of le.

Output
For each N output L in separate lines.



Sample Input
1
2
3

Sample Output
1
2
2