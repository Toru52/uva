11233 - Deli Deli
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/11233%20-%20Deli%20Deli.cpp



#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {
	short L, N;
	string s1, s2;
	map<string, string> M;

	cin >> L >> N;

	for (int i = 0; i<L; i++) {
		cin >> s1 >> s2;
		M[s1] = s2;
	}

	char c1, c2;

	for (int i = 0; i<N; i++) {
		cin >> s1;
		if (M[s1] != "") cout << M[s1] << endl;  //condition 1 by use map STL
		else {
			c1 = s1[s1.size() - 1];
			c2 = s1[s1.size() - 2];

			if (c1 == 'y' && (c2 != 'a'&&c2 != 'e'&&c2 != 'i'&&c2 != 'o'&&c2 != 'u')) {
				s1.erase(s1.size() - 1, 1);
				cout << s1 << "ies" << endl; //condition 2
			}
			else if (c1 == 'o' || c1 == 's' || c1 == 'x' || 
			(c1 == 'h' && (c2 == 'c' || c2 == 's'))) 
			cout << s1 << "es" << endl;   //condition 3
			else 
				cout << s1 << "s" << endl;  //condition 4
		}
	}

	return 0;
}



#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	short L, N;
	char last1, last2;
	string s1, s2;
	map<string, string>m;
	cin >> L >> N;
	for (int i = 0; i < L; i++)
		cin >> s1 >> s2, m[s1] = s2;
	for (int i = 0; i < N; i++) {
		cin >> s1;
		if (m[s1] != "")
			cout << m[s1];
		else {
			last1 = s1[s1.size() - 1], last2 = s1[s1.size() - 2];
			if (last1 == 'y' &&
				(last2 != 'a'&&last2 != 'e'&&last2 != 'i'&&last2 != 'o'&&last2 != 'u'))
				s1.erase(s1.size() - 1, 1), cout << s1 << "ies";
			else if (last1 == 'o' || last1 == 's' || last1 == 'x' ||
				(last1 == 'h' && (last2 == 'c' || last2 == 's')))
				cout << s1 << "es";
			else
				cout << s1 << 's';
		}
		puts("");
	}
	return 0;
}
/*
condition
1 fix the string while see the above list.
2 fix from last character 'y' to 'ies'
3 add 'es' from "o,s,ch,sh,x"
4 add s 