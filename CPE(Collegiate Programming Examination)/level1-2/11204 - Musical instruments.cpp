11204 - Musical instruments



#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int m, n, rank, i, j, cnt[32] = {};
		scanf("%d %d", &m, &n);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				scanf("%d", &rank);
				if (rank == 1)
					cnt[j]++;
			}
		}
		int ans = 1;
		for (i = 0; i < m; i++) {
			if (cnt[i])
				ans *= cnt[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}



#include<stdio.h>
int main()
{
	int c,m,n,rank;
	scanf("%d", &c);
	while (c--)
	{
		int ans = 1, cnt[32] = {0};
		scanf("%d %d", &m, &n);
		for(int i=0;i<n;i++)
			for (int j = 0; j < m; j++) {
				scanf("%d", &rank);
				if (rank == 1) 
					cnt[j]++;// printf("cnt %d", cnt[j]);
			}
		for (int i = 0; i < m; i++)
			if(cnt[i])
				ans *= cnt[i];
		printf("%d\n", ans);
	}
}



Algorithm
Priority represent 1 
We consider 1 pointly 
 

Julio is a musician who teaches classical music at 
secondary school. Julio has N musical instruments
to distribute among his M students, N ≥ M. To make an 
adequate distribution, Julio asked each
student to list the N musical instruments in order of 
priority. Julio wants to make a distribution in
which the biggest number of students have their 
favourite musical instrument, but there may be several
possibilities. He wants to know how many possible 
arrangements –maximizing the assignment of the
first priority– can be obtained.
You must write a program which computes how many 
different distributions are possible, supposing the 
biggest number of students have their favourite 
musical instrument.



Input
The first line of the input contains the number of test 
cases. For each test case, there is a line with two
numbers, N indicating the number of musical instruments, 
and M indicating the number of students,
32 ≥ N ≥ M. Subsequently, M lines are listed, one for 
each student; each line contains, separated by
one space, N numbers between 1 and N which determine 
the priority of the corresponding student.
The first number is the priority of the first musical 
instrument, the second number is the priority of
the second musical instrument, and so on.

Output
For every test case you are to print a line containing a 
number which represents how many possible
distributions can be obtained.



Sample Input
4
10 6
1 2 3 4 5 6 7 8 9 10
4 5 6 7 8 9 10 1 2 3
6 7 8 9 10 1 2 3 4 5
7 8 9 10 1 2 3 4 5 6
9 10 1 2 3 4 5 6 7 8
9 10 3 4 5 6 7 8 1 2
12 4
3 4 5 6 7 8 9 10 1 2 11 12
7 8 9 10 1 2 6 11 12 3 4 5
4 5 6 7 8 9 10 12 1 2 3 11
12 5 6 7 8 9 10 1 2 3 4 11
6 4
2 3 1 4 5 6
2 3 1 4 5 6
6 1 2 3 4 5
5 1 2 3 4 6
2 1
1 2

Sample Output
1
2
4
1