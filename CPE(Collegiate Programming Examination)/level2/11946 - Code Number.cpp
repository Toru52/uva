11946 - Code Number
https://lintacse.wordpress.com/2013/01/16/uva-11946-code-numbe/



#include<stdio.h>
int main()
{
	int nCase;
	char c;
	scanf("%d\n", &nCase);
	while (~(c = getchar()))
	{
		if (c == '1')
			printf("I");
		else if (c == '2')
			printf("Z");
		else if (c == '3')
			printf("E");
		else if (c == '4')
			printf("A");
		else if (c == '5')
			printf("S");
		else if (c == '6')
			printf("G");
		else if (c == '7')
			printf("T");
		else if (c == '8')
			printf("B");
		else if (c == '9')
			printf("P");
		else if (c == '0')
			printf("O");
		else
			printf("%c", c);
	}
	return 0;
}



Adrian and Maria are relatives that live in different towns. 
As they inhabit a rural area, it is very difficult for them to 
keep in touch. One way they found to overcome their 
communication problem was to send a line through their parents 
that used to visit each other.
The point is that Adrian and Maria did not want that their 
parents read their messages, and they decided to create a secret 
code for the messages. The code is not very sophisticated, 
but you should keep in mind Adrian and Maria are just children.
In general, the meaning of a message is based on changing some 
letters by numbers. Each message is composed by several lines 
using uppercase letters of the English alphabet, 
space and punctuation symbols: dot and comma. 
The letters that are changed by numbers can be seen in the 
following example; this change is the same for all messages 
between Adrian and Maria. Message in \Code Number":
H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3.
7H15 71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 200
0N3 70 533 7H3 238R42 4ND 60R1L42.
Decode Message:
HELLO MY LOVE, I M HAPPY BECAUSE SOON I WILL BE TO YOUR SIDE.
THIS TIME WITHOUT YOU HAS BEEN ETERNAL. I INVITE YOU TO THE ZOO
ONE TO SEE THE ZEBRAS AND GORILAS.
Hint: In this example, the relation Number-Letter between the 
message in \Code Number" and the
Decode Message this indicated by the numbers and letters in bold.



Input
The rst line of input gives the number of test cases, 
T (1  T  30). Each test case represents a
message written in Code Number, 
which is composed by 1  N  100 lines and each line cannot
exceed 80 characters of length. Two words in the same line are 
separated by one white space. One
blank line separated each test case.

Output
For each test case you must print the decoded message. 
You must print a blank line between each test case.



Sample Input
1
H3LL0 MY L0V3, 1 M H499Y 83C4U53 500N 1 W1LL 83 70 Y0UR 51D3. 7H15
71M3 W17H0U7 Y0U H45 833N 373RN4L. 1 1NV173 Y0U 70 7H3 200 0N3 70
533 7H3 238R45 4ND 60R1L45.

Sample Output
HELLO MY LOVE, I M HAPPY BECAUSE SOON I WILL BE TO YOUR SIDE. THIS
TIME WITHOUT YOU HAS BEEN ETERNAL.
