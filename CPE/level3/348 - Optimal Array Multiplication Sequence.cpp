348 - Optimal Array Multiplication Sequence



#include<stdio.h>
int Wy[11][11]{};
//binary search principle
void Backtracking(int l, int r) {
	if (l + 1 < r) {
		int m = Wy[l][r];
	//	printf("\nl %d r %d m %d\n", l, r, m);
		printf("(");
		Backtracking(l, m);
		printf(" x ");
		Backtracking(m + 1, r);
		printf(")");
	}
	//l==r represent l,r a same character,number is a one
	if (l == r)
		printf("A%d", l + 1);
	//l+1=r represented l ans r different,number are two
	if (l + 1 == r)
		printf("(A%d x A%d)", l + 1, r + 1);
}
int main() {
	int n, C = 0, A[11], DP[11][11]{};
	while (scanf("%d", &n),n) {
		for (int i = 0; i < n; i++)
			scanf("%d %d", &A[i], &A[i + 1]);
		//XYZ calculate from i to n  ;shift to left
		for (int i = 1; i < n; i++) 
			//x->X in XYZ z->Z in XYZ ;shift to left
			for (int x = 0, z = i + x; z < n; x++, z++) {
				int min = 2147483647, t, set;
				for (int y= x; y < z; y++) {
					//like a shortest path or floyed
					t = DP[x][y] + DP[y + 1][z] + A[x] * A[y + 1] * A[z + 1];
		//			printf("%d %d %d %d %d\n", DP[x][y], DP[y + 1][z], A[x], A[y + 1], A[z + 1]);
					if (min > t) 
						min = t, set = y;
				}
				DP[x][z] = min, Wy[x][z] = set;
		//		printf("x %d z %d min %d set %d\n", x, z, min, set);
			}
		printf("Case %d: ", ++C);
		Backtracking(0, n - 1);
		puts("");
	}
	return 0;
}



#include<stdio.h>
int M[11][11]{};
void backtracking(int l, int r) {
	if (l + 1 < r) {
		int m = M[l][r];
		printf("(");
		backtracking(l, m);
		printf(" x ");
		backtracking(m + 1, r);
		printf(")");
	}
	if (l == r)
		printf("A%d", l + 1);
	if (l + 1 == r)
		printf("(A%d x A%d)", l + 1, r + 1);
}
int main() {
	int n, cas = 0, A[11]{}, dp[11][11]{};
	while (scanf("%d", &n), n) {
		for (int i = 0; i < n; i++)
			scanf("%d %d", &A[i], &A[i + 1]);
		for(int i=1;i<n;i++)
			for (int x = 0, z = x + i; z < n; x++,z++) {
				int t, set, min = 1e9;
				for (int y = x; y < z; y++) {
					t = dp[x][y] + dp[y + 1][z] + A[x] * A[y + 1] * A[z + 1];
					if (min > t)
						min = t, set = y;
				}
				dp[x][z] = min, M[x][z] = set;
			}
		printf("Case %d: ", ++cas);
		backtracking(0,n-1);
		puts("");
	}
	return 0;
}



/*
Cij=(sigma k)Aik*Bkj

ex 
X 5*10
Y 10*20
Z 20*35
->

(XY)Z
=(1000(5(i)*20(j)*10(k=10))) <-5*20
=(3500(5(i)*35(j)*20(k=20)))
1000+3500=4500

X(YZ)
=7000(10(i)*35(j)*20(k=20)) <-10*35
=1750(5(i)*35(j)*20(k=20))
->1750+7000=8750

*/
Given two arrays A and B, we can determine the array C = A B using 
the standard definition of matrix multiplication:
Ci;j =
Σ
k
Ai;k  Bk;j
The number of columns in the A array must be the same as the number 
of rows in the B array. Notationally, let’s say that rows(A) and 
columns(A) are the number of rows and columns, respectively,
in the A array. The number of individual multiplications required to 
compute the entire C array (which will have the same number of rows 
as A and the same number of columns as B) is then rows(A)
columns(B) columns(A). For example, if A is a 10  20 array, 
and B is a 20  15 array, it will take 10  15  20, or 3000 
multiplications to compute the C array.
To perform multiplication of more than two arrays we have a choice 
of how to proceed. 
For example, if X, Y , and Z are arrays, then to compute X Y Z 
we could either compute (X Y ) Z or X (Y Z).
Suppose X is a 5  10 array, Y is a 10  20 array, 
and Z is a 20  35 array. Let’s look at the number of 
multiplications required to compute the product using the two 
different sequences: (X Y ) Z
• 5  20  10 = 1000 multiplications to determine the product 
  (XY ), a 5  20 array.
• Then 5  35  20 = 3500 multiplications to determine the 
  final result.
• Total multiplications: 4500. X (Y Z)
• 10  35  20 = 7000 multiplications to determine the product 
  (Y Z), a 10  35 array.
• Then 5  35  10 = 1750 multiplications to determine the 
  final result.
• Total multiplications: 8750.
Clearly we’ll be able to compute (X Y ) Z using fewer individual
multiplications.
Given the size of each array in a sequence of arrays to be multiplied, 
you are to determine an optimal computational sequence. Optimality, 
for this problem, is relative to the number of individual
multiplications required.



Input
For each array in the multiple sequences of arrays to be multiplied 
you will be given only the dimensions of the array.
Each sequence will consist of an integer N which indicates the number
of arrays to be multiplied, and then N pairs of integers, 
each pair giving the number of rows and columns in an array;
the order in which the dimensions are given is the same as the order 
in which the arrays are to be multiplied. 
A value of zero for N indicates the end of the input. 
N will be no larger than 10.

Output
Assume the arrays are named A1;A2; : : : ;AN. Your output for each 
input case is to be a line containing a parenthesized expression 
clearly indicating the order in which the arrays are to be 
multiplied. Prefix the output for each case with the case number 
(they are sequentially numbered, starting with 1). 
Your output should strongly resemble that shown in the samples shown 
below. If, by chance, there are multiple correct sequences, 
any of these will be accepted as a valid answer.



Sample Input
3
1 5
5 20
20 1
3
5 10
10 20
20 35
6
30 35
35 15
15 5
5 10
10 20
20 25
0

Sample Output
Case 1: (A1 x (A2 x A3))
Case 2: ((A1 x A2) x A3)
Case 3: ((A1 x (A2 x A3)) x ((A4 x A5) x A6))
