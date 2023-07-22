11714 - Blind Sorting
http://blog.csdn.net/keshuai19940722/article/details/18186255
concept
http://blog.csdn.net/accelerator_/article/details/18180303


#include <stdio.h>
#include <math.h>

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", n + (int)ceil(log2((double)n)) - 2);
	}
	return 0;
}


#include<cstdio>
#include<math.h>
int main() {
	int n;
	while(scanf("%d", &n)==1)
		printf("%d\n", n + (int)ceil(log2((double)n)) - 2);
	return 0;
}
/*
key point 
find out the largest and second largest number.
->m^2 in n 
*/

I am a polar bear. But I am not just an ordinary polar bear. 
Yes I am extra ordinary! I love to play with numbers.
One day my very good friend Mr. Panda came to me, 
and challenged me to solve a puzzle. He blindfolded me, 
and said that I have n distinct numbers. 
What I can ask is whether a-th number is larger than b-th number 
and he will answer me properly. 
What I have to do is to nd out the largest and 
second largest number. 
I thought for a while and said \Come on, I will do it in minimum
number of comparison."



Input
There will be a non-negative integer, n in each of the line of 
input where n is as described above. n will be less than any 10 
digit prime number and not less than the smallest prime.

Output
For each n, output number of questions that I have to ask Mr. 
Panda in the worst case.



Sample Input
2
4

Sample Output
1
4




