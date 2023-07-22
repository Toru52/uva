621	Secret Research



#include <iostream>
#include <cstdio>
#include<string>
using namespace std;

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		string input;
		for (int i = 0; i < n; ++i) {
			cin >> input;
			if (input[input.length() - 2] == '3' && input[input.length() - 1] == '5') 
				printf("-\n");
			else if (input[0] == '9' && input[input.length() - 1] == '4') 
				printf("*\n");
			else if (input[0] == '1' && input[1] == '9' && input[2] == '0') 
				printf("?\n");	
			else 
				printf("+\n");	
		}
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	string a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a[a.length() - 2] == '3'&&a[a.length() - 1] == '5')
			cout << '-' << endl;
		else if (a[0] == '9'&&a[a.length() - 1] == '4')
			cout << '*' << endl;
		else if (a[0] == '1'&&a[1] == '9'&&a[2] == '0')
			cout << '?' << endl;
		else
			cout << '+' << endl;
	}

}


At a certain laboratory results of secret research are 
thoroughly encrypted. A result of a single experiment
is stored as an information of its completion:
‘positive result’, ‘negative result’, ‘experiment failed’ 
or ‘experiment not completed’
The encrypted result constitutes a string of digits S, 
which may take one of the following forms:
• positive result S = 1 or S = 4 or S = 78
• negative result S = S35
• experiment failed S = 9S4
• experiment not completed S = 190S
(A sample result S35 means that if we add digits 35 from 
the right hand side to a digit sequence
then we shall get the digit sequence corresponding to a 
failed experiment) You are to write a program which 
decrypts given sequences of digits.



Input
A integer n stating the number of encrypted results and 
then consecutive n lines, each containing a
sequence of digits given as ASCII strings.

Output
For each analysed sequence of digits the following lines 
should be sent to output (in separate lines):
+ for a positive result
- for a negative result
* for a failed experiment
? for a not completed experiment
In case the analysed string does not determine the 
experiment result, a first match from the above
list should be outputted.



Sample Input
4
78
7835
19078
944

Sample Output
+
-
?
*