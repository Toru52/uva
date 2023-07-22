10223 	How many nodes ?
https://www.eecs.qmul.ac.uk/~pbo/ACM/archive/10223code1.html
http://mypaper.pchome.com.tw/zerojudge/post/1322929553

explain about Binary Trees
http://www.maths.usyd.edu.au/u/kooc/catalan/cat13ftree.pdf


#include <stdio.h>

int main() {
	int n,sol[22] = {};

	sol[0] = 1;
	for (int i = 1; i < 22; i++) 
		for (int j = 0; j < i; j++) 
			sol[i] += sol[j] * sol[i - 1 - j];

	while (scanf("%d", &n) == 1) 
		for (int i = 1; i < 22; i++) 
			if (sol[i] == n) {
				printf("%d\n", i);
				break;
			}
	return 0;
}



#include<stdio.h>

int main() {
	int n, nodes[22] = {};
	nodes[0] = 1;
	for (int i = 1; i < 22; i++)
		for (int j = 0; j < i; j++)
			nodes[i] += nodes[j] * nodes[i - 1 - j];
	while (scanf("%d", &n)==1) {
		for (int i = 1; i < 22; i++)
			if (nodes[i] == n)
				printf("%d\n", i);
	}
	return 0;
}

ex
n=4

sol[0]=1
i=1
sol[1]+=sol[0]*sol[0]=1
i=2
sol[2]+=sol[0]*sol[2-1-0(1)]=1
sol[2]+=sol[1]*sol[2-1-1(0)]=2
i=3
sol[3]+=sol[0]*sol[3-1-0(2)]=2
sol[3]+=sol[1]*sol[3-1-1(1)]=3
sol[3]+=sol[2]*sol[3-1-2(0)]=5
i=4
sol[4]+=sol[0]*sol[4-1-0(3)]=5
sol[4]+=sol[1]*sol[4-1-1(2)]=7
sol[4]+=sol[2]*sol[4-1-2(1)]=9
sol[4]+=sol[3]*sol[4-1-3(0)]=14



One of the most popular topic of Data Structures is Rooted 
Binary Tree.  If you are given some nodes you can de nitely 
able to make the maximum number of trees with them.  
But if you are given the maximum number of trees built upon a 
few nodes, 
Can you  nd out how many nodes built those trees?



Input
The input  le will contain one or more test cases.
Each test case consists of an integer
n
(
n

4
;
294
;
967
;
295).  
Here n is the maximum number of trees.

Output
For each test case, print one line containing the actual 
number of nodes.



SampleInput
5
14
42

SampleOutput
3
4
5