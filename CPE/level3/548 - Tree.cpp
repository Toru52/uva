548 - Tree
http://liu233w.github.io/blog/2016/05/04/uva-548/



#include <iostream>
#include <sstream>
#include<algorithm>
#include <string>
using namespace std;
int ans, minn, I[10010], P[10010];
//walk on tree on 
//left->postorder mainly
//L,H->inorder mainly
//walk from behind number
void solve(int L, int H, int left, int path) {
	if (H <= L)
		return;
	if (H - L <= 1) {
		if (I[L] + path < minn)
			minn = I[L] + path, ans = I[L];
		return;
	}
	//when this forked road, 
	//I[i] walk at parent,P[i] walk at others child 
	//i->like a median
	int i = find(I + L, I + H, P[left]) - I;
	//jump to left subtree 
	solve(i + 1, H, left - 1, path + P[left]);
	//jump to right subtree
	solve(L, i, left - H + i, path + P[left]);
}
int main() {
	string in,post;
	while (getline(cin, in)) {
		getline(cin, post);
		minn = 1e9;
		istringstream stL(in), stM(post);
		int N = 0;
		while (stL >> I[N])
			stM >> P[N++];
		solve(0, N, N - 1, 0);
		cout << ans << endl;
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
using namespace std;
int least,minn, in[10005], post[10005];
void walk(int L, int H, int ip, int sum) {
	if (H <= L)
		return;
	if (H-L<=1) {
		if (minn > sum + in[L])
			minn = sum + in[L], least = in[L];
		return;
	}
	
	int m = find(in + L, in + H, post[ip]) - in;
	walk(m + 1, H, ip - 1, sum + post[ip]);
	walk(L, m, m + ip - H, sum + post[ip]);
}
int main() {
	string I, P;
	while (getline(cin, I)) {
		getline(cin, P);
		minn = 1e9;
		int n = 0;
		stringstream strI(I), strP(P);
		while (strI >> in[n])
			strP >> post[n++];
		walk(0, n, n - 1, 0);
		printf("%d\n", least);
	}
	return 0;
}



/*
traversal tree
ex
inorder
3 2 1 4 5 7 6
postorder
3 1 2 5 6 7 4
->
       4
  2         7
3   1     5   6   
->
9   7    16    17
->7 is lowest value->this leaf(lowest rank)->1



7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
->
      5
 7         12
   11    16  18
  8  3           
->
 31  26  33  35
->26->last leaf is 3



How to make tree as computer eyes

ex
in 
3 2 1 4 5 7 6
post
3 1 2 5 6 7 4

walk from behind number as post order mainly
post 4
in left sub tree(3 2 1   4)   right sub tree (5 7 6)
post 7
5 7 6
->last leaf is 5,6

post 2
in 3 2 1
->last leaf 3,1
*/
You are to determine the value of the leaf node in a given binary tree 
that is the terminal node of a path of least value from the root of the 
binary tree to any leaf. The value of a path is the sum of values
of nodes along that path.



Input
The input file will contain a description of the binary tree given as 
the inorder and postorder traversal sequences of that tree. 
Your program will read two line (until end of file) from the input file.
The first line will contain the sequence of values associated with an
inorder traversal of the tree and the second line will contain the 
sequence of values associated with a postorder traversal of the tree. 
All values will be different, greater than zero and less than 10000. 
You may assume that no binary tree will have more than 10000 nodes or 
less than 1 node.

Output
For each tree description you should output the value of the leaf node 
of a path of least value. In the case of multiple paths of least value 
you should pick the one with the least value on the terminal node.



Sample Input
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255

Sample Output
13
255