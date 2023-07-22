490	Rotating Sentences



#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s;
	vector<string> v;
	int n = -1;

	while (getline(cin, s)) {
		v.push_back(s);
		n = max(n, (int)s.size());
	}
	vector<string> u(n, "");
	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = 0; j<v[i].size(); j++) 
			u[j] += v[i][j];
		for (int j = v[i].size(); j<n; j++)
			u[j] += " ";
	}
	for (int i = 0; i<n; i++) 
		cout << u[i] << endl;
}



#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	vector<string>v;
	int n=-1;
	while (getline(cin, s)) {
		v.push_back(s);
		n = max(n, (int)s.size());
	}
	vector<string>u(n,"");

	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = 0; j < v[i].size(); j++)
			u[j] += v[i][j];
		for (int j = v[i].size(); j < n; j++)
			u[j] += " ";
	}
	for (int i = 0; i < n; i++)
		cout << u[i] << endl;
}



In “Rotating Sentences,” you are asked to rotate a series 
of input sentences 90 degrees clockwise. So
instead of displaying the input sentences from left to 
right and top to bottom, your program will display
them from top to bottom and right to left.



Input
As input to your program, you will be given a maximum of 
100 sentences, each not exceeding 100 characters long. 
Legal characters include: newline, space, any punctuation 
characters, digits, and lower case or upper case English 
letters. (NOTE: Tabs are not legal characters.)

Output
The output of the program should have the last sentence 
printed out vertically in the leftmost column;
the first sentence of the input would subsequently end up 
at the rightmost column.



Sample Input
Rene Decartes once said,
"I think, therefore I am."

Sample Output
"R
Ie
n
te
h
iD
ne
kc
,a
r
tt
he
es
r
eo
fn
oc
re
e
s
Ia
i
ad
m,
.
"