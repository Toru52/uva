10919 - Prerequisites?
http://mypaper.pchome.com.tw/zerojudge/post/1324754683



#include <stdio.h>
int main() {
	int n, m,x, r, c;
	while (scanf("%d %d", &n, &m) == 2) {
		int mark[10000] = {};
		for (int i = 0; i < n; i++)
			scanf("%d", &x), mark[x] = 1;
		int ok = 1;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &r, &c);
			int cnt = 0;
			while (r--) {
				scanf("%d", &x);
				cnt += mark[x];
			}
			ok &= cnt >= c;
		}
		puts(ok ? "yes" : "no");
	}
	return 0;
}



#include<stdio.h>
int main() {
	int n, m,x,r,c;
	while (scanf("%d%d", &n, &m) == 2) {
		bool mark[10000] = {}, ok = true;
		for (int i = 0; i < n; i++)
			scanf("%d", &x), mark[x] = true;
		for (int i = 0; i < m; i++) {
			int cnt = 0;
			scanf("%d%d", &r, &c);
			while (r--) 
				scanf("%d", &x),cnt += mark[x];
			ok &= cnt >= c;
		}
		puts(ok ? "yes" : "no");
	}
	return 0;
}



Freddie the frosh has
chosen to take k courses.
To meet the degree re-
quirements, he must
take courses from each
of several categories.
Can you assure Fred-
die that he will grad-
uate, based on his
course selection?



Input
Input consists of sev-
eral test cases. For
each case, the rst
line of input contains
1  k  100,
the number of courses
Freddie has chosen,
and 0  m  100, the
number of categories.
One or more lines fol-
low containing k 4-
digit integers follow;
each is the number of
a course selected by
Freddie. Each cate-
gory is represented by
a line containing 1 
c  100, the number
of courses in the cat-
egory, 0  r  c,
the minimum number
of courses from the category that must be taken, and the c course 
numbers in the category. Each course number is a 4-digit integer.
 The same course may full several category requirements. 
Freddie's selections, and the course numbers in any particular 
category, are distinct. A line containing `0' follows
the last test case.

Output
For each test case, output a line containing `yes' if Freddie's 
course selection meets the degree require-
ments; otherwise output `no'.



Sample Input
3 2
0123 9876 2222
2 1 8888 2222
3 2 9876 2222 7654
3 2
0123 9876 2222
2 2 8888 2222
3 2 7654 9876 2222
0

Sample Output
yes