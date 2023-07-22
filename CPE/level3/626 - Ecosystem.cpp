626 - Ecosystem
http://mypaper.pchome.com.tw/zerojudge/post/1323192185



#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int n, g[100][100];
	vector<int> gv[100];//'1' position
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			gv[i].clear();
			for (int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
				if (g[i][j])
					gv[i].push_back(j);//make chain order per 'i'
			}
		}
		int time = 0;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < gv[i].size(); j++) 
				for (int k = 0; k < gv[gv[i][j]].size(); k++) 
					//chain or not(refer to ex)
					if (gv[gv[i][j]][k] != i && g[gv[gv[i][j]][k]][i] == 1) 
						    //ascending or not
						if ((i + 1 < gv[i][j] + 1 && gv[i][j] + 1 < gv[gv[i][j]][k] + 1) ||
						    //descending or not
							(i + 1 > gv[i][j] + 1 && gv[i][j] + 1 > gv[gv[i][j]][k] + 1))
							printf("%d %d %d\n", i + 1, gv[i][j] + 1, gv[gv[i][j]][k] + 1), time++;
		printf("total:%d\n", time);
		puts("");
	}
	return 0;
}



#include<stdio.h>
#include<vector>
using namespace std;
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int g[105][105]{}, cnt = 0;
		vector<int>v[105];
		for(int i=0;i<n;i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &g[i][j]);
				if (g[i][j])
					v[i].push_back(j);
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < v[i].size(); j++)
				for (int k = 0; k < v[v[i][j]].size(); k++)
					if (v[v[i][j]][k] != i&&g[v[v[i][j]][k]][i])
						if ((i < v[i][j] && v[i][j] < v[v[i][j]][k])||
							(i>v[i][j]&&v[i][j]>v[v[i][j]][k]))
							printf("%d %d %d\n", i + 1, v[i][j] + 1, v[v[i][j]][k] + 1), cnt++;
		printf("total:%d\n\n", cnt);
	}
	return 0;
}



/*
ex
3
0 1 0
0 0 1
1 0 0

ij  0 1 2 
0   0 1 0   ->1 since j=1,go to i=1
1   0 0 1   ->2 since j=2,go to i=2
2   1 0 0   ->3 since j=0,go to i=0
->123(ascending(ok))



3
0 0 1
1 0 0
0 1 0

ij  0 1 2 
0   0 0 1   ->3 since j=2,go to i=2
1   1 0 0   ->2 since j=0,go to i=0
2   0 1 0   ->1 since j=1,go to i=1
->321(descending(ok))
*/
There are various food chains in any ecosystem, hawk, mouse and corn to name 
one. Mice feed on corn, hawks eat mice and life goes on. 
Given the relations between the species one can easily create food chains.
One can also determine whether a chain is a cyclic one with caterpillars, 
plants, fungi and bacteria, as an example of cyclic chain. 
Caterpillars feed on plants, plants use organic substances produced by
bacteria and fungi by decomposition of dead bodies of organisms such as 
caterpillars. These constitute a 3-member cyclic food chain.
Your task is to find 3-member cyclic food chains.



Input
Unlimited number of tests. Each test consists of: number of observer species 
(n), consecutive n lines containing coincidence matrix describing food 
relations between species. 
There is ‘0’ in the (i; k)-th element when i-th species does not eat k-th 
species and respectively ‘1’ when it does so.

Output
Outputted cyclic chains, followed by word ‘total:’ and then number of cyclic 
chains. The chain consists of three species separated by spaces, 
for example ‘1 2 4’ means that 1 eats 2, which eats 4, and 1 is a food for 4.
With such a rule the chain ‘1 2 4’ is identical with ‘4 1 2’ and ‘2 4 1’ 
but not with ‘4 2 1’ (inverted sequence of prey and predator).
You should not print all identical chain (only that one with species sorted 
with ascend or descend order). 
Chains should be sorted. This means that the chains ‘1 2 4’, ‘1 2 3’ and 
‘3 2 1’ should be printed in the following order:
1 2 3
1 2 4
3 2 1
Output a blank line after each test case.
Assumptions: number of species in one test belongs to a range [3; 100].



Sample Input
3
0 1 0
0 0 1
1 0 0
3
0 0 1
1 0 0
0 1 0
3
0 1 1
1 0 1
1 1 0
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

Sample Output
1 2 3
total:1
3 2 1
total:1
1 2 3
3 2 1
total:2
1 2 3
1 2 4
1 3 4
2 3 4
3 2 1
4 2 1
4 3 1
4 3 2
total:8
