10106 - Product
http://knightzone.org/?p=1435



#include<iostream>
#include<string>
using namespace std;

int main() {
	string input;
	int X[255] = { 0 }, Y[255] = { 0 };
	int xlen, ylen, anslen;
	while (getline(cin, input)) {
		xlen = input.length();
		for (int i = 0; i < xlen; i++)
			X[i] = input[xlen - i - 1] - '0';

		getline(cin, input);
		ylen = input.length();
		for (int i = 0; i < ylen; i++)
			Y[i] = input[ylen - i - 1] - '0';

		int answer[510] = { 0 };
		for (int i = 0; i < xlen; i++)
			for (int j = 0; j < ylen; j++) {
				// ex 56
				answer[i + j] += X[i] * Y[j];//56
				answer[i + j + 1] += answer[i + j] / 10; //carry up 5
				answer[i + j] %= 10;//6
			}
		anslen = xlen + ylen;
		while (anslen > 1 && !answer[anslen - 1]) anslen--;

		for (int i = anslen - 1; i >= 0; i--)
			printf("%d", answer[i]);
		printf("\n");
	}
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	string input;
	int xlen, ylen,anslen;	
	while (getline(cin, input)) {
		int x[255] = {}, y[255] = {}, ans[510] = {};
		xlen = input.length();
		for (int i = 0; i < xlen; i++)
			x[i] = input[xlen-i-1] - '0';
		getline(cin, input);
		ylen = input.length();
		for (int i = 0; i < ylen; i++)
			y[i] = input[ylen-i-1] - '0';
		for(int i=0;i<xlen;i++)
			for (int j = 0; j < ylen; j++) {
				ans[i + j] += x[i] * y[j];
				ans[i + j + 1] += ans[i + j] / 10;
				ans[i + j] = ans[i + j] % 10;
			}
		anslen = xlen + ylen;
		while (anslen > 1 && !ans[anslen - 1])anslen--;

		for (int i = anslen - 1; i >= 0; i--)
			printf("%d", ans[i]);
		puts("");
	}
	return 0;
}



The problem is to multiply two integers X, Y . (0 ≤ X, Y < 10250)



Input
The input will consist of a set of pairs of lines. Each line in 
pair contains one multiplyer.

Output
For each input pair of lines the output line should consist one 
integer the product.



Sample Input
12
12
2
222222222222222222222222

Sample Output
144
444444444444444444444444



