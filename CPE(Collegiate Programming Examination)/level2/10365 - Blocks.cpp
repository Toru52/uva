10365 - Blockshttp
http://mypaper.pchome.com.tw/zerojudge/post/1323192109



#include <stdio.h>
#include<algorithm>
#include <math.h>
using namespace std;
int main() {
	int t, n,j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sq = (int)sqrt(n), sq2;//plane square
		int mi = 0xfffffff;
		for (int i = 1; i <= sq; i++) 
			if (n%i == 0) {
				j = n / i;
				sq2 = (int)sqrt(j);//height square
				for (int k = 1; k <= sq2; k++) 
					if (j%k == 0) 
						mi = min(mi,2 * (i*k + j + i*j / 
			//printf("sq %d i %d j %d sq2 %d k %d area %d\n",
		    //    sq, i, j, sq2, k, 2 * (i*k + j + i*j / k));
			}
		printf("%d\n", mi);
	}
	return 0;
}



#include<stdio.h>
#include<algorithm>
#include<math.h>
int main() {
	int cas, n, j;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d", &n);
		int sq = sqrt(n),mi=0xffff;
		for (int i = 1; i <= sq; i++) {
			if (n%i == 0) {
				j = n / i;
				int sq2 = sqrt(j);
				for (int k = 1; k <= sq2; k++)
					if (j%k == 0)
						mi = std::min(mi,2*( i*k + j + i*j / k));
			}
		}
		printf("%d\n", mi);
	}
	return 0;
}



/*
concept
It's better blocks be cube form , 
since cube form can be minimum surface area
So It can determine length of a side by use "sqrt"
It has two "sqrt".one is plane, one is height.

ex n=4
1 4
b|b|b|b ->area:18 
2 2
b|b
b|b ->area:16

sq=2
i=1 (row)
j=4 (column)
sq2=2
k=1 (height)
area=2 * (i*k + j + i*j / k)
    =2*(1*1+4+1*4/1)
	=18
k=2
area=2*(1*2+4+1*4/2)
    =16
sq=2
i=2
j=2
sq2=1
k=1
area=16


/*
ex
->1
surface area = 1inch*1inch
a block = 6 surface area = 6(1inch *1inch)=6
*/



Donald wishes to send a gift to his
new nephew, Fooey. Donald is a bit
of a traditionalist, so he has cho-
sen to send a set of
N
classic baby
blocks. Each block is a cube, 1 inch
by 1 inch by 1 inch. Donald wants
to stack the blocks together into
a rectangular solid and wrap them
all up in brown paper for shipping.
How much brown paper does Donald need?
Input
The  rst line of input contains
C
, the number of test cases. For each case there is an 
additional line
containing
N
, the number of blocks to be shipped.
N
does not exceed 1000.
Output
Your program should produce one line of output per case, 
giving the minimal area of paper (in square
inches) needed to wrap the blocks when they are stacked 
together.



SampleInput
5
9
10
26
27
100

SampleOutput
30
34
82
54
130