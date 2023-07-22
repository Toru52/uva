257 - Palinwords
http://mypaper.pchome.com.tw/zerojudge/post/1324680705



#include <stdio.h>
#include <string.h>
#include <set>
using namespace std;
int main() {
	int  x, y;
	char s[1024];
	while (scanf("%s", s) == 1) {
		string word(s), odd, even;
		set<string> S;
		for (int i = 1; s[i]; i++) {
			x = i, y = i;// odd length
			//i->center,y->right,x->left 
			//word length
			//s[x]==s[y] -> whether right part and left part are same or not
			while (x >= 0 && s[x] == s[y]) {
				x--, y++;
				if (y - x - 1 == 3)  break;
			}
		//	printf("x %d y %d", x, y);
			odd = word.substr(x + 1, y - x - 1);
		//	cout << " odd "<<odd;
			if (odd.length() >= 3)
				S.insert(odd);
			//adjacent character is same
			//ex AAAA
			if (s[i] == s[i + 1]) {
				x = i, y = i + 1;
				while (x >= 0 && s[x] == s[y]) {
					x--, y++;
					if (y - x - 1 == 4)  break;
				}
				even = word.substr(x + 1, y - x - 1);
				if (even.length() >= 3)
					S.insert(even);
			}
		//	cout << " even " << even << endl;
		}
		int found = 0;
		for (set<string>::iterator it = S.begin();
			it != S.end(); it++) {
			for (set<string>::iterator jt = it;
				jt != S.end(); jt++) {
				if (it == jt)    continue;
				if ((*jt).find(*it) == string::npos &&
					(*it).find(*jt) == string::npos) {
					printf("%s\n", s);
					found = 1;
				}
				if (found)   break;
			}
			if (found)   break;
		}
	}
	return 0;
}



#include<iostream>
#include<string>
#include<set>
using namespace std;
int main() {
	char s[1024];
	int x, y;
	while (scanf("%s", s) == 1) {
		set<string>S;
		string word(s), odd, even;
		for (int i = 0; s[i]; i++) {
			x = i, y = i;
			while (x >= 0 && s[x] == s[y]) {
				x--, y++;
				if (y - x - 1 == 3)break;
			}
			odd = word.substr(x + 1, y - x - 1);
			if (odd.length() >= 3)S.insert(odd);
			if (s[i] == s[i + 1]) {
				x = i, y = i+1;
				while (x >= 0 && s[x] == s[y]) {
					x--, y++;
					if (y - x - 1 == 4)break;
				}
				even = word.substr(x + 1, y - x - 1);
				if (even.length() >= 3)S.insert(even);
			}
		}
		int found = 0;
		for (set<string>::iterator it = S.begin();
			it != S.end(); it++) {
			for (set<string>::iterator jt = it;
				jt != S.end(); jt++) {
				if (it == jt)continue;
				if ((*jt).find(*it) == string::npos &&
					(*it).find(*jt) == string::npos)
					puts(s), found = 1;
				if (found)break;
			}
			if (found)break;
		}
	}
	return 0;
}



/*
A palinword is a string of characters that contains 
at least 2 different palindromes each with a length of at least 3.
->represent if make that 3 character is palindrome in word,then ok
Don't have to 5,7 character parindrome in word

ex
MOEILIJKHEDEN
ILIJKHEDE
VERNEDEREN
NEDERE
AMAMA
AMAM
MUMMUM
MUMMU
*/
A palindrome is a string of characters which can be read forward and 
backward and still result in the same word, e.g. ‘mumdadmum’. 
So by definition the empty string, all strings containing 1 character, 
and all strings containing 2 equal characters are palindromes. 
The length of a palindrome is the number of characters in the 
palindrome.
A palinword is a string of characters that contains at least 2 
different palindromes each with a lengthof at least 3. 
(Here the position is immaterial: 
the same palindrome occurring in another position is not considered 
as different.) Neither of these 2 palindromes may be embedded in the 
other palindrome
(for example the palindrome ‘mum’ is embedded in the palindrome ‘amuma’, 
and ‘aaa’ is embedded in ‘aaaa’)
but they may partially overlap. Also see the examples below.
Your program’s task is to copy only the palinwords from the input file 
to the output file.



Input
The input for your program is a textfile. Each line in this file is 
empty or consists of one or more words
(uppercase letters ‘A’ through ‘Z’ only) 
separated by one or more spaces (each line in the input file contains 
at most 255 characters in all).

Output
The output file is a textfile and must have one palinword per line in 
order of occurrence in the input file.



Sample Input
MOEILIJKHEDEN INVOER
VERNEDEREN
AMUMA AMAMA MUMMUM
AMATRAMA AAAA
ABATRABAR
DUMMY
WORDS

Sample Output
MOEILIJKHEDEN
VERNEDEREN
AMAMA
MUMMUM
