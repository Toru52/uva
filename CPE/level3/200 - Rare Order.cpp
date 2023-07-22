200 - Rare Order
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/II/200%20-%20Rare%20Order.cpp



#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main() {
	vector<string> idx;
	string s;
	int n,cont;
	bool M[26][26]{}, now[26]{};
	char order[26];

	while (cin >> s,s[0]!='#') 
		idx.push_back(s);
	n = idx.size();

	for (int i = 0; i<n - 1; i++) 
		for (int j = 0; j<min(idx[i].size(), idx[i + 1].size()); j++) 
			if (idx[i][j] != idx[i + 1][j]) {
				M[idx[i][j] - 'A'][idx[i + 1][j] - 'A'] = 1;
				now[idx[i][j] - 'A'] = now[idx[i + 1][j] - 'A'] = 1;
			//	printf("%d %d %c %c\n", i, j,idx[i][j], idx[i + 1][j]);
			//
				break;
			}
		//	puts("");
		//make shortest path in alpha root
	for (int k = 0; k<26; k++)
		for (int i = 0; i<26; i++)
			for (int j = 0; j<26; j++)
				M[i][j] |= (M[i][k] && M[k][j]);//,printf("%c %c %d\n", i+'A', j+'A', cont);
	n = 0;
	for (int i = 0; i<26; i++) 
		if (now[i]) {
			n++;
			cont = 0;
			for (int j = 0; j<26; j++)
				if (M[i][j]) 
					cont++;
			order[cont] = 'A' + i;
		}
	for (int i = n - 1; i >= 0; i--) 
		cout << order[i];
	cout << endl;
	return 0;
}



#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	string s;
	vector<string>idx;
	while (cin >> s, s[0] != '#')
		idx.push_back(s);
	int n = idx.size();
	int M[26][26]{}, now[26]{};
	for(int i=0;i<n-1;i++)
		for(int j=0;j<min(idx[i].size(),idx[i+1].size());j++)
			if (idx[i][j] != idx[i + 1][j]) {
				M[idx[i][j] - 'A'][idx[i + 1][j] - 'A'] = 1;
				now[idx[i][j] - 'A'] = 1, now[idx[i + 1][j]- 'A'] = 1;
				break;
			}
	for (int k = 0; k < 26; k++)
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < 26; j++)
				M[i][j] |= (M[i][k] && M[k][j]);
	n = 0;
	char order[26]{};
	for(int i=0;i<26;i++)
		if (now[i]) {
			n++;
			int cnt = 0;
			for (int j = 0; j < 26; j++)
				if (M[i][j])
					cnt++;
			order[cnt] = i + 'A';
		}
	for (int i = n - 1; i >= 0; i--)
		cout << order[i];
	puts("");
	return 0;
}



/*
ex 
XWY
ZX
ZXY
ZXW
YWWX


XWY
ZX
->
X->Z 
W->X 

ZX
ZXY
->
nothing

ZXY
ZXW
->
Y->W

ZXW
YWWX
->
Z->Y
X->W

X4
Z3
Y2
W1

->XZYW

#
#
*/



A rare book collector recently discovered a book written in an unfamiliar 
language that used the same characters as the English language. 
The book contained a short index, but the ordering of the items
in the index was different from what one would expect if the characters 
were ordered the same way as in the English alphabet. 
The collector tried to use the index to determine the ordering of 
characters (i.e., the collating sequence) of the strange alphabet, 
then gave up with frustration at the tedium of the task.
You are to write a program to complete the collector's work. In particular, 
your program will take a set of strings that has been sorted according to 
a particular collating sequence and determine what that sequence is.



Input
The input consists of an ordered list of strings of uppercase letters, 
one string per line. Each string contains at most 20 characters. 
The end of the list is signalled by a line with the single character `#'.
Not all letters are necessarily used, but the list will imply a complete 
ordering among those letters that are used.

Output
Your output should be a single line containing uppercase letters 
in the order that species the collating
sequence used to produce the input data le.



Sample Input
XWY
ZX
ZXY
ZXW
YWWX
#

Sample Output
XZYW