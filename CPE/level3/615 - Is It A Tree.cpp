615 - Is It A Tree?
http://blog.csdn.net/mobius_strip/article/details/39782475



#include <iostream>  
#include <cstdlib>   
using namespace std;
int used[100001], sets[100001],ran[100001];
int root(int a){
	if (a != sets[a])
		sets[a] = root(sets[a]);
	return sets[a];
}
int main(){
	int a, b, t = 1;
	while (~scanf("%d%d", &a, &b) && a+b >= 0) {
		for (int i = 0; i < 100000; ++i) 
			sets[i] = i,used[i] = 0,ran[i]=0;	
		int flag = 1;
		while (a || b) {
			//find ex1 situation
			if (root(a) == root(b))
				flag = 0;
			if (flag) {
				used[a] = used[b] = 1;
				sets[root(b)] = root(a);
			}
			scanf("%d%d", &a, &b);
		}
		//find ex2 situation
		if (flag == 1) {
			int count = 0;
			for (int i = 0; i < 100000; ++i)
				if (used[i] && root(i) == i)
					if (count++) {
						flag = 0;
						break;
					}
		}
		if (flag == 0)
			printf("Case %d is not a tree.\n", t++);
		else printf("Case %d is a tree.\n", t++);
	}
	return 0;
}



#include<stdio.h>
int used[100001], p[100001];
int root(int a) {
	if (a != p[a])
		p[a] = root(p[a]);
	return p[a];
}
int main() {
	int t=1, a, b;
	while (scanf("%d %d", &a, &b), a + b >= 0) {
		for (int i = 0; i < 100000; i++)
			p[i] = i, used[i] = 0;
		int flag = 1;
		while (a || b) {
			if (root(a) == root(b))
				flag = 0;
			if (flag) {
				used[a] = used[b] = 1;
				p[root(b)] = root(a);
			}
			scanf("%d %d", &a, &b);
		}
		
		if (flag) {
			int cnt = 0;
			for(int i=0;i<100000;i++)
				if(i==root(i)&&used[i])
					if (cnt++) {
						flag = 0;
						break;
					}
		}
		printf("Case %d is ", t++);
		printf(flag == 1 ? "a tree.\n" : "not a tree.\n");
	}
	return 0;
}



/*
ex1
p c
3 8 
6 8 
6 4
5 3 
5 6 
5 2 

3 8
3=8

6 8 
6=8=3

6 4
6=4=8=3

5 3
5=3=8=6=4

5 6
5 5(5=6) ->double->not tree


ex2
1 2
3 4

1=2 3=4
1 3
->exist double number
->double tree->not tree

*suppose that there is a tree 
number of tree must be just one.
->contradiction
 */
A tree is a well-known data structure that is either empty (null, 
void, nothing) or is a set of one or more nodes connected by 
directed edges between nodes satisfying the following properties.
• There is exactly one node, called the root, to which no 
  directed edges point.
• Every node except the root has exactly one edge pointing to it.
• There is a unique sequence of directed edges from the root to 
  each node.
For example, consider the illustrations below, in which nodes are 
represented by circles and edges are represented by lines with 
arrowheads. The first two of these are trees, but the last is not.
In this problem you will be given several descriptions of 
collections of nodes connected by directed edges. 
For each of these you are to determine if the collection 
satisfies the definition of a tree or not.



Input
The input will consist of a sequence of descriptions (test cases) 
followed by a pair of negative integers.
Each test case will consist of a sequence of edge descriptions 
followed by a pair of zeroes Each edge description will consist 
of a pair of integers; the first integer identifies the node from 
which the edge begins, and the second integer identifies the node 
to which the edge is directed. Node numbers will
always be greater than zero.

Output
For each test case display the line ‘Case k is a tree.’ or the 
line ‘Case k is not a tree.’, where k corresponds to the test case
number (they are sequentially numbered starting with 1).



Sample Input
6 8 5 3 5 2 6 4
5 6 0 0
8 1 7 3 6 2 8 9 7 5
7 4 7 8 7 6 0 0
3 8 6 8 6 4
5 3 5 6 5 2 0 0
-1 -1

Sample Output
Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.