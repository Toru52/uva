10892 - LCM Cardinality  
https://kimox2.wordpress.com/2012/06/25/uva-10892-lcm-cardinality/



#include <stdio.h>
int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b,int n){return a*(b / gcd(a, b))==n?1:0;}
int main() {	
	int n;
	while (scanf("%d", &n),n)	{
		int top = 0,cnt = 0;
		static int div[1000000] = {};
		for (int i = 1; i*i<=n; i++)
			if (n%i == 0){
				div[top++] = i;
				if (i != (n / i))
					div[top++] = n / i;
			}
		for (int i = 0; i<top; i++)
			for (int j = i+1; j<top; j++)
					cnt += lcm(div[i], div[j], n), printf("c %d %d %d\n", lcm(div[i], div[j], n), div[i], div[j]);
		printf("%d %d\n", n, cnt + 1);
	}
	return 0;
}



#include<stdio.h>
int gcd(int a, int b) { return b == 0 ? a : gcd(b,a%b); }
int LCM(int a, int b, int n) { return a*(b / gcd(a, b)) == n ? 1 : 0; }
int main() {
	int n;
	while (scanf("%d", &n), n) {
		int tot = 0, cnt = 0;
		static int div[1000000] = {};
		for(int i=1;i*i<=n;i++)
			if (n%i == 0) {
				div[tot++] = i;
				if (i != n / i)
					div[tot++] = n / i;
			}
		for (int i = 0; i < tot; i++)
			for (int j = i + 1; j < tot; j++)
				if (LCM(div[i], div[j], n))
					cnt++;
		printf("%d %d\n", n, cnt+1);
	}
	return 0;
}

/*
ex 12 
div->
1 12
2 6
3 4
1 12 2 6 3 4
top=6


LCM formula
http://www.geeksforgeeks.org/c-program-find-lcm-two-numbers/
int lcm(int a, int b,int n){return a*(b / gcd(a, b))==n?1:0;}
*/



A pair of numbers has a unique LCM but a single number can be the LCM 
of more than one possible pairs. For example 12 is the LCM of (1, 12), 
(2, 12), (3,4) etc. For a given positive integer N,
the number of different integer pairs with LCM is equal to N can be 
called the LCM cardinality of that number N. 
In this problem your job is to nd out the LCM cardinality of a number.



Input
The input le contains at most 101 lines of inputs. 
Each line contains an integer N (0 < N  2  109).
Input is terminated by a line containing a single zero. 
This line should not be processed.

Output
For each line of input except the last one produce one line of output.
 This line contains two integers
N and C. Here N is the input number and C is its cardinality. 
These two numbers are separated by a
single space.



Sample Input
2
12
24
101101291
0

Sample Output
2 2
12 8
24 11
101101291 5