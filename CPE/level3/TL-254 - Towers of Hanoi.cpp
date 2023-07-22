Time-limit 254 - Towers of Hanoi
http://mypaper.pchome.com.tw/zerojudge/post/1323475368


#include <stdio.h>
int n,m, flag,peg[3];
void h(int n, int A, int B, int C) {
	if (flag)    return;
	if (m == 0) {
		printf("%d %d %d\n", peg[0], peg[2], peg[1]);
		flag = 1;
	}
	if (n > 0) {
		if (m > (1 << (n - 1)) - 1) {
			m -= (1 << (n - 1)) - 1;
			peg[A] -= n - 1;
			peg[B] += n - 1;
		}
		else
			h(n - 1, A, C, B);
		m--;
		peg[A]--, peg[C]++;
		if (m > (1 << (n - 1)) - 1) {
			m -= (1 << (n - 1)) - 1;
			peg[B] -= n - 1;
			peg[C] += n - 1;
		}
		else
			h(n - 1, B, A, C);
	}
}
int main() {
	while (scanf("%d %d", &n, &m),n+m) {
		flag = 0;
		peg[0] = n, peg[1] = 0,peg[2] = 0;
		h(n, 0, 1, 2);
	}
	return 0;
}