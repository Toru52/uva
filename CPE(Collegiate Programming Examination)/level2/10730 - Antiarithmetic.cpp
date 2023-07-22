10730 - Antiarithmetic?
https://github.com/Diusrex/UVA-Solutions/blob/master/10730%20Antiarithmetic.cpp


#include<stdio.h>
int main()
{
	int N,nums[10005],numReachedBy[10005];
	while (scanf("%d: ",&N),N){
		for (int i = 0; i < N; ++i){
			scanf("%d", &nums[i]);
			numReachedBy[nums[i]] = i;
		}
		bool isSeq = true;
		for (int i = 0; i < N && isSeq; ++i)
			for (int j = i + 1; j < N; ++j)	{
				int third = 2 * nums[j] - nums[i];
				//nums[j]*2 since check whether it is bigger than N or not
				//This represent it check whether nums[j] is higher than middle or lower.
                //third->third number				
				printf("num[%d]=%d num[%d]=%d third %d\n",i,nums[i],j,nums[j], third);
				if (third >= 0 && third < N)//whether it is progression or not.*1
					if (numReachedBy[third] > j){//*2
						//This section already passed first second number
						//check third i number(i<j<k<n)
						printf("j %d < reached[%d]=%d\n", j, third, numReachedBy[third]);
						isSeq = false;
						break;
					}
			}
		if (isSeq)
			puts("yes");
		else
			puts("no");
	}
}



#include<stdio.h>
int main() {
	int n,num[10005], inum[10005];
	while (scanf("%d: ", &n), n) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
			inum[num[i]] = i;
		}
		bool flag = true;
		for(int i=0;i<n&&flag;i++)
			for (int j = i + 1; j < n; j++) {
				int third = num[j] * 2 - num[i];
				if(0<third&&third<n)
					if (j < inum[third]) {
						flag = false;
						break;
					}
			}
		if (!flag)
			puts("no");
		else
			puts("yes");
	}
	return 0;
}

/*
concept
antialithmetic->
no alithmetic->
0<=i<j<k<n, (pi,pj,pk) progression
->no

alithmetic->yes

antialithmetic condition
1,first,second,third number is progression
2.i<j<k<n

ex n=4
4:0 1 2 3
0 1 
third=1*2-1=1
since 0<1 , ascending first second number with third
since N>1 , ascending first second number
4:1 0 2 3  
1 0
third=0*2-1=-1
since 0>-1 ,decending first second number with third
since N>1 , ascending first second number


***THIRD=[j]*2-[i]
if THIRD is bigger than N,
then third number and first second number should be decending.
otherwise is ascending


ex 0 1 2
yes 
012
210

no
102
120
021
201

*/



A permutation of n is a
bijective function of the
initial n natural numbers:
0; 1; : : : ; n 􀀀 1. A per-
mutation p is called an-
tiarithmetic if there is no
subsequence of it forming
an arithmetic progression of
length bigger than 2, i.e. 
there are no three indices 0  i < j < k < n such that 
(pi; pj ; pk) forms an arithmetic progression.
For example, the sequence (2, 0, 1, 4, 3) is an antiarithmetic 
permutation of 5. The sequence (0, 5, 4, 3, 1, 2) is not an 
antiarithmetic permutation as its rst, fth and sixth term 
(0, 1, 2) form an arithmetic progression; and so do its second, 
forth and fth term (5, 3, 1).
Your task is to check whether a given permutation of n is 
antiarithmetic.



Input
There are several test cases, followed by a line containing 0. 
Each test case is a line of the input le containing a natural 
number 3  n  10000 followed by a colon and then followed by n 
distinct numbers separated by whitespace. All n numbers are natural 
numbers smaller than n.

Output
For each test case output one line with `yes' or `no' stating 
whether the permutation is antiarithmetic or not.



Sample Input
3: 0 2 1
5: 2 0 1 3 4
6: 2 4 3 5 0 1
0

Sample Output
yes
no
yes