679 - Dropping Balls



#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int N;
	while (scanf("%d", &N) != EOF && N != -1) {
		for (int i = 0; i < N; ++i) {
			int D, I;
			scanf("%d%d", &D, &I);

			int answer = 1 << (D - 1);//1*2^x  first time ball

			--I;//over 	first ball
			for (int j = D - 2; j >= 0; --j) {
				answer |= (I % 2) << j;//
//				I%2 -> for check bit and {(I % 2) << j} -> (I%2)*2^j  
				I /= 2;//a shift to left for bit 
			}

			printf("%d\n", answer);
		}
	}
	return 0;
}
/*
x<<1 -> x*2^1
x<<2 -> x*2^2
1<<x -> 1*2^x
*/


#include<iostream>
using namespace std;
int main() {
	int n,d,t;
	while (~scanf("%d", &n) && n != -1) {
		while (n--) {
			cin >> d >> t;
			int ball = 1 << (d - 1);
			t--;
			for (int j = d - 2; j >= 0; j--) 
				ball |= (t % 2) << j,t >>= 1;
			cout << ball << endl;
		}
	}
}



A number of K balls are dropped one by one from the root of a fully 
binary tree structure FBT. Each time the ball being dropped first 
visits a non-terminal node. It then keeps moving down, 
either follows the path of the left subtree, or follows the path 
of the right subtree, until it stops at one of the leaf nodes of 
FBT. To determine a ball’s moving direction a flag is set up in 
every non-terminal node with two values, either false or true. 
Initially, all of the flags are false. When visiting a non-terminal
node if the flag’s current value at this node is false, 
then the ball will first switch this flag’s value, i.e., from
the false to the true, and then follow the left subtree of this 
node to keep moving down. Otherwise, it will also switch this 
flag’s value, i.e., from the true to the false, but will follow
the right subtree of this node to keep moving down. Furthermore, 
all nodes of FBT are sequentially numbered, starting at
1 with nodes on depth 1, and then those on depth 2, and so on. 
Nodes on any depth are numbered from left to right.
For example, Fig. 1 represents a fully binary tree of maximum 
depth 4 with the node numbers 1, 2, 3, ..., 15. Since all of the 
flags are initially set to be false, the first ball being dropped 
will switch flag’s values at node 1, node 2, and node 4 before it 
finally stops at position 8. The second ball being dropped will 
switch flag’s values at node 1, node 3, and node 6, and stop at 
position 12. Obviously, the third ball being dropped will switch 
flag’s values at node 1, node 2, and node 5 before it stops at
position 10.



Fig. 1: An example of FBT with the maximum depth 4 and sequential 
node numbers. Now consider a number of test cases where two 
values will be given for each test. The first value is D, the 
maximum depth of FBT, and the second one is I, the I-th ball 
being dropped. You may assume the value of I will not exceed the 
total number of leaf nodes for the given FBT.
Please write a program to determine the stop position P for each 
test case. For each test cases the range of two parameters D and 
I is as below: 2 ≤ D ≤ 20, and 1 ≤ I ≤ 524288.



Input
Contains l + 2 lines.
Line 1 l the number of test cases
Line 2 D1 I1 test case #1, two decimal numbers that are separated 
by one blank
...
Line k + 1 Dk Ik test case #k
Line l + 1 Dl Il test case #l
Line l + 2 -1 a constant ‘-1’ representing the end of the input 
file

Output
Contains l lines.
Line 1 the stop position P for the test case #1
...
Line k the stop position P for the test case #k
...
Line l the stop position P for the test case #l



Sample Input
5
4 2
3 4
10 1
2 2
8 128
-1
Sample Output
12
7
512
3
255