10878 - Decode the tape



#include <cstdio>

int main()
{
	char line[50];
	while (fgets(line,sizeof(line),stdin)) {
		if (line[0] != '|') 
			continue;
		char c = 0;
		for (int i = 0; line[i]; i++) {
			if (line[i] == ' ' || line[i] == 'o')
				c <<= 1;
			if (line[i] == 'o')
				c++;
		}
		printf("%c", c);
	}
	return 0;
}



no2
#include<stdio.h>

int main()
{
	char line[50];
	while (fgets(line, sizeof(line), stdin))
	{
		if (line[0] != '|')
			continue;
		int c = 0;
		for (int i = 0; line[i]; i++)
		{
			if (line[i] == ' ' || line[i] == 'o')
				c <<= 1;
			if (line[i] == 'o')
				c++;
		}
		printf("%c", c);
	}
}



#include <iostream>
#include <string>
using namespace std;

int main () {
    string s;
    while (getline(cin, s)) {
        while (getline(cin, s), s !="___________") {
            cout << char((s[2]=='o')*64 + 
                (s[3]=='o')*32 + (s[4]=='o')*16 +
                (s[5]=='o')*8 + (s[7]=='o')*4 +
                (s[8]=='o')*2 + (s[9]=='o'));
        }
        cout << endl;
    }
}



Your boss has just unearthed a roll of old computer tapes.
The tapes have holes in them and might
contain some sort of useful information. 
It falls to you to figure out what is written on them



Input
The input will contain one tape

Output
Output the message that is written on the tape.



Sample Input
| o   .  o|
|  o  .   |
| ooo .  o|
| ooo .o o|
| oo o.  o|
| oo  . oo|
| oo o. oo|
|  o  .   |
| oo  . o |
| ooo . o |
| oo o.ooo|
| ooo .ooo|
| oo o.oo |
|  o  .   |
| oo  .oo |
| oo o.ooo|
| oooo.   |
|  o  .   |
| oo o. o |
| ooo .o o|
| oo o.o o|
| ooo .   |
| ooo . oo|
|  o  .   |
| oo o.ooo|
| ooo .oo |
| oo  .o o|
| ooo . o |
|  o  .   |
| ooo .o  |
| oo o.   |
| oo  .o o|
|  o  .   |
| oo o.o  |
| oo  .  o|
| oooo. o |
| oooo.  o|
|  o  .   |
| oo  .o  |
| oo o.ooo|
| oo  .ooo|
|  o o.oo |
|    o. o |

Sample Output
A quick brown fox jumps over the lazy dog.

___________
| o   .  o|A
|  o  .   |
| ooo .  o|q
| ooo .o o|u
| oo o.  o|i
| oo  . oo|c
| oo o. oo|k
| o   .   |
| oo  . o |b
| ooo . o |r
| oo o.ooo|o
| ooo .ooo|w
| oo o.oo |n
| o   .   |
| oo  .oo |f
| oo o.ooo|o
| oooo.   |x
| o   .   |
| oo o. o |j
| ooo .o o|u
| oo o.o o|m
| ooo .   |p
| ooo . oo|s
| o   .   |
| oo o.ooo|o
| ooo .oo |v
| oo  .o o|e
| ooo . o |r
| o   .   |
| ooo . o |t
| oo o.   |h
| oo  .o o|e
| o   .   |
| oo o. o |l
| oo  .  o|a
| oooo. o |z
| oooo.  o|y
| o   .   |
| oo  .o  |d
| oo o.ooo|o
| oo  .ooo|g
|  o o.oo |.
|    o. o |