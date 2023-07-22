112 - Tree Summing   
http://mypaper.pchome.com.tw/zerojudge/post/1322796940



#include <stdio.h>
int ans;
int solve(int sum, int S, char *c) {
	int flag = 0, token, neg;
	while (*c == ' ' || *c == '\n')
		*c = getchar();
	if (*c == '(') {
		token = 0, flag = 0, neg = 1;
		while (*c = getchar()) {
			if (*c >= '0' && *c <= '9')
				token = token * 10 + *c - '0', flag = 1;
			else {
				if (*c == '-')	neg = -1;
				else break;// input '(' or ')' ->break 
			}
		}
		token *= neg;
		while (*c == ' ' || *c == '\n')
			*c = getchar();
		if (flag == 0) {
			//no tree
			return 0;
		}
		// if there is num at bottom of tree,go to under code
		// hanoi principle
		int left = solve(sum + token, S, c);
		while ((*c = getchar()) != '(');//ignore space and next line until '('
		int right = solve(sum + token, S, c);
		while ((*c = getchar()) != ')');
		if (left == 0 && right == 0) {
			if (sum + token == S)
				ans = 1;
		}
		return 1;
	}
}
int main() {
	int S;
	char c;
	while (scanf("%d", &S) == 1) {
		ans = 0;
		c = getchar();
		solve(0, S, &c);
		if (ans == 1)
			puts("yes");
		else
			puts("no");
	}
	return 0;
}


https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji/acm-112---tree-summing

#include <stdio.h>
int n, found;
typedef struct node {
	int value;
	struct node *left,*right;
} binaryNode;
binaryNode * buildTree() {
	int num;
	binaryNode *bNode = NULL;
	char ch1, ch2;
	while (scanf("%c", &ch1) == 1) {
		if (ch1 == '(') break;
	}
	if (scanf("%d", &num) == 1) {
		bNode = new binaryNode;
		bNode->value = num;
		bNode->left = buildTree();
		bNode->right = buildTree();
	}
	while (scanf("%c", &ch2) == 1) 
		if (ch2 == ')') 
			return bNode;
}
void root2leaf(binaryNode *nd, int sum) {
	if (!found) {
		if ((nd->left == NULL) && (nd->right == NULL)) {
			sum += nd->value;
			if (sum == n)  
				found = 1;
		}
		sum += nd->value;
		if (nd->left != NULL) 
			root2leaf(nd->left, sum);
		if (nd->right != NULL) 
			root2leaf(nd->right, sum);
	}
}
int main() {
	char ch;
	while (scanf("%d", &n) == 1) {
		found = 0;
		binaryNode *root;
		root = buildTree();
		if (root != NULL) 
			root2leaf(root, 0);
		else{
			puts("no");
			continue;
		}
		if (found) 
			puts("yes");
		else 
			puts("no");
	}
	return 0;
}



#include<stdio.h>
int ans, S;
int solve(int sum, char *c) {
	int token, flag = 0, neg;
	while (*c == ' ' || *c == '\n')
		*c = getchar();
	if (*c == '(') {
		token = 0, flag = 0, neg = 1;
		while (*c = getchar()) {
			if ('0' <= *c&&*c <= '9')
				token = token * 10 + *c - '0', flag = 1;
			else {
				if (*c == '-')neg = -1;
				else break;
			}
		}
	}
	token *= neg;
	while (*c == ' ' || *c == '\n')
		*c = getchar();
	if (flag == 0)
		return 0;

	int left = solve(sum + token, c);
	while ((*c = getchar()) != '(');
	int right = solve(sum + token, c);
	while ((*c = getchar()) != ')');
	if (left == 0 && right == 0)
		if (sum + token == S)
			ans = 1;
	return 1;
}
int main() {
	char c;
	while (scanf("%d", &S) == 1) {
		ans = 0;
		c = getchar();
		solve(0, &c);
		if (ans)puts("yes");
		else puts("no");
	}
	return 0;
}



LISP was one of the earliest high-level programming languages
and, with FORTRAN, is one of the oldest languages
currently being used. Lists, which are the fundamental data
structures in LISP, can easily be adapted to represent other
important data structures such as trees.
This problem deals with determining whether binary trees
represented as LISP S-expressions possess a certain property.
Given a binary tree of integers, you are to write a program
that determines whether there exists a root-to-leaf path whose
nodes sum to a specified integer.
For example, in the tree shown on the right there are exactly
four root-to-leaf paths. The sums of the paths are 27, 22, 26, 
and 18. Binary trees are represented in the input file as LISP 
S-expressions having the following form.
empty tree ::= ()
tree ::= empty tree j (integer tree tree)
The tree diagrammed above is represented by the expression
(5 (4 (11 (7 () ()) (2 () ()) ) ()) (8 (13 () ()) (4 () (1 () ()) ) ) )
Note that with this formulation all leaves of a tree are of the form
(integer () () )
Since an empty tree has no root-to-leaf paths, 
any query as to whether a path exists whose sum is
a specified integer in an empty tree must be answered negatively.



Input
The input consists of a sequence of test cases in the form of 
integer/tree pairs. Each test case consists
of an integer followed by one or more spaces followed by a binary tree 
formatted as an S-expression as described above. 
All binary tree S-expressions will be valid, 
but expressions may be spread over
several lines and may contain spaces. 
There will be one or more test cases in an input file, and input
is terminated by end-of-file.

Output
There should be one line of output for each test case 
(integer/tree pair) in the input file. For each
pair I; T (I represents the integer, T represents the tree) 
the output is the string ‘yes’ if there is a root-to-leaf path in 
T whose sum is I and ‘no’ if there is no path in T whose sum is I.



Sample Input
22 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
20 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
10 (3
(2 (4 () () )
(8 () () ) )
(1 (6 () () )
(4 () () ) ) )
5 ()

Sample Output
yes
no
yes
no