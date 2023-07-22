562 - Dividing coins 
https://github.com/shahidul2k9/problem-solution/blob/master/uva%20online%20judge/562%20-%20Dividing%20coins.cpp



#include<stdio.h>
#include<algorithm>
int A[25005], wt[105];
int knapsack(int n,int W) {
	for (int i = 1; i <= W; i++)
		A[i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = W; j > 0; j--)
			if (j >= wt[i])
				A[j] = std::max(A[j], wt[i] + A[j - wt[i]]);
	return A[W];
}
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &wt[i]), sum += wt[i];
		printf("%d\n", sum - 2 * knapsack(n, sum / 2));
	}
	return 0;
}



/*
knapsack
ex
3
2 3 5

   1 2 3 4 5   wt[j]<-n=sum/2=10/2=5
   
2    2 2 2 2
3      3 3 3
5          5     
A[i]
->
A[sum/2]=A[5]=5



4
1 2 4 6  

    1 2 3 4 5 6   <-n=sum/2=13/2=6
1   1 1 1 1 1 1
2     2 3 3 3 3
4         4 5 6
6             6

*/
It’s commonly known that the Dutch have invented copper-wire. Two Dutch
men were fighting over a nickel, which was made of copper. 
They were both so eager to get it and the fighting was so fierce,
they stretched the coin to great length and thus created copper-wire.
Not commonly known is that the fighting started, after the two Dutch 
tried to divide a bag with coins between the two of them. 
The contents of the bag appeared not to be equally divisible. 
The Dutch of the past couldn’t stand the fact that a division should 
favour one of them and they always wanted a fair share to the very 
last cent. Nowadays fighting over a single cent will not be seen 
anymore, but being capable of making an equal division as fair as 
possible is something that will remain important forever...
That’s what this whole problem is about. Not everyone is capable of 
seeing instantly what’s the most fair division of a bag of coins 
between two persons. Your help is asked to solve this problem.
Given a bag with a maximum of 100 coins, determine the most fair 
division between two persons.
This means that the difference between the amount each person obtains 
should be minimised. The value of a coin varies from 1 cent to 500 
cents. It’s not allowed to split a single coin.



Input
A line with the number of problems n, followed by n times:
• a line with a non negative integer m (m  100) indicating the 
  number of coins in the bag
• a line with m numbers separated by one space, each number indicates 
  value of a coin.
  
Output
The output consists of n lines. Each line contains the minimal 
positive difference between the amount the two persons obtain when 
they divide the coins from the corresponding bag.



Sample Input
2
3
2 3 5
4
1 2 4 6

Sample Output
0
1
