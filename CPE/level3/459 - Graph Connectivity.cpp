459 - Graph Connectivity
https://github.com/Rasec09/UVa-Solutions/blob/master/459%20-%20Graph%20Connectivity.cpp



#include <iostream>
#include<string.h>
#include <vector>
using namespace std;
vector <int> G[30];
bool used[30];
void dfs(int u){
	used[u] = true;
	for (int v = 0; v < G[u].size(); v++) 
		if (!used[G[u][v]])
			dfs(G[u][v]);
}
void S(int V){
	int num = 0;
	for (int i = 1; i <= V; i++) 
		if (!used[i]) 
			num++,dfs(i);
	printf("%d\n", num);
}
int main(){
	int n, V;
	char c, a, b, s[10]{};
	scanf("%d ", &n);
	while (n--){
		memset(used, false, sizeof(used));
		memset(G, 0, sizeof(G));
		scanf("%c", &c);
		V = c - '@';
		getchar();
		while (fgets(s,sizeof(s),stdin) && 
			   sscanf(s, "%c%c", &a, &b) == 2){
			int u = a - '@',v = b - '@';
			G[u].push_back(v),G[v].push_back(u);
		}
		S(V);
		if (n)
			puts("");
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
bool used[30]{};
vector<int>G[30]{};
void dfs(int u) {
	used[u] = true;
	for (int v = 0; v < G[u].size(); v++)
		if (!used[G[u][v]])
			dfs(G[u][v]);
}
void S(int v) {
	int num = 0;
	for (int i = 1; i <= v; i++)
		if (!used[i])
			num++,dfs(i);
	printf("%d\n", num);
}
int main() {
	int n,V;
	char c, c2,s[10];
	scanf("%d ", &n);
	while (n--) {
		memset(used, 0, sizeof(used));
		memset(G, 0, sizeof(G));
		scanf("%c", &c);
		V = c - '@';
		getchar();
		while (fgets(s, sizeof(s), stdin) &&
			sscanf(s, "%c%c", &c, &c2) == 2) {
			int u = c - '@', v = c2 - '@';
			G[u].push_back(v), G[v].push_back(u);
		}
		S(V);
		if (n)
			puts("");
	}
	return 0;
}
/*
The sample input section contains a possible input set for the 
graph pictured above.
->
we must count in range selected

ex 

E ->range(A~E)
AB
CE
DB
EC
*/
Consider a graph G formed from a large number of nodes connected 
by edges. G is said to be connected if a path can be found in 0 or 
more steps between any pair of nodes in G. For example,the graph 
below is not connected because there is no path from A to C.
This graph contains, however, a number of subgraphs that are 
connected, one for each of the following sets of nodes: 
{A}, {B}, {C}, {D}, {E}, {A,B}, {B,D}, {C,E}, {A,B,D}
A connected subgraph is maximal if there are no nodes and edges in
the original graph that could be added to the subgraph and still 
leave it connected. There are two maximal connected subgraphs 
above, one associated with the nodes {A;B;D} and the other with 
the nodes {C;E}.
Write a program to determine the number of maximal connected 
subgraphs of a given graph.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases following, 
each of them as described below. 
This line is followed by a blank line, and there is also a blank 
line between two consecutive inputs.
The first line of each input set contains a single uppercase 
alphabetic character. This character represents the largest node 
name in the graph. Each successive line contains a pair of 
uppercase alphabetic characters denoting an edge in the graph.
The sample input section contains a possible input set for the 
graph pictured above. Input is terminated by a blank line.

Output
For each test case, write in the output the number of maximal 
connected subgraphs. The outputs of two consecutive cases will be 
separated by a blank line.



Sample Input
1

E
AB
CE
DB
EC

Sample Output
2

10



E  	
	AB          
     CE         
  	  DB 			
	   EC   		

Z
AB
CF

A
ZY
WS
PQ

D
AA
BB
CC
DD

E
AB
BA
AB
BA

Z
AB
BC
CD
DE
EF
FG
GH
HI
IJ
JK
KL
LM
MN
NO
OP
PQ
QR
RS
ST
TU
UV
VW
WX
XY
YZ

A

M

Z

I
AI
BI
CI
DI
IE
IF
IG
IH



2

24

1

4

4

1

1

13

26

1