11069 - A Graph Problem
https://www.google.com.tw/search?biw=794&bih=635&q=11069+-+A+Graph+Problem%E3%80%80include&oq=11069+-+A+Graph+Problem%E3%80%80include&gs_l=psy-ab.3..33i160k1l2.3099.10711.0.10883.19.16.3.0.0.0.119.980.15j1.16.0....0...1.1j4.64.psy-ab..0.9.509...0i22i30k1j33i21k1.sp_GMInzhzo



#include<cstdio>

int main() {
	int n;
	int dp[80] = { 0,1,2,2 };
	for (int i = 4; i <= 76; i++)
		dp[i] = dp[i - 2] + dp[i - 3];
	while (scanf("%d", &n) ==1)
		printf("%d\n", dp[n]);
	return 0;
}

/*
concept
no nodes in the subset should be connected
12345->1 3 5 ,2 4  ,1 4  ,1 5
• it shouldn't be possible to add further nodes to the subset 
   without violating the first condition
   1 3 5 -> 1 3 ,1 5 ->x(don't duplicate)
*/


Given an undirected graph of the following form with n nodes, 
1  n  76:
Your task is to calculate the number of subsets of nodes of the graph 
with the following properties:
• no nodes in the subset should be connected
• it shouldn't be possible to add further nodes to the subset without 
  violating the rst condition
For a graph with 5 nodes the number of subsets which fulll the 
above conditions is 4. The subsets
are f1,3,5g,f2,4g,f2,5g,f1,4g.



Input
The input will consist of a sequence of numbers n, 1  n  76. 
Each number will be on a separate line.
The input will be terminated by EOF.

Output
Output the number of subsets as described above on a single line. 
The number of all subsets will be less than 231.



Sample Input
1
2
3
4
5
30

Sample Output
1
2
2
3
4
4410