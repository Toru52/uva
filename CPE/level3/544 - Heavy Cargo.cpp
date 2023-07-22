544 - Heavy Cargo
http://programming-helpline.blogspot.tw/2014/08/uva-544-heavy-cargo.html



#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main(){
	int n, r, cas = 0;
	while (scanf("%d %d", &n, &r),n+r){
		int w, x, y, c = 1, g[205][205]{};
		string s1, s2;
		map<string, int>W;
		for (int i = 0; i<r; i++){
			cin >> s1 >> s2 >> w;
			if (!W[s1])
				W[s1] = c++;
			if (!W[s2])
				W[s2] = c++;
			x = W[s1],y = W[s2];
			g[x][y] = w,g[y][x] = w;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)	
					g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
		cin >> s1 >> s2;
		cout << "Scenario #" << ++cas << endl;
		cout << g[W[s1]][W[s2]] << " tons" << endl << endl;
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
int main() {
	int n, r,cas=0;
	while (scanf("%d %d", &r, &n), n + r) {
		string s1, s2;
		map<string, int>W;
		int x, y, w, rank = 1, g[205][205]{};
		for (int i = 0; i < n; i++) {
			cin >> s1 >> s2 >> w;
			if (!W[s1])
				W[s1] = rank++;
			if (!W[s2])
				W[s2] = rank++;
			x = W[s1], y = W[s2];
			g[x][y] = w, g[y][x] = w;
		}
		for (int k = 1; k <= r; k++)
			for (int i = 1; i <= r; i++)
				for (int j = 1; j <= r; j++)
					g[i][j] = max(g[i][j], min(g[i][k], g[k][j]));
		cin >> s1 >> s2;
		printf("Scenario #%d\n", ++cas);
		printf("%d tons\n\n", g[W[s1]][W[s2]]);
	}
	return 0;
}



/*
ex 
ex 
k  -  s  -  u  -  m
  100   80    120

suppose that we would like to 100 tons load from k to m 
k-s track ->can go
s-u track ->can't go to u. 
            Because s-u track can take load at most 80
			
Thus only 80 tons load can go from k to m.S
  
ex 2
k  -  s  -  u  -  m
  100   80    120
80(k-m)

k  -  h  -  m 
  220    170
170(k-m)

since my job is maximum possible load,
So I choice 170(k-m) tons load



4 3
k s 100
s u 80
u m 120
k m 

5 5
k s 100
s u 80
u m 120
k h 220
h m 170
m k 
*/
Big Johnsson Trucks Inc. is a company specialized in manufacturing big trucks. 
Their latest model, the Godzilla V12, is so big that the amount of cargo you 
can transport with it is never limited by the truck itself. 
It is only limited by the weight restrictions that apply for the roads along 
the path you want to drive.
Given start and destination city, your job is to determine the maximum load of 
the Godzilla V12 so that there still exists a path between the two specified 
cities.



Input
The input file will contain one or more test cases. The first line of each 
test case will contain two integers: the number of cities n (2  n  200) 
and the number of road segments r (1  r  19900)
making up the street network.
Then r lines will follow, each one describing one road segment by naming the 
two cities connected by the segment and giving the weight limit for trucks 
that use this segment. Names are not longer than 30 characters and do not 
contain white-space characters. 
Weight limits are integers in the range 0..10000. 
Roads can always be travelled in both directions.
The last line of the test case contains two city names: start and destination.
Input will be terminated by two values of 0 for n and r.

Output
For each test case, print three lines:
• a line saying ‘Scenario #x’ where x is the number of the test case
• a line saying ‘y tons” where y is the maximum possible load
• a blank line



Sample Input
4 3
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Muenchen
5 5
Karlsruhe Stuttgart 100
Stuttgart Ulm 80
Ulm Muenchen 120
Karlsruhe Hamburg 220
Hamburg Muenchen 170
Muenchen Karlsruhe
0 0

Sample Output
Scenario #1
80 tons
Scenario #2
170 tons