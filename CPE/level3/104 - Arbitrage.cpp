104 - Arbitrage
http://alan790712.pixnet.net/blog/post/73504112-%5Buva%5D-104---arbitrage
concept
http://www.cnblogs.com/scau20110726/archive/2012/12/26/2834674.html



#include <stdio.h>
#include<string.h>
double pro[30][30][30];
int pre[30][30][30];
void printPath(int s, int i, int j) {
	if (s <= 0)return;
	printPath(s - 1, i, pre[s][i][j]);
	printf(" %d", pre[s][i][j] + 1);
}
int main() {
	int n,i, j,k, s;
	while (scanf("%d", &n) ==1) {
		memset(pro, 0, sizeof(pro));
		memset(pre, 0, sizeof(pre));
		for (i = 0; i<n; ++i) 
			for (j = 0; j<n; ++j) 
				if (i == j)
					pro[0][i][j] = 1.0;//standard starting currency rate
				else 
					scanf("%lf", &pro[0][i][j]);
		//s->dimention times
		for (s = 1; s<n; ++s) {
			for (k = 0; k<n; ++k) 
				for (i = 0; i<n; ++i) 
					for (j = 0; j<n; ++j) 
						if (pro[s][i][j] < pro[s - 1][i][k] * pro[0][k][j]) {
							pro[s][i][j] = pro[s - 1][i][k] * pro[0][k][j];
							pre[s][i][j] = k;
						}
			//whether standard rate be higher or not.
			for (i = 0; i<n; ++i) 
				if (pro[s][i][i] > 1.01)
					break;
			if (i<n)
				break;
		}
		if (s == n)
			puts("no arbitrage sequence exists");
		else {
			printf("%d", i + 1);
			printPath(s, i, i);
			printf(" %d\n", i + 1);
		}
	}
	return 0;
}



#include<stdio.h>
void Kpath(int s, int i, int j,int pre[][25][25]) {
	if(s<1)return;
	Kpath(s - 1, i, pre[s][i][j],pre);
	printf(" %d", pre[s][i][j] + 1);
}
int main() {
	int n, s, k, i, j;
	while (scanf("%d", &n) == 1) {
		double pro[25][25][25]{};
		int pre[25][25][25]{};
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (i == j)
					pro[0][i][j] = 1.0;
				else
					scanf("%lf", &pro[0][i][j]);	
		for (s = 1; s < n; s++) {
			for (k = 0; k < n; k++)
				for (i = 0; i < n; i++)
					for (j = 0; j < n; j++)
						if (pro[s][i][j] < pro[s - 1][i][k] * pro[0][k][j]) {
							pro[s][i][j] = pro[s - 1][i][k] * pro[0][k][j];
							pre[s][i][j] = k;
						}
			for (i = 0; i < n; i++)
				if (pro[s][i][i] > 1.01)
					break;
			if (i < n)
				break;
		}
		if (s == i)
			puts("no arbitrage sequence exists");
		else {
			printf("%d", i + 1);
			Kpath(s, i, i,pre);
			printf(" %d\n", i + 1);
		}
	}
	return 0;
}



/*
concept 
dimensions of the table ->update times
problem ex
US(1)->British(0.7)->france(9.5)->US(0.95)
->(1.064)

image(floyed warshall)
A->C(1.5)
A->B(2)
B->C(3)
A->C(1.5) < A->B(2)*B->C(3)
->update A->C(6)



ex1
1     1.2  0.89
0.88    1   5.1
1.1  0.15     1

*2(1)  2(0)  6(1)
 5(2)  2(0)  5(1)
 2(0)  2(0)   no



ex2
1        3.1   0.0023    0.35
0.21       1  0.00353    8.13
200  180.559        1  10.339
2.11   0.089  0.06111       1

s=1(i=2)
no(0)       3(0)   no  *25(1)
17(3)    no(1)     no   8(1)
200(0)  620(0)  no(2)  70(1)
12(2)    11(2)  no     no(3) 

s=2(i=4)
*53(3)    3(0)   2(3)    25(1)
99(2)    89(2)   no       8(1)
2(3)   3097(0)  89(3)  5040(1)
12(0)    37(0)   no     *89(1)
*/



The use of computers in the finance industry has been marked 
with controversy lately as programmed trading —
designed to take advantage of extremely small fluctuations 
in prices — has been outlawed at many Wall Street firms. 
The ethics of computer programming is a fledgling field with 
many thorny issues.
Arbitrage is the trading of one currency for another with 
the hopes of taking advantage of small differences in 
conversion rates among several currencies in order to 
achieve a profit. For example, if $1.00 in U.S. currency buys
0.7 British pounds currency, £1 in British currency buys 9.5
French francs, and 1 French franc buys 0.16 in U.S. dollars, 
then an arbitrage trader can start with $1.00 and earn
1  0:7  9:5  0:16 = 1:064 dollars thus earning a 
profit of 6.4 percent.
You will write a program that determines whether a sequence 
of currency exchanges can yield a profit as described above.
To result in successful arbitrage, a sequence of exchanges 
must begin and end with the same currency,
but any starting currency may be considered.



Input
The input file consists of one or more conversion tables. 
You must solve the arbitrage problem for each
of the tables in the input file.
Each table is preceded by an integer n on a line by itself 
giving the dimensions of the table. 
The maximum dimension is 20; the minimum dimension is 2.
The table then follows in row major order but with the 
diagonal elements of the table missing 
(these are assumed to have value 1.0). 
Thus the first row of the table represents the conversion 
rates between country 1 and n 􀀀 1 other countries, i.e., 
the amount of currency of country i (2  i  n) that 
can be purchased with one unit of the currency of country 1.
Thus each table consists of n+1 lines in the input file: 
1 line containing n and n lines representing
the conversion table.

Output
For each table in the input file you must determine whether 
a sequence of exchanges exists that results in a profit of 
more than 1 percent (0.01). 
If a sequence exists you must print the sequence of 
exchanges that results in a profit. 
If there is more than one sequence that results in a profit 
of more than 1 percent
you must print a sequence of minimal length, i.e., 
one of the sequences that uses the fewest exchanges
of currencies to yield a profit.
Because the IRS (United States Internal Revenue Service) 
notices lengthy transaction sequences,
all profiting sequences must consist of n or fewer 
transactions where n is the dimension of the table
giving conversion rates. The sequence 1 2 1 represents two 
conversions.
If a profiting sequence exists you must print the sequence 
of exchanges that results in a profit.
The sequence is printed as a sequence of integers with the 
integer i representing the i-th line of the
conversion table (country i). 
The first integer in the sequence is the country from which 
the profiting sequence starts. 
This integer also ends the sequence.
If no profiting sequence of n or fewer transactions exists, 
then the line no arbitrage sequence exists should be printed.



Sample Input
3
1.2 .89
.88 5.1
1.1 0.15
4
3.1 0.0023 0.35
0.21 0.00353 8.13
200 180.559 10.339
2.11 0.089 0.06111
2
2.0
0.45

Sample Output
1 2 1
1 2 4 1
no arbitrage sequence exists

