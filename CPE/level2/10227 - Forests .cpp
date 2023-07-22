10227 - Forests 
https://github.com/morris821028/UVa/blob/master/volume102/10227%20-%20Forests.cpp



#include <stdio.h>
#include <string.h>
int main() {
	int cas, P, T;
	char blank[200];
	scanf("%d ", &cas);
	while (cas--) {
		scanf("%d %d ", &P, &T);
		int PT[101][101] = {};
		int i, j, k;
		while (fgets(blank,sizeof(blank),stdin)) {

			if (strcmp(blank, "\n") == 0)
				break;
			sscanf(blank, "%d %d", &i, &j);
			PT[i][j] = 1;
		}
		int ans = 0, used[101] = {};
		for (i = 1; i <= P; i++) {
			if (used[i] == 0) {
				for (j = i + 1; j <= P; j++) {
					if (used[j] == 0) {
						for (k = 1; k <= T; k++)
							if (PT[i][k] != PT[j][k])
								break;
						if (k == T + 1)
							used[j] = 1;
					}
				}
				ans++;
			}
		}
		printf("%d\n", ans);
		if (cas)	
			puts("");
	}
	return 0;
}



#include<stdio.h>
#include<string.h>
int main() {
	int cas, T, P;
	char blank[120];
	scanf("%d", &cas);
	while (cas--) {
		int i, j, k, PT[105][105] = {};
		scanf("%d %d ", &P, &T);
		while (fgets(blank, sizeof(blank), stdin)) {
			if (strcmp(blank, "\n") == 0)
				break;
			sscanf(blank, "%d %d",&i, &j);
			PT[i][j] = 1;
		}
		int dif = 0, used[105] = {};
		for(i=1;i<=P;i++)
			if (used[i] == 0) {
				for (j = i + 1; j <= P; j++) 
					if (used[j] == 0) {
						for (k = 1; k <= T; k++)
							if (PT[i][k] != PT[j][k]) 
								break;						
						if (k == T + 1)
						   used[j] = 1;
					}
				dif++;
			}
		printf("%d\n", dif);
		if (cas)
			puts("");
	}
}



ex 
1
3 4
1 2
3 3
1 3
2 2
3 2
2 4

person 1 heard tree of number 2 3
person 2 heard tree of number 2 4
person 3 heard tree of number 2 3

->two different opinions 2 3 and 2 4


If a tree falls in the forest, and
there's nobody there to hear, does
it make a sound?   This classic
conundrum was coined by George
Berkeley (1685-1753), the Bishop
and  in uential  Irish  philosopher
whose primary philosophical achieve-
ment is the advancement of what
has come to be called
subjective
idealism
.  He wrote a number of
works, of which the most widely-
read are
Treatise  Concerning  the
Principles  of  Human  Knowledge
(1710)  and
Three  Dialogues  be-
tween Hylas and Philonous
(1713)
(Philonous,  the
\lover   of   the
mind"
, representing Berkeley him-
self).
A forest contains
T
trees numbered from 1 to
T
and
P
people numbered from 1 to
P
.



Input
The input begins with a single positive integer on a line by 
itself indicating the number of the cases following, 
each of them as described below.  
This line is followed by a blank line, and there is also a 
blank line between two consecutive inputs.
Standard input consists of a line containing
P
and
T
followed by several lines, containing a pair of
integers
i
and
j
, indicating that person
i
has heard tree
j
fall. People may have different opinions as
to which trees, according to Berkeley, have made a sound.

Output
For  each  test  case,  the  output  must  follow  the  
description  below.   The  outputs  of  two
consecutive cases will be separated by a blank line.
How many different opinions are represented in the input? 
Two people hold the same opinion only
if they hear exactly the same set of trees. 
You may assume that
P <
100 and
T <
100.



SampleInput
1
3 4
1 2
3 3
1 3
2 2
3 2
2 4

SampleOutput
2