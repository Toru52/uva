496 - Simply Subsets
http://mypaper.pchome.com.tw/zerojudge/post/1322958931

about proper
https://mathwords.net/sinbubunsyugo

#include <iostream>
#include <sstream>
using namespace std;

int main() {
	string line;
	while (getline(cin, line)) {
		stringstream sin;
		int A[100], B[100];
		int At = 0, Bt = 0, num, i, j;
		sin << line;
		while (sin >> num)
			A[At++] = num;
		getline(cin, line);
		sin.clear();
		sin << line;
		while (sin >> num)
			B[Bt++] = num;
		int Act = 0, Bct = 0;
		for (i = 0; i < At; i++) 
			for (j = 0; j < Bt; j++) 
				if (A[i] == B[j]) {
					Act++;break;
				}
		for (i = 0; i < Bt; i++) 
			for (j = 0; j < At; j++) 
				if (B[i] == A[j]) {
					Bct++;
					break;
				}
		if (At == Act && At < Bt)
			puts("A is a proper subset of B");
		else if (Bt == Bct && Bt < At)
			puts("B is a proper subset of A");
		else if (At == Bt && Act == At && Bct == Bt)
			puts("A equals B");
		else if (Act == 0 && Bct == 0)
			puts("A and B are disjoint");
		else
			puts("I'm confused!");
	}
	return 0;
}



#include<iostream>
#include<sstream>
using namespace std;
int main() {
	string s;
	while (getline(cin, s)) {
		stringstream aa, bb;
		int num, at = 0, bt = 0, a[100]{}, b[100]{};
		aa << s;
		while (aa >> num)
			a[at++] = num;
		getline(cin, s);
		bb << s;
		while (bb >> num)
			b[bt++] = num;
		int act = 0, bct = 0;
		for(int i=0;i<at;i++)
			for(int j=0;j<bt;j++)
				if (a[i] == b[j]) {
					act++; break;
				}
		for (int i = 0; i<bt; i++)
			for (int j = 0; j<at; j++)
				if (b[i] == a[j]) {
					bct++; break;
				}
		if(at==act&&at<bt)
			puts("A is a proper subset of B");
		else if(bt==bct&&bt<at)
			puts("B is a proper subset of A");
		else if(at==bt&&at==act&&bt==bct)
			puts("A equals B");
		else if(!act&&!bct)
			puts("A and B are disjoint");
		else
			puts("I'm confused!");
	}
	return 0;
}



/*
ex
1 3 2 1   //consider the '1' and '1' independently 
1 2 3
->B of A


*/
After graduating from the University of Notre Dame, you obtained a job at Top Shelf Software, Inc.,
as an entry-level computer engineer. On the first day, your manager sits down with you and tasks
you with the following job: “We want to see how well you understand computer programming and the
abstract science behind it. As an evaluation for all of our new hires, we require them to write a program
to determine the relationship between pairs of sets. I’m quite sure that you’ll do well; my confidence is
high. Here’s a list of requirements for what the program should do. Good luck.”
Input
Your program should accept an even number of lines of text. Each pair of lines will represent two sets;
the first line represents set A, the second line represents set B. Each line of text (set) will be a list of
distinct integers.
Output
After each pair of lines has been read in, the sets should be compared and one of the following responses
should be output:
• A is a proper subset of B
• B is a proper subset of A
• A equals B
• A and B are disjoint
• I'm confused!
Sample Input
55 27
55 27
9 24 1995
9 24
1 2 3
1 2 3 4
1 2 3
4 5 6
1 2
2 3

1
1 1

1 3 2 1
1 2 3
Sample Output
A equals B
B is a proper subset of A
A is a proper subset of B
A and B are disjoint
I'm confused!

A is a proper subset of B

B is a proper subset of A

