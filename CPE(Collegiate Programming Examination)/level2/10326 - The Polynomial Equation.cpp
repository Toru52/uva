10326 - The Polynomial Equation
https://github.com/Hikari9/UVa/blob/master/10326%20-%20The%20Polynomial%20Equation.cpp



#include<iostream>
#include<vector>
using namespace std;
typedef long long lag;

int main() {
	int n, i, j;
	char sign;
	while (cin >> n) {
		vector<lag> f = {};
		f.push_back(1LL);
		for (i = 0; i<n; ++i) {
			lag root,temp[55] = {};
			cin >> root;
			root = -root;
			for (j = 0; j<f.size(); ++j) {
				//by polynomial equation
				//	printf("temp[%d] = %d ", j, temp[j] );
				//printf("temp[%d] = %d\n",  j + 1, temp[j + 1]);
				temp[j] += f[j] * root;
				temp[j + 1] += f[j];
			}
			f.assign(temp, temp + j + 1);
			/*   for (int k = 0; k < f.size(); k++)
				printf("f[%d] = %lld\n", k, f[k]);
			puts("");*/
		}
		bool first = true;
		sign = '+';
		for (i = f.size() - 1; i>0; --i) {
			if (f[i]) {
				if (first) first = false;
				else {
					if (f[i]<0) {
						f[i] = -f[i];
						sign = '-';
					}
					else sign = '+';
					cout << sign << ' ';
				}
				if (f[i] != 1) 
					cout << f[i];
				cout << 'x';
				if (i != 1) 
					cout << '^' << i;	
				cout << ' ';
			}
		}
		if (f[0]<0) {
			f[0] = -f[0];
			sign = '-';
		}
		else sign = '+';
		cout << sign << ' ' << f[0] << " = 0" << endl;
	}
}



#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int i, j, n;
	while (~scanf("%d", &n)) {
		vector<ll>f = {};
		f.push_back(1LL);
		for (i = 0; i < n; i++) {
			ll root, temp[55] = {};
			cin >> root;
			root = -root;
			for (j = 0; j < f.size(); j++) {
				temp[j] += f[j] * root;
				temp[j + 1] += f[j];
			}
			f.assign(temp, temp + j + 1);
		}
		char sign = '+';
		bool first = true;
		for (i = f.size() - 1; i > 0; i--) {
			if (f[i]) {
				if (first)
					first = false;
				else {
					if (f[i] < 0)
						f[i] = -f[i], sign = '-';
					else
						sign = '+';
					cout << sign<<' ';
				}
				if (f[i] != 1)
					cout << f[i];
				cout << 'x';
				if (i != 1)
					cout<<'^'<<i;
				cout << ' ';
			}
		}
		if (f[0] < 0)
			f[0] = -f[0], sign = '-';
		else
			sign = '+';
		cout << sign <<' '<<f[0]<< ' ' << "= 0" << endl;
	}
}



A Polynomial equation of degree
n
is de ned as follows :
C
0
+
n
∑
i
=1
(
C
i

x
i
) = 0
:
A polynomial equation of
n
degree can have at most
n
distinct roots which may be both real or
complex. Such as a quadratic equation :
x
2


has two roots 2 and 3. In this problem you have to generate such a 
polynomial equation whose roots are already given.

Input
The input will start with a positive integer
N
indicating the number of roots of the polynomial equation.
The next line will contain the roots each of which is an integer.
N
will not exceed 50.
Input is terminated by EOF.

Output
You have to show the polynomial using
x
as a variable. If coefficient of any term
x
i
(
i >
0) becomes
zero then you need not show that term. In case of coeffecient being 
1 only print
x
^
i
(
i >
0). Again if the constant term is zero always use `
+ 0
'. See sample output for more clari cation.
You can be sure that no coeffecient will exceed 10
15
.



SampleInput
2
2 3
2
-2 -3
3
0 1 -1

SampleOutput
x^2 - 5x + 6 = 0
x^2 + 5x + 6 = 0
x^3 - x + 0 = 0



