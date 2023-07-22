9.10222 - Decode the Mad man

No1.
#include <cstdio>
#include <cctype>
const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main()
{
	char c;
	while (scanf("%c", &c) != EOF) {
		c = tolower(c);                  //換成小寫字母
		if (isspace(c))
			printf("%c", c);  //如果為' '或'\n'直接輸出
		else {
			for (int i = 0; keyboard[i]; ++i)
				if (c == keyboard[i]) {
					printf("%c", keyboard[i - 2]);
					break;
				}
		}
	}
	return 0;
}




Once in BUET, an old professor had gone completely mad. 
He started talking with some peculiar words. 
Nobody could realize his speech and lectures. 
Finally the BUET authority fall in great trouble.
There was no way left to keep that man working in university.
Suddenly a student (definitely he was a registered author 
at UVA ACM Chapter and hold a good rank on 24 hour-Online 
Judge) created a program that was able to decode that 
professor’s speech. After his invention, everyone got 
comfort again and that old teacher started his everyday 
works as before.So, if you ever visit BUET and see a 
teacher talking with a microphone, which is connected to a
IBM computer equipped with a voice recognition software 
and students are taking their lecture from the computer 
screen, don’t get thundered! Because now your job is to 
write the same program which can decode that mad 
teacher’s speech!



Input
The input file will contain only one test case i.e. 
the encoded message.The test case consists of one or 
more words.

Output
For the given test case, print a line containing the 
decoded words. However, it is not so hard task to replace 
each letter or punctuation symbol by the two immediately 
to its left alphabet on your standard keyboard.


`1234567890-=qwertyuiop[]asdfghjkl;'\zxcvbnm,./
Sample Input
k[r dyt I[o

Sample Output
how are you