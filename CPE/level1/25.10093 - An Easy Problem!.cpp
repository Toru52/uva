10093 - An Easy Problem!



#include<iostream>
#include<string>
using namespace std;

int main()
{
	string digit;

	while (getline(cin, digit))
	{
		int sum = 0, max = 1;

		for (int i = 0; i < digit.size(); i++)
		{
			int R=0;

			if (isdigit(digit[i]))
				R = digit[i] - 48;
			else if (isupper(digit[i]))
				R = digit[i] - 55;
			else if (islower(digit[i]))
				R = digit[i] - 61;
			if (R > max)
				max = R;
			sum += R;
		}

		for (int i = max; i <= 62; i++)
		{
			if (sum%i == 0) {
				cout << i + 1 << endl;
				break;
			}
			else if (i == 62)
				cout << "such number is impossible!" << endl;
		}
	}
}



Have you heard the fact “The base of every normal number system 
is 10”? Of course, I am not talking about number systems like 
Stern Brockot Number System. This problem has nothing to do with 
this fact but may have some similarity. You will be given an N 
based integer number R and you are given the guaranty that R is 
divisible by (N − 1). You will have to print the smallest 
possible value for N. The range for N is 2 ≤ N ≤ 62 and the 
digit symbols for 62 based number is (0..9 and A..Z and a..z). 
Similarly, the digit symbols for 61 based number system is 0..9 
and A..Z and a..y) and so on.



Input
Each line in the input file will contain an integer (as defined 
in mathematics) number of any integer base (2..62). You will 
have to determine what is the smallest possible base of that 
number for the given conditions. No invalid number will be given 
as input.

Output
If number with such condition is not possible output the line 
‘such number is impossible!’ For each
line of input there will be only a single line of output. 
The output will always be in decimal number system.



Sample Input
3
5
A

3
  +5
-A
4964654623232355454546554546546545464564564565465465454654600655460
   -005444554f546554654A5445656466
00000q123
1
0
q12345

Sample Output
4
6
11

4
6
11
62
60
59
2
2
such number is impossible!