10193	All You Need Is Love


no1
#include <iostream>  
#include <cstdlib>  
#include <cstdio>  

using namespace std;

char buf[32];

int gcd(int a, int b)
{
	return (a%b) ? gcd(b, a%b) : b;
}

int main()
{
	int n, A, B;
	while (scanf("%d", &n) != EOF)
		for (int i = 1; i <= n; ++i) {
			scanf("%s", buf);
			A = 0;
			for (int j = 0; buf[j]; ++j) {
				A <<= 1;
				A += buf[j] - '0';
			}
			scanf("%s", buf);
			B = 0;
			for (int j = 0; buf[j]; ++j) {
				B <<= 1;
				B += buf[j] - '0';
			}
			printf("Pair #%d: ", i);
			if (gcd(A, B) != 1)
				printf("All you need is love!\n");
			else printf("Love is not all you need!\n");
		}
	return 0;
}



no2
#include<cstdio>
char s1[40], s2[40];

int gcd(int a, int b) { return (a%b) ? gcd(b, (a%b)) : b; }

int main()
{
	int n;

	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
		{
			int A = 0;
			scanf("%s", s1);
			for (int j = 0; j < s1[j]; j++)
			{
				A <<= 1;
				A += s1[j] - '0';
			}

			int B = 0;
			scanf("%s", s2);
			for (int j = 0; j < s2[j]; j++)
			{
				B <<= 1;
				B += s2[j] - '0';
			}

			if (gcd(A, B) != 1)
				printf("Pair #%d: All you need is love!\n", i);
			else
				printf("Pair #%d: Love is not all you need!\n", i);
		}
	}
}



 There was invented a new powerfull gadget by the International 
Beautifull Machines corporation called the love machine! 
Given a string made of binary digits, the love machine answers 
if it’s made only of love, that is, if all you need is love to 
build that string. The definition of love for the love machine 
is another string of binary digits, given by a human operator. 
Let’s say we have a string L which represents “love” and we 
give a string S for the love machine. We say that all you need 
is love to build S, if we can repeatly subtract L from S until 
we reach L. The subtraction defined here is the same arithmetic 
subtraction in base 2. By this definition it’s easy to see that 
if L > S (in binary), then S is not made of love.
If S = L then S is obvious made of love.
 Let’s see an example. Supose S = “11011” and L = “11”. 
If we reapetly subtract L from S, we
get: 11011, 11000, 10101, 10010, 1111, 1100, 1001, 110, 11. 
So, given this L, all you need is love to build S. 
Because of some limitations of the love machine, there can be 
no string with leading zeroes.That is, 
“0010101”, “01110101”, “011111”, etc. are invalid strings. 
Strings which have only one digit are also 
invalid (it’s another limitation).
Your task in this problem is: given two valid binary strings, 
S1 and S2, find if it’s possible to have a valid string L such 
that both S1 and S2 can be made only of L (i.e. given two valid 
strings S1 and S2, find if there exists at least one valid 
string L such as both S1 and S2 are made only of L). 
For instance, for S1 = 11011 and S2 = 11000, 
we can have L = 11 such that S1 and S2 are both made only of L 
(as we can see in the example above).



Input
The first line of input is a positive integer N < 10000 which 
stands for the number of teste cases. Then,2 ∗ N lines will 
follow. Each pair of lines consists in one teste case. Each 
line of the pair stands for each string (S1 and S2) to be 
entered as an input for the love machine. No string will have 
more than 30 characters. You can assume that all strings in the 
input will be valid acording to the rules above.

Output
For each string pair, you must print one of the following 
messages:
Pair #p: All you need is love!
Pair #p: Love is not all you need!
Where p stands for the pair number (starting from 1). 
You should print the first message if there exists at least one 
valid string L such as both S1 and S2 can be made only of L. 
Otherwise, print the second line.



Sample Input
5
11011
11000
11011
11001
111111
100
1000000000
110
1010
100

Sample Output
Pair #1: All you need is love!
Pair #2: Love is not all you need!
Pair #3: Love is not all you need!
Pair #4: All you need is love!
Pair #5: All you need is love!