10776 - Determine The Combination
http://programming-study-notes.blogspot.tw/2014/02/uva-10776-determine-combination.html



#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;

string str;
int n;

void choose_ch(vector<char> &ans, int start)
{
	if (ans.size() == n) {
		for (char &c : ans)
			cout << c;
		cout << endl;
		return;
	}
	for (int i = start; i < str.size(); ) {
		char c = str[i];
		ans.push_back(c);
		choose_ch(ans, i + 1);
		ans.pop_back();
		while (str[i] == c) i++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while (cin >> str >> n) {
		sort(str.begin(), str.end());
		vector<char> ans;
		choose_ch(ans, 0);
	}
	return 0;
}



Jahir is a student of NSU (Nice Students' University). 
He hates the chapter Permutation & Com-bination of the subject 
Discrete Math. But his teacher give him a assignment to generate all 
the r combination of a string. But he is too busy with his new 
girlfriend to do the assignment himself. So he went to Shabuj, 
a student of CSE (Calculation Science and Engineering) in BUET 
(Bangladesh University of Extraordinary Talents). 
He asked him to make a program to generate the combinations.
But Shabuj is always lazy. He wants your help.
Your task is to print all different r combinations of a string s 
(a r combination of a string s is a collection of exactly r letters 
from different positions in s).
There may be different permutations of the same combination; 
consider only the one that has its r characters in non-decreasing order.
The string consists of only lowercase letters. Any letter can occur 
more than once.



Input
The input is consist of several test cases. Each test case consists 
of a string s (the length of s is between
1 and 30) and an integer r (0 < r  length of s).

Output
For each test case you have to print all different r combinations 
of s in lexicographic order in separate
line. You can assume there are at most 1000 different ones.



Sample Input
abcde 2
abcd 3
aba 2

Sample Output
ab
ac
ad
ae
bc
bd
be
cd
ce
de
abc
abd
acd
bcd
aa
ab