455 - Periodic Strings
https://github.com/morris821028/UVa/blob/master/volume004/455%20-%20Periodic%20Strings.cpp

definition about failure functioin
data structure-chapter2-p52

#include<stdio.h>
#include<string.h>
int KMP_init(char *A) {
	int i, j,P[1000];
	P[0] = -1, i = 1, j = -1;
	while (A[i]) {
		//when cnt add one to 'j',if appear no repeated character
		//'j' must back original place
		//ex
		// a b c a b c  d
		//-1-1-1 0 1 2 -1 
		while (j >= 0 && A[j + 1] != A[i])
			j = P[j];
		//start from if(A[0]==A[1])
		if (A[j + 1] == A[i])
			++j;
		P[i] = j, ++i;//shift to left
	}
	return j;
}
int main() {
	int T;
	char s[1000];
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int l = strlen(s), t = KMP_init(s);
		//no pattern
		if (l % (l - t - 1))
			printf("%d\n", l);
		else // has pattern
			printf("%d\n", l - t - 1);
		if (T)	puts("");
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int KMP(char *A) {
	int i = 1, j = -1, p[1000]{ -1 };
	while (A[i]) {
		while (j >= 0 && A[j + 1] != A[i])
			j = p[j];
		if (A[j + 1] == A[i])
			j++;
		p[i] = j, i++;
	}
	return j;
}
int main() {
	int n;
	char s[1000]{};
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int len = strlen(s), j = KMP(s);
		if (len % (len - j - 1))
			printf("%d\n", len);
		else
			printf("%d\n", len - j - 1);
		if (n)
			puts("");
	}
	return 0;
}



/*
ex
 a b c a b c a b c(9)
-1-1-1 0 1 2 3 4 5
->
9-5-1=3
9%3=0->ok

 a b c a b c a b(8)
-1-1-1 0 1 2 3 4

8-4-1=3
n(8)%3>0 ->no
->8
*/
A character string is said to have period k if it can be formed by 
concatenating one or more repetitions of another string of length 
k. For example, the string ”abcabcabcabc” has period 3, 
since it is formed by 4 repetitions of the string ”abc”. 
It also has periods 6 (two repetitions of ”abcabc”) and 12 (one
repetition of ”abcabcabcabc”).
Write a program to read a character string and determine its 
smallest period.



Input
The first line oif the input file will contain a single integer N 
indicating how many test case that your program will test followed 
by a blank line. Each test case will contain a single character 
string of up to 80 non-blank characters. 
Two consecutive input will separated by a blank line.

Output
An integer denoting the smallest period of the input string for 
each input. Two consecutive output are separated by a blank line.



Sample Input
1
HoHoHo

5

HoHoHo
dodoldudulzz
mangomangomangom
dodod

abcabcabcabc

HoHaHo

ooHooH

abaaababaaab

Sample Output
2

2
12
16
5

3

6

3

6