256 - Quirksome Squares



#include<cmath>
#include<iomanip>
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> squares;

int prep() {
	for (int i = 0; i < 10000; i++)
		squares.push_back(i * i);
}

int main() {
	prep();
	while (scanf("%d", &N) == 1) {
		for (int i = 0; i < squares.size(); i++) {
			if (squares[i] >= (int)pow(10, N)) break;
			if (pow(squares[i] % (int)pow(10, N / 2) + squares[i] / (int)pow(10, N / 2), 2) == squares[i]) \
				cout << setw(N) << setfill('0') << squares[i] << endl;
		}
	}
}



#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
vector<int>p;
void power()
{
	for (int i = 0; i < 10000; i++)
		p.push_back(i*i);
}
int main()
{
	power();
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] >= (int)pow(10, n))
				break;
			if (pow(p[i] % (int)pow(10, n / 2) + p[i] / (int)pow(10, n / 2),2) == p[i])
				cout << setw(n) << setfill('0') << p[i] << endl;
		}
	}
}


ex 3025
pow(/*30*/squares[i] % (int)pow(10, N / 2)       +        /*25*/squares[i] / (int)pow(10, N / 2), 2)

we have number 3025,we want to separate them to 30 with 25
So all you have to  do this ->10^(n/2)
in other words 
Right side:3025%10^(4/2)->10^(2)  ->3025%100->30
Left side:3025/10^(4/2)->10^*(2)  ->3025/100->25
				
						
				
The number 3025 has a remarkable quirk: if you split its decimal 
representation in two strings of equal length (30 and 25) and 
square the sum of the numbers so obtained,
 you obtain the original number:
(30 + 25)2 = 3025
The problem is to determine all numbers with this property 
having a given even number of digits.
For example, 4-digit numbers run from 0000 to 9999. 
Note that leading zeroes should be taken
into account. This means that 0001 which is equal to (00 + 01)2
is a quirksome number of 4 digits.
The number of digits may be 2,4,6 or 8. 
Although maxint is only 32767 and numbers of eight digits
are asked for, a well-versed programmer can keep his numbers in 
the range of the integers. However
efficiency should be given a thought.



Input
The input of your program is a textflle containing numbers of 
digits (taken from 2,4,6,8), each number on a line of its own.

Output
The output is a textfile consisting of lines containing the 
quirksome numbers (ordered according to the
input numbers and for each input number in increasing order).
Warning: Please note that the number of digits in the output is 
equal to the number in the corresponding
input line : leading zeroes may not be suppressed.



Sample Input
2
2

Sample Output
00
01
81
00
01
81