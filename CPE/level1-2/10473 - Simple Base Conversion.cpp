10473 - Simple Base Conversion



no1
#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;

int main() {
	string s;
	stringstream ss;
	int num;
	while (cin >> s) {
		if (s[0] == '-')
			break;
		ss.clear();
		ss.str(s);
		if (s[1] == 'x') {
			ss >> hex >> num;
			printf("%d\n", num);
		}
		else {
			ss >> dec >> num;
			printf("0x%X\n", num);
		}
	}
	return 0;
}



no2
#include<iostream>
#include<sstream>
using namespace std;
int main()
{
	stringstream ss;
	string s;
	int num;

	while (cin >> s)
	{
		if (s[0] == '-')
			break;
		ss.clear();
		ss.str(s);
		if (s[1] == 'x')
		{
			ss >> hex >> num;
			printf("%d\n", num);
		}
		else
		{
			ss >> dec >> num;
			printf("0x%X\n", num);
		}
	}
}




The way of convert
http://www.it-license.com/cardinal_number/ToDecimal.html



In this problem you are asked to write a simple
base conversion program. You will be given
a hexadecimal or decimal integer number as input.
You will have to output the corresponding
decimal or hexadecimal number. Hexadecimal
numbers always starts with a ‘0x’ and all other
numbers are to be considered as decimal numbers.
There will be no invalid numbers in the input.



Input
The input file contains several lines of input. Each line 
contains a single non-negative number, which may be a decimal 
or hexadecimal number as explained in the problem statement.
The decimal value of this number will be less than 231. 
A line containing a negative decimal number terminates input.
This number should not be processed. Input numbers will 
contain no space within them.

Output
For each line of input (Except the last one) produce one 
line of output. This line should contain the decimal or 
hexadecimal representation of the corresponding hexadecimal 
or decimal number. Like the input, the hexadecimal numbers 
in the output should be preceded by a ‘0x’



Sample Input
4
7
44
0x80685
-1

Sample Output
0x4
0x7
0x2C
525957