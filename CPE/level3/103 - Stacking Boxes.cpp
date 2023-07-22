103 - Stacking Boxes
http://eunicecode.blogspot.tw/2015/08/uva-103-stacking-boxes.html



#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n, k,dp[35];
bool DE[35][35];
struct Box{
	int ind = 0,len[15] = { 0 };
	friend bool operator < (Box a, Box b);
};
bool operator < (Box a, Box b){
	sort(a.len, a.len + n),sort(b.len, b.len + n);
	for (int i = 0; i<n; i++)
		if (a.len[i] >= b.len[i]) 
			return false;
	return true;
}
//count from biggest number to smallestnumber
//compare which is smaller number
//If new side is smaller(max number is bigger),then count it(update dp)
int DP(int i){
	if (dp[i]>0) 
		return dp[i];
	dp[i] = 1;
	for (int j = 1; j <= k; j++)
		if (DE[i][j])
			dp[i] = max(dp[i], DP(j) + 1);
	return dp[i];
}
void printans(int i){
	printf("%d ", i);
	for (int j = 1; j <= k; j++) 
		if (DE[i][j] && dp[i] == dp[j] + 1){
			printans(j);
			break;
	}
}
int main(){
	while (cin >> k >> n){
		Box boxes[35];
		memset(DE, false, sizeof(DE));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= k; i++)	
			for (int j = 0; j<n; j++)	
				cin >> boxes[i].len[j];
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (boxes[i]<boxes[j]) 
					DE[i][j] = true;
		int maxn = 0, idx = 0;
		for (int i = 1; i <= k; i++)
			DP(i);
		for (int i = 1; i <= k; i++)
			if (dp[i]>maxn)
				maxn = dp[i],idx = i;
		printf("%d\n", maxn);
		printans(idx);
		cout << endl;
	}
	return 0;
}



#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
struct box {
	int len[15] = {};
	friend bool operator <(box a, box b);
};
bool DE[35][35];
int k, n, dp[35];
bool operator <(box a, box b) {
	sort(a.len, a.len + n), sort(b.len, b.len + n);
	for (int j = 0; j < n; j++)
		if (a.len[j] >= b.len[j])
			return false;
	return true;
}
int DP(int i) {
	if (dp[i] > 0)
		return dp[i];
	dp[i] = 1;
	for (int j = 1; j <= k; j++)
		if (DE[i][j])
			dp[i] = max(dp[i], DP(j) + 1);
	return dp[i];
}
void print(int i) {
	printf("%d ", i);
	for(int j=1;j<=k;j++)
		if (DE[i][j] && dp[i] == dp[j] + 1) {
			print(j);
			break;
		}
}
int main() {
	while (cin >> k >> n) {
		memset(dp, 0, sizeof(dp));
		memset(DE, false, sizeof(DE));
		box boxes[35];
		for (int i = 1; i <= k; i++)
			for (int j = 0; j < n; j++)
				cin >> boxes[i].len[j];
		for (int i = 1; i <= k; i++)
			for (int j = 1; j <= k; j++)
				if (boxes[i] < boxes[j])
					DE[i][j] = true;
		for (int i = 1; i <= k; i++)
			DP(i);
		int max = 0, idx = 0;
		for (int i = 1; i <= k; i++)
			if (max < dp[i])
				max = dp[i], idx = i;
		printf("%d\n", max);
		print(idx);
		puts("");
	}
	return 0;
}



/*
concept
D can not larger than 
D,E array number can to rearrange.

ex1
5 2
3 7
8 10
5 2
9 11
21 18
->
2 5
3 7
8 10
9 11
15 21
->3 1 2 4 5

ex2
5 2 20 1 30 10
23 15 7 9 11 3
40 50 34 24 14 4
9 10 11 12 13 14
31 4 18 8 27 17
44 32 13 19 41 19
1 2 3 4 5 6
80 37 47 18 21 9
->
 1  2  3  4  5  6
 3  7  9 11 15 23
 4  8 17 18 27 31
13 19 19 32 41 44
->7 2 5 6
*/



Some concepts in Mathematics and Computer Science are simple in 
one or two dimensions but become more complex when extended to 
arbitrary dimensions. Consider solving differential equations in 
several dimensions and analyzing the topology of an n-dimensional
hypercube. The former is much more complicated than its one 
dimensional relative while the latter bears a remarkable 
resemblance to its “lower-class” cousin.
Consider an n-dimensional “box” given by its dimensions. 
In two dimensions the box (2,3) might represent a box with 
length 2 units and width 3 units. 
In three dimensions the box (4,8,9) can represent a box 
4  8  9 (length, width, and height). 
In 6 dimensions it is, perhaps, 
unclear what the box (4,5,6,7,8,9) represents; but we can analyze
 properties of the box such as the sum of its dimensions.
In this problem you will analyze a property of a group of 
n-dimensional boxes. You are to determine the longest nesting 
string of boxes, that is a sequence of boxes b1; b2; : : : ; bk 
such that each box bi nests in box bi+1 (1  i < k).
A box D = (d1; d2; : : : ; dn) nests in a box 
E = (e1; e2; : : : ; en) if there is some rearrangement of the
di such that when rearranged each dimension is less than the 
corresponding dimension in box E. 
This loosely corresponds to turning box D to see if it will fit 
in box E. However, since any rearrangement suffices, 
box D can be contorted, not just turned (see examples below).
For example, the box D = (2,6) nests in the box E = (7,3) 
since D can be rearranged as (6,2) so that each dimension is 
less than the corresponding dimension in E. 
The box D = (9,5,7,3) does NOT nest in the box E = (2,10,6,8) 
since no rearrangement of D results in a box that satisfies the 
nesting property, but F = (9,5,7,1) does nest in box E since F 
can be rearranged as (1,9,5,7) which nests in E.
Formally, we define nesting as follows: box 
D = (d1; d2; : : : ; dn) nests in box E = (e1; e2; : : : ; en)
if there is a permutation  of 1 : : : n such that (d(1); 
d(2); : : : ; d(n)) “fits” in (e1; e2; : : : ; en) i.e., 
if d(i) < ei for all 1  i  n.



Input
The input consists of a series of box sequences. 
Each box sequence begins with a line consisting of the
the number of boxes k in the sequence followed by the 
dimensionality of the boxes, n (on the same line.)
This line is followed by k lines, one line per box with the n 
measurements of each box on one line separated by one or more 
spaces. The i-th line in the sequence (1  i  k) 
gives the measurements for the i-th box.
There may be several box sequences in the input file. 
Your program should process all of them and determine, 
for each sequence, which of the k boxes determine the longest 
nesting string and the length of that nesting string 
(the number of boxes in the string).
In this problem the maximum dimensionality is 10 and the minimum 
dimensionality is 1. 
The maximum number of boxes in a sequence is 30.

Output
For each box sequence in the input file, output the length of 
the longest nesting string on one line followed on the next 
line by a list of the boxes that comprise this string in order. 
The “smallest” or “innermost” box of the nesting string should 
be listed first, the next box (if there is one) should be
listed second, etc.
The boxes should be numbered according to the order in which 
they appeared in the input file (first box is box 1, etc.).
If there is more than one longest nesting string then any one of 
them can be output.



Sample Input
5 2
3 7
8 10
5 2
9 11
21 18
8 6
5 2 20 1 30 10
23 15 7 9 11 3
40 50 34 24 14 4
9 10 11 12 13 14
31 4 18 8 27 17
44 32 13 19 41 19
1 2 3 4 5 6
80 37 47 18 21 9

Sample Output
53
1 2 4 5
47
2 5 6