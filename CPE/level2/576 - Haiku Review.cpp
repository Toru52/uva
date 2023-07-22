576 - Haiku Review



#include <cstdio>  
#include <cstring>  

int  maps[256];
int  size[3];
char buf[202];

int main()
{
	memset(maps, 0, sizeof(maps));
	maps['a'] = maps['e'] = maps['i'] = maps['o'] = maps['u'] = maps['y'] = 1;
	//visual studio: gets ->gets_s
	while (gets(buf)) {
		if (!strcmp(buf, "e/o/i")) break;
		int item = 0;
		size[0] = size[1] = size[2] = 0;
		for (int i = 0; buf[i]; ++i) {
			if (buf[i] == '/') ++item;
			//ex code -> 1 because in English the ‘e’ is silent
			//so last digit vowel don't count
			//a e i o u -> 5 count all because have space in middle 
			if (i == 0 || !maps[buf[i - 1]])
				size[item] += maps[buf[i]];
		}

		if (size[0] != 5) puts("1");
		else if (size[1] != 7) puts("2");
		else if (size[2] != 5) puts("3");
		else puts("Y");
	}
	return 0;
}



#include<cstdio>
#include<cstring>

int main() {
	int str[260] = {};
	char buf[260] = {};
	str['a'] = str['e'] = str['i'] 
		=str['o'] = str['u']=str['y']=1;
	while (gets(buf)) {
		if (!strcmp(buf, "e/o/i"))
			break;
		int line=0,size[3] = {};
		for (int i = 0; buf[i]; i++) {
			if (buf[i] == '/')
				line++;
			if (i == 0 || !str[buf[i - 1]])
				size[line] += str[buf[i]];
		}
		if (size[0] != 5)
			puts("1");
		else if (size[1] != 7)
			puts("2");
		else if (size[2] != 5)
			puts("3");
		else
			puts("Y");
	}
}


Haiku is an ancient form of Japanese poetry. A haiku is a 
three-line poem with seventeen syllables, where the first line 
must contain five syllables, the second line must contain 
seven syllables, and the third line must contain five 
syllables. The lines do not have to rhyme. Here is an example,
where slashes separate the lines:
Computer programs/T he bugs try to eat my code/I must not let 
them. You must write a program that will review a haiku and 
check that each line contains the correct number of syllables.



Input
The input contains one or more lines, each of which contains 
a single haiku. A haiku will contain at least three words, 
and words will be separated by either a single space or a 
slash (‘/’). Slashes also separate the three lines of a haiku,
 so each haiku will contain exactly two slashes. 
 (The three lines of the haiku will be contained within one 
 physical line of the file.) A haiku will contain only 
 lowercase letters (‘a’..‘z’), forward slashes (‘/’), and 
 spaces, and will be no more than 200 characters long (not
counting the end-of-line characters). The haiku ‘e/o/i’ 
signals the end of the input. Each haiku is guaranteed to 
contain three lines, and each line will contain at least one 
word. Your job is to determine whether each line has the 
correct number of syllables (5/7/5). For the purposes of
this problem, every contiguous sequence of one or more vowels 
counts as one syllable, where the vowels are 
‘a’, ‘e’, ‘i’, ‘o’, ‘u’, and ‘y’. Every word will contain at 
least one syllable.
(Note that this method of counting syllables does not always 
agree with English conventions. In the second example below, 
your program must consider the word ‘code’ to have two 
syllables because the ‘o’ and the ‘e’ are not consecutive. 
However, in English the ‘e’ is silent and so ‘code’ actually 
has only one syllable.)

Output
For each haiku, output a single line that contains
‘1’ if the first line has the wrong number of syllables,
‘2’ if the second line has the wrong number of syllables, 
‘3’ if the third line has the wrong number of
syllables, or ‘Y’ if all three lines have the correct number 
of syllables. If the haiku is not correct, you
must output the number of the first line that has the wrong 
number of syllables.



Sample Input
happy purple frog/eating bugs in the marshes/get indigestion
computer programs/the bugs try to eat my code/i will not let 
them a e i o u/this is seven syllables/a e i o u y    e/o/i

Sample Output
Y
2
3


