382	Perfection
https://sites.google.com/site/pcshic/solutions/102-2-zi-xun-di-yi-ci-xiao-kao-can-kao-jie-da



#include<cstdio>

int pda(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++) 
		if (n % i == 0) sum += i;
	
	return sum - n;
}

int main() {
	int n;
	printf("PERFECTION OUTPUT\n");
	for (;;) {
		scanf("%d", &n);
		if (n == 0)
			break;
		int d = pda(n);
		printf("%5d  %s\n", n, d == 0 ? "PERFECT" : d > 0 ? "ABUNDANT" : "DEFICIENT");
	}
	printf("END OF OUTPUT\n");
}



#include<cstdio>
int SUM(int n) {
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
		if (n%i==0)
			sum += i;
	return sum;
}

int main() {
	int n;
	puts("PERFECTION OUTPUT");
	while (~scanf("%d", &n)&&n) {
		int sum = SUM(n);
		if (sum == n)
			printf("%5d  PERFECT\n", n);
		else if (sum > n)
			printf("%5d  ABUNDANT\n", n);
		else if (sum < n)
			printf("%5d  DEFICIENT\n", n);
	}
	puts("END OF OUTPUT");
}



#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	int s, n, f;
	string output[3] = { "DEFICIENT", "PERFECT", "ABUNDANT" };

	cout << "PERFECTION OUTPUT\n";
	while (cin >> n, n) {
		s = n>1;
		for (f = 2; f*f<n; f++)
			if (n % f == 0)
				s += f + n / f;
		if (f*f == n)
			s += f;
		cout << setw(5) << n << "  " << output[(s >= n) + (s>n)] << endl;
	}
	cout << "END OF OUTPUT\n";
}



From the article Number Theory in the 1994 Microsoft Encarta: 
“If a, b, c are integers such that a = bc, a is called a multiple 
of b or of c, and b or c is called a divisor or factor of a. 
If c is not ±1, b is called a proper divisor of a. Even integers, 
which include 0, are multiples of 2, for example, -4, 0, 2, 10; 
an odd integer is an integer that is not even, 
for example, -5, 1, 3, 9. A perfect number is a positive integer
that is equal to the sum of all its positive, proper divisors; 
for example, 6, which equals 1 + 2 + 3, and 28, which 
equals 1 + 2 + 4 + 7 + 14, are perfect numbers. 
A positive number that is not perfect is imperfect and is deficient 
or abundant according to whether the sum of its positive, 
proper divisors is smaller or larger than the number itself. 
Thus, 9, with proper divisors 1, 3, is deficient; 12, with proper
divisors 1, 2, 3, 4, 6, is abundant.”
Your task is: Given a number, determine 
if it is perfect, abundant, or deficient.



Input
A list of N positive integers (none greater than 60,000), 
with 1 < N < 100. A ‘0’ will mark the end of the list.

Output
The first line of output should read ‘PERFECTION OUTPUT’. 
The next N lines of output should list for each input integer 
whether it is perfect, deficient, or abundant, as shown in the 
example below. Format counts: the echoed integers should be right 
justified within the first 5 spaces of the output line, followed
by two blank spaces, followed by the description of the integer. 
The final line of output should read ‘END OF OUTPUT’.



Sample Input
15 28 6 56 60000 22 496 0

Sample Output
PERFECTION OUTPUT
15 DEFICIENT
28 PERFECT
6 PERFECT
56 ABUNDANT
60000 ABUNDANT
22 DEFICIENT
496 PERFECT
END OF OUTPUT
