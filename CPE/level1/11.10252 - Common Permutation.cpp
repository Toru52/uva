11.10252 - Common Permutation

#include<algorithm>
#include<cstdio>
#include<iostream>
#include <string>
using namespace std;

string a, b;

int main() {
	while (getline(cin, a) && getline(cin, b)) {
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i=0,j=0; ;) {
			if (i >= a.size() || j >= b.size())
				break;
			if (a[i] == b[j]) {
				printf("%c", a[i]);
				i++, j++;
			}
			else {
				if (a[i] > b[j])
					j++;
				else 
					i++;
			}
		}
		printf("\n");
	}
}



Given two strings of lowercase letters, a and b, print the 
longest string x of lowercase letters such that there is a 
permutation of x that is a subsequence of a and there is a 
permutation of x that is a subsequence of b.



Input
Input file contains several lines of input. Consecutive two 
lines make a set of input. That means in the input file 
line 1 and 2 is a set of input, line 3 and 4 is a set of 
input and so on. The first line of a pair contains a and 
the second contains b. Each string is on a separate line 
and consists of at most 1000 lowercase letters.

Output
For each set of input, output a line containing x. 
If several x satisfy the criteria above, choose the first
one in alphabetical order.



Sample Input
pretty
women
walking
down
the
street

Sample Output
e
nw
et