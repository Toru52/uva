315 - Network
http://mypaper.pchome.com.tw/zerojudge/post/1322853931/
explain abou Network
https://mathtrain.jp/kyorenketsu
http://d.hatena.ne.jp/mkiken/touch/20130425/1366895887
http://programming-study-notes.blogspot.tw/2014/05/uva-315-poj-1144-network.html
cut vertex
http://dopal.cs.uec.ac.jp/okamotoy/lect/2012/graphtheory/lect10.pdf#search=%27%E3%82%B0%E3%83%A9%E3%83%95+cut+vertex%27
http://aiweb.cs.ehime-u.ac.jp/~ninomiya/archive/infomath/im1-12.pdf#search=%27%E5%88%87%E6%96%AD%E7%82%B9%27
http://d.hatena.ne.jp/mkiken/20130425


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int link[100][100], n;
int depth[100], low[100];
int used[100], cut;
int DFS(int node, int d, int parent) {
	int back = 1000, son = 0, tmp, flag = 0;
	//How many steps(d) foward to node
	depth[node] = d;
	for (int i = 1; i <= n; i++) 
		if (link[node][i] == 1) {
			if (used[i] == 0) {
				used[i] = 1;
				tmp = DFS(i, d + 1, node);
				//To avoid triangle graph case
				if (tmp >= d)	flag = 1;
				back = back < tmp ? back : tmp;
				//printf("node %d i %d d %d tmp %d back %d\n", node, i, d,tmp,back);
				son++;
			}
			else 
				if (i != parent)
					back = back < depth[i] ? back : depth[i];
		}
	low[node] = back;
	//If node 1 have two sons or more,
	//Even if whatever,wherever node connected to,
	// It established "cut vertex".
	//ex 1-2,1-3 ->parent 1 sons 2,3 cut vertex node ->1
	if (node == 1) {
		if (son > 1)
			cut++;	}
	else 
		cut += flag;
	return low[node];
}
int main() {
	int x, y;
	char c;
	while (scanf("%d", &n) == 1 && n) {
		memset(link, 0, sizeof(link));
		memset(depth, 0, sizeof(depth));
		memset(low, 0, sizeof(low));
		memset(used, 0, sizeof(used));
		while (scanf("%d", &x) == 1 && x) {
			while (scanf("%d%c", &y, &c) == 2) {
				link[x][y] = 1;
				link[y][x] = 1;
				if (c == '\n')	break;
			}
		}
		used[1] = 1;
		cut = 0;
		DFS(1, 1, 0);
		printf("%d\n", cut);
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int n, cut = 0, graph[100][100];
int used[100], depth[100];
int dfs(int node, int d, int p) {
	int tmp, flag = 0, son = 0, back = 100;
	depth[node] = d;

	for (int i = 1; i <= n; i++) 
		if (graph[node][i]==1) {
			if (!used[i]) {
				used[i] = 1;
				tmp = dfs(i, d + 1, node);
				if (tmp >= d)flag = 1;
				back = (back < tmp) ? back : tmp;

				son++;
			}
			else if (p != i)
				back = (back < depth[i]) ? back : depth[i];
		}
	if (node == 1) {
		if (son > 1)cut++;
	}
	else
		cut += flag;
	return back;
}
int main() {
	int x, y;
	char c;
	while (scanf("%d", &n), n) {
		memset(used, 0, sizeof(used));
		memset(depth, 0, sizeof(depth));
		memset(graph, 0, sizeof(graph));
		used[1] = 1, cut = 0;
		while(scanf("%d",&x),x)
			while (scanf("%d%c", &y, &c) == 2) {
				graph[x][y] = 1, graph[y][x] = 1;
				if (c == '\n')break;
			}
		dfs(1, 1, 0);
		printf("%d\n", cut);
	}
	return 0;
}



/*
Search how many cut verticals in graph
They are connecting
several places numbered by integers from 1 to
from 1
*/

A Telephone Line Company (TLC) is establishing a new telephone 
cable network. They are connecting several places numbered by 
integers from 1 to N. No two places have the same number. 
The lines are bidirectional and always connect together two places 
and in each place the lines end in a telephone exchange. 
There is one telephone exchange in each place. 
From each place it is possible to reach through lines every other 
place, however it need not be a direct connection, 
it can go through several exchanges. 
From time to time the power supply fails at a place and then the 
exchange does not operate.
The officials from TLC realized that in such a case it can happen 
that besides the fact that the place with the failure is 
unreachable, this can also cause that some other places cannot 
connect to each other.
In such a case we will say the place (where the failure occured) 
is critical. Now the officials are trying to write a program for 
finding the number of all such critical places. Help them.



Input
The input file consists of several blocks of lines. Each block 
describes one network. In the first line of each block there is 
the number of places N < 100. Each of the next at most N lines 
contains the number of a place followed by the numbers of some 
places to which there is a direct line from this place.
These at most N lines completely describe the network, i.e., 
each direct connection of two places in the network is contained 
at least in one row. All numbers in one line are separated by one 
space. Each block ends with a line containing just ‘0’. 
The last block has only one line with N = 0.

Output
The output contains for each block except the last in the input 
file one line containing the number of critical places.



Sample Input
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0

4
1 4 2 3
2 4
0
3
2 1 3
0
0

Sample Output
1
2

1
1
