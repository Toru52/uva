10494 - If We Were a Child Again
http://programming-study-notes.blogspot.tw/2014/02/uva-10494-if-we-were-child-again.html



#include <stdio.h>

int main(){
	char num[10001],oper[2];
    long long int b, R;
 
	while (~scanf("%s%s%lld", num, oper, &b)) {
		int i,pos = 0, Q[10001] ;

		for (i = 0, R = 0; num[i]; i++) {
			R = R * 10 + (num[i] - '0');
			Q[pos++] = R / b;          // ans前面幾個數字可能為0，等等輸出要從非0開始
			R = R % b;
		}
		if (oper[0] == '/') {
			//loop for jump '0' number
			for (i = 0; i < pos && Q[i] == 0; i++)
				;
			if (i == pos) printf("0");   // 如果被除數比除數小的情況
			else
				for (; i < pos; i++) 
					printf("%d", Q[i]);
			printf("\n");
		}
		else
			printf("%lld\n", R);
	}
	return 0;
}



#include<stdio.h>
int main() {
	long long int b;
	char num[10005], op[2];
	while (~scanf("%s %c %lld", &num, &op, &b)) {
		long long int R = 0;
		int i,pos=0,Q[10005];
		for (int i = 0; num[i]; i++) {
			R = R * 10 + (num[i] - '0');
			Q[pos++] = R / b;
			R %= b;
		}
		if (op[0] == '/') {
			for (i = 0; i < pos&&Q[i] == 0; i++);
			if (pos == i)
				printf("0");
			else
				for (; i < pos; i++)
					printf("%d", Q[i]);
			puts("");
		}
		else
			printf("%d\n", R);
	}
	return 0;
}



Oooooooooooooooh!
If I could do the easy mathematics like my school days!!
I can guarantee, that I'd not make any mistake this time!!"
Says a smart university student!!
But his teacher even smarter { \Ok!  I'd assign you such
projects in your software lab.  Don't be so sad."
\Really!!"  {  the  students  feels  happy.   And  he  feels  so
happy that he cannot see the smile in his teacher's face.
The  rst project for the poor student was to make a cal-
culator that can just perform the basic arithmetic operations.
But like many other university students he doesn't like to
do any project by himself.  He just wants to collect programs
from here and there.  As you are a friend of him, he asks you
to write the program.  But, you are also intelligent enough to tackle 
this kind of people.  You agreed to
write only the (integer)
division
and mod (% in C/C++) operations for him.

Input
Input  is  a  sequence  of  lines.   Each  line  will  contain  an  
input  number.   One  or  more  spaces.   A  sign
(
division
or  mod).   Again  spaces.   And  another  input  number.   Both  the  
input  numbers  are  non-negative  integer.   The   rst  one  may  be  
arbitrarily  long.   The  second  number
n
will  be  in  the  range
(0
< n <
2
31
).

Output
A line for each input, each containing an integer.  
See the sample input and output.  Output should not
contain any extra space.



SampleInput
110 / 100
99 % 10
2147483647 / 2147483647
2147483646 % 2147483647

SampleOutput
1
9
1
2147483646