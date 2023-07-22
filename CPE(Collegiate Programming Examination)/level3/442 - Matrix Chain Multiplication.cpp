442 - Matrix Chain Multiplication
https://github.com/morris821028/UVa/blob/master/volume004/442%20-%20Matrix%20Chain%20Multiplication.cpp



#include <stdio.h>
int n, ch[105][2]{};
char s[105];
void solve() {
	int S[105], sidx = -1;
	int j, sum = 0, chx = 'Z';
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') 
			S[++sidx] = '(';
		else if (s[i] == ')') {
			j = sidx;
			while (S[j] != '(')
				j--;
			for (int k = j + 1; k < sidx; k++) {
				if (ch[S[k] - 'A'][1] != ch[S[k + 1] - 'A'][0]) {
					puts("error");
					return;
				}
				sum += ch[S[k] - 'A'][0]*ch[S[k] - 'A'][1] * 
					   ch[S[k + 1] - 'A'][1];
			}
			chx++;
			ch[chx - 'A'][0] = ch[S[j + 1] - 'A'][0];
			ch[chx - 'A'][1] = ch[S[sidx] - 'A'][1];
			S[j] = chx;
			sidx = j;
		}
		else
			S[++sidx] = s[i];
	}
	printf("%d\n", sum);
}
int main() {
	int x, y;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d %d", s, &x, &y);
		ch[s[0] - 'A'][0] = x,ch[s[0] - 'A'][1] = y;
	}
	while (scanf("%s", s) == 1) 
		solve();
	return 0;
}



/*
matrix product
ex
A{50,10}*B[10,20]
=50*10*20=10000

B{10,20}*C[20,5]
=10*20*5=1000

(A[50,10]*B[10,20])*C[20,5]
=50*10*20+50*20*5=15000

A[50,10]*(B[10,20]*C[20,5])
=10*20*5+50*10*5=3500


*/
Suppose you have to evaluate an expression like A*B*C*D*E where A,B,C,D
and E are matrices.
Since matrix multiplication is associative, 
the order in which multiplications are performed is arbitrary.
However, the number of elementary multiplications needed strongly 
depends on the evaluation order you choose.
For example, let A be a 50*10 matrix, B a 10*20 matrix and C a 20*5 
matrix. There are two different strategies to compute A*B*C, 
namely (A*B)*C and A*(B*C).
The first one takes 15000 elementary multiplications, 
but the second one only 3500.
Your job is to write a program that determines the number of 
elementary multiplications needed for a given evaluation strategy.



Input
Input consists of two parts: a list of matrices and a list of 
expressions.
The first line of the input file contains one integer n 
(1  n  26), representing the number of matrices in the first 
part. The next n lines each contain one capital letter, 
specifying the name of the matrix, and two integers, 
specifying the number of rows and columns of the matrix.
The second part of the input file strictly adheres to the following 
syntax (given in EBNF):
SecondPart = Line { Line } <EOF>
Line = Expression <CR>
Expression = Matrix | "(" Expression Expression ")"
Matrix = "A" | "B" | "C" | ... | "X" | "Y" | "Z"
Output
For each expression found in the second part of the input file, 
print one line containing the word ‘error’ if evaluation of the 
expression leads to an error due to non-matching matrices. 
Otherwise print one line containing the number of elementary 
multiplications needed to evaluate the expression in the way
specified by the parentheses.



Sample Input
9A
50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
ABC
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))

Sample Output
000
error
10000
error
3500
15000
40500
47500
15125
9
A 50 10
B 10 20
C 20 5
D 30 35
E 35 15
F 15 5
G 5 10
H 10 20
I 20 25
A
B
C
(AA)
(AB)
(AC)
(A(BC))
((AB)C)
(((((DE)F)G)H)I)
(D(E(F(G(HI)))))
((D(EF))((GH)I))