11956 Brainfuck 
http://mypaper.pchome.com.tw/zerojudge/post/1323219537



#include <stdio.h>

int main() {
	int t, cas = 0;
	char cmd[100005];
	scanf("%d ", &t);
	while (t--) {
		fgets(cmd,sizeof(cmd),stdin);
		unsigned char mem[100] = {};//set unsigned char since HEX
		int idx = 0;
		for (int i = 0; cmd[i]; i++) {
			switch (cmd[i]) {
			case '>':idx++; break;
			case '<':idx--; break;
			case '+':mem[idx]++; break;
			case '-':mem[idx]--; break;
			}
			if (idx >= 100)  idx = 0;
			if (idx < 0) idx = 99;
		}
		printf("Case %d:", ++cas);
		for (int i = 0; i < 100; i++)
			printf(" %02X", mem[i]);
		puts("");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int t;
	char c[100005]{};
	scanf("%d ", &t);
	for (int cas = 1; cas <= t; cas++) {
		unsigned char mem[105]{};
		int it = 0;
		fgets(c, sizeof(c), stdin);
		for (int i = 0; c[i]; i++) {
			switch (c[i]) {
			case '>':it++; break;
			case '<':it--; break;
			case '+':mem[it]++; break;
			case '-':mem[it]--; break;
			}
			if (it >= 100)it = 0;
			else if (it < 0)it = 99;
		}
		printf("Case %d:", cas);
		for (int i = 0; i < 100; i++)
			printf(" %02X", mem[i]);
		puts("");
	}
	return 0;
}


Recently your friend Bob has bought a new brainfuck 
programmable LED display. However executing a program 
directly on LED display takes huge amount of time. 
Because of this, now Bob decided to write the interpreter
of display instruction set in order to test and debug 
all his programs on his PC and only after that execute 
his code on LED display. 
However Bob knows only one programming language
| its certainly brainfuck (otherwise he would not have 
bought this LED display). 
So he asks you to write him an interpreter.
A display's program is a sequence of commands executed 
sequentially. The commands of the display
processor is a subset of brainfuck language commands. 
The commands that processor was capable to
execute were `>', `<', `+', `-' and `.', which are 
described in the table below. Moreover, this LED
display has an array of 100 bytes of circular memory 
(initialised with zeros) and a pointer to this
array (initialised to point to the leftmost byte of the 
array). This means, that after incrementing a pointer, 
which points to the rightmost byte of memory, 
it will point to the leftmost byte and vice versa.
Individual bytes are circular as well, so increasing a 
255 gives a 0 and vice versa. Command Description
> Increment the pointer 
(to point to the next cell to the right).
< Decrement the pointer 
(to point to the next cell to the left).
+ Increment (increase by one) the byte at the pointer.
- Decrement (decrease by one) the byte at the pointer.
. Output the value of the byte at the pointer.



Input
There is a number of tests T (T  100) on the rst 
line. After T tests follow. Each test case is a
sequence of display processor commands on a separate 
line. You can assume that line length is less than 100000.

Output
For each test output a single line `Case T: D'. 
Where T is the test number (starting from 1) and D
is display's memory dump in hexademical numeration 
system after executing given brainfuck program.
Every byte must be separated exactly by one space 
character. See examples for clarication. Please
note, that the sample input and output is divided into 
several lines only for convenience.



Sample Input
1
..++<><<+++>>++++++++++++++++++++++++++>>>+++
<+...++<><<+++>>++++++++++++++++++++++++++>>>
+++<+...++<><<+++>>++++++++++++++++++++++++++
>>>+++<+.

Sample Output
Case 1: 1F 00 20 03 1D 03 01 03 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00 00 00 00 03 00