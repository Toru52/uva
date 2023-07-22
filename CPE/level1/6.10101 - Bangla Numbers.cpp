10101 - Bangla Numbers

No1.

#include <cstdio>
using namespace std;

void bangla(long long int n)
{
	if (n >= 10000000) {
		bangla(n / 10000000);
		printf(" kuti");
		n %= 10000000;
	}
	if (n >= 100000) {
		bangla(n / 100000);
		printf(" lakh");
		n %= 100000;
	}
	if (n >= 1000) {
		bangla(n / 1000);
		printf(" hajar");
		n %= 1000;
	}
	if (n >= 100) {
		bangla(n / 100);
		printf(" shata");
		n %= 100;
	}
	if (n)
		printf(" %d", n);
}
int main()
{
	long long int n;
	int Case = 1;
	while (scanf("%lld", &n) != EOF) {
		printf("%4d.", Case++);
		if (n == 0) printf(" 0");
		bangla(n);
		printf("\n");
	}
	return 0;
}

No2.
#include<cstdio>

void bangla(long long int num)
{
	if (num >= 10000000) {
		bangla( num / 10000000);
		printf(" kuti");
		num %= 10000000;
	}
    if (num >= 100000) {
		bangla(num / 100000);
		printf(" lakh");
		num %= 100000;
	}
	if (num >= 1000) {
		bangla(num / 1000);
		printf(" hajar");
		num %= 1000;
	}
	 if (num >= 100) {
		bangla(num / 100);
		printf(" shata");
		num %= 100;
	}
	if(num)
		printf(" %d", num);


}

int main()
{
	long long int num;
	int cnt = 0;

	while (scanf("%lld", &num) != EOF)
	{
		printf("%4d.", ++cnt);

		if (num == 0)
			printf(" 0");

		bangla(num);
		printf("\n");
	}
}




Bangla numbers normally use ’kuti’ (10000000),
 ’lakh’ (100000), ’hajar’ (1000), ’shata’ (100) 
 while expanding and converting to text. 
 You are going to write a program to convert 
 a given number to text with them.
 
Input
The input file may contain several test cases. 
Each case will contain a
non-negative number ≤ 999999999999999.

Output
For each case of input, you have to output a 
line starting with the case number with four 
digits adjustment followed by the converted text.

Sample Input
23764
45897458973958

Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58