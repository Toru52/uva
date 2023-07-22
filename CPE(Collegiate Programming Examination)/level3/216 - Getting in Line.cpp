216 - Getting in Line
https://github.com/Hikari9/UVa/blob/master/245%20-%20Uncompress.cpp


#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> v;
	string buf, word;
	while (getline(cin, buf), buf != "0") {
		word.clear();
		for (int i = 0; i<buf.size(); ++i) {
			//alpha
			if (isalpha(buf[i])) {
				word.clear();
				word.push_back(buf[i]);
				while (++i < buf.size()) 
					if (isalpha(buf[i])) 
						word.push_back(buf[i]);
				else {//space or num or symbol
						--i;
						//i is positioned at 
						//last character of word 
						break;
					}
				v.push_back(word);
				cout << word;
			}
			//num
			else if (isdigit(buf[i])) {
				int x = buf[i] - '0';
				while (++i < buf.size()) 
					// if input num is two digit or more digitt num
					if (isdigit(buf[i])) 
						x *= 10,x += buf[i] - '0';
					else {
						--i;
						break;
					}
				word = *(v.end() - x);
				v.erase(v.end() - x);
				//A word that used once can not use again
				v.push_back(word);
				cout << word;
			}
			//symbol
			else cout << buf[i];
		}
		puts("");
	}
	return 0;
}



#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	string buf, word;
	vector<string>v;
	while (getline(cin, buf), buf != "0") {
		word.clear();
		for (int i = 0; i < buf.size(); i++) {
			if (isalpha(buf[i])) {
				word.clear();
				word.push_back(buf[i]);
				while (++i < buf.size())
					if (isalpha(buf[i]))
						word.push_back(buf[i]);
					else { i--; break; }
					v.push_back(word);
					cout << word;
			}
			else if (isdigit(buf[i])) {
				int x = buf[i] - '0';
				while (++i < buf.size())
					if (isdigit(buf[i]))
						x = x * 10 + buf[i] - '0';
					else { i--; break; }
				word = *(v.end() - x);
				v.erase(v.end() - x);
				v.push_back(word);
				cout << word;
			}
			else cout << buf[i];
		}
		puts("");
	}
	return 0;
}



A simple scheme for creating a compressed version of a text le 
can be used for les which contain no digit characters. 
The compression scheme requires making a list of the words in the 
uncompressed le.
When a non-alphabetic character is encountered in the uncompressed 
le, it is copied directly into the compressed le. 
When a word is encountered in the uncompressed le, 
it is copied directly into the compressed le only 
if this is the rst occurrence of the word. In that case, 
the word is put at the front of the list. 
If it is not the rst occurrence, 
the word is not copied to the compressed le. Instead, 
its position in the list is copied into the compressed le and 
the word is moved to the front of the list. 
The numbering of list positions begins at 1.
Write a program that takes a compressed le as input and generates 
a reproduction of the original uncompressed le as output.



Input
You can assume that no word contains more than 50 characters and 
that the original uncompressed le contains no digit characters.
For the purposes of this problem, a word is dened to be a maximal 
sequence of upper- and lower- case letters. Words are 
case-sensitive | the word `abc' is not the same as the word `Abc'. 
For example, x-ray contains 2 words: x and ray
Mary's contains 2 words: Mary and s
It's a winner contains 4 words: It and s and a and winner
There is no upper limit on the number of different words in the 
input le. The end of the input le is signied by the number 
`0' on a line by itself. 
The terminating `0' merely indicates the end of the input and 
should not be part of the output produced by your program.

Output
See the sample output below for details of the output format.



Sample Input
Dear Sally,
Please, please do it--1 would 4
Mary very, 1 much. And 4 6
8 everything in 5's power to make
14 pay off for you.
-- Thank 2 18 18--
0

Sample Output
Dear Sally,
Please, please do it--it would please
Mary very, very much. And Mary would
do everything in Mary's power to make
it pay off for you.
-- Thank you very much--