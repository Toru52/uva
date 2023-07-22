195 - Anagram
https://github.com/Diusrex/UVA-Solutions/blob/master/195%20Anagram.cpp
http://knightzone.org/?p=2790



#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// There are two condition in function of compare
//ex compare A and a
bool compare(char a, char b) {
	//A and a -> true if condition
	//since A(65) is lower than a(97)
	//A before a
	if (tolower(a) == tolower(b)) return a < b;
	else return tolower(a) < tolower(b);
}

int main() {
	int n;
	while (scanf("%d", &n) ==1) {
		string s;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			sort(s.begin(), s.end(), compare);
			do {
				printf("%s\n", s.c_str());
			} while (next_permutation(s.begin(), s.end(), compare));
		}
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
char compare(char a, char b) {
	if (tolower(a) == tolower(b))return a<b;
	else return tolower(a) < tolower(b);
}
int main() {
	string s;
	int t;
	scanf("%d", &t);
	while (t--) {
		cin >> s;
		sort(s.begin(), s.end(), compare);
		do {
			printf("%s\n", s.c_str());
		} while (next_permutation(s.begin(), s.end(), compare));
	}
	return 0;
}



You are to write a program that has to generate all possible words from a 
given set of letters.
Example: Given the word “abc”, your program should — by exploring all 
different combination of the three letters — output the words “abc”, “acb”, 
“bac”, “bca”, “cab” and “cba”.
In the word taken from the input file, some letters may appear more than 
once. For a given word,
your program should not produce the same word more than once, 
and the words should be output in alphabetically ascending order.



Input
The input file consists of several words. The first line contains a number 
giving the number of words to follow. Each following line contains one word. 
A word consists of uppercase or lowercase letters from ‘A’ to ‘Z’. 
Uppercase and lowercase letters are to be considered different.

Output
For each word in the input file, the output file should contain all 
different words that can be generated with the letters of the given word. 
The words generated from the same input word should be output in
alphabetically ascending order. An upper case letter goes before the 
corresponding lower case letter.



Sample Input
3
aAb
abc
acba

Sample Output
Aab
Aba
aAb
abA
bAa
baA
abc
acb
bac
bca
cab
cba
aabc
aacb
abac
abca
acab
acba
baac
baca
bcaa
caab
caba
cbaa