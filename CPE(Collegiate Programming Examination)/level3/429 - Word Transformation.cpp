429 - Word Transformation
https://github.com/morris821028/UVa/blob/master/volume004/424%20-%20Integer%20Inquiry.cpp



#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		vector<string> words;
		string word, line;
		while (cin >> word, word != "*")
			words.push_back(word);
		cin.ignore();
		while (getline(cin, line) && line != "") {
			stringstream ss(line);
			string s, e;
			ss >> s >> e;
			queue<string> q;
			map<string, int> trans;
			trans[s] = 0;
			q.push(s);
			while (!q.empty() && !trans.count(e)) {
				string u = q.front();
				q.pop();
				for (int  i = 0; i < words.size(); ++i) {
					const string &v = words[i];
					if (!trans.count(v) && u.length() == v.length()) {
						int diff = 0;
						for (int j = 0; j < u.length(); ++j)
							if (u[j] != v[j])
								++diff;
							//difference a character in words
							//count by use map 
						if (diff == 1)
							trans[v] = trans[u] + 1, q.push(v);
					}
				}
			}
			cout << s << " " << e << " " << trans[e] << endl;
		}
		if (cas)
			puts("");
	}
	return 0;
}



#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
int main() {
	int cas;
	scanf("%d", &cas);
	while (cas--) {
		vector<string>word;
		string s;
		while (cin >> s, s != "*")
			word.push_back(s);
		cin.ignore();
		while (getline(cin, s), s != "") {
			stringstream ss(s);
			map<string,int>trans;
			queue<string>q;
			string s, e;
			ss >> s >> e;
			trans[s] = 0;
			q.push(s);
			while (!q.empty()&&!trans.count(e)) {
				string u = q.front();
				q.pop();
				for (int i = 0; i < word.size(); i++) {
					const string &v = word[i];
					if (!trans.count(v) && u.length() == v.length()) {
						int dif = 0;
						for (int j = 0; j < v.length(); j++)
							if (u[j] != v[j])
								dif++;
						if (dif == 1) 
							trans[v] = trans[u] + 1, q.push(v);
					}
				}
			}
			cout << s << " " << e << " " << trans[e] << endl;
		}
		if (cas)
			puts("");
	}
	return 0;
}



/*
ex 
spice stock
(a character change by a turn)
spice->slice->slick->stick->stock
->4
*/
A common word puzzle found in many newspapers and magazines is the 
word transformation. By taking a starting word and successively 
altering a single letter to make a new word, one can build a 
sequence of words which changes the original word to a given end 
word. For instance, the word “spice” can be transformed in four 
steps to the word “stock” according to the following sequence:
spice, slice, slick, stick, stock. Each successive word differs 
from the previous word in only a single character position while 
the word length remains the same.
Given a dictionary of words from which to make transformations, 
plus a list of starting and ending words, 
your team is to write a program to determine the number of steps in 
the shortest possible transformation.



Input
The first line of the input is an integer N, indicating the number 
of test set that your correct program should test followed by a 
blank line.
Each test set will have two sections. 
The first section will be the dictionary of available words with
one word per line, terminated by a line containing an asterisk (*) 
rather than a word. There can be up to 200 words in the dictionary; 
all words will be alphabetic and in lower case, 
and no word will be longer than ten characters. 
Words can appear in the dictionary in any order.
Following the dictionary are pairs of words, one pair per line, 
with the words in the pair separated by a single space. 
These pairs represent the starting and ending words in a 
transformation. All pairs are guaranteed to have a transformation 
using the dictionary given. 
The starting and ending words will appear in the dictionary.
Two consecutive input set will separated by a blank line.

Output
The output should contain one line per word pair for each test set, 
and must include the starting word,
the ending word, and the number of steps in the shortest possible 
transformation, separated by single spaces.
Two consecutive output set will be separated by a blank line.



Sample Input
1
dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

Sample Output
spice stock 4
may pod 3


