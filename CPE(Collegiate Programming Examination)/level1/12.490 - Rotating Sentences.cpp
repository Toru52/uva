12.490 - Rotating Sentences

#include<algorithm>
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int m = 0;
string b;
vector<string> a;

int main() {
	while (getline(cin, b)) {
		a.push_back(b);
		m = max(m, (int)b.length());
	}
	for (int i = 0; i < m; i++) {
		for (int j = a.size() - 1; j >= 0; j--) {
			printf("%c", i < a[j].length() ? a[j][i] : ' ');
		} printf("\n");
	}
}


   m(i)
<----->
^
|
|a(j)
|
v

abd
d
ef

eda
f b
d


In ``Rotating Sentences,'' you are asked to rotate a series 
of input sentences 90 degrees clockwise. So instead of 
displaying the input sentences from left to right and top 
to bottom, your program will display them from top to 
bottom and right to left.



Input 
As input to your program, you will be given a maximum of 
100 sentences, each not exceeding 100 characters long. 
Legal characters include: newline, space, any punctuation 
characters, digits, and lower case or upper case English 
letters. (NOTE: Tabs are not legal characters.)

Output
The output of the program should have the last sentence
printed out vertically in the leftmost column; the first 
sentence of the input would subsequently end up at the 
rightmost column.




Sample Input
Rene Decartes once said,
"I think, therefore I am."

Sample Output
"R
Ie
 n
te
h 
iD
ne
kc
,a
 r
tt
he
es
r
eo
fn
oc
re
e
 s
Ia
 i
ad
m,
.
"