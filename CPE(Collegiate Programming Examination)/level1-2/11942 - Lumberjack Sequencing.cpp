11942 - Lumberjack Sequencing



#include<iostream>

int main() {
	int N,lumberjacks[12];
	bool order;
	while (scanf("%d", &N) != EOF) {
		printf("Lumberjacks:\n");
		for (int i = 0; i < N; i++) {
			order = true;
			for (int j = 0; j < 10; j++)
				scanf("%d", &lumberjacks[j]);
			for (int j = 2; j < 10; j++) {
				if ((lumberjacks[j] > lumberjacks[j - 1]) ^ (lumberjacks[j - 1] > lumberjacks[j - 2]))
					order = false;
			}

			if (order) printf("Ordered\n");
			else printf("Unordered\n");
		}
	}
	return 0;
}



Another tale of lumberjacks?. Let see . . .
The lumberjacks are rude, bearded workers, while foremen tend 
to be bossy and simpleminded.The foremen like to harass the 
lumberjacks by making them line up in groups of ten, 
ordered by the length of their beards. The lumberjacks, 
being of different physical heights, vary their arrangements to
confuse the foremen. Therefore, the foremen must actually 
measure the beards in centimeters to see if
everyone is lined up in order.
Your task is to write a program to assist the foremen in 
determining whether or not the lumberjacks are lined up 
properly, either from shortest to longest beard or from 
longest to shortest.



Input
The input starts with line containing a single integer 
N, 0 < N < 20, which is the number of groups
to process. Following this are N lines, each containing ten 
distinct positive integers less than 100.

Output
There is a title line, then one line per set of beard lengths.
See the sample output for capitalization and punctuation.
 
 
 
Sample Input
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18

Sample Output
Lumberjacks:
Ordered
Unordered
Ordered

