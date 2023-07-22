10706 - Number Sequence   
http://mypaper.pchome.com.tw/zerojudge/post/1322741413
concept(group number sequence)
http://jukensansuu.com/suretsuouyou.html
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q11129711416?__ysp=MSAxIDIgMSAyIDMg5L2V55Wq55uuIOaVsOWtpg%3D%3D
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q13109346308?__ysp=MSwxLDIsMSwyLDMsMSwyLDMsNCwxLDIsMyw0LDUg5L2V55Wq55uuIOaVsOWtpg%3D%3D



#include <stdio.h>
#include <math.h>

long long loc[33001];
char seq[1000000];
void ini() {
	int len, tot = 0;
	char *s = seq;
	//use char type to use sprintf 
	for (int i = 1; i <= 33000; i++) {
		sprintf(s, "%d", i);
		len = (int)log10(i) + 1;
		s += len;   //digit number can to read (i)		
		tot += len;
		loc[i] = tot + loc[i - 1];		
	}
}
void FindNSeq(int v) {
	int l = 0, r = 33000, m;
	//l,r,m=group sequence number
	//l=low,r=high(right),m=middle
	do {
		m = (l + r) >> 1;
		printf("loc[%d] %lld l %d r %d seq[%lld] \n", m,loc[m],l,r,v - loc[m] - 1);
		if (loc[m] < v) {
			if (loc[m + 1] >= v) {
				puts("ok");
				break;
			}
				
			else
				l = m + 1;
		}
		else
			r = m - 1;
	} while (l <= r);
	printf("%c\n", seq[v - loc[m] - 1]);
}
int main() {
	ini();
	int T, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &i);
		FindNSeq(i);
	}
	return 0;
}



#include<stdio.h>
#include<math.h>
char seq[1000000];
long long loc[33001];
void ini() {
	int tot = 0, len;
	char *s = seq;
	for (int i = 1; i <= 33000; i++) {
		sprintf(s, "%d", i);
		len = (int)log10(i) + 1;
		tot += len;
		s += len;
		loc[i] = loc[i - 1] + tot;
	}
}
void Find(int v){
	int l = 0, m, r = 33000;
	do {
		m = (l + r) >> 1;
		if (v > loc[m])
			if (v <= loc[m + 1])
				break;
			else
				l=m+1;
		else
			r = m - 1;
	} while (l <= r);
	printf("%c\n", seq[v - loc[m] - 1]);
}
int main() {
	ini();
	int t, i;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &i);
		Find(i);
	}
}

/*
struct
loc[group sequence number]
=number in group
tot 0 loc[0]=0
tot 1 loc[1]=1   1
tot 2 loc[2]=3   112
tot 3 loc[3]=6   112123
tot 4 loc[4]=10  1121231234
tot 5 loc[5]=15  112123123412345
tot 6 loc[6]=21  112123123412345123456
tot 7 loc[7]=28  1121231234123451234561234567
tot 8 loc[8]=36  112123123412345123456123456712345678
tot 9 loc[9]=45  112123123412345123456123456712345678123456789
len = (int)log10(i) + 1=1(10log10)+1=2
tot 11 loc[10]=56  11212312341234512345612345671234567812345678912345678910
tot 13 loc[11]=69  112123123412345123456123456712345678123456789123456789101234567891011



s+=len(digit number can to read (i))
len = 1 -> one digit can read
len = 2 ->two digit can read
len = 3 ->three digit can read

ex
digit
4321
0000
0001
0002
0003
0004
0005
0006
0007
0008
0009
0010
0011
0012
...

char type can just read one digit
if digit have two or more, char to read separately.
ex 10
read 1 
read 0

*/


A single positive integer i is given. Write a program to nd the 
digit located in the position i in
the sequence of number groups S1S2 : : : Sk. 
Each group Sk consists of a sequence of positive integer
numbers ranging from 1 to k, written one after another. 
For example, the rst 80 digits of the sequence
are as follows:
112123123412345123456123456712345678123456789123456789
10123456789101112345678910



Input
The rst line of the input le contains a single integer t 
(1  t  25), the number of test cases, followed
by one line for each test case. The line for a test case contains 
the single integer i (1  i  2147483647)

Output
There should be one output line per test case containing the digit 
located in the position i.



Sample Input
2
8
3

Sample Output
2
2