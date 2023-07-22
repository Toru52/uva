355	The Bases Are Loaded



#include <iostream>
#include <cstring>
#include <cmath>
#include<string>
using namespace std;
string h = "0123456789ABCDEF";



//convert to string type number
string itoa(long long N, int base)
{
	char s[1000];
	int a[1000];
	int i = 0;
	while (N >= base)
	{
		a[i++] = N%base;
		N /= base;
	}
	a[i] = N;
	//convert to string type number
	for (int j = 0; j <= i; j++)
	{
		s[j] = h[a[i - j]];
	}
	s[++i] = 0;
	string str = s;
	return str;
}
long long strtoDec(char* N, int base)
{
	long long a = 0;
	for (int i = 0; i<strlen(N); i++)
	{
		int temp = h.find(N[strlen(N) - 1 - i]);
		a += temp*pow((double)base, i);
	}
	return a;
}
int main()
{
	int base1, base2;
	char N[1000];
	while (cin >> base1 >> base2 >> N)
	{
		int Continue = 0;
		for (int i = 0; i<strlen(N); i++)
		{
			if (h.find(N[i]) >= base1)
			{
				Continue = 1;
				cout << N << " is an illegal base " << base1 << " number" << endl;
				break;
			}
		}
		if (Continue) continue;
		long long int N_in_Base10;
		N_in_Base10 = strtoDec(N, base1);///strtol只能用int範圍
		cout << N << " base " << base1 << " = " << itoa(N_in_Base10, base2) << " base " << base2 << endl;
	}
	return 0;
}



#include<iostream>
#include<string>
#include<cstring>
#include<math.h>
using namespace std;
string NUM = "0123456789ABCDEF";

string BASE2(long long n, int base2) {
	int c = 0, SUM[1000];
	char s[1000];

	while (n >= base2) {
		SUM[c++] = n%base2;
		n /= base2;
	}
	SUM[c] = n;
	for (int i = 0; i <= c; i++)
		s[i] = NUM[SUM[c - i]];
	s[++c] = 0;
	string str = s;
	return str;
}
long long TEN(char *N, int base1) {
	long long sum = 0;
	for (int i = 0; N[i]; i++) {
		int temp = NUM.find(N[strlen(N)-i-1]);
		sum += temp*pow(base1, i);
	}
	return sum;
}
int main() {
	int base1, base2;
	char N[1000];
	while (cin >> base1 >> base2>>N) {
		bool F = 0;
		for (int i = 0; N[i]; i++) 
			if (NUM.find(N[i]) >= base1) {
				printf("%s is an illegal base %d number\n", N, base1);
				F = 1;
				break;
			}
		if (F)
			continue;
		long long base10 = TEN(N, base1);
		cout << N <<" base "<<base1<<" = "<<BASE2(base10,base2)
			<<" base "<<base2<<endl;
	}
}



Write a program to convert a whole number specified in any base (2..16) 
to a whole number in any other base (2..16). “Digits” above 9 are 
represented by single capital letters; e.g. 10 by A, 15 by F, etc.



Input
Each input line will consist of three values. The first value will be a 
positive integer indicating the base of the number. The second value is 
a positive integer indicating the base we wish to convert to. The third 
value is the actual number (in the first base) that we wish to convert. 
This number will have letters representing any digits higher than 9 and 
may contain invalid “digits”. It will not exceed 10 characters. 
Each of the input values on a single line will be separated by at least 
one space.

Output
Program output consists of the original number followed by the string 
‘base’, followed by the original base number, followed by the string 
‘=’ followed by the converted number followed by the string ‘base’
followed by the new base. If the original number is invalid, output the 
statement original_V alue is an illegal base original_Base number
where original_V alue is replaced by the value to be converted and 
original_Base is replaced by the original base value.



Sample input
2 10 10101
5 3 126
15 11 A4C

Sample output
10101 base 2 = 21 base 10
126 is an illegal base 5 number
A4C base 15 = 1821 base 11