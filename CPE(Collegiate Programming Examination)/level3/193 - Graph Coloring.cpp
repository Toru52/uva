193 - Graph Coloring
https://github.com/morris821028/UVa/blob/master/volume001/193%20-%20Graph%20Coloring.cpp



#include <stdio.h>
#include <string.h>
int map[101][101], mt[101];
int tmp[101], Ans[101],used[101];
int T, n, m, max;
void DFS(int node, int B, int V) {
	if (B + V == n || node == n + 1) {
	//	printf("max B %d V %d node %d\n\n", B,V,node);
		if (B > max) {
			max = B;	
			for (int i = 0; i < max; i++)
				Ans[i] = tmp[i];
		}
		return;
	}
	//can paint(used->1) black on vertex(node) and 
	//white on next vertex(map[node][i])
	if (!used[node]) {
		int reduce[101], idx = 0,newV = V;
		for (int i = 0; i < mt[node]; i++) 
			//paint white on next vertex
			if (!used[map[node][i]]) {
				used[map[node][i]] = 1, newV++;
				//reduce = vertex of V
				reduce[idx++] = map[node][i];
	//			printf("idx %d W %d node %d\n",idx, reduce[idx - 1], node);
			}
	//	printf("B %d V %d newV %d\n",B, V+1, newV);
	    //tmp=vertex of black(node)
		tmp[B] = node;
		//black part
		DFS(node + 1, B + 1, newV);
		for (int i = 0; i < idx; i++)
			used[reduce[i]] = 0;
	}
	//white part
	DFS(node + 1, B, V + used[node]);
}
int main() {
	int i, x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		memset(mt, 0, sizeof(mt));
		memset(used, 0, sizeof(mt));
		for (i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			//mt = vertex num count
			// since indirected graph,
			//so input two vertex in map 
			map[x][mt[x]++] = y;
			map[y][mt[y]++] = x;
			//		printf("map[%d][%d]=%d\n", x, mt[x], y);
			//		printf("map[%d][%d]=%d\n", y, mt[y], x);
		}
		max = 0;
		DFS(1, 0, 0);
		printf("%d\n", max);
		for (i = 0; i < max - 1; i++)
			printf("%d ", Ans[i]);
		printf("%d\n", Ans[i]);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int map[105][105], num[105];
int tmp[105], used[105], ans[105];
int t, n, m, x, y, max;
void dfs(int node,int B,int V){
	if (B + V == node||node==n+1) {
		if (max < B) {
			max = B;
			for (int i = 0; i < B; i++)
				ans[i] = tmp[i];
		}
		return ;
	}
	if (!used[node]) {
		int vertex[105], idx = 0, newV = V;
		for (int i = 0; i < num[node]; i++) 
			if (!used[map[node][i]]) {
				newV++;
				used[map[node][i]] = 1;
				vertex[idx++] = map[node][i];
			}
		tmp[B] = node;
		dfs(node + 1, B+1, newV);
		for (int i = 0; i < idx; i++)
			used[vertex[i]] = 0; 
	}
	dfs(node + 1, B, V + used[node]);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		max = 0;
		memset(used, 0, 105);
		memset(num, 0, 105);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			map[x][num[x]++] = y;
			map[y][num[y]++] = x;
		}
		dfs(1, 0, 0);
		printf("%d\n", max);
		for (int i = 0; i < max - 1; i++)
			printf("%d ", ans[i]);
		printf("%d\n", ans[max - 1]);
	}
	return 0;
}



You are to write a program that tries to find an optimal coloring
for a given graph. Colors are applied to the nodes of
the graph and the only available colors are black and white.
The coloring of the graph is called optimal if a maximum of
nodes is black. The coloring is restricted by the rule that no
two connected nodes may be black.



Input
The graph is given as a set of nodes denoted by numbers
1 : : : n, n  100, and a set of undirected edges denoted by
pairs of node numbers (n1; n2), n1 ̸= n2.
The input file contains m graphs. The number m is given on the first 
line. The first line of each graph contains n and k, the number of 
nodes and the number of edges, respectively. The following k
lines contain the edges given by a pair of node numbers, 
which are separated by a space.

Output
The output should consists of 2m lines, two lines for each graph 
found in the input file. The first line of should contain the maximum 
number of nodes that can be colored black in the graph. The second
line should contain one possible optimal coloring. 
It is given by the list of black nodes, separated by a blank.



Sample Input
1
6 8
1 2
1 3
2 4
2 5
3 4
3 6
4 6
5 6

Sample Output
3
1 4 5