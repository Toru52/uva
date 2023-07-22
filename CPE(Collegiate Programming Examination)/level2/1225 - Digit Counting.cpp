1225 - Digit Counting


#include <iostream>
using namespace std;

int main() {
	int cas;
	while (scanf("%d", &cas) != EOF) {
		for (int j = 0; j < cas; ++j) {
			int N;
			scanf("%d", &N);

			for (int i = 0; i <= 9; ++i) {
				int value = N,digit = 1,lastDigit = 0,number = 0;

				while (value > 0) {
					//digit 0
					if (i == 0) {
						if (value % 10 == i) 
							number += (value / 10 - 1) * digit + lastDigit + 1;
						//value=10 -> num=1, value=20 ->num=2, value=100 ->num=10
						//value=200 -> 1st num=20 2nd num=31
						// 10~ ->+1 digit*10 -> num*10
						//(value / 10 - 1) -> one digit number is no zero cnt
						else 
							number += value / 10 * digit;
						//value=11 -> num=1, value=22 ->num=2, value=101 ->num=10
					}
					//digit 1 2 3 4 5 6 7 8 9
					else {
						//ex 13
						if (value % 10 < i) 
							number += value / 10 * digit;
						//digit 1 2
						else if (value % 10 == i) 
							number += value / 10 * digit + lastDigit + 1;
						//digit 3
						else 
							number += (value / 10 + 1) * digit;
						//digit 4 5 6 7 8 9 
					}

					lastDigit += value % 10 * digit;
					digit *= 10;
					value /= 10;
				}
				if (i > 0) 
					printf(" ");
				printf("%d", number);
			}
			printf("\n");
		}
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n,cas;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		for (int i = 0; i < 10; i++) {

			int cnt = 0, value = n, digit = 1, lastdigit = 0;

			while (value > 0) {
				if (i == 0) {
					if (value % 10 == 0)
						cnt += (value / 10-1)*digit + 1;
					else
						cnt+= (value / 10)*digit;
				}
				else
					if(value%10<i)
						cnt += (value / 10)*digit;
					else if(value%10==i)
						cnt += (value / 10)*digit+lastdigit+1;
					else
						cnt += (value / 10+1)*digit;
			lastdigit += value % 10 * digit;
			value /= 10;
			digit *= 10;
			}
			if (i)
				printf(" ");
			printf("%d", cnt);
		}
		puts("");
	}
}



*concept 
10 1~10
0 1 2 3 4 5 6 7 8 9 
1 2 1 1 1 1 1 1 1 1 

->Any number digit at least put in 1 definitely,
when input 10.

20 1~20
1~10 ->look above
11~20
0  1 2 3 4 5 6 7 8 9
2 10 1 1 1 1 1 1 1 1 
When input 20,The counter number 1 put in 10.

1~9
0 1 2 3 4 5 6 7 8 9
0 1 1 1 1 1 1 1 1 1 



Trung is bored with his mathematics homeworks. He takes a piece of 
chalk and starts writing a sequence of consecutive integers 
starting with 1 to N (1 < N < 10000). After that, he counts the 
number of times each digit (0 to 9) appears in the sequence. 
For example, with N = 13, the sequence is: 12345678910111213
In this sequence, 0 appears once, 1 appears 6 times, 2 appears 2 
times, 3 appears 3 times, and each digit from 4 to 9 appears once. 
After playing for a while, Trung gets bored again. He now wants to
write a program to do this for him. Your task is to help him with 
writing this program.



Input
The input file consists of several data sets. The first line of the
input file contains the number of data sets which is a positive 
integer and is not bigger than 20. The following lines describe the 
data sets. For each test case, there is one single line containing 
the number N.

Output
For each test case, write sequentially in one line the number of 
digit 0, 1, . . . 9 separated by a space.



Sample Input
2
3
13

Sample Output
0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 1