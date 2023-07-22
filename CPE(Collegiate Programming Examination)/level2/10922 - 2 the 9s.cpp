10922 - 2 the 9s
http://webcache.googleusercontent.com/search?q=cache:Cu8mD-t7VJkJ:knightzone.org/%3Fp%3D2854+&cd=2&hl=en&ct=clnk&gl=tw



#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string toString(int num) {
	stringstream ss;
	ss << num;
	return ss.str();
}

int main() {
	string num;
	while (getline(cin, num) && num != "0") {
		string temp = num;
		int degree = (num.length() == 1) ? 1 : 0;

		while (temp.length() > 1) {
			for (int i = 0; i < temp[i]; i++)
				printf("%c", temp[i]);
			puts("");
			int number = 0;
			for (int i = 0; i < temp.length(); ++i) 
				number += temp[i] - '0';
			printf("num %d\n", number);
			temp = toString(number);
			++degree;
		}

		if ((temp[0] - '0') % 9 == 0) 
			printf("%s is a multiple of 9 and has 9-degree %d.\n", num.c_str(), degree);
		else 
			printf("%s is not a multiple of 9.\n", num.c_str());		
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	string nine;
	while (cin >> nine, nine != "0") {
		string temp = nine;
		int degree = (nine.length() == 1)?1:0;
		while (temp.length() > 1) {
			int num = 0;
			for (int i = 0;temp[i]; i++)
				num += temp[i] - '0';
			temp = to_string(num);
			degree++;
		}
		if (temp[0] == '9')
			printf("%s is a multiple of 9 and has 9-degree %d.\n", nine.c_str(), degree);
		else
			printf("%s is not a multiple of 9.\n", nine.c_str());
	}
	return 0;
}



/*
9 degrees=sum each digits=9
ex
999->9+9+9=27->9(9-degrees 2)
99999999999->189->27->9(9-degree 3)

