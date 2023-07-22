11876 N + NOD (N) 
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/11876%20-%20N%20%2B%20NOD%20(N).cpp

concept
http://mathschallenge.net/library/number/number_of_divisors

#include <cstdio>
int ans[1000001];
int nod(int x) {
	//The number of divisor of x
	int div = 1;   //divisor already counted 1,x
	//so i start from 2
	//All you have to know harf number of factor of divisor 
	for (int i = 2; i <= x / i; ++i) {
		if (x % i == 0) {
			int cnt = 1;
			while (x % i == 0)
				x /= i, ++cnt ;
			div *= cnt;
		}
	}
	if (x > 1)
		div *= 2;
	return div;
}
int main() {
	int x = 1,T, A, B;
	while (x <= 1000000) 
		++ans[x],x += nod(x);
	for (int i = 1; i <= 1000000; ++i)
		ans[i] += ans[i - 1];//dp

	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d %d", &A, &B);
		printf("Case %d: %d\n", tc, ans[B] - ans[A - 1]);
	}
	return 0;
}



#include<stdio.h>
int ans[1000005];
int NOD(int x) {
	int div=1;
	for (int i = 2; i <= x / i; i++) 
		if (x%i == 0) {
			int cnt = 1;
			while (x%i == 0)
				x /= i, cnt++;
			div *= cnt;
		}
	if (x > 1)
		div *= 2;
	return div;
}
int main() {
	int x = 1, T, A, B;
	while (x <= 1000000)
		++ans[x], x += NOD(x);
	for (int i = 1; i <= 1000000; i++)
		ans[i] += ans[i - 1];
	
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d %d", &A, &B);
		printf("Case %d: %d\n", cas, ans[B] - ans[A - 1]);
	}
	return 0;
}



/*
N
1,2,4,7,9,12,18,24,32,38,,,86,90,102,,,,

N(0)=1
N(1)=N(0)+NOD(0)=1+1=2
N(2)=N(1)+NOD(1)=2+2=4
N(3)=N(2)+NOD(2)=4+3=7
N(4)=N(3)+NOD(3)=7+2=9
N(5)=N(4)+NOD(4)=9+3=12
N(6)=N(5)+NOD(5)=12+6=18
->N(6) has 7 divisor

N(NOD(N)) |common divisor
1(1)      |1
2(2)      |1,2
4(3)      |1,2,4
7(2)      |1,7
9(3)      |1,3,9
12(6)     |1,2,3,4,6,12
18(6)     |1,2,3,6,9,18
*/



Consider an integer sequence N where,
N0 = 1
Ni = Ni􀀀1 + NOD(Ni􀀀1) for i > 0
Here, NOD(x) = number of divisors of x.
So the rst few terms of this sequence are 1 2 4 7 9 12 18
...
Given two integers A and B, nd out the number of integers in 
the above sequence that lies within the range [A;B].



Input
The rst line of input is an integer T (T < 100000), 
that indicates the number of test cases. Each case
contains two integers, A followed by B 
(1  A  B  1000000).

Output
For each case, output the case number rst followed by the 
required result.



Sample Input
3
1 18
1 100
3000 4000

Sample Output
Case 1: 7
Case 2: 20
Case 3: 87