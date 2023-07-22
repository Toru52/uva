417 - Word Index
http://mypaper.pchome.com.tw/zerojudge/post/1322796439/



#include <stdio.h>
#include <string.h>

int main() {
	char s[10];
	int i,C[50][50] = {1};
	//nCr principle recursion formula
	//combination classic
	//nC0=1,nCr=((n-r+1)/*r)*(nC(r-1)) by p12 
	for (i = 1; i < 50; i++) {
		C[i][0] = 1;//nCr=1
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		//  nCr     = n-1Cr-1         +  n-1Cr
	}
	while (scanf("%s", &s) == 1) {
		int len = strlen(s), idx = 0;
		for (i = 1; i < len; i++) {
			if (s[i] <= s[i - 1]) {
				puts("0"); break;
			}
			idx += C[26][i];
		}
		if (i != len)	continue;
		for (i = 0; i < len; i++) {
			//s[i-1]-'a'+2<=s[i]-'a'
			//since no include 1 difference and 'a'
			//,so s[i - 1] - 'a' + 2
			for (int j = (i == 0) ? 
				1 : s[i - 1] - 'a' + 2; j <= s[i] - 'a'; j++)
				idx += C[26 - j][len - i - 1];
		}
		printf("%d\n", idx + 1);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main() {
	char s[10]{};
	int i,C[50][50]{ 1 };
	for (i = 1; i < 50; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	while (scanf("%s", s) == 1) {
		int sum = 0, len = strlen(s);
		for (i = 1; i < len; i++) {
			if (s[i] <= s[i - 1]) {
				puts("0"); break;
			}
			sum += C[26][i];
		}
		if (i != len)continue;
		for (i = 0; i < len; i++)
			for (int j = (i == 0) ?
				1 : s[i - 1] - 'a' + 2; j <= s[i] - 'a'; j++)
				sum += C[26 - j][len - i - 1];
		printf("%d\n", sum+1);
	}
	return 0;
}



/*
concept
(int j = (i == 0) ? 
  1 : s[i - 1] - 'a' + 2; j <= s[i] - 'a'; j++)
  
  1.since word are always after previous letters
  ex ac ce  ca->no ea->no

  2.since no include 1 difference and 'a'
  //,so s[i - 1] - 'a' + 2
*/
Encoding schemes are often used in situations requiring encryption 
or information storage/transmission economy. Here, we develop a 
simple encoding scheme that encodes particular types of words with 
five or fewer (lower case) letters as integers.
Consider the English alphabet {a,b,c,...,z}. Using this alphabet, 
a set of valid words are to be formed that are in a strict 
lexicographic order. In this set of valid words, the successive 
letters of a word are in a strictly ascending order; that is, 
later letters in a valid word are always after previous letters 
with respect to their positions in the alphabet list {a,b,c,...,z}.
For example,
abc aep gwz
are all valid three-letter words, whereas
aab are cat
are not.
For each valid word associate an integer which gives the position 
of the word in the alphabetized
list of words. That is:
a -> 1
b -> 2
..z
-> 26
ab -> 27
ac -> 28
..
az -> 51
bc -> 52
..
vwxyz -> 83681
Your program is to read a series of input lines. 
Each input line will have a single word on it, 
that will be from one to five letters long. For each word read, 
if the word is invalid give the number ‘0’. 
If the word read is valid, give the word’s position index in the 
above alphabetical list.



Input
The input consists of a series of single words, one per line. 
The words are at least one letter long and no more that five 
letters. Only the lower case alphabetic {a,b,...,z} characters 
will be used as input.
The first letter of a word will appear as the first character on 
an input line.
The input will be terminated by end-of-file.

Output
The output is a single integer, greater than or equal to zero (0) 
and less than or equal 83681. The first
digit of an output value should be the first character on a line. 
There is one line of output for each input line.



Sample Input
z
a
cat
vwxyz

Sample Output
26
1
0
83681