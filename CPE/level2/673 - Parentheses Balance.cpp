673 - Parentheses Balance  



#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int n;
	string s;
	stack<char> stk;
	bool correct;
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			correct = 1;
			while (!stk.empty()) stk.pop();
			for (int j = 0; j < s.length(); j++) {
				if (s[j] == '(' || s[j] == '[')
					stk.push(s[j]);
				else if (s[j] == ')') {
					if (stk.empty() || stk.top() != '(') {
						correct = 0;
						break;
					}
					stk.pop();
				}
				else if (s[j] == ']') {
					if (stk.empty() || stk.top() != '[') {
						correct = 0;
						break;
					}
					stk.pop();
				}
			}
			if (!stk.empty()) correct = 0;
			printf(((correct) ? "Yes\n" : "No\n"));
		}
	}
	return 0;
}



#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	getchar();
	while (n--) {
		stack<char>stk = {};
		string str;
		bool F = 1;
		getline(cin, str);
		for (int i = 0; i < str[i]; i++) {
			if (str[i] == '(' || str[i] == '[')
				stk.push(str[i]);
			else if (str[i] == ')') {
				if (stk.empty() || !stk.top() == '(') {
					F = 0;
					break;
				}
				stk.pop();
			}
			else if (str[i] == ']') {
				if (stk.empty() || !stk.top() == '[') {
					F = 0;
					break;
				}
				stk.pop();
			}
		}
		if (!stk.empty())
			F = 0;
		if (F)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}


You are given a string consisting of parentheses () and []. A string of 
this type is said to be correct:
(a) if it is the empty string
(b) if A and B are correct, AB is correct,
(c) if A is correct, (A) and [A] is correct.
Write a program that takes a sequence of strings of this type and check 
their correctness. Your program can assume that the maximum string 
length is 128.



Input
The file contains a positive integer n and a sequence of n strings of 
parentheses ‘()’ and ‘[]’, one string
a line.

Output
A sequence of ‘Yes’ or ‘No’ on the output file.



Sample Input
3
([])
(([()])))
([()[]()])()

Sample Output
Yes
No
Yes



8
([] )
(([()])))
([()[]()])()
(
(]
)(
][
([)]

Yes
No
Yes
No
No
No
No
No