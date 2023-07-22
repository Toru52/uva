492	Pig-Latin



#include<stdio.h>
int main()
{
	char g, v;
	while ((g = getchar()) != EOF)
	{
		if ((g<'a' || g>'z') && (g<'A' || g>'Z'))        // condition 3
			printf("%c", g);
		else if (g == 'a' || g == 'A' || g == 'e' || g == 'E' || // condition 2
		g == 'i' || g == 'I' || g == 'o' || g == 'O' || g == 'u' || g == 'U')
		{
			printf("%c", g);
			while ((g = getchar()) && (g >= 'a'&&g <= 'z') || (g >= 'A'&&g <= 'Z'))
				printf("%c", g);
			printf("ay%c", g);
		}  // condition1
		else if ((g >= 'a'&&g <= 'z') || (g >= 'A'&&g <= 'Z'))
		{
			v = g;
			while ((g = getchar()) && (g >= 'a'&&g <= 'z') || (g >= 'A'&&g <= 'Z'))
				printf("%c", g);
			printf("%cay%c", v, g);
		}
	}
	return 0;
}



#include<stdio.h>
int main() {
	char v, g;
	while (~(g = getchar())) {
		if (('a' > g || g > 'z') && ('A' > g || g > 'Z'))
			putchar(g);
		else if (g == 'A' || g == 'a' || g == 'E' || g == 'e' || g == 'I'
			|| g == 'i' || g == 'O'||g == 'o' || g == 'U' || g == 'u') {
			putchar(g);
			while ((g = getchar()) && ('a' <= g&&g <= 'z') || ('A' <= g&&g <= 'Z'))
				putchar(g);
			printf("ay%c", g);
		}
		else if (('a' <= g&&g <= 'z') || ('A' <= g&&g <= 'Z')) {
			v = g;
			while ((g = getchar()) && ('a' <= g&&g <= 'z') || ('A' <= g&&g <= 'Z'))
				putchar(g);
			printf("%cay%c",v, g);
		}
	}
}




//https://ja.wikipedia.org/wiki/Pretty_Good_Privacy

You have decided that PGP encryptation is not strong enough 
for your email. You have decided to supplement it by first 
converting your clear text letter into Pig Latin before 
encrypting it with PGP.



Input and Output
You are to write a program that will take in an arbitrary 
number of lines of text and output it in Pig Latin. 
Each line of text will contain one or more words. 
A “word” is defined as a consecutive sequence of letters 
(upper and/or lower case). Words should be converted to Pig 
Latin according to the following rules (non-words should be 
output exactly as they appear in the input):

1. Words that begin with a vowel (a, e, i, o, or u, and the 
capital versions of these) should just have the string “ay” 
(not including the quotes) appended to it. For example, 
“apple” becomes “appleay”.

2. Words that begin with a consonant (any letter than is not
 A, a, E, e, I, i, O, o, U or u) should have the first 
 consonant removed and appended to the end of the word, 
 and then appending “ay” as well. For example, 
 “hello” becomes “ellohay”.
3. Do not change the case of any letter.



Sample Input
This is the input.

Sample Output
hisTay isay hetay inputay.