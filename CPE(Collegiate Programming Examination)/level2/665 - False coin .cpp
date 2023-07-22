665 - False coin  



#include<stdio.h>
struct record {
	int l[101], r[101];
	char st[2];
}D[100];
main() {
	int m, n, k, a, b, c, pi, x;
	scanf("%d", &m);
	while (m--) {
		scanf("%d %d", &n, &k);
		int possible[101] = {};
		for (a = 0; a < k; a++) {
			for (b = 1; b <= n; b++) {
				D[a].l[b] = D[a].r[b] = 0;
			}
		}
		for (a = 0; a < k; a++) {
			scanf("%d", &pi);
			for (b = 0; b < pi; b++)    scanf("%d", &x), D[a].l[x] = 1;
			for (b = 0; b < pi; b++)    scanf("%d", &x), D[a].r[x] = 1;
			scanf("%s", &D[a].st);
			if (D[a].st[0] == '=') {
				for (b = 1; b <= n; b++) {
					if (D[a].l[b])    possible[b] = 1;
					if (D[a].r[b])    possible[b] = 1;
				}
			}
		}
		int Ans = 0, flag = 0, ll, lr, hl, hr;
		for (a = 1; a <= n; a++) {
			if (possible[a]) continue;
			for (b = 0; b < k; b++) {
				ll = lr = hl = hr = 0;
				if (D[b].l[a] != 0) ll--;
				if (D[b].r[a] != 0) lr--;
				if (D[b].l[a] != 0) hl++;
				if (D[b].r[a] != 0) hr++;
				if (ll == lr && D[b].st[0] == '=') continue;
				if (ll < lr && D[b].st[0] == '<') continue;
				if (ll > lr && D[b].st[0] == '>') continue;
				if (hl == hr && D[b].st[0] == '=') continue;
				if (hl < hr && D[b].st[0] == '<') continue;
				if (hl > hr && D[b].st[0] == '>') continue;
				break;
			}
			if (b == k)
				flag++, Ans = a;
		}
		if (flag == 1)    printf("%d\n", Ans);
		else puts("0");
		if (m)	puts("");
	}
	return 0;
}



#include<stdio.h>

struct record {int l[101], r[101];char st[2];};

int main() {
	int i,cas, n, m, j, pi, x;
	scanf("%d", &cas);
	while (cas--) {
		scanf("%d %d", &n, &m);
		struct record coin[100] = {};
		int possible[101] = {};

		for (int i = 0; i < m; i++) {
			scanf("%d", &pi);
			for (j = 0; j < pi; j++)
				scanf("%d", &x), coin[i].l[x] = 1;
			for (j = 0; j < pi; j++)
				scanf("%d", &x), coin[i].r[x] = 1;
			scanf("%s", &coin[i].st);
			if (coin[i].st[0] == '=') {
				for (j = 1; j <= n; j++) {
					if (coin[i].l[j])    possible[j] = 1;
					if (coin[i].r[j])    possible[j] = 1;
				}
			}
		}
		int Ans = 0, flag = 0, ll, lr, hl, hr;
		for (int i = 1; i <= n; i++) {
			if (possible[i]) continue;
			for (j = 0; j < m; j++) {
				ll = lr = hl = hr = 0;
				if (coin[j].l[i] != 0) ll--,hl++;
				if (coin[j].r[i] != 0) lr--,hr++;
				if (ll == lr && coin[j].st[0] == '=') continue;//number no appear
				if (ll < lr && coin[j].st[0] == '<') continue;
				if (ll > lr &&coin[j].st[0] == '>') continue;
				if (hl == hr && coin[j].st[0] == '=') continue;
				if (hl < hr && coin[j].st[0] == '<') continue;
				if (hl > hr && coin[j].st[0] == '>') continue;
				break;
			}
			if (j == m)
				flag++, Ans = i;
		}
		if (flag == 1)
			printf("%d\n", Ans);
		else
			puts("0");
		if (cas)
			puts("");
	}
	return 0;
}


The “Gold Bar” bank received information from reliable
sources that in their last group of N coins exactly one coin
is false and differs in weight from other coins (while all 
other coins are equal in weight). After the economic crisis 
they have only a simple balance available (like one in the 
picture). Using this balance, one is able to determine if 
the weight of objects in the left pan is less than, greater 
than, or equal to the weight of objects in the right pan.
In order to detect the false coin the bank employees 
numbered all coins by the integers from 1 to N, thus 
assigning each coin a unique integer identifier. After that 
they began to weight various groups of coins by placing
equal numbers of coins in the left pan and in the right pan. 
The identifiers of coins and the results of the weightings 
were carefully recorded. You are to write a program that 
will help the bank employees to determine the identifier of 
the false coin using the results of these weightings.



Input
The first line of the input is an integer M, then a blank line
followed by M datasets. There is a blank line between datasets.
The first line of each dataset contains two integers N and K, 
separated by spaces, where N is the number of coins 
(1 ≤ N ≤ 100) and K is the number of weightings fulfilled 
(1 ≤ K ≤ 100). The following 2K lines describe all weightings.
 Two consecutive lines describe each weighting. 
 The first of them starts with a number Pi (1 ≤ Pi ≤ N/2), 
 representing the number of coins placed in the left and in 
 the right pans, followed by Pi identifiers of coins placed 
 in the left pan and Pi identifiers of coins placed in the 
 right pan. All numbers are separated by spaces.
The second line contains one of the following characters: 
‘<’, ‘>’, or ‘=’. It represents the result of the weighting:
• ‘<’ means that the weight of coins in the left pan is less 
   than the weight of coins in the right pan,
• ‘>’ means that the weight of coins in the left pan is 
   greater than the weight of coins in the right pan,
• ‘=’ means that the weight of coins in the left pan is equal 
   to the weight of coins in the right pan.
   
   
   
Output
For each dataset, write to the output file the identifier of 
the false coin or ‘0’, if it cannot be found by the results of
the given weightings.Print a blank line between datasets.



Sample Input
2
5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=
6 4
3 1 2 3 4 5 6
<
1 1 2
=
2 1 3 4 5
<
2 4 5 2 6
>

Sample Output
3
0


Sample Input
2
5 3
2   1 2   3 4
<
1   1   4
=
1   2   5
=
6 4
3   1 2 3   4 5 6
<
1   1   2
=
2   1 3   4 5
<
2   4 5   2 6
>




3

5 3
2 1 2 3 4
<
1 1 4
=
1 2 5
=

5 2
1 1 2
=
1 1 3
<

5 3
1 1 3
<
1 1 4
=
1 3 4
=

output
3
3
0
