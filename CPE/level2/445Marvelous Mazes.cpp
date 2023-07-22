445	Marvelous Mazes




#include<cstdio>
#include<cctype>


int main() {
	char s;
	int times = 0;

	while ((s = getchar()) != EOF) {
		if (isdigit(s))
			times += (int)(s - '0');
		else if (s == '!')
			printf("\n");
		else if (s == 'b') {
			while (times--) printf(" ");
			++times;
		}
		else if (isgraph(s)) {
			while (times--) printf("%c", s);
			++times;
		}
		else if (s == '\n')
			printf("\n");
	}
	return 0;
}



#include<cstdio>
#include<cctype>

int main()
{
	int c = 0;
	char s;
	while (~(s = getchar())) {
		if (isdigit(s))
			c += (int)(s - '0');
		else if (s == '!')
			puts("");
		else if (s == 'b') {
			while (c--)
				printf(" ");
			c++;
		}
		else if (isgraph(s)) {
			while (c--)
				printf("%c", s);
			c++;
		}
		else if (s == '\n')
			puts("");
	}
}


Your mission, if you decide to accept it, is to create a maze drawing 
program. A maze will consist of
the alphabetic characters A-Z, * (asterisk), and spaces.



Input
Your program will get the information for the mazes from the input 
file. This file will contain lines of characters which your program 
must interpret to draw a maze. Each row of the maze will be described
by a series of numbers and characters, where the numbers before a 
character tell how many times that character will be used. 
If there are multiple digits in a number before a character, 
then the number of times to repeat the character is the sum of the 
digits before that character. The lowercase letter ‘b’ will be used 
in the input file to represent spaces in the maze.
The descriptions for different rows in the maze will be separated by 
an exclamation point (!), or by an end of line.
Descriptions for different mazes will be separated by a blank line. 
The input file will be terminated by an end of file.

Output
For each description in the input file, draw the corresponding maze 
as it is shown in the sample output below. 
There is no limit to the number of rows in a maze or the number of 
mazes in a file, though no
row will contain more than 132 characters.
Print a blank line between two consecutive mazes.
Happy mazing!



Sample Input
1T1b5T!1T2b1T1b2T!1T1b1T2b2T!1T3b1T1b1T!3T3b1T!1T3b1T1b1T!5T1*1T
11X21b1X
4X1b1X
Sample Output
T TTTTT
T T TT
T T TT
T T T
TTT T
T T T
TTTTT*T
XX X
XXXX X
