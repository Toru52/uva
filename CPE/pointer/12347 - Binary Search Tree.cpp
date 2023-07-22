12347 - Binary Search Tree   
http://programming-study-notes.blogspot.tw/2014/03/uva-12347-binary-search-tree.html

concept
https://www.youtube.com/watch?v=0QOtVxTVj4w&vl=en



#include <cstdio>
using namespace std;
struct Tree {
	int val = 0;
	Tree *L = nullptr;
	Tree *R = nullptr;
};
Tree *Insert(Tree *H, int node)
{
	Tree *N = new Tree;
	N->val = node;

	if (H == nullptr) return N;

	Tree *T = H, *nxt = H;
	//dig part 
	while (nxt != nullptr) {
		T = nxt;
		if (node > nxt->val) nxt = nxt->R;
		else nxt = nxt->L;
	}
	//import val part
	if (node > T->val) T->R = N;
	else T->L = N;
	return H;
}
void Post_Order(Tree *Root)
{
	if (Root == nullptr) return;
	//dig priority left 
	//then start to up and shift right from left side  
	Post_Order(Root->L);
	Post_Order(Root->R);
	printf("%d\n", Root->val);
}
int main()
{
	Tree *head = nullptr;
	int node;
	while (scanf("%d", &node) != EOF)
		head = Insert(head, node);
	Post_Order(head);
	return 0;
}



/*
ex
12,9,5,4,7,10,15,13,19,16
4,7,5,10,9,13,16,19,15,12

image
Pre-order: 50 30 24 5 28 45 98 52 60
Post-order: 5 28 24 45 30 60 52 98 50
          50
    30          98
 24    45    52
5  28          60


            L|val|R
           30|50|98
     24|30|45    52|98
5|24|28           52|60
*/



A binary search tree is a binary tree that satises the following 
properties:
 The left subtree of a node contains only nodes with keys less than the 
node's key.
 The right subtree of a node contains only nodes with keys greater 
than the node's key.
 Both the left and right subtrees must also be binary search trees.
Figure 1. Example binary search tree
Pre-order traversal (Root-Left-Right) prints out the nodes key by visiting 
the root node then travers-ing the left subtree and then traversing the 
right subtree. Post-order traversal (Left Right-Root) prints out 
the left subtree rst and then right subtree and nally the root node. 
For example, the results of pre-order traversal and 
post-order traversal of the binary tree shown in Figure 1 are as follows:
Pre-order: 50 30 24 5 28 45 98 52 60
Post-order: 5 28 24 45 30 60 52 98 50
Given the pre-order traversal of a binary search tree, you task is to 
nd the post-order traversal of this tree.



Input
The keys of all nodes of the input binary search tree are given according 
to pre-order traversal. Each node has a key value which is a positive 
integer less than 106. All values are given in separate lines
(one integer per line). You can assume that a binary search tree does not 
contain more than 10,000 nodes and there are no duplicate nodes.

Output
The output contains the result of post-order traversal of the input 
binary tree. Print out one key per line.



Sample Input
50
30
24
5
28
45
98
52
60

Sample Output
5
28
24
45
30
60
52
98
50