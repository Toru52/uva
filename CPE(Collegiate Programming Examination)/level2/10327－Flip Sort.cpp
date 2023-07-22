10327－Flip Sort
http://knightzone.org/?p=1588



#include<iostream>
using namespace std;

int main() {
	int N,M,flip[1005];

	while (~scanf("%d", &N)) {
		for (int i = 0; i < N; i++)
			scanf("%d", &flip[i]);
		M = 0;
		for (int i = 0; i < N; i++)
			for (int j = N - 1; j > i; j--)
				if (flip[j] < flip[j - 1]) {
					swap(flip[j], flip[j - 1]);
					M++;
				}
		printf("Minimum exchange operations : %d\n", M);
	}
	return 0;
}



#include<iostream>
int main() {
	int n, flip[1005];
	while (~scanf("%d", &n)) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &flip[i]);
		for (int i = 0; i < n; i++)
			for (int j = n - 1; j > i; j--)
				if (flip[j - 1] > flip[j])
					cnt++, std::swap(flip[j], flip[j - 1]);
		printf("Minimum exchange operations : %d\n", cnt);
	}
	return 0;
}


Sorting in computer science is an important part. 
Almost every problem can be solved effeciently if sorted data are 
found. There are some excellent sorting algorithm which has already 
acheived the lower bound n  lg n. 
In this problem we will also discuss about a new sorting approach. 
In this approach only one operation (Flip) is available and that is 
you can exchange two adjacent terms. If you think a while, 
you will see that it is always possible to sort a set of numbers 
in this way.
A set of integers will be given. Now using the above approach we want 
to sort the numbers in ascending order. 
You have to  nd out the minimum number of  ips required. 
Such as to sort `1 2 3' we need no  ip operation whether to sort 
`2 3 1' we need at least 2  ip operations.



Input
The input will start with a positive integer
N
(
N

1000). In next few lines there will be
N
integers.
Input will be terminated by EOF.

Output
For each data set print `
Minimum exchange operations :
M
' where
M
is the minimum  ip opera-
tions required to perform sorting. 
Use a seperate line for each case.



SampleInput
3
1 2 3
3
2 3 1

SampleOutput
Minimum exchange operations : 0
Minimum exchange operations : 2