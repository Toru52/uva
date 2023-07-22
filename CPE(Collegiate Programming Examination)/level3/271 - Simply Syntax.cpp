271 - Simply Syntax
http://blog.tobygameac.com/2013/09/uva-271-simply-syntax.html



#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	char s[999];
	while (fgets(s,sizeof(s),stdin)) {
		stack<char> exp;
		bool ok = true;
		//from oppsite side
		for (int i = strlen(s) - 1; ok && i >= 0; i--) 
			if (s[i] >= 'p' && s[i] <= 'z') 
				exp.push(s[i]);
			else if (s[i] == 'N') {
				if (!exp.size()) 
					ok = false;
			}
			else if (s[i] == 'C' || s[i] == 'D' || 
				     s[i] == 'E' || s[i] == 'I') {
				if (exp.size() >= 2) 
					exp.pop();
				else 
					ok = false;
			}
		puts((exp.size() == 1 && ok) ? "YES" : "NO");
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<stack>
using namespace std;
int main() {
	char s[1024]{};
	while (fgets(s, sizeof(s), stdin)) {
		stack<char>S;
		bool ok = true;
		for (int i = strlen(s) - 1; i >= 0 && ok; i--)
			if ('p' <= s[i] && s[i] <= 'z')
				S.push(s[i]);
			else if (s[i] == 'N') {
				if (!S.size())
					ok = false;
			}
			else if (s[i] == 'C' || s[i] == 'D' ||
				s[i] == 'E' || s[i] == 'I') {
				if (S.size() >= 2)
					S.pop();
				else
					ok = false;
			}
			puts((ok&&S.size() == 1) ? "YES" : "NO");
	}
	return 0;
}



In the land of Hedonia the official language is Hedonian. 
A Hedonian professor had noticed that many of her students still did 
not master the syntax of Hedonian well. Tired of correcting the many 
syntactical mistakes, she decided to challenge the students and asked 
them to write a program that could check the syntactical correctness 
of any sentence they wrote. Similar to the nature of Hedonians, 
the syntax of Hedonian is also pleasantly simple. Here are the rules:
0. The only characters in the language are the characters ‘p’ through 
‘z’ and ‘N’, ‘C’, ‘D’, ‘E’, and ‘I’.
1. Every character from ‘p’ through ‘z’ is a correct sentence.
2. If s is a correct sentence, then so is Ns.
3. If s and t are correct sentences, then so are Cst, Dst, Est and Ist.
4. Rules 0. to 3. are the only rules to determine the syntactical 
correctness of a sentence. You are asked to write a program that checks 
if sentences satisfy the syntax rules given in Rule 0. - Rule 4.



Input
The input consists of a number of sentences consisting only of characters 
‘p’ through ‘z’ and ‘N’, ‘C’, ‘D’, ‘E’, and ‘I’. 
Each sentence is ended by a new-line character. 
The collection of sentences is terminated by the end-of-file character. 
If necessary, you may assume that each sentence has at most 256 characters
and at least 1 character.

Output
The output consists of the answers ‘YES’ for each well-formed sentence and 
‘NO’ for each not-wellformed sentence. 
The answers are given in the same order as the sentences. 
Each answer is followed by a new-line character, and the list of answers is 
followed by an end-of-file character.



Sample Input
Cp
Isz
NIsz
Cqpq

Sample Output
NO
YES
YES
NO