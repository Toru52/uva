10063 - Knuth's Permutation



#include <iostream>
#include <string>
using namespace std;

string s;

void knuth(string p) {
	if (p.size() == s.size())
		cout << p << endl;
	else
		for (unsigned i = 0; i <= p.size(); i++)
			knuth(p.substr(0, i) + s[p.size()] + p.substr(i));
}           //將 s 的下一字元依序插入 p 的每個空隙

int main() {
	for (int tc = 0; cin >> s; tc++) {
		if (tc) cout << endl;                   //測試資料間空一行
		knuth(s.substr(0, 1));                  //插入第一個字元
	}
}



#include<iostream>
#include<string>
using namespace std;
string s;
void knuth(string p) {
	if (s.size() == p.size())
		cout << p << endl;
	else
		for (unsigned i = 0; i <= p.size(); i++)
			knuth(p.substr(0, i) + s[p.size()] + p.substr(i));
}
int main() {
	for (int cas = 0; cin >> s; cas++) {
		if (cas)
			puts("");
		knuth(s.substr(0, 1));
	}
}


/*
abc->

a->

for(a)
(i=0)
0+b+a->
(i=1)
a+b->

for(ba)
(i=0)
0+c+ba->output1
(i=1)
b+c+a->output2
(i=2)
ba+c+0->output3

for(ab)
(i=0)
0+c+ab->output4
(i=1)
a+c+b->output5
(i=2)
ab+c+0->output6

*/



There are some permutation generation techniques in Knuth's 
book \The Art of Computer Program-
ming - Volume 1". One of the processes is as follows:
For each permutation
A
1
A
2
:::A
n
For example, from the permutation 231 inserting 4 in all 
possible places we get 4231 2431 2341 2314
Following this rule you have to generate all the permutation 
for a given set of characters. All the given characters will 
be different and there number will be less than 10 and they 
all will be alpha numerals. 
This process is recursive and you will have to start 
recursive call with the  rst character and
keep inserting the other characters in order. 
The sample input and output will make this clear. 
Your output should exactly mach the sample output for the 
sample input.



Input
The input contains several lines of input. Each line will be 
a sequence of characters. There will be less than ten 
alphanumerals in each line. The input will be terminated by
\End of File".

Output
For each line of input generate the permutation of those 
characters. The input ordering is very important
for the output. That is the permutation sequence for `

abc
' and `
bca
' will not be the same.
Separate each set of permutation output with a blank line.



SampleInput
abc
bca
dcba

SampleOutput
cba
bca
bac
cab
acb
abc
acb
cab
cba
abc
bac
bca
abcd
bacd
bcad
bcda
acbd
cabd
cbad
cbda
acdb
cadb
cdab
cdba
abdc
badc
bdac
bdca
adbc
dabc
dbac
dbca
adcb
dacb
dcab
dcba