11000 - Bee



#include <cstdio>

int main() {
	long long int maleBee[70] = {}, femaleBee[70] = { 1 };
	for (int i = 1; i < 70; ++i) {
		maleBee[i] = maleBee[i - 1] + femaleBee[i - 1];
		femaleBee[i] = maleBee[i - 1] + 1;
	}
	int N;
	while (scanf("%d", &N),N != -1) 
		printf("%lld %lld\n", maleBee[N], maleBee[N] + femaleBee[N]);
	return 0;
}



#include<stdio.h>
int main() {
	long long int N,m[50] = {}, f[50] = { 1 };
	for (int i = 1; i < 50; i++) {
		m[i] = m[i - 1] + f[i - 1];
		f[i] = m[i-1] + 1;
	}
	while (scanf("%lld", &N), N != -1) 
		printf("%lld %lld\n", m[N], m[N] + f[N]);
	return 0;
}



/*
concept
*1 queen bee just one live.
1
f,m
1 2



2
m->0
->
f,m 1 2

f
->
m   1 2

2 4



3
f,f->1(*1)
->m,m 2 3

m,m,->0
->f,m,f,m 2 4

4 7



4
f,f,f->1(*1)
->m,m,m 3 4
m,m,m,m->0
->f,m,f,m,f,m,f,m 4 8
 
7 12



5
12 20...
*/

In Africa there is a very special species of bee. Every year, 
the female bees of such species give birth to one male bee, 
while the male bees give birth to one male bee and one female bee, 
and then they die!
Now scientists have accidentally found one \magical female bee" of 
such special species to the effect that she is immortal, 
but still able to give birth once a year as all the other female 
bees. The scientists would like to know how many bees there will be 
after N years. 
Please write a program that helps them nd the number of male 
bees and the total number of all bees after N years.



Input
Each line of input contains an integer N ( 0). 
Input ends with a case where N = 􀀀1. (This case
should NOT be processed.)

Output
Each line of output should have two numbers, the rst one being 
the number of male bees after N years, 
and the second one being the total number of bees after N years. 
(The two numbers will not exceed 232.)



Sample Input
1
3
-1

Sample Output
1 2
4 7