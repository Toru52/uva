10959 - The Party, Part I
http://blog.csdn.net/mobius_strip/article/details/51534598



#include <cstring>  
#include <cstdio>  
int link[1001][1001], dis[1001];
void bfs(int P)
{
	int head = 0, tail = 1, queue[1001]{};
	for (int i = 0; i < P; ++i)
		dis[i] = P;
	dis[0] = 0;

	while (head < tail) {
		//head increase every one turn		
		int i = queue[head++];
		printf("be queue[%d] %d \n", head - 1, queue[head - 1]);
		 //start from zero number(It's not from input number)
		 //A number is independent if break out on a route to some place.
		 //tails increase when react if function	
		for (int j = 0; j < P; ++j)
			if (link[i][j] && dis[j] > dis[i] + 1) {
				dis[j] = dis[i] + 1;
				printf("now %d dis[%d]=%d\n", i, j, dis[j]);
				queue[tail++] = j;
			}printf("af queue[%d] %d\n\n", tail - 1, queue[tail - 1]);
	}
}
int main() {
	int t, P, D, u, v;
	while (~scanf("%d ", &t))
		while (t--) {
			memset(link, 0, sizeof(link));
			scanf("%d%d", &P, &D);
			for (int i = 0; i < D; ++i) {
				scanf("%d%d", &u, &v);
				link[u][v] = 1; link[v][u] = 1;
			}
			bfs(P);
			for (int i = 1; i < P; ++i)
				printf("%d\n", dis[i]);
			if (t) puts("");
		}
	return 0;
}




#include <cstring>  
#include <cstdio>  
int link[1001][1001], dis[1001];
void bfs(int P)
{
	int head = 0, tail = 1, queue[1001]{};
	for (int i = 0; i < P; ++i)
		dis[i] = P;
	dis[0] = 0;

	while (head < tail) {
		int i = queue[head++];
		for (int j = 0; j < P; ++j)
			if (link[i][j] && dis[j] > dis[i] + 1) {
				dis[j] = dis[i] + 1;
				queue[tail++] = j;
			}
	}
}
int main() {
	int t, P, D, u, v;
	while (~scanf("%d ", &t))
		while (t--) {
			memset(link, 0, sizeof(link));
			scanf("%d%d", &P, &D);
			for (int i = 0; i < D; ++i) {
				scanf("%d%d", &u, &v);
				link[u][v] = 1; link[v][u] = 1;
			}
			bfs(P);
			for (int i = 1; i < P; ++i)
				printf("%d\n", dis[i]);
			if (t) puts("");
		}
	return 0;
}
 


 
/*
problem image
ex
5 6
0 1
0 2
3 2
2 4
4 3
1 2
->
1 1
2 1
3 2
4 2
->
1&2 pair(1)
3&4 pair(2)

5 5
1 2
0 1
2 3
3 4
0 4
->
1 1
2 2
3 2
4 1
->
1&4 pair(1)
2&3 pair(2)
*/


Don Giovanni likes to dance{especially with girls! And everyone else 
in the party enjoyed the dance,
too. Getting a chance to dance with the host (that is Don Giovanni) is 
the greatest honour; failing that, dancing with someone who has danced 
with the host or will dance with the host is the second greatest honour. 
This can go further. Dene the Giovanni number of a person as follows, 
at the time after the party is over and therefore who has danced with 
whom is completely known and xed:
1. No one has a negative Giovanni number.
2. The Giovanni number of Don Giovanni is 0.
3. If a person p is not Don Giovanni himself, and has danced with 
someone with Giovanni number n, and has not danced with anyone with a 
Giovanni number smaller than n, then p has Giovanni
number n + 1.
4. If a person's Giovanni number cannot be determined from the above 
rules (he/she has not danced with anyone with a nite Giovanni number), 
his/her Giovanni number is 1. Fortunately, 
you will not need this rule in this problem.
Your job is to write a program to compute Giovanni numbers.



Input
The input begins with a single positive integer on a line by itself 
indicating the number of the cases following, each of them as described 
below. This line is followed by a blank line, and there is also a
blank line between two consecutive inputs.
The rst line has two numbers P and D; this means there are P persons 
in the party (including Don Giovanni) and D dancing couples 
(P  1000 and D  P(P 􀀀 1)=2:) Then D lines follow, each containing 
two distinct persons, meaning the two persons has danced. 
Persons are represented by numbers between 0 and P 􀀀 1; 
Don Giovanni is represented by 0.
As noted, we design the input so that you will not need the 1 rule in 
computing Giovanni numbers.
We have made our best effort to eliminate duplications in listing the 
dancing couples, e.g., 
if there is a line \4 7" among the D lines, then this is the only 
occurrence of \4 7", and there is no occurrence of \74". 
But just in case you see a duplication, you can ignore it 
(the duplication, not the rst occurrence).



Output
For each test case, the output must follow the description below. 
The outputs of two consecutive cases
will be separated by a blank line.
Output P 􀀀 1 lines. Line i is the Giovanni number of person i, 
for 1  i  P 􀀀 1. Note that it is
P 􀀀 1 because we skip Don Giovanni in the output.



Sample Input
2

5 6
0 1
0 2
3 2
2 4
4 3
1 2

5 5
1 2
0 1
2 3
3 4
0 4

Sample Output
1
1
2
2

1
2
2
1
