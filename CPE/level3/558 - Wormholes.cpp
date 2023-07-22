558 - Wormholes



#include<stdio.h>
int main() {
	int N, n,m;
	int g[2000][2]{}, v[2000]{}, dis[1000]{};
	bool p[1000]{1}, find;

	scanf("%d", &N);
	while(N--){
		//n->number of star systems
		//m->number of wormholes
		scanf("%d %d", &n, &m);
		for (int i = 0; i<m; i++) 
			scanf("%d %d %d", &g[i][0], &g[i][1], &v[i]);
		for (int i = 1; i<n; i++)
			for (int j = 0; j<m; j++)
				if (p[g[j][0]]) {
					if (!p[g[j][1]]) {
						dis[g[j][1]] = dis[g[j][0]] + v[j];
						p[g[j][1]] = true;
					}
					else dis[g[j][1]] = dis[g[j][0]] + v[j], printf("i %d j %d dis %d\n",i,j, dis[g[j][1]]);
				}
		find = false;
		for (int j = 0; j<m && !find; j++)
			if (p[g[j][0]])
				if (!p[g[j][1]] || dis[g[j][1]]>dis[g[j][0]] + v[j]) 
					find = true;
		puts(find == 1 ? "possible" : "not possible");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, m, N;
	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &n, &m);
		int g[2005][2]{}, v[2005]{}, dis[2005]{};
		bool find = 0, p[2005]{ 1 };
		for (int i = 0; i < m; i++)
			scanf("%d %d %d", &g[i][0], &g[i][1], &v[i]);
		for(int i=1;i<n;i++)
			for (int j = 0; j < m; j++) {
				if (p[g[j][0]])
					if (!p[g[j][1]])
						p[g[j][1]] = 1;
				dis[g[j][1]] = dis[g[j][0]] + v[j];
			}
		for (int j = 0; j < m; j++) 
			if (p[g[j][0]])
				if (dis[g[j][1]] > dis[g[j][0]] + v[j])
					find = 1;
		puts(find == 1 ? "possible" : "not possible");
	}
	return 0;
}
/*
The scientist wants to reach a cycle of 
wormholes somewhere in the universe 
that causes her to end up in the past.
in other words
some place must be less number than that place in the past
in looping place anywhere(star system number is finite) 

ex 
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

1st star system
0 1 10
2nd star system
0 1 10
3rd star system 
0 1 10
->
no change->impossible



4 4
0 1 10
1 2 20
2 3 30
3 0 -59

1st star system
0 1 10
2nd star system
0 1 11
3rd star system 
0 1 12
->
ascension->impossible



4 4
0 1 10
1 2 20
2 3 30
3 0 -61

1st star system
0 1 10
2nd star system
0 1 9
3rd star system 
0 1 8
->10>9>8
descention->possible
*/
In the year 2163, wormholes were discovered. A wormhole is a subspace 
tunnel through space and time connecting two star systems. 
Wormholes have a few peculiar properties:
• Wormholes are one-way only.
• The time it takes to travel through a wormhole is negligible.
• A wormhole has two end points, each situated in a star system.
• A star system may have more than one wormhole end point within its 
  boundaries.
• For some unknown reason, starting from our solar system, it is 
  always possible to end up in any star system by following a sequence 
  of wormholes (maybe Earth is the centre of the universe).
• Between any pair of star systems, there is at most one wormhole in 
  either direction.
• There are no wormholes with both end points in the same star system.
All wormholes have a constant time difference between their end points.
For example, a specific wormhole may cause the person travelling 
through it to end up 15 years in the future. 
Another wormhole may cause the person to end up 42 years in the past.
A brilliant physicist, living on earth, wants to use wormholes to 
study the Big Bang. Since warp drive has not been invented yet, 
it is not possible for her to travel from one star system to another 
one directly. This can be done using wormholes, of course.
The scientist wants to reach a cycle of wormholes somewhere in the 
universe that causes her to end up in the past. 
By travelling along this cycle a lot of times, 
the scientist is able to go back as far in time as necessary to reach 
the beginning of the universe and see the Big Bang with her own eyes. 
Write a program to find out whether such a cycle exists.



Input
The input file starts with a line containing the number of cases c to 
be analysed. Each case starts with a line with two numbers n and m. 
These indicate the number of star systems (1  n  1000) and
the number of wormholes (0  m  2000). The star systems are 
numbered from 0 (our solar system) through n 􀀀 1 . 
For each wormhole a line containing three integer numbers x, y and 
t is given. 
These numbers indicate that this wormhole allows someone to travel 
from the star system numbered x to the star system numbered y, 
thereby ending up t (􀀀1000  t  1000) years in the future.

Output
The output consists of c lines, one line for each case, containing the 
word ‘possible’ if it is indeed possible to go back in time 
indefinitely, or ‘not possible’ if this is not possible with the given 
set of star systems and wormholes.



Sample Input
2
3 3
0 1 1000
1 2 15
2 1 -42
4 4
0 1 10
1 2 20
2 3 30
3 0 -60

Sample Output
possible
not possible
