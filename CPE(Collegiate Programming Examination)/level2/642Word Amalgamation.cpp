642	Word Amalgamation



#include <iostream>
#include <algorithm>
#include<string>
#include <map>
#include <set>
using namespace std;

int main() {
	string word, origin;
	map<string, set<string> > o;
	while (cin >> word) {
		if (word == "XXXXXX") {
			break;
		}
		origin = word;
		sort(word.begin(), word.end());
		o[word].insert(origin);
	}
	while (cin >> word) {
		if (word == "XXXXXX") {
			break;
		}
		origin = word;
		sort(word.begin(), word.end());
		int flag = 0;
		for (set<string>::iterator it = o[word].begin(); it != o[word].end(); it++) {
			cout << *it << endl;
			flag = 1;
		}
		if (!flag)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}



#include <iostream>
#include <algorithm>
#include<string>
#include <map>
#include <set>
using namespace std;

int main() {
	string w, origin;
	map<string, set<string> > o;
	while (cin >> w) {
		if (w == "XXXXXX") 
			break;

		origin = w;
		sort(w.begin(), w.end());
		o[w].insert(origin);
	}
	while (cin >> w) {
		if (w == "XXXXXX") 
			break;

		origin = w;
		sort(w.begin(), w.end());
		int flag = 0;
		for (set<string>::iterator it = o[w].begin(); it != o[w].end(); it++) {
			cout << *it << endl;
			flag = 1;
		}
		if (!flag)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
	return 0;
}



#include<iostream>
#include<set>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string origin, w;
	map<string, set<string>>o;
	while (cin >> w) {
		if (w == "XXXXXX")
			break;
		origin = w;
		sort(w.begin(), w.end());
		o[w].insert(origin);
	}
	while (cin >> w) {
		if (w == "XXXXXX")
			break;
		sort(w.begin(), w.end());
	
		int flag = 0;
		for (set<string>::iterator it=o[w].begin();it != o[w].end(); it++)
			flag = 1, cout << *it << endl;
		if (!flag)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}
}



algorithm
tarp

origin = w;
sort(w.begin(), w.end());
o[w].insert(origin);

w ->artp
insert(tarp)

o[artp]
(part)
(tarp)
(trap)
#dicotionary form by set function


In millions of newspapers across the United States there is a word 
game called Jumble. The object of this game is to solve a riddle, 
but in order to find the letters that appear in the answer it is 
necessary to unscramble four words. Your task is to write a 
program that can unscramble words.



Input
The input file contains four parts:
1. a dictionary, which consists of at least one and at most 100 
   words, one per line;
2. a line containing ‘XXXXXX’, which signals the end of the 
   dictionary;
3. one or more scrambled ‘words’ that you must unscramble, 
   each on a line by itself; and
4. another line containing ‘XXXXXX’, which signals the end of the 
   file.
All words, including both dictionary words and scrambled words, 
consist only of lowercase English letters and will be at least 
one and at most six characters long. (Note that the sentinel 
‘XXXXXX’ contains uppercase X’s.) 
The dictionary is not necessarily in sorted order, 
but each word in the dictionary is unique.

Output
For each scrambled word in the input, output an alphabetical list 
of all dictionary words that can be formed by rearranging the 
letters in the scrambled word. Each word in this list must appear 
on a line by itself. If the list is empty (because no dictionary 
words can be formed), output the line ‘NOT A VALID WORD’ instead. 
In either case, output a line containing six asterisks to signal 
the end of the list.



Sample Input
tarp
given
score
refund
only
trap
work
earn
course
pepper
part
XXXXXX
resco
nfudre
aptr
sett
oresuc
XXXXXX

Sample Output
score
******
refund
******
part
tarp
trap
******
NOT A VALID WORD
******
course
******