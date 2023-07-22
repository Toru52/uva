458 - The Decoder 



#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
string line;

int main() {
	while (getline(cin, line)) {
		for (int i = 0; i < line.length(); i++)
			printf("%c", line[i] - ('1' - '*'));
		printf("\n");
	}
}



no2
#include<iostream>
#include<string>
using namespace std;
string ch;
int main()
{
	while (getline(cin, ch))
	{
		for (int i = 0; ch[i]; i++)
			printf("%c", ch[i] - ('1' - '*'));
		puts("");
	}
}



Write a complete program that will correctly decode a set of 
characters into a valid message. Your program should read a given 
file of a simple coded set of characters and print the exact message 
that the characters contain. The code key for this simple coding is a 
one for one character substitution based upon a single arithmetic 
manipulation of the printable portion of the ASCII character set.



Input and Output
For example: with the input file that contains:

1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5

1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'
Jvywvyh{pvu5

1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5

your program should print the message:

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.
Your program should accept all sets of characters that use the same 
encoding scheme and should print the actual message of each set of 
characters.




Sample Input

1JKJ'pz'{ol'{yhklthyr'vm'{ol'Jvu{yvs'Kh{h'Jvywvyh{pvu5
1PIT'pz'h'{yhklthyr'vm'{ol'Pu{lyuh{pvuhs'I|zpulzz'Thjopul'J
vywvyh{pvu5
1KLJ'pz'{ol'{yhklthyr'vm'{ol'Kpnp{hs'Lx|pwtlu{'Jvywvyh{pvu5

Sample Output

*CDC is the trademark of the Control Data Corporation.
*IBM is a trademark of the International Business Machine Corporation.
*DEC is the trademark of the Digital Equipment Corporation.