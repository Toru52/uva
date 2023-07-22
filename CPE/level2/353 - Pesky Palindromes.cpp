353 - Pesky Palindromes



#include <iostream>
#include <string>
#include <map>
#include<algorithm>
using namespace std;

bool PorN(const string &s)
{
	string r_s(s);
	reverse(r_s.begin(), r_s.end());
	return s == r_s;
}

int main()
{
	string s;
	while (cin >> s)
	{
		map<string, int> V;
		int c = 0;
		for (size_t i = 0; i < s.size(); ++i)
			for (size_t j = i; j < s.size(); ++j)
			{
				string subS = s.substr(i, j - i + 1);
				if (!V.count(subS)
					&& PorN(subS))
				{
					++c;
					++V[subS];
				}
			}
		cout << "The string '"<< s<< "' contains "
			<< c<< " palindromes."<< endl;
	}
	return 0;
}



#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

bool PorN(const string &s) {
	string rs(s);
	reverse(rs.begin(), rs.end());
	return s == rs;
}
int main() {
	string s;
	while (cin >> s) {
		map<string, int>V;
		int c = 0;
		for(size_t i=0 ;i<s.size();i++)
			for (size_t j = i; j < s.size(); j++) {
				string subS = s.substr(i, j - i + 1);
				if (!V.count(subS) && PorN(subS)) {
					c++;
					V[subS]++;
				}
			}
		cout << "The string '"<<s <<"' contains " 
		           << c << " palindromes." << endl;
	}
}


A palindrome is a sequence of one or more characters that reads 
the same from the left as it does from the right. For example, 
Z, TOT and MADAM are palindromes, but ADAM is not. Your job, 
should you choose to accept it, is to write a program that reads 
a sequence of strings and for each string determines the number 
of UNIQUE palindromes that are substrings.



Input
The input file consists of a number of strings (one per line), 
of at most 80 characters each, starting in
column 1.

Output
For each non-empty input line, the output consists of one line 
containing the message:
The string 'input string' contains nnnn palindromes.
where input string is replaced by the actual input string and 
nnnn is replaced by the number of
UNIQUE palindromes that are substrings.
Note:
See below the explanation of the sample below
• The 3 unique palindromes in ‘boy’ are ‘b’, ‘o’ and ‘y’.
• The 4 unique palindromes in ‘adam’ are ‘a’, ‘d’, ‘m’, and ‘ada’.
• The 5 unique palindromes in ‘madam’ are ‘m’, ‘a’, ‘d’, 
                              ‘ada’, and ‘madam’.
• The 3 unique palindromes in ‘tot’ are ‘t’, ‘o’ and ‘tot’.



Sample input
boy
adam
madam
tot

Sample output
The string 'boy' contains 3 palindromes.
The string 'adam' contains 4 palindromes.
The string 'madam' contains 5 palindromes.
The string 'tot' contains 3 palindromes.


