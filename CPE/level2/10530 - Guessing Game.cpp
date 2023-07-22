10530 - Guessing Game
https://belbesy.wordpress.com/2012/07/05/uva-10530-guessing-game/

#include <stdio.h>
#include <string.h>
int main() {
	int n;
	char line[20], a[11];
	while (scanf("%d\n", &n) && fgets(line,sizeof(line),stdin)) {
		if (line[4] == 'l')         
			memset(a, 1, n + 1);
		else if (line[4] == 'h')    
			memset(a + n, 1, 10 - n + 1);
		else {
			puts(a[n] ? "Stan is dishonest" : "Stan may be honest");
			memset(a, 0, 11);
		}
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main() {
	int n;
	char a[11], lhr[20];
	while (scanf("%d\n", &n) && fgets(lhr, sizeof(lhr), stdin)) {
		if (lhr[4] == 'l')
			memset(a, 1, n + 1);
		else if (lhr[4] == 'h')
			memset(a + n, 1, 10-n + 1);
		else {
			puts(a[n] ? "Stan is dishonest" : "Stan may be honest");
			memset(a, 0, 11);
		}
		
	}
	return 0;
}


Stan and Ollie are playing a guessing game. Stan
thinks of a number between 1 and 10 and Ollie
guesses what the number might be. After each
guess, Stan indicates whether Ollie's guess is too
high, too low, or right on.
After playing several rounds, Ollie has be-
come suspicious that Stan cheats; that is, that he
changes the number between Ollie's guesses. To
prepare his case against Stan, Ollie has recorded
a transcript of several games. You are to deter-
mine whether or not each transcript proves that
Stan is cheating.
Input
Standard input consists of several transcripts.
Each transcript consists of a number of paired guesses and responses.  
A guess is a line containing
single integer between 1 and 10, and a response is a line containing `
too high
', `
too low
', or `
right
on
'. Each game ends with `
right on
'. A line containing `
0
' follows the last transcript.
Output
For each game, output a line `
Stan is dishonest
' if Stan's responses are inconsistent with the  nal
guess and response. Otherwise, print `
Stan may be honest
'.



SampleInput
10
too high
3
too low
4
too high
2
right on
5
too low
7
too high
6
right on
0

SampleOutput
Stan is dishonest
Stan may be honest