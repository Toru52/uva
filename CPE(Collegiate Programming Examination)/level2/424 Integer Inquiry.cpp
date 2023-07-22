424	Integer Inquiry
https://sites.google.com/site/pcshic/solutions/2014-zi-xun-neng-li-jing-sai-can-kao-jie-da



#include <iostream>
#include <string>
using namespace std;

int main() {
	string n1, n2;
	cin >> n1;
	while (cin >> n2, n2 != "0") {
		if (n1.size() < n2.size())              //確定 n1 比 n2 長
			swap(n1, n2);
		n2.insert(0, n1.size() - n2.size(), '0');//把數字補成一樣長
		int c = 0;                              //c(arry)--進位
		for (int i = n1.size() - 1; i >= 0; i--) {    //從個位數開始算
			c += n1[i] + n2[i] - 96;
			n1[i] = c % 10 + '0';
			c /= 10;
		}
		if (c)                                  //若還有進位
			n1.insert(0, 1, '1');              //再加一位數
	}
	cout << n1 << endl;
}



#include<iostream>
#include<string>
using namespace std;
int main() {
	string n1, n2;
	cin >> n1;
	while (cin >> n2, n2 != "0") {
		if (n2.size() > n1.size())
			swap(n1, n2);
		n2.insert(0, n1.size() - n2.size(), '0');
		int c = 0;
		for (int i = n1.size() - 1; i >= 0; i--) {
			c += n1[i] + n2[i] - 96;
			n1[i] = c % 10 + '0';
			c /= 10;
		}
		if (c)
			n1.insert(0, 1, '1');
	}
	cout << n1 << endl;
	return 0;
}



One of the first users of BIT’s new supercomputer was Chip 
Diller. He extended his exploration of powers of 3 to go from 
0 to 333 and he explored taking various sums of those numbers.
“This supercomputer is great,” remarked Chip. “I only wish 
Timothy were here to see these results.”
(Chip moved to a new apartment, once one became available on 
the third floor of the Lemon Sky apartments on Third Street.)



Input
The input will consist of at most 100 lines of text, each of 
which contains a single VeryLongInteger.
Each VeryLongInteger will be 100 or fewer characters in 
length, and will only contain digits 
(no VeryLongInteger will be negative).
The final input line will contain a single zero 
on a line by itself.

Output
Your program should output the sum of the VeryLongIntegers 
given in the input.



Sample Input
123456789012345678901234567890
123456789012345678901234567890
123456789012345678901234567890
0

Sample Output
370370367037037036703703703670