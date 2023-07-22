10489 	Boxes of Chocolates
https://github.com/morris821028/UVa/blob/master/volume104/10489%20-%20Boxes%20of%20Chocolates.cpp


#include <stdio.h>
int main() {
	int t, n, m, x, y, z;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		int ans = 0;
		while (m--) {
			scanf("%d", &x);
			z = 1;
			while (x--)
				scanf("%d", &y), z *= y, z %= n;
			ans += z;
		}
		printf("%d\n", ans%n);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int cas,N,B;
	scanf("%d", &cas);
	while (cas--) {
		int residue = 0;
		scanf("%d %d", &N, &B);
		while (B--) {
			int K, bc,ch=1;
			scanf("%d", &K);
			while (K--)
				scanf("%d", &bc), ch *= bc, ch %= N;
			residue += ch;
		}
		printf("%d\n", residue%N);
	}
	return 0;
}



SampleInput
2
5 2        (5:friends 2:two lines)
3 2 3 4    (3:three integer 2 3:number of boxes 4:number of chocolates)
4 5 2 3 1
6 1
4 5 6 7 8

Little
Pippy
has got a lot of chocolates on her 6-th birthday. 
She is a very good and charming girl and
always shares his belongings with her friends 
(and she has lots of friends). Now she wants to share all
the chocolate with her friends. She will try her best to give all her 
friend equal number of chocolates
but in case she fails, she will give her pet cat
Kittu
the residue number of chocolates. The chocolates
she has got are in boxes wrapped with beautiful papers. 
Sometimes a box do not contain chocolates
but have smaller boxes inside them. Even sometimes 
the smaller boxes do not contain any chocolates
but have further smaller boxes inside them. 
Only the smallest boxes always contain some chocolates.



Input
Input will start with an integer
T
. Following lines will contain descriptions for
T
test cases. First
line of each test case will contain two integers
N
and
B
indicating the number of friends
Pippy
has
and the number of box of chocolates she has got respectively. 
Each of the next
B
lines will contain a
description of a single box. These lines will start with an integer
K
followed by
K
integers identi ed
as
a
1
; a
2
; a
3
; : : : ; a
k
.  Here
a
i
indicates the number of boxes the
i
-th box contains within it where
(0
< i < K
). The last number of the line indicates the number of chocolates 
contained in each of the
smallest box. All the numbers will be positive and
T
,
B
,
K
will be less than 101 and
N
,
a
i
will be less
than 10001.
Output
For each test case, print an integer on a single 
line indicating the number of extra chocolates
Kittu
will
get after dividing all of them equally among
Pippy
's friends.



SampleInput
2
5 2
3 2 3 4
4 5 2 3 1
6 1
4 5 6 7 8

SampleOutput
4
0