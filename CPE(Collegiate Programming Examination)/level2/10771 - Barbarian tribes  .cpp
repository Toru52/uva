10771 - Barbarian tribes  
explain
http://blog.csdn.net/bobodem/article/details/50396641

https://github.com/zimpha/acm-icpc/blob/master/UVA/10771%20-%20Barbarian%20tribes.cc



#include <cstdio>

int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3 && k) {
		if (m & 1) puts("Keka");
		else puts("Gared");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3 && k) {
		if (m & 1)puts("Keka");
		else puts("Gared");
	}
	return 0;
}



/*
gk->k
kg->k
gg->g
kk->g
ex 3 3 2
g1g2g3k4k5k6
g1g3k7k5k6 
g1k8k7k5
g1g9k7
g9k10
k11
*/



In a lost land two primitive tribes coexist: Gareds and Kekas. 
Every summer solstice they meet and compete to decide which tribe will 
be the favorite of the gods for the rest of the year, following an old 
ritual:
First, a local guru chooses three numbers at random: n, m and k.
Afterwards, n Gared maids (in the positions 1; 2; : : : ; n) and 
m Keka maids(in the positions n+1; n+2; : : : ; n+m) are placed in a 
circle looking inwards.
Then the guru begins to count 1; 2; : : : ; k starting at the rst 
Gared maid.When the k-th maid is reached, she is immediately 
sacriced to the gods. The guru then counts again 1; 2; : : : ; k 
starting at the maid following the one just sacriced. Again, 
the k-th maid reached this way is sacriced.
After every two sacrices, the second sacriced maid is replaced by 
a new maid. In order to decide the tribe of the new maid, 
the guru looks at the heads of the two maids just killed 
(nothing else remains of them). 
If both heads are of the same tribe, the guru calls a Gared maid. 
If the heads are from different tribes, the guru calls a Keka maid.
The process then begins again (counting and sacricing twice and 
replacing once) starting to count at the maid following the new maid 
just added to the circle. Since the number of maids reduces by one
after every step (of two sacrices and one replacement), 
after n + m 􀀀 1 steps only one maid remains.
According to the tradition, the tribe of the last maid will be the 
favorite of the gods. 
(What the guru does to the last maid is something you don't want to 
know.) 
Anyway, write a program such that,
given n, m and k, writes the name of the fortunate tribe.
For example, this is what happens for n = m = 3 and k = 2 
(a \G" denotes a Gared maid and a \K" denotes a Keka maid; 
the subindexes mark the order the maids enter the circle):
1. Initial content of the circle: G1 G2 G3 K4 K5 K6 Starting to count 
at G1. First sacrice: G2.
Second sacrice: K4 (replaced by K7).
2. Content of the circle: G1 G3 K7 K5 K6 Starting to count at K5. 
First sacrice: K6. Second
sacrice: G3 (replaced by K8).
3. Content of the circle: G1 K8 K7 K5 Starting to count at K7. 
First sacrice: K5. Second sacrice:
K8 (replaced by G9).
4. Content of the circle: G1 G9 K7 Starting to count at K7. 
First sacrice: G1. Second sacrice:
K7 (replaced by K10).
5. Content of the circle: G9 K10 Starting to count at G9. 
First sacrice: K10. Second sacrice: G9
(replaced by K11).
6. Final content of the circle: K11



Input
Input consists of zero ore more test cases. 
Each test case consists of a line with three positive integers:
n, m and k. You can assume 1  n + m  2000 and 1  k  1000.
 A test case with n = m = k = 0
ends the input and must not be processed.

Output
For every test case, print either `Gared' or `Keka' as convenient.



Sample Input
3 3 2
4 2 2
0 1 7
0 0 0

Sample Output
Keka
Gared
Keka