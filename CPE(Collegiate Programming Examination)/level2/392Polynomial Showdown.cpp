392	Polynomial Showdown



#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int coefficients[9];
	while (scanf("%d", &coefficients[0]) != EOF) {
		for (int i = 1; i < 9; ++i) {
			scanf("%d", &coefficients[i]);
		}

		bool firstTerm = false;
		for (int i = 0; i < 9; ++i) {
			if (coefficients[i] != 0) {
				int coefficientTemp = coefficients[i];
				if (firstTerm) {
					coefficientTemp = abs(coefficientTemp);
					if (coefficients[i] > 0) {
						printf(" + ");
					}
					else {
						printf(" - ");
					}
				}

				if (8 - i == 0) {
					printf("%d", coefficientTemp);
				}
				else {
					if (abs(coefficientTemp) != 1) {
						printf("%d", coefficientTemp);
					}
					else if (coefficientTemp == -1) {
						printf("-");
					}
					printf("x");
					if (8 - i > 1) {
						printf("^%d", 8 - i);
					}
				}
				firstTerm = true;
			}
		}
		if (!firstTerm) {
			printf("0");
		}
		printf("\n");
	}
	return 0;
}



#include<iostream>
int main()
{
	int co[8];
	while (~scanf("%d", &co[0])) {
		for (int i = 1; i <= 8; i++)
			scanf("%d", &co[i]);
		bool F = false;
		for (int i = 0; i <= 8; i++) {
			if (co[i] != 0) {
				int temp = co[i];
				if (F) {
					temp = abs(temp);
					if (co[i] > 0)
						printf(" + ");
					else
						printf(" - ");
				}
				if (i == 8)
					printf("%d", temp);
				else {
					if (abs(temp) != 1)
						printf("%d", temp);
					else if (temp == -1)
						printf("-");
					printf("x");
					if (8 - i > 1)
						printf("^%d", 8 - i);
				}
				F = true;
			}
		}
		if (!F)
			printf("0");
		puts("");
	}
}



Given the coefficients of a polynomial from degree 8 down to 0, 
you are to format the polynomial in a readable format with 
unnecessary characters removed. For instance, 
given the coefficients 0, 0, 0, 1, 22,
-333, 0, 1, and -1, you should generate an output line which 
displays x^5 + 22x^4 - 333x^3 + x - 1.
The formatting rules which must be adhered to are as follows:
1. Terms must appear in decreasing order of degree.
2. Exponents should appear after a caret “^”.
3. The constant term appears as only the constant.
4. Only terms with nonzero coefficients should appear, 
   unless all terms have zero coefficients in
which case the constant term should appear.
5. The only spaces should be a single space on either side of 
   the binary + and − operators.
6. If the leading term is positive then no sign should precede 
   it; a negative leading term should be preceded by a minus 
   sign, as in -7x^2 + 30x + 66.
7. Negated terms should appear as a subtracted unnegated 
   term (with the exception of a negative leading term which 
   should appear as described above). That is,
   rather than x^2 + -3x, the output should be x^2 - 3x.
8. The constants 1 and -1 should appear only as the constant 
   term. That is, rather than -1x^3 + 1x^2 + 3x^1 - 1,
   the output should appear as -x^3 + x^2 + 3x - 1.
   
   
   
Input
The input file will contain one or more lines of coefficients 
delimited by one or more spaces. There are
nine coefficients per line, each coefficient being an integer 
with a magnitude of less than 1000.

Output
The output file should contain the formatted polynomials, 
one per line.



Sample Input
0 0 0 1 22 -333 0 1 -1
0 0 0 0 0 0 -55 5 0
Sample Output
x^5 + 22x^4 - 333x^3 + x - 1
-55x^2 + 5x