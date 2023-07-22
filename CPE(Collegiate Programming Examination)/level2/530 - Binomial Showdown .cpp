530 - Binomial Showdown 


#include<iostream>
using namespace std;

int main() {
	int n, k;
	long long C;

	while (cin >> n >> k&&(n!=0)||(k!=0)) {
		if (k>n / 2) 
			k = n - k;
		C = 1;
		for (int i = 0; i<k; i++) 
			C = C*(n - i) / (1 + i);//Pascal's triangle
		cout << C << endl;
	}
}



#include<iostream>
using namespace std;

int main() {
	int n, k;
	while (cin >> n >> k&&n != 0) {
		long long C=1;
		if (k > n / 2)
			k = n - k;
		for (int i = 0; i < k; i++)
			C =C*(n - i) / (i + 1);
		cout << C << endl;
	}
}



k>n / 2
ex
1 4 6 4 1
Left side number duplicate with right side number.



In how many ways can you choose k elements out of n 
elements, not taking order into account?
Write a program to compute this number.



Input
The input file will contain one or more test cases.
Each test case consists of one line containing two 
integers n (n ≥ 1) and k (0 ≤ k ≤ n).
Input is terminated by two zeroes for n and k.

Output
For each test case, print one line containing the 
required number. This number will always fit into 
an integer, i.e. it will be less than 2 31.
Warning: Don’t underestimate the problem. The 
result will fit into an integer — but if all 
intermediate results arising during the computation 
will also fit into an integer depends on your 
algorithm. The test cases will go to the limit.



Sample Input
4 2
10 5
49 6
0 0

Sample Output
6
252
13983816