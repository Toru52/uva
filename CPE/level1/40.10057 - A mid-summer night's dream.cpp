10057 - A mid-summer night's dream. 



no1.
#include <algorithm>  
#include <cstdio>  
int s[1000005];

int main()
{
	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; ++i)
			scanf("%d", &s[i]);
		std::sort(s, s + n);
		int val = s[(n - 1) >> 1], count = 0;
		for (int i = 0; i < n; ++i)
			count += (val == s[i] || s[i] == s[n >> 1]);
		printf("%d %d %d\n", val, count, s[n >> 1] - val + 1);
	}
	return 0;
}



no2.
#include<cstdio>
#include<algorithm>

int main()
{
	int n,s[1000005];
	while (~scanf("%d", &n))
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			scanf("%d", &s[i]);
		std::sort(s, s + n);
		int A = s[(n-1) / 2];

		for (int i = 0; i < n; i++)
			if (A == s[i] || s[i] == s[n / 2])
				cnt++;
		printf("%d %d %d\n", A, cnt, s[n / 2] - A + 1);

	}
}



/*output
A 

number of minimum of A
ex.
2 10 10
->A=10 for i=1,2 ->A=s[1],s=[2]->two number exist.

how many possible different integer values are there for A
except input number

(Algorithm)
If number of integer is even, The inside number of integer in the
middle two integer is number of minimum.

n >> 1  ->  n/2


*/



This is year 2200AD. Science has progressed a lot in two hundred 
years. Two hundred years is mentioned here because this problem 
is being sent back to 2000AD with the help of time machine. 
Now it is possible to establish direct connection between man 
and computer CPU. People can watch other peoples dream on 3D 
displayer (That is the monitor today) as if they were watching 
a movie. One problem in this century is that people have become 
so dependent on computers that their analytical ability is
approaching zero. Computers can now read problems and solve them 
automatically. But they can solve only difficult problems. 
There are no easy problems now. Our chief scientist is in great 
trouble as he has forgotten the number of his combination lock. 
For security reasons computers today cannot solve combination 
lock related problems. In a mid-summer night the scientist has 
a dream where he sees a lot of unsigned integer numbers flying 
around. He records them with the help of his computer,Then he 
has a clue that if the numbers are (X1, X2, . . . , Xn)
he will have to find an 
integer number A(This A is the combination lock code) 
such that
(|X1 − A| + |X2 − A| + . . . + |Xn − A|) is minimum.



Input
Input will contain several blocks. Each block will start with a 
number n (0 < n ≤ 1000000) indicating how many numbers he saw in 
the dream. Next there will be n numbers. All the numbers will be 
less that 65536. The input will be terminated by end of file.

Output
For each set of input there will be one line of output. That line
will contain the minimum possible value for A. Next it will 
contain how many numbers are there in the input that satisfy the 
property of A (The summation of absolute deviation from A is 
minimum). And finally you have to print how many possible 
different integer values are there for A (these values need not 
be present in the input). These numbers will be separated 
by single space.



Sample Input
2
10
10
4
1
2
2
4

Sample Output
10 2 1
2 2 1