10931 - Parity



no1.
#include <cstdio>
#include <vector>

int main() {
	long long I;
	while (scanf("%lld", &I), I != 0) {
		int P = 0;
		std::vector<char> out;
		for (int i = 0; I != 0; i++) {
			if (I & 1) {
				out.push_back('1');
				P++;
			}
			else out.push_back('0');
			I = I >> 1;
		}
		printf("The parity of ");
		for (int i = out.size() - 1; i >= 0; i--) printf("%c", out[i]);
		printf(" is %d (mod 2).\n", P);
	}
}




no2.
#include<cstdio>
#include<vector>
using namespace std;

int main()
{
	long long  n;

	while (scanf("%lld", &n) && n || 0)
	{
		vector<char>rec;
		int cnt = 0;

		while (n)
		{
			if (n % 2 == 1) {
				rec.push_back('1');
				cnt++;
			}
			else
				rec.push_back('0');
			n /= 2;
		}
		printf("The parity of ");
		for (int i = rec.size() - 1; i >= 0; i--)
			printf("%c", rec[i]);
		printf(" is %d (mod 2).\n", cnt);
	}
}



We define the parity of an integer n as the sum of the bits in 
binary representation computed modulo two. As an example, 
the number 21 = 101012 has three 1s in its binary representation 
so it has parity 3(mod2), or 1.
In this problem you have to calculate the parity of
an integer 1 ≤ I ≤ 2147483647.



Input
Each line of the input has an integer I and the end of the input 
is indicated by a line where I = 0 that
should not be processed.

Output
For each integer I in the inputt you should print a line 
‘The parity of B is P (mod 2).’, 
where B is the binary representation of I.



Sample Input
1
2
10
21
0

Sample Output
The parity of 1 is 1 (mod 2).
The parity of 10 is 1 (mod 2).
The parity of 1010 is 2 (mod 2).
The parity of 10101 is 3 (mod 2).
