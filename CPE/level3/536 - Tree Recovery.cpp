536 - Tree Recovery  
http://knightzone.org/?p=3132

about preorder,postorder,inorder
https://www.youtube.com/watch?v=0QOtVxTVj4w&t=124s



#include <iostream>
#include <string>
using namespace std;
string pre, in;
//preI->cnt
int po(int preI, int inL, int inH) {
	if (inL >= inH) 
		return preI;
	for (int i = inL; i < inH; ++i) 
		if (in[i] == pre[preI]) 
			//LRP
			preI = po(preI + 1, inL, i);
			preI = po(preI, i + 1, inH);
			printf("%c", in[i]);
			break;
		}
	return preI;
}
int main() {
	while (cin >> pre >> in) 
		po(0, 0, in.length()),printf("\n");
	return 0;
}



#include<iostream>
#include<string>
using namespace std;
string pre, in;
int po(int i, int L, int H) {
	if (L >= H)
		return i;
	for (int j = 0; j < H; j++) 
		if (pre[i] == in[j]) {
			i = po(i + 1, L, j);
			i = po(i, j + 1, H);
			printf("%c", in[j]);
			break;
		}
	return i;
}
int main() {
	while (cin >> pre >> in)
		po(0, 0, in.length()), puts("");
	return 0;
}



/*
ex
pre->BST from top
in ->from left to right

pre->(PLR)
post->(LRP)
in->(LPR)

ex
round 1:
d bacegf(pre)
abc d efg(in)
d-> 

2:
b acegf
a b c  efg
b->

3:
a cegf
a b c  efg
a->(divide last)

4:
c egf
b c  efg
c->(divide last)

5:
e gf
e fg
e->

6:
g f
f g
g->
e->


*/
Little Valentine liked playing with binary trees very much.
Her favorite game was constructing randomly
looking binary trees with capital letters in the nodes.
This is an example of one of her creations:
D
/ \
/ \
B E
/ \ \
/ \ \
A C G
/
/
F
To record her trees for future generations, she wrote down two strings for 
each tree: a preorder traversal (root, left subtree, right subtree) and an 
inorder traversal (left subtree, root, right subtree).
For the tree drawn above the preorder traversal is DBACEGF and the inorder 
traversal is ABCDEFG.
She thought that such a pair of strings would give enough information to 
reconstruct the tree later (but she never tried it).
Now, years later, looking again at the strings, 
she realized that reconstructing the trees was indeed possible, 
but only because she never had used the same letter twice in the same tree.
However, doing the reconstruction by hand, soon turned out to be tedious.
So now she asks you to write a program that does the job for her!



Input
The input file will contain one or more test cases.
Each test case consists of one line containing two strings ‘preord’ and 
‘inord’, representing the preorder traversal and inorder traversal of a 
binary tree. Both strings consist of unique capital letters.
(Thus they are not longer than 26 characters.)
Input is terminated by end of file.

Output
For each test case, recover Valentine’s binary tree and print one line 
containing the tree’s postorder
traversal (left subtree, right subtree, root).



Sample Input
DBACEGF ABCDEFG
BCAD CBAD

Sample Output
ACBFGED
CDAB