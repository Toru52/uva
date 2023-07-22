124 - Following Orders   
http://mypaper.pchome.com.tw/zerojudge/post/1322919722



#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
using namespace std;

int can[26], map[26][26], used[26];
char str[26];
void DFS(int idx, int n) {
	if (idx == n) {
		str[idx] = '\0';
		puts(str);
		return;
	}
	int i, j;
	for (i = 0; i < 26; i++) {
		if (can[i] == 1 && used[i] == 0) {
			for (j = 0; j < 26; j++)
				if (map[i][j] == 1 && used[j] == 1)
					return;
			used[i] = 1;
			str[idx] = i + 'a';
			DFS(idx + 1, n);
			used[i] = 0;
		}
	}
}
int main() {
	stringstream sin;
	string line;
	char ch1, ch2, first = 0;
	while (getline(cin, line)) {
		if (first)
			puts("");
		first = 1;
		memset(can, 0, sizeof(can));
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		sin.clear();
		sin << line;
		while (sin >> ch1) {
			can[ch1 - 'a'] = 1;
		}
		int n = 0;
		for (int i = 0; i < 26; i++)
			n += can[i];
		getline(cin, line);
		sin.clear();
		sin << line;
		while (sin >> ch1 >> ch2) {
			map[ch1 - 'a'][ch2 - 'a'] = 1;
		}
		DFS(0, n);
	}
	return 0;
}



#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

int can[26], map[26][26], used[26];
char str[26];
void DFS(int idx, int n) {
	if (idx == n) {
		str[idx] = '\0';
		puts(str);
		puts("");
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (can[i] == 1 && used[i] == 0) {
			for (int j = 0; j < 26; j++)
				if (map[i][j] == 1 && used[j] == 1) {
					printf("quit(%c,%c) ",i+'a',j+'a');
					puts(str);
					return;
				}
			used[i] = 1;
			str[idx] = i + 'a';
			printf("process ");
			puts(str);
			DFS(idx + 1, n);
			used[i] = 0;
		}
	}
}
int main() {
	stringstream sin;
	string line;
	char ch1, ch2, first = 0;
	while (getline(cin, line)) {
		if (first)
			puts("");
		first = 1;
		memset(can, 0, 26);
		memset(map, 0, 26);
		memset(used, 0, 26);
		sin.clear();
		sin << line;
		while (sin >> ch1) 
			can[ch1 - 'a'] = 1;	
		int n = 0;
		for (int i = 0; i < 26; i++)
			n += can[i];
		getline(cin, line);
		sin.clear();
		sin << line;
		while (sin >> ch1 >> ch2)
			map[ch1 - 'a'][ch2 - 'a'] = 1;
		DFS(0, n);
	}
	return 0;
}



http://www.cnblogs.com/devymex/archive/2010/08/17/1800952.html

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	bool bFirst = true;
	char szOrder[24];

	for (string str; getline(cin, str); bFirst = false) {
		strcpy(szOrder, str.c_str());
		int nLen = remove(szOrder, &szOrder[str.size()], ' ') - szOrder;
		szOrder[nLen] = '\0';
		getline(cin, str);
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		bool aCompMat[26][26] = { 0 };
		for (string::iterator i = str.begin(); i != str.end(); i += 2) 
			aCompMat[*i - 'a'][*(i + 1) - 'a'] = true;
		sort(&szOrder[0], &szOrder[nLen]);
		if (!bFirst) 
			cout << endl;
		
		for (bool bFlag = true; bFlag; bFlag = next_permutation(
			&szOrder[0], &szOrder[nLen])) {
			for (int i = 0; i < nLen - 1 && bFlag; ++i) 
				for (int j = i + 1; j < nLen && bFlag; ++j) 
					bFlag &= !aCompMat[szOrder[j] - 'a'][szOrder[i] - 'a'];
			if (bFlag) 
				cout << szOrder << endl;
		}
	}
	return 0;
}



/*
ex
a b f g
a b b f
->
a<b,b<f (these alpha must not sort)


v w x y z
v y x v z v w v
->
v>y,x>v,z>v,w>v
*/



Order is an important concept in mathematics and in computer 
science. For example, Zorn’s Lemma states: “a partially ordered 
set in which every chain has an upper bound contains a maximal 
element.”
Order is also important in reasoning about the fix-point 
semantics of programs.
This problem involves neither Zorn’s Lemma nor fix-point semantics,
but does involve order.
Given a list of variable constraints of the form x < y, 
you are to write a program that prints all orderings of the 
variables that are consistent with the constraints.
For example, given the constraints x < y and x < z there are two 
orderings of the variables x, y,
and z that are consistent with these constraints: xyz and xzy.



Input
The input consists of a sequence of constraint specifications. 
A specification consists of two lines: a list
of variables on one line followed by a list of constraints on the 
next line. A constraint is given by a pair of variables, 
where ‘x y’ indicates that x < y.
All variables are single character, lower-case letters. 
There will be at least two variables, 
and no more than 20 variables in a specification. 
There will be at least one constraint, and no more than 50
constraints in a specification. There will be at least one, 
and no more than 300 orderings consistent with the constraints 
in a specification. Input is terminated by end-of-file.

Output
For each constraint specification, all orderings consistent with 
the constraints should be printed. 
Orderings are printed in lexicographical (alphabetical) order, 
one per line. Output for different constraint specifications is 
separated by a blank line.



Sample Input
a b f g
a b b f
v w x y z
v y x v z v w v
s
Sample Output
abfg
abgf
agbf
gabf
wxzvy
wzxvy
xwzvy
xzwvy
zwxvy
zxwvy