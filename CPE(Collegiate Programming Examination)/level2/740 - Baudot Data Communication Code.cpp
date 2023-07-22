740 - Baudot Data Communication Code



#include <iostream>    
#include <string>  
using namespace std;
#define down 1  
#define up   0  

string ushift, dshift, buf;

int code(int space)
{
	int value = 0;
	for (int i = 0; i < 5; ++i) {
		value <<= 1;
		value += buf[space + i] - '0';
	}
	return value;
}

int main()
{
	getline(cin, dshift);
	getline(cin, ushift);
	while (getline(cin, buf)) {
		int state = down;
		for (int i = 0; i < buf.length(); i += 5) {
			int value = code(i);
			if (value == 27)
				state = down;
			else if (value == 31)
				state = up;
			else if (state == down)
				cout << dshift[value];
			else 
				cout << ushift[value];
		}
		cout << endl;
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
string upkey, downkey, buf;
int code(int n) {
	int value = 0;
	for (int i = 0; i < 5; i++) {
		value <<= 1;
		value += buf[n + i] - '0';
	}
	return value;
}
int main() {
	getline(cin,downkey);
	getline(cin, upkey);
	while (getline(cin, buf)) {
		bool F = 1;
		for (int i = 0; i < buf.length(); i += 5) {
			int val = code(i);
			
			if (val == 27)
				F = 1;
			else if (val == 31)
				F = 0;
			else if (F)
				cout << downkey[val];
			else
				cout << upkey[val];
		}
		cout << endl;
	}
}

Data are communicated between digital computers as sequences of bits. 
To provide meaning to asequence of bits, the bits are grouped to form 
a data character and an encoding scheme, or translation table, 
is provided to allow a computer system to translate each group of bits 
into a character. The ideal encoding scheme will provide a unique code 
for every possible character to be communicated and stored in the 
computer, but this requires that each group have a sufficient number of 
bits for each data character.
A code used early in the data communications industry is the Baudot 
code. Baudot uses five bits per character, thus allowing up to 32 
distinct characters. As a technique used to extend this limitation,
the code uses up-shift and down-shift modes as is used on a typewriter. In the Baudot code, each five
bits transmitted must be interpreted according to whether they are 
up-shifted (figures) or down-shifted (letters). The complete BAUDOT 
code (modified for this problem) is shown in the table below.
Bit Pattern Down-Shift Character Up-Shift Character

00000 < >
00001 T 5
00010 * @
00011 O 9
00100 Space Space
00101 H %
00110 N ,
00111 M .
01000 = +
01001 L )
01010 R 4
01011 G &
01100 I 8
01101 P 0
01110 C :
01111 V ;
10000 E 3
10001 Z ”
10010 D $
10011 B ?
10100 S #
10101 Y 6
10110 F !
10111 X /
11000 A -
11001 W 2
11010 J ’
11011 Shift Down Shift Down
11100 U 7
11101 Q 1
11110 K (
11111 Shift Up Shift Up
For example, the bit pattern 11111 represents up-shift and the bit 
pattern 11011 represents downshift characters. 
All characters transmitted after the sequence 11111 but before the 
shifted sequence 11011 are treated as up-shift characters. 
All characters transmitted after the sequence 11011 are treated
as down-shift characters until the pattern 11111 is recognized.



Input
The input consists of two parts. The first part is the Baudot character 
set: line one contains the 32 down-shift characters and line two 
contains the 32 up-shift characters. (Note: spaces are inserted for
the shift characters.) The remainder of the input file consists of one 
or more messages encoded using the Baudot code. Each message will be 
on a line in the input file. Each line will consist of 1’s and 0’s,
with no characters between the bits. There can be up to 80 bits per 
message. The input file will be terminated by end-of-file. 
The initial state of each message should be assumed
to be in the down-shift state.

Output
The output should consist of one line of text for each message. 
The output should contain the character
representation, as translated using BAUDOT, of each of the messages.



Sample Input
<T*O HNM=LRGIPCVEZDBSYFXAWJ UQK
>5@9 %,.+)4&80:;3"$?#6!/-2' 71(
100100110011000010011111101110000111110111101
001100001101111001001111100001001100010001100110111100000111

Sample Output
DIAL:911
NOV 5, 8AM