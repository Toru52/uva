483 - Word Scramble



#include<cstdio>
#include<stack>
using namespace std;
stack<char> s;

int main() {
	char c;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n') {
			while (s.size() != 0) {
				putchar(s.top());
				s.pop();
			}
			putchar(c);
		}
		else 
			s.push(c);
	}
}



#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<char>s;
	char c;
	while (~(c = getchar())) {
		if (c == ' ' || c == '\n') {
			while (s.size()) {
				putchar(s.top());
				s.pop();
			}
			putchar(c);
		}
		else
			s.push(c);
	}
}


Write a program that will reverse the letters in each of a 
sequence of words while preserving the order
of the words themselves.



Input
The input file will consist of several lines of several words. 
Words are contiguous stretches of printable
characters delimited by white space.
Output
The output will consist of the same lines and words as the input file. However, the letters within each
word must be reversed.
Sample Input
I love you.
You love me.
We're a happy family.
Sample Output
I evol .uoy
uoY evol .em
er'eW a yppah .ylimaf