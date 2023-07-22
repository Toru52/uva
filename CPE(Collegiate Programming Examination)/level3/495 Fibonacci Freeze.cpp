495 Fibonacci Freeze 
http://knightzone.org/?p=1426

about fibonacci
http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/



#include <cstdio>
int Fib[5001][500];
int main(){
	
	Fib[1][0] = 1;
	//digit calc
	for (int i = 2; i <= 5000; i++) {
		for (int j = 0; j<500; j++) {
			//nCr=n-1Cr+n-2Cr
			Fib[i][j] += Fib[i - 1][j] + Fib[i - 2][j];
			if (Fib[i][j] >= 1000) 
				Fib[i][j] -= 1000,Fib[i][j + 1]++;	
		}
	}
	int n;
	while (scanf("%d", &n) ==1) {
		printf("The Fibonacci number for %d is ", n);
		if (!n) printf("0\n");
		else {
			int i = 500;
			while (Fib[n][--i] == 0);
			printf("%d", Fib[n][i--]);
			for (; i >= 0; i--) printf("%.3d", Fib[n][i]);
			printf("\n");
		}
	}
	return 0;
}



#include<stdio.h>
int j, n, f[5001][501];
int main() {
	f[1][0] = 1;
	for(int i=2;i<=5000;i++)
		for (int j = 0; j < 350; j++) {
			f[i][j] += f[i - 1][j] + f[i - 2][j];
			if (f[i][j] >= 1000)
				f[i][j] -= 1000, f[i][j + 1]++;
		}
	while (scanf("%d", &n) == 1) {
		printf("The Fibonacci number for %d is ", n);
		if (!n) puts("0");
		else {
			j = 350;
			while (f[n][--j] == 0);
			printf("%d", f[n][j--]);
			for (; j >= 0; j--)
				printf("%.3d", f[n][j]);
			puts("");
		}
	}
	return 0;
}




The Fibonacci numbers 
(0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, ...) 
are defined by the recurrence:
F0 = 0
F1 = 1
Fi = Fi􀀀1 + Fi􀀀2 for all i  2
Write a program to calculate the Fibonacci Numbers.
Input
The input to your program would be a sequence of numbers smaller 
or equal than 5000, each on a separate line, specifying which 
Fibonacci number to calculate.

Output
Your program should output the Fibonacci number for each input 
value, one per line.



Sample Input
5
7
11

Sample Output
The Fibonacci number for 5 is 5
The Fibonacci number for 7 is 13
The Fibonacci number for 11 is 89