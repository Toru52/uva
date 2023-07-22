465 - Overflow
https://github.com/morris821028/UVa/blob/master/volume004/465%20-%20Overflow.cpp



#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main() {
	double a, b;
	int INF = 2147483647;
	char op;
	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		cout << s << endl;
		ss >> a >> op >> b;
		if (a > INF)
			cout << "first number too big\n";
		if (b > INF)
			cout << "second number too big\n";
		if (op == '+' && a + b > INF)
			cout << "result too big\n";
		if (op == '*' && a*b > INF)
			cout << "result too big\n";
	}
	return 0;
}



#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main() {
	int inf = -1u >> 1;
	double a, b;
	char op;
	string s;
	while (getline(cin, s)) {
		stringstream ss(s);
		cout << s << endl;;
		ss >> a >> op >> b;
		if (a > inf)
			cout << "first number too big\n";
		if (b > inf)
			cout << "second number too big\n";
		if (op == '+'&&a + b > inf)
			cout << "result too big\n";
		if (op == '*'&&a*b > inf)
			cout << "result too big\n";
	}
	return 0;
}



Write a program that reads an expression consisting of 
two non-negative integer and an operator.
Determine if either integer or the result of the 
expression is too large to be represented as a “normal”
signed integer (type integer if you are working Pascal, 
type int if you are working in C).



Input
An unspecified number of lines. Each line will contain an 
integer, one of the two operators ‘+’ or ‘*’, 
and another integer.

Output
For each line of input, print the input followed by 0-3 
lines containing as many of these three messages
as are appropriate: ‘first number too big’, 
‘second number too big’, ‘result too big’.



Sample Input
300 + 3
9999999999999999999999 + 11

Sample Output
300 + 3
9999999999999999999999 + 11
first number too big
result too big
