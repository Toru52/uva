122 - Trees on the level
https://github.com/lamphanviet/competitive-programming/blob/master/uva-online-judge/accepted-solutions/122%20-%20Trees%20on%20the%20level.cpp



#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define For(i, a, b) for (int i=a; i<=b; i++)
#define M 1000000
int val[M], Maxp;
bool Exist[M], cmpl;
//check whether it composed tree or not
bool Check() {
	if (!Exist[1]) return false;
	for (int i = 2; i <= Maxp; i += 2) {
		bool Child = Exist[i] || Exist[i + 1];
		//           L part      R part
		if (Child && !Exist[i / 2]) return false;
	}
	return true;
}

int main() {
	int a, len;
	char s[300], path[300];
	while (scanf("%s", &s) != EOF) {
		Maxp = 1; cmpl = true;
		memset(Exist, false, M);
		while (1) {
			if (strcmp(s, "()") == 0) break;
			sscanf(s, "(%d,%s)", &a, &path);
			len = strlen(path);
			int p = 1;
			For(i, 0, len - 2) {
				p *= 2;
				if (path[i] == 'R') p++;
			}
			//	printf("len %d p %d V %d\n", len, p,V);
			//no double at same position
			if (Exist[p]) cmpl = false;
			Exist[p] = true;
			val[p] = a;
			Maxp = max(p, Maxp);
			scanf("%s", &s);
		}
		if (!cmpl || !Check()) puts("not complete");
		else {
			printf("%d", val[1]);
			For(i, 2, Maxp)
				if (Exist[i]) printf(" %d", val[i]);
			printf("\n");
		}
	}
}



#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int val[300], M;
bool used[300], flag;

bool Check() {
	if (!used[1]) return false;
	for (int i = 2; i <= M; i += 2) {
		bool Child = used[i] || used[i + 1];
		//parent
		if (Child && !used[i / 2])
			return false;
	}
	return true;
}
int main() {
	int V, len;
	char s[300], LR[300];
	while (~scanf("%s", &s)) {
		M = 1; flag = true;
		memset(used, false, 300);
		while (1) {
			if (strcmp(s, "()") == 0) break;
			sscanf(s, "(%d,%s)", &V, &LR);
			len = strlen(LR);
			int p = 1;
			for (int i = 0; i <= len - 2; i++) {
				p *= 2;
				if (LR[i] == 'R')
					p++;
			}
			//no double
			if (used[p])
				flag = false;
			used[p] = true;
			val[p] = V;
			M = max(p, M);
			scanf("%s", &s);
		}
		if (!flag || !Check())
			puts("not complete");
		else {
			printf("%d", val[1]);
			for (int i = 2; i <= M; i++)
				if (used[i])
					printf(" %d", val[i]);
			printf("\n");
		}
	}
}



#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool used[300], flag;
int M;
int check() { 
	if (!used[1])return true;
	for (int i = 2; i <= M; i+=2) {
		bool child = used[i] || used[i + 1];
		if (child && !used[i / 2])
			return true;
	}
	return false;
}
int main() {
	char LR[300], s[300];
	int len,val[300],V;
	while (~scanf("%s", &s)) {
		M = 1,flag=1;
		memset(used, false, 300);
		while (1) {
			if (strcmp(s, "()") == 0)break;
			sscanf(s, "(%d,%s)",&V,&LR);
			len = strlen(LR);
			int p = 1;
			for (int i = 0; i < len - 1; i++) {
				p *= 2;
				if (LR[i] == 'R')p++;
			}
			if (used[p])
				flag = false;
			used[p] = true;
			val[p] = V;
			M = max(M, p);
			scanf("%s",&s);
		}
		if (!flag || check())
			puts("not complete");
		else {
			printf("%d", val[1]);
			for (int i = 2; i <= M; i++) {
				if (used[i])
					printf(" %d", val[i]);
			}
			puts("");
		}
	}
	return 0;
}
/*
p=
no->1
L->n+2(ever)
R->n+1(odd)

LL->4
RR->6
...

*/
Trees are fundamental in many branches of computer science 
(Pun definitely intended). Current stateof-the art parallel computers 
such as Thinking Machines’ CM-5 are based on fat trees. Quad- and
octal-trees are fundamental to many algorithms in computer graphics.
This problem involves building and traversing binary trees.
Given a sequence of binary trees, you are to write a program
that prints a level-order traversal of each tree. In this
problem each node of a binary tree contains a positive integer
and all binary trees have have fewer than 256 nodes.
In a level-order traversal of a tree, the data in all nodes at
a given level are printed in left-to-right order and all nodes at
level k are printed before all nodes at level k + 1.
For example, a level order traversal of the tree on the right
is: 5, 4, 8, 11, 13, 4, 7, 2, 1.
In this problem a binary tree is specified by a sequence
of pairs ‘(n,s)’ where n is the value at the node whose path
from the root is given by the string s. A path is given be
a sequence of ‘L’s and ‘R’s where ‘L’ indicates a left branch and ‘R’ 
indicates a right branch. In the tree diagrammed above, 
the node containing 13 is specified by (13,RL), and the node 
containing 2 is specified by (2,LLR). The root node is specified by 
(5,) where the empty string indicates the path from
the root to itself. A binary tree is considered to be completely 
specified if every node on all root-to-node
paths in the tree is given a value exactly once.



Input
The input is a sequence of binary trees specified as described above. 
Each tree in a sequence consists of several pairs ‘(n,s)’ as 
described above separated by whitespace. 
The last entry in each tree is ‘()’.
No whitespace appears between left and right parentheses.
All nodes contain a positive integer. Every tree in the input will 
consist of at least one node and
no more than 256 nodes. Input is terminated by end-of-file.

Output
For each completely specified binary tree in the input file, the 
level order traversal of that tree should be printed. 
If a tree is not completely specified, i.e., 
some node in the tree is NOT given a value or a
node is given a value more than once, 
then the string ‘not complete’ should be printed.



Sample Input
(11,LL) (7,LLL) (8,R)
(5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()

Sample Output
5 4 8 11 13 4 7 2 1
not complete