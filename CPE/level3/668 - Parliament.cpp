668 - Parliament
http://programming-study-notes.blogspot.tw/2014/02/uva-668-parliament.html



#include <cstdio>
int main(){
	int M, N;
	scanf("%d", &M);
	while (M--) {
		scanf("%d", &N);
		int a[1001], n = 0, sum = 0;
		for (int i = 2; sum + i <= N; i++) 
			sum += i,a[n++] = i;		
		int j = N - sum;
		for (int i = n - 1; j > 0; i--, j--) {
			if (i < 0) 
				i = n - 1;
			a[i]++;
		}
		for (int i = 0; i < n; i++)
			printf(i == 0 ? "%d" : " %d", a[i]);
		printf("\n");
		if (M) 
			printf("\n");
	}
	return 0;
}



New convocation of The Fool Land’s Parliament consists of N delegates. 
According to the present regulation delegates should be divided into 
disjoint groups of different sizes and every day each group has to 
send one delegate to the conciliatory committee. 
The composition of the conciliatory committee should be different each 
day. The Parliament works only while this can be accomplished.
You are to write a program that will determine how many delegates 
should contain each group in order for Parliament to work as long as 
possible.



Input
The first line of the input is an integer M, then a blank line 
followed by M datasets. There is a blank line between datasets.
Each dataset contains a single integer N (5  N  1000).

Output
For each dataset, write to the output file the sizes of groups that 
allow the Parliament to work for the maximal possible time. 
These sizes should be printed on a single line in ascending order and
should be separated by spaces.
Print a blank line between datasets.



Sample Input
2
7
31

Sample Output
3 4
2 3 5 6 7 8
