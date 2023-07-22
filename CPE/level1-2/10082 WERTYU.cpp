10082	WERTYU



no1
#include<stdio.h>

int main()
{
	const char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char input;
	while ((input = getchar()) != EOF)
	{
		int i;
		if (input == ' ' || input == '\n')
		{
			printf("%c", input);
			continue;
		}
		for (i = 0; keyboard[i] != input; i++);
		printf("%c", keyboard[i - 1]);
	}
	return 0;
}



no2
#include<cstdio>
int main()
{
	const char key[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char input;

	while ((input = getchar()) != EOF)
	{
		int i;
		if (input == ' ' || input == '\n')
		{
			printf("%c", input);
			continue;
		}
		for (i = 0; input != key[i]; i++);
		printf("%c", key[i-1]);
	}
}



A common typing error is to place the
hands on the keyboard one row to the
right of the correct position. So ‘Q’ is
typed as ‘W’ and ‘J’ is typed as ‘K’ and
so on. You are to decode a message typed in this manner.



Input
Input consists of several lines of text. Each line may contain 
digits, spaces, upper case letters (exceptQ, A, Z), 
or punctuation shown above [except back-quote (‘)]. 
Keys labelled with words [Tab, BackSp,Control, etc.] 
are not represented in the input.

Output
You are to replace each letter or punction symbol by the one 
immediately to its left on the ‘QWERTY’ keyboard shown above. 
Spaces in the input should be echoed in the output.



Sample Input 
O S, GOMR YPFSU/

Sample Output
I AM FINE TODAY.