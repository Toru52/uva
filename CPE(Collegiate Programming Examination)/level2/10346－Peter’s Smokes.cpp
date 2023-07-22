10346－Peter’s Smokes
https://github.com/marioyc/Online-Judge-Solutions/blob/master/UVA/Contest%20Volumes/10346%20-%20Peter's%20Smoke.cpp

#include<stdio.h>

int main() {
	int n, k;
	while (scanf("%d %d", &n, &k) == 2) {
		int cont = 0, res = 0;
		while (n > 0) {
			cont += n;
			res += n;
			n = res / k;
			res %= k;
		}
		printf("%d\n", cont);
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		int cnt = 0,res=0;
		while (n) {
			cnt += n;
			res += n;
			n = res / k;
			res %= k;
		}
		printf("%d\n", cnt);
	}
	return 0;
}

Peter has
n
cigarettes. He smokes them one by one keeping all the butts. 
Out of k>1 butts he can roll a new cigarette.
How many cigarettes can Peter have?



Input
Input is a sequence of lines. Each line contains two 
integer numbers giving the values of
n
and
k
. The
input is terminated by end of  le

Output
For each line of input, output one integer number on a 
separate line giving the maximum number of
cigarettes that Peter can have.



SampleInput
4 3
10 3
100 5

SampleOutput
5
14
124