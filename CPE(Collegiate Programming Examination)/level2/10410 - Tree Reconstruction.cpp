10410 - Tree Reconstruction
http://blog.csdn.net/keshuai19940722/article/details/38778243



#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int root,x,N, pos[1005];
	while (scanf("%d", &N) == 1) {
		vector<int> g[1005] = {};
		for (int i = 1; i <= N; i++) {
			scanf("%d", &x);
			pos[x] = i;
		}
		stack<int> sta;
		scanf("%d", &root);
		sta.push(root);

		for (int i = 1; i < N; i++) {
			scanf("%d", &x);

			while (true) {
				int u = sta.top();
          //   bfs->u dfs->x
				if (u == root || pos[u] + 1 < pos[x]) {
					//printf("u %d x %d pos[u]+1 = %d pos[x] = %d\n", u, x,pos[u]+1,pos[x]);
					g[u].push_back(x);
					sta.push(x);
					break;
				}
				else
					sta.pop();
			}
		}
		for (int i = 1; i <= N; i++) {
			printf("%d:", i);
			for (int j = 0; j < g[i].size(); j++)
				printf(" %d", g[i][j]);
			printf("\n");
		}
	}
	return 0;
}



#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
int main() {
	int n, c, root, pos[1005];
	while (~scanf("%d", &n)) {
		vector<int>pc[1005];
		stack<int>sta;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c);
			pos[c] = i;
		}
		scanf("%d", &root);
		sta.push(root);
		for (int i = 1; i < n; i++) {
			scanf("%d", &c);
			while (1) {
				int p = sta.top();
				if (root == p || pos[p] + 1 < pos[c]) {
					pc[p].push_back(c);
					sta.push(c);
					break;
				}
				else
					sta.pop();
			}
		}
		for (int i = 1; i <= n; i++) {
			printf("%d:", i);
			for (int j = 0; j < pc[i].size(); j++)
				printf(" %d", pc[i][j]);
			puts("");
		}
	}
	return 0;
}



/*
parent:child 
1: 7
2: 6
3: 1 2
4: 3 5
5: 8
6:
7:
8:
*/

http://mypaper.pchome.com.tw/zerojudge/post/1324808111

#include <stdio.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int BFS[1005], DFS[1005];
int n;
vector<int> g[1005];
vector<int> sub_dfs[1005];
int root[1005];
int dfs(int nd, int &bidx) {
	/*printf("%d %d:\n", nd, bidx);
	for(int i = 0; i < sub_dfs[nd].size(); i++)
	printf("%d ", sub_dfs[nd][i]);
	puts("");*/
	int i, x;
	for (i = 0; i < sub_dfs[nd].size(); i++) {
		if (sub_dfs[nd][i] == BFS[bidx] && bidx < n) {
			x = BFS[bidx];
			g[nd].push_back(x);
			root[x] = nd;
			bidx++, i++;
			while (bidx < n && i < sub_dfs[nd].size()) {
				if (sub_dfs[nd][i] == BFS[bidx])
					break;
				sub_dfs[x].push_back(sub_dfs[nd][i]);
				root[sub_dfs[nd][i]] = x;
				i++;
			}
			i--;
		}
	}
	while (bidx < n)
		dfs(root[BFS[bidx]], bidx);
}
void print(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
		printf("%d:", i);
		for (j = 0; j < g[i].size(); j++)
			printf(" %d", g[i][j]);
		puts("");
	}
}
int main() {
	int i;
	while (scanf("%d", &n) == 1) {
		for (i = 0; i < n; i++)
			scanf("%d", &BFS[i]);
		for (i = 0; i < n; i++)
			scanf("%d", &DFS[i]);
		for (i = 0; i <= n; i++)
			g[i].clear(), sub_dfs[i].clear();
		for (i = 1; i < n; i++)
			sub_dfs[BFS[0]].push_back(DFS[i]);
		int bidx = 1;
		dfs(BFS[0], bidx);
		print(n);
	}
	return 0;
}