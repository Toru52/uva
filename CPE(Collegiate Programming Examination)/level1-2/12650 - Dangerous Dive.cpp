12650 - Dangerous Dive



#include<stdio.h>
#include <string.h>

int main() {
	int N, R;
	int i, j;
	char mark[10005];
	while (scanf("%d %d", &N, &R) == 2) {
		memset(mark, 0, sizeof(mark));
		while (R--)
			scanf("%d", &i), mark[i] = 1;
		for (i = 1, j = 0; i <= N; i++) {
			if (mark[i] == 0) {
				j++;
				printf("%d ", i);
			}
		}
		if (!j)   
			putchar('*');
		puts("");
	}
	return 0;
}



The recent earthquake in Nlogonia did not affect too much the 
buildings in the capital, which was at the epicenter of the quake. 
But the scientists found that it affected the dike wall, 
which now has a
significant structural failure in its underground part that, 
if not repaired quickly, can cause the collapse of the dike, 
with the consequent flooding the whole capital.
The repair must be done by divers, at a large depth, under 
extremely difficult and dangerous conditions. 
But since the survival of the city is at stake, 
its residents came out in large numbers to volunteer for this 
dangerous mission. As is traditional in dangerous missions, 
each diver received at the start of his/her mission a small
card with an identification number. At the end of their mission, 
the volunteers returned the nameplate, placing it in a repository.
The dike is safe again, but unfortunately it seems that some 
volunteers did not return from their missions. 
You were hired for the grueling task of, given the plates placed 
in the repository, determine which volunteers lost their lives 
to save the city.



Input
The input contains several test cases. Each test case is 
composed of two lines. The first line contains two integers N 
and R, indicating respectively the number of volunteers that 
went to the mission and the number of volunteers that returned 
from the mission. Volunteers are identified by numbers from 1
to N. The second line contains R integers, indicating the 
volunteers which returned from the mission
(at least one volunteer returned).

Output
For each test case your program must produce a single line 
containing the identifiers of the volunteers who did not return 
from their missions, in ascending order of their identifications. Leave a blank space
after each identifier (notice that, therefore, there must be a 
blank space after the last identifier in the line). 
If every volunteer returned, the line must contain a single 
character ‘*’ (asterisc).
Restrictions
• 1 ≤ R ≤ N ≤ 104



Sample Input
5 3
3 1 5
6 6
6 1 3 2 5 4

Sample Output
2 4
*